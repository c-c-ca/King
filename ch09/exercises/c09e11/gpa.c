#include <stdio.h>

#define N 5

float compute_GPA(int n, char grades[n]);

int main(void)
{
    char grades[N] = {'B', 'C', 'F', 'A', 'B'};

    printf("GPA: %.1f\n", compute_GPA(N, grades));

    return 0;
}

float compute_GPA(int n, char grades[n])
{
    int i;
    float gpa = 0.0f;

    for (i = 0; i < n; i++)
        switch (grades[i]) {
            case 'A': gpa += 4.0f; break;
            case 'B': gpa += 3.0f; break;
            case 'C': gpa += 2.0f; break;
            case 'D': gpa += 1.0f; break;
        }
    
    return gpa / n;
}