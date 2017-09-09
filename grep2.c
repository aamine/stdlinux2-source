/*
    grep2.c

    (EUC-JP encoding)
    第 8 章の練習問題 1 の解答です。

    なお、書籍 (第一刷) には -v と -f を実装しろと書いてありますが
    これは間違いで、意図していたのは -i オプションでした。
    そこでこのファイルでは -v, -f, -i の三つを実装してあります。

    ただ、-f オプションを実装するときに「問題 8.2 (難)」のテーマである
    バッファの自動拡張が必要になってしまいました。read_file() は 8 章
    までの時点では理解できないと思いますので、11 章の malloc() のあたり
    を読んでから取り組んでください。
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <regex.h>
#include <unistd.h>

static void grep_file(regex_t *re, char *path);
static void grep_stream(regex_t *re, FILE *f);
static char *read_file(char *path);
static void die(const char *s);

static int opt_invert = 0;
static int opt_ignorecase = 0;

int
main(int argc, char *argv[])
{
    char *pattern = NULL;
    regex_t re;
    int re_mode;
    int err;
    int i;
    int opt;

    while ((opt = getopt(argc, argv, "if:v")) != -1) {
        switch (opt) {
        case 'i':
            opt_ignorecase = 1;
            break;
        case 'f':
            pattern = read_file(optarg);
            break;
        case 'v':
            opt_invert = 1;
            break;
        case '?':
            fprintf(stderr, "Usage: %s [-iv] [-f PATTERN] [<file>...]\n", argv[0]);
            exit(1);
        }
    }
    argc -= optind;
    argv += optind;
    if (!pattern) {
        if (argc < 1) {
            fputs("no pattern\n", stderr);
            exit(1);
        }
        pattern = argv[0];
        argc--;
        argv++;
    }

    /* re は「正規表現 (Regular Expression)」の略語。
       「regexp」「regex」などもよく使われます */
    re_mode = REG_EXTENDED | REG_NOSUB | REG_NEWLINE;
    if (opt_ignorecase) re_mode |= REG_ICASE;
    err = regcomp(&re, argv[0], re_mode);
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

/* path で示されるファイルの内容全体を読み、それを返す */
static char *
read_file(char *path)
{
    FILE *f;
    char *buf;
    size_t capa = 1024;   /* バッファサイズ */
    size_t idx;           /* 現在のバッファ書き込み位置 */
    int c;
    
    f = fopen(path, "r");
    if (!f) {
        perror(path);
        exit(1);
    }
    buf = malloc(capa);
    if (!buf) die("malloc");
    while ((c = getc(f)) != EOF) {
        /* バッファ長チェック ('\0' も入れることを考えて +1 する) */
        if (idx + 1 >= capa) {
            capa *= 2;
            buf = realloc(buf, capa);
            if (!buf) die("realloc");
        }
        buf[idx++] = c;
    }
    buf[idx++] = '\0';
    fclose(f);

    return buf;
}

static void
die(const char *s)
{
    perror(s);
    exit(1);
}
