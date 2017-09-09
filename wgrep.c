/*
    GREP with wide character support.
    This program handles only immediate pattern.
    Set environment variable LANG before invokind this command.

    e.g.  LANG=ja_JP.eucJP ./wgrep PATTERN FILE...
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <locale.h>
#include <wchar.h>

static void do_grep(wchar_t *pattern, FILE *f);

int
main(int argc, char *argv[])
{
    wchar_t pattern[1024];
    int i;

    setlocale(LC_CTYPE, "");
    if (argc < 2) {
        fputs("no pattern\n", stderr);
        exit(1);
    }
    if (mbstowcs(pattern, argv[1], 1024) == (size_t)(-1)) {
        fprintf(stderr, "mbstowcs failed #1\n");
        exit(1);
    }
    if (argc == 2) {
        do_grep(pattern, stdin);
    }
    else {
        for (i = 2; i < argc; i++) {
            FILE *f;
            
            f = fopen(argv[i], "r");
            if (!f) {
                perror(argv[i]);
                exit(1);
            }
            do_grep(pattern, f);
            fclose(f);
        }
    }
    exit(0);
}

static void
do_grep(wchar_t *pattern, FILE *src)
{
    char buf[4096];
    wchar_t wbuf[4096];

    while (fgets(buf, sizeof buf, src)) {
        if (mbstowcs(wbuf, buf, 4096) == (size_t)(-1)) {
            fprintf(stderr, "mbstowcs failed #2\n");
            exit(1);
        }
        if (wcsstr(wbuf, pattern)) {
            fputs(buf, stdout);
        }
    }
}
