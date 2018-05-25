// Computational objects
// Written by jas@cse, April 2017

int a;  // global variable


int fun1(int b)
{
    int c;
    // this function knows about a, b, c
    // b and c exist only while fun1() executes
    c = b*b;
    return c;
}

int d;  // global variable

int fun2(int e)
{
    int f;
    // this function knows about a, d, e, f
    // this function also knows about fun1()
    // e and f exist only while fun2() executes
    f = 2 * fun1(e);
    return f+1;
}

int main(int argc, char *argv[])
{
    int g;
    // this function knows about a, d, g 
    // this function also knows about argc, argv
    // this function also knows about fun1(), fun2()
    g = fun2(5);
    printf("g = %d\n", g);
    return 0;
}

