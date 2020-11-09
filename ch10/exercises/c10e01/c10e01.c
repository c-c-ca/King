int a;         /* visible variables */

void f(int b)  /* a, b, c */
{
    int c;
}

void g(void)   /* a, d  */
{
    int d;
    {
        int e; /* a, d, e */
    }
}

int main(void) /* a, f */
{
    int f;
}
