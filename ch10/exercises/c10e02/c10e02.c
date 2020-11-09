int b, c;          /* visible variables */

void f(void)       /* b (non-extern), c, d */
{
    int b, d;
}

void g(int a)      /* a, b, c (non-extern) */
{
    int c;
    {
        int a, d;  /* a (non-param), b, c (non-extern), d */
    }
}

int main(void)     /* b, c (non-extern), d */
{
    int c, d;
}
