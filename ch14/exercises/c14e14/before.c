#define N = 10               /* omit = */
#define INC(x) x+1           /* missing outer parens */
#define SUB (x,y) x-y        /* omit spaces between macro and params */
#define SQR(x) ((x)*(x))
#define CUBE(x) (SQR(x)*(x))
#define M1(x,y) x##y
#define M2(x,y) #x #y

int main(void)
{
    int a[N], i, j, k, m;

#ifdef N
    i = j;
#else
    j = i;
#endif

    i = 10 * INC(j);
    i = SUB(j, k);
    i = SQR(SQR(j));
    i = CUBE(j);
    i = M1(j, k);
    puts(M2(i, j));

#undef SQR
    i = SQR(j);
#define SQR
    i = SQR(j);

    return 0;
}
