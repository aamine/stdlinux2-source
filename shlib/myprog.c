#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern int sample_function1(int n);
extern int sample_function2(int n);

int
main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "no arg\n");
        exit(1);
    }
    printf("n * 2  = %d\n", sample_function1(atoi(argv[1])));
    printf("n ** 2 = %d\n", sample_function2(atoi(argv[1])));
    exit(0);
}
