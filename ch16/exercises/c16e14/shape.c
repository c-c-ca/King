#include <stdio.h>

#define PI 3.14159

#define RECTANGLE 0
#define CIRCLE    1

struct point { int x, y; };

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
};

int shape_area(struct shape s);
struct shape move_shape(struct shape s, int x, int y);
struct shape scale_shape(struct shape, double c);

int main(void)
{
    struct shape r = {RECTANGLE, {0, 0}, {10, 5}},
                 c = {CIRCLE, {0, 0}, {5}};

    printf("Area of rectangle: %d\n", shape_area(r));
    printf("Area of circle: %d\n", shape_area(c));

    r = move_shape(r, 3, 2);
    printf("Center of rectangle: x = %d, y = %d\n",
            r.center.x, r.center.y);

    c = move_shape(c, -5, 0);
    printf("Center of circle: x = %d, y = %d\n",
            c.center.x, c.center.y);

    r = scale_shape(r, 2);
    printf("Rectangle dimensions: height = %d, width = %d\n",
            r.u.rectangle.height, r.u.rectangle.width);

    c = scale_shape(c, 3);
    printf("Circle dimensions: radius = %d\n",
            c.u.circle.radius);

    return 0;
}

int shape_area(struct shape s)
{
    if (s.shape_kind == RECTANGLE)
        return s.u.rectangle.height * s.u.rectangle.width;
    else
        return (int) ((double) (s.u.circle.radius * s.u.circle.radius) * PI);
}

struct shape move_shape(struct shape s, int x, int y)
{
   s.center.x += x;
   s.center.y += y;

   return s;
}

struct shape scale_shape(struct shape s, double c)
{
    if (s.shape_kind == RECTANGLE) {
        s.u.rectangle.height = (int) ((double) s.u.rectangle.height * c);
        s.u.rectangle.width = (int) ((double) s.u.rectangle.width * c);
    } else
        s.u.circle.radius = (int) ((double) s.u.circle.radius * c);

    return s;
}
