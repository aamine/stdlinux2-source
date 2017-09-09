#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dlfcn.h>
#include <sys/stat.h>
#if defined(sun) && defined(unix)
# include <alloca.h>
#endif

int egvar;
int egvar2 = 7;
static int sgvar;
static int sgvar2 = 7;
char *egstr = "string";

#if defined(__alpha__) || defined(__arch64__)
# define FMT "%016lx"
#else
# define FMT "%08lx"
#endif

int
main(int argc, char *argv[])
{
    static int svar;
    static int svar2 = 7;
    int lvar;
    int *p;
    void *libm, *sin;

    printf("extern global   = " FMT "\n", (unsigned long)&egvar);
    printf("static global   = " FMT "\n", (unsigned long)&sgvar);
    printf("function static = " FMT "\n", (unsigned long)&svar);
    printf("function local  = " FMT "\n", (unsigned long)&lvar);
    printf("extern globalB  = " FMT "\n", (unsigned long)&egvar2);
    printf("extern globalC  = " FMT "\n", (unsigned long)egstr);
    printf("static globalB  = " FMT "\n", (unsigned long)&sgvar2);
    printf("function staticB= " FMT "\n", (unsigned long)&svar2);
    p = (int*)malloc(1024 * 1024);
    *p++ = 0;
    *p++ = 1;
    printf("malloc mem      = " FMT "\n", (unsigned long)p);
    printf("alloca mem      = " FMT "\n", (unsigned long)alloca(1));
    printf("main()          = " FMT "\n", (unsigned long)main);
    printf("printf()        = " FMT "\n", (unsigned long)printf);
    libm = dlopen("libm.so", RTLD_NOW);
    if (!libm) {
        puts("dlopen failed");
        exit(1);
    }
    sin = dlsym(libm, "sin");
    printf("dl sin()        = " FMT "\n", (unsigned long)sin);

#if defined(linux)
    {
	char buf[128];
	snprintf(buf, sizeof buf, "cat /proc/%d/maps", getpid());
	system(buf);
    }
#elif defined(sun) && defined(unix)
    {
	char buf[128];
	snprintf(buf, sizeof buf, "pmap %d", getpid());
	system(buf);
    }
#else
# error "no vm map handler"
#endif

    exit(0);
}
