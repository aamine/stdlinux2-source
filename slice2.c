/*
    slice - Prints matched substrings (*without* line length limitation)

    Copyright (c) 2017 Minero Aoki

    This program is free software.
    Redistribution and use in source and binary forms,
    with or without modification, are permitted.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <regex.h>

static void do_slice(regex_t *pat, FILE *f);
static char* get_line(FILE *f);
static void die(const char *s);

int
main(int argc, char *argv[])
{
    regex_t pat;
    int err;
    int i;

    if (argc < 2) {
        fputs("no pattern\n", stderr);
        exit(1);
    }
    err = regcomp(&pat, argv[1], REG_EXTENDED | REG_NEWLINE);
    if (err != 0) {
        char buf[1024];

        regerror(err, &pat, buf, sizeof buf);
        puts(buf);
        exit(1);
    }
    if (argc == 2) {
        do_slice(&pat, stdin);
    }
    else {
        for (i = 2; i < argc; i++) {
            FILE *f = fopen(argv[i], "r");
            if (!f) die(argv[i]);
            do_slice(&pat, f);
            fclose(f);
        }
    }
    regfree(&pat);
    exit(0);
}

static void
do_slice(regex_t *pat, FILE *src)
{
    char *line;
    while (line = get_line(src)) {
        regmatch_t matched[1];
        if (regexec(pat, line, 1, matched, 0) == 0) {
            char *str = line + matched[0].rm_so;
            regoff_t len = matched[0].rm_eo - matched[0].rm_so;
            fwrite(str, len, 1, stdout);
            fputc('\n', stdout);
        }
        free(line);
    }
}

static char*
get_line(FILE *src)
{
    unsigned char *line;   /* バッファ */
    size_t capa = 160;     /* バッファサイズ */
    size_t idx = 0;        /* 現在のバッファ書き込み位置 */
    int c;

    line = malloc(capa);
    if (!line) die("malloc");
    while ((c = getc(src)) != EOF) {
        if (c == '\n')
            break;
        if (idx == capa - 1) {   /* バッファ長チェック */
            capa *= 2;
            line = realloc(line, capa);
            if (!line) die("realloc");
        }
        line[idx++] = (unsigned char)c;
    }
    if ((idx == 0) && (c == EOF)) {
        free(line);
        return NULL;
    }
    line[idx++] = '\0';

    return (char*)line;
}

static void
die(const char *s)
{
    perror(s);
    exit(1);
}
