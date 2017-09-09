#include <stdio.h>
#include <stdlib.h>

static void do_head(FILE *f, long nlines);

/* #@@range_begin(main) */
int
main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s n\n", argv[0]);
        exit(1);
    }
    do_head(stdin, atol(argv[1]));
    exit(0);
}
/* #@@range_end(main) */

/* #@@range_begin(do_head) */
static void
do_head(FILE *f, long nlines)
{
    int c;

    if (nlines <= 0) return;
    while ((c = getc(f)) != EOF) {
        if (putchar(c) < 0) exit(1);
        if (c == '\n') {
            nlines--;
            if (nlines == 0) return;
        }
    }
}
/* #@@range_end(do_head) */
