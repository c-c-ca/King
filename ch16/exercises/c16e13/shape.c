#include <stdio.h>

#define RECTANGLE 0
#define CIRCLE    1

struct point { int x, y; };

int main(void)
{
    struct shape {
        int shape_kind;         /* RECTANGLE or CIRCLE */
        struct point center;    /* coordinate of center */
        union {
            struct {
                int height, width;
            } rectangle;
            struct {
                int radius;
            } circle;
        } u;
    } s;

    /* a */
    s.shape_kind = RECTANGLE;    /* CORRECT */

    /* b */
    s.center.x = 10;             /* CORRECT */

    /* c */
//  s.height = 25;               /* WRONG   */
    s.u.rectangle.height = 25;   /* CORRECT */

    /* d */
    s.u.rectangle.width = 8;     /* CORRECT */

    /* e */
//  s.u.circle = 5;              /* WRONG   */
    s.u.circle.radius = 5;       /* CORRECT */

    /* f */
//  s.u.radius = 5;              /* WRONG   */
    s.u.circle.radius = 5;       /* CORRECT */

    return 0;
}
