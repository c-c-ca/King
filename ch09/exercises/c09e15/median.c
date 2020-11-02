#include <stdio.h>

double median(double x, double y, double z);

int main(void)
{
    double x = 3.0, y = -2.0, z = 1.0;

    printf("Median of %.1f, %.1f, and %.1f: %.1f",
        x, y, z, median(x, y, z));
    
    return 0;
}

double median(double x, double y, double z)
{
    return (
        (x <= y) ? 
            ((y <= z) ? y : 
                (x <= z) ? z : x) :
            ((z <= y) ? y :
                (x <= z) ? x : z)
    );
}
