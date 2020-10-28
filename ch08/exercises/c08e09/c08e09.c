#include <stdio.h>

#define NUM_DAYS  30
#define NUM_HOURS 24

int main(void)
{
    float temperature_readings[NUM_DAYS][NUM_HOURS], sum = 0.0f;
    int i, j;

    for (i = 0; i < NUM_DAYS; i++)
        for (j = 0; j < NUM_HOURS; j++)
            sum += temperature_readings[i][j];
    printf("Average temperature: %.2f\n", sum / (NUM_DAYS * NUM_HOURS));

    return 0;
}