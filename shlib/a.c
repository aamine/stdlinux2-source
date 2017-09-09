static int a(int n);

int
sample_function1(int n)
{
    return a(n);
}

static int
a(int n)
{
    return n * 2;
}
