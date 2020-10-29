#include <stdio.h>

#define NUM_QUIZZES  5
#define NUM_STUDENTS 5

int main(void)
{
    int grades[NUM_STUDENTS][NUM_QUIZZES];
    int high, low, quiz, student, total;

    for (student = 0; student < NUM_STUDENTS; student++) {
        printf("Enter grades for student %d: ", student + 1);
        for (quiz = 0; quiz < NUM_QUIZZES; quiz++)
            scanf("%d", &grades[student][quiz]);
    }

    printf("\nStudent  Total  Average\n");
    for (student = 0; student < NUM_STUDENTS; student++) {
        printf("%4d      ", student + 1);
        total = 0;
        for (quiz = 0; quiz < NUM_QUIZZES; quiz++)
            total += grades[student][quiz];
        printf("%3d     %3d\n", total, total / NUM_QUIZZES);
    }

    printf("\nQuiz  Average  High  Low\n");
    for (quiz = 0; quiz < NUM_QUIZZES; quiz++) {
        printf("%3d     ", quiz + 1);
        total = high = low = grades[0][quiz];
        for (student = 1; student < NUM_STUDENTS; student++) {
            total += grades[student][quiz];
            if (grades[student][quiz] > high)
                high = grades[student][quiz];
            else if (grades[student][quiz] < low)
                low = grades[student][quiz];
        }
        printf("%3d    %3d   %3d\n", total / NUM_STUDENTS, high, low);
    }
    printf("\n");

    return 0;
}