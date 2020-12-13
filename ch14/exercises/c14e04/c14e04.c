#include <stdio.h>

#define AVG(x,y)  (x+y)/2
#define AREA(x,y) (x)*(y)

#define AVG2(x,y)  (((x)+(y))/2)
#define AREA2(x,y) ((x)*(y))

int main(void)
{
    int x = 3, y = 5;

    printf("%d/AVG(%d/%d): %d\n", x*x, x, y, x*x / AVG(x,y));
    printf("%d/AREA(%d,%d): %d\n", x*10, x, y, x*10/AREA(x,y));

    printf("%d/AVG2(%d/%d): %d\n", x*x, x, y, x*x / AVG2(x,y));
    printf("%d/AREA2(%d,%d): %d\n", x*10, x, y, x*10/AREA2(x,y));

    return 0;
}
