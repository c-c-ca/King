#include <stdbool.h>
#include <stdio.h>

#define MIN(x,y)  ((x) < (y) ? (x) : (y))
#define MAX(x,y)  ((x) > (y) ? (x) : (y))
#define MIN_X(r)  (MIN((r).upper_left.x, (r).lower_right.x))
#define MAX_X(r)  (MAX((r).upper_left.x, (r).lower_right.x))
#define MIN_Y(r)  (MIN((r).upper_left.y, (r).lower_right.y))
#define MAX_Y(r)  (MAX((r).upper_left.y, (r).lower_right.y))
#define WIDTH(r)  (MAX_X(r) - MIN_X(r))
#define LENGTH(r) (MAX_Y(r) - MIN_Y(r))

#define PRINT_NL() printf("\n")

#define PRINT_POINT(p)                \
    printf("point: x = %d, y = %d; ", \
            (p).x, (p).y)

#define PRINT_RECTANGLE(r)            \
    do {                              \
        printf("rectangle: ");        \
        printf("upper_left = ");      \
        PRINT_POINT((r).upper_left);  \
        printf("lower_right = ");     \
        PRINT_POINT((r).lower_right); \
    } while (false)

struct point { int x, y; };
struct rectangle { struct point upper_left, lower_right; };

int rectangle_area(struct rectangle r);
struct point getCenter(struct rectangle r);
struct point move_point(struct point p, int x, int y);
struct rectangle move_rectangle(struct rectangle r, int x, int y);
bool contains_point(struct rectangle r, struct point p);

int main(void)
{
    struct point p1 = {0, 0}, p2 = {10, 5}, p3;
    struct rectangle r = {p1, p2};

    p3 = getCenter(r);

    PRINT_RECTANGLE(r); PRINT_NL();
    PRINT_POINT(p3); PRINT_NL();

    r = move_rectangle(r, 3, 5);
    PRINT_RECTANGLE(r); PRINT_NL();

    printf("Point is %s of rectangle\n",
            contains_point ? "inside" : "outside");

    return 0;
}

int rectangle_area(struct rectangle r)
{
    return LENGTH(r) * WIDTH(r);
}

struct point getCenter(struct rectangle r)
{
    return (struct point) {
        (r.upper_left.x + r.lower_right.x) / 2,
        (r.upper_left.y + r.lower_right.y) / 2
    };
}

struct point move_point(struct point p, int x, int y)
{
    return (struct point) {p.x + x, p.y + y};
}

struct rectangle move_rectangle(struct rectangle r, int x, int y)
{
    return (struct rectangle) {
        move_point(r.upper_left, x, y),
        move_point(r.lower_right, x, y)
    };
}

bool contains_point(struct rectangle r, struct point p)
{
    return MIN_X(r) <= p.x < MAX_X(r) &&
           MIN_Y(r) <= p.y < MAX_Y(r);
}
