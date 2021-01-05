#include <stdio.h>

#ifdef A
enum week_days {MON, TUE, WED, THU, FRI, SAT, SUN};
#endif

#ifdef B
typedef enum {MON, TUE, WED, THU, FRI, SAT, SUN} Week_days;
#endif

int main(void)
{
#ifdef A
    enum week_days day = MON;
#endif

#ifdef B
    Week_days day = TUE;
#endif

    printf("Day of week: %d\n", day);

    return 0;
}
