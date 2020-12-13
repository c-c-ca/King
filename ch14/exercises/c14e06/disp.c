#include <math.h>
#include <stdio.h>

#define DISP(f,x)    (printf(#f "(%g) = %g\n", x, (f(x))))
#define DISP2(f,x,y) (printf(#f "(%g,%g) = %g\n", x, y, (f(x,y))))

int main(void)
{
    DISP(sqrt, 3.0);
    DISP2(fmod, 3.0, 1.8);

    return 0;
}
