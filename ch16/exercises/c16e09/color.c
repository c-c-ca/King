#include <stdbool.h>
#include <stdio.h>

#define CONSTRAIN(x) ((x) < 0 ? 0 : (x) > 255 ? 255 : (x))
#define BRIGHTEN(x) ((int) ((double) (0 < (x) && (x) < 3 ? 3 : (x)) / 0.7))
#define DARKEN(x) ((int) ((double) (x) * 0.7))

#define PRINT_COLOR(x)                                 \
    printf("color: red = %d, green = %d, blue = %d\n", \
            (x).red, (x).green, (x).blue)

#define PRINT_COLORS_EQUAL(x,y)                        \
    printf("Colors are %s equal.\n",                   \
            equal_color((x),(y)) ? "" : "not")

struct color {
    int red;
    int green;
    int blue;
};

struct color make_color(int red, int green, int blue);
int getRed(struct color c);
bool equal_color(struct color color1, struct color color2);
struct color brighter(struct color c);
struct color darker(struct color c);

int main(void)
{
    struct color c1, c2, c3;

    c1 = make_color(20, 140, 80);
    c2 = make_color(70, 0, 220);
    c3 = c1;

    printf("red: %d\n", getRed(c1));

    PRINT_COLORS_EQUAL(c1, c2);
    PRINT_COLORS_EQUAL(c1, c3);

    c2 = brighter(c1);
    PRINT_COLOR(c2);

    c3 = darker(c1);
    PRINT_COLOR(c3);

    return 0;
}

struct color make_color(int red, int green, int blue)
{
    return (struct color) {
        CONSTRAIN(red), CONSTRAIN(green), CONSTRAIN(blue)
    };
}

int getRed(struct color c)
{
    return c.red;
}

bool equal_color(struct color color1, struct color color2)
{
    return color1.red == color2.red &&
           color1.green == color2.green &&
           color1.blue == color2.blue;
}

struct color brighter(struct color c)
{
    return c.red == 0 && c.green == 0 && c.blue == 0 ?
           (struct color) {3, 3, 3} :
           make_color(BRIGHTEN(c.red), BRIGHTEN(c.green), BRIGHTEN(c.blue));
}

struct color darker(struct color c)
{
    return make_color(DARKEN(c.red), DARKEN(c.green), DARKEN(c.blue));
}
