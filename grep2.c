/*
    grep2.c -- grep command with -i and -v options
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <regex.h>
#include <unistd.h>

static void grep_file(regex_t *re, char *path);
static void grep_stream(regex_t *re, FILE *f);

static int opt_invert = 0;
static int opt_ignorecase = 0;

int
main(int argc, char *argv[])
{
    int opt;
    while ((opt = getopt(argc, argv, "iv")) != -1) {
        switch (opt) {
        case 'i':
            opt_ignorecase = 1;
            break;
        case 'v':
            opt_invert = 1;
            break;
        case '?':
            fprintf(stderr, "Usage: %s [-iv] pattern [<file>...]\n", argv[0]);
            exit(1);
        }
    }
    argc -= optind;
    argv += optind;

    if (argc < 1) {
        fputs("no pattern\n", stderr);
        exit(1);
    }
    char *pattern = argv[0];
    argc--;
    argv++;

    /* re は「正規表現 (Regular Expression)」の略語。
       「regexp」「regex」などもよく使われます */
    int re_mode = REG_EXTENDED | REG_NOSUB | REG_NEWLINE;
    if (opt_ignorecase) re_mode |= REG_ICASE;
    regex_t re;
    int err = regcomp(&re, pattern, re_mode);
    if (err != 0) {
        char buf[1024];

        regerror(err, &re, buf, sizeof buf);
        puts(buf);
        exit(1);
    }
    if (argc == 0) {
        grep_stream(&re, stdin);
    }
    else {
        int i;
        for (i = 0; i < argc; i++) {
            grep_file(&re, argv[i]);
        }
    }
    regfree(&re);
    exit(0);
}

/* path で示されるファイルを grep する */
static void
grep_file(regex_t *re, char *path)
{
    FILE *f;
    
    f = fopen(path, "r");
    if (!f) {
        perror(path);
        exit(1);
    }
    grep_stream(re, f);
    fclose(f);
}

/* f で示されるストリームを grep する。
   書籍では「FILE* はストリームなんだ！」と散々言ったくせに、
   変数名を f (file の頭文字) にするあたりが弱い。 */
static void
grep_stream(regex_t *re, FILE *f)
{
    char buf[4096];
    int matched;

    while (fgets(buf, sizeof buf, f)) {
        matched = (regexec(re, buf, 0, NULL, 0) == 0);
        if (opt_invert) {
            matched = !matched;
        }
        if (matched) {
            fputs(buf, stdout);
        }
    }
}
