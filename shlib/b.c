static int a(int n);

int
sample_function2(int n)
{
    return a(n);
}

static int
a(int n)
{
    return n * n;
}
