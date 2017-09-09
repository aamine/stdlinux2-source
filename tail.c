/*
    tail -- Shows last 10 lines of files (with line length limitation)
*/

#include <stdio.h>
#include <stdlib.h>

#define N_LINES 10
#define MAX_LINE_LENGTH 1024

static void tail(FILE *f);

int
main(int argc, char *argv[])
{
    if (argc != 1) {
        fprintf(stderr, "Usage: %s < infile\n", argv[0]);
        exit(1);
    }
    tail(stdin);
    exit(0);
}

static char ring_buffer[N_LINES][MAX_LINE_LENGTH];

#define RING_BUFFER_INC(idx) do { \
    idx++; \
    if (idx >= N_LINES) { \
        idx = 0; \
    } \
} while (0)

static void
tail(FILE *f)
{
    long curr = 0;
    long n_read_lines = 0;

    // Read all lines into ring buffer
    while (fgets(ring_buffer[curr], MAX_LINE_LENGTH, f)) {
        RING_BUFFER_INC(curr);
        n_read_lines++;
    }

    // Rewind ring buffer
    if (n_read_lines < N_LINES) {
        curr = 0;
    }

    // Flush ring buffer
    for (int n = N_LINES; n > 0 && n_read_lines; n--, n_read_lines--) {
        printf("%s", ring_buffer[curr]);
        RING_BUFFER_INC(curr);
    }
}
