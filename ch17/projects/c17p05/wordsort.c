#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 20

char *words[MAX_WORDS];

void quicksort(char *a[], int low, int high);
int split(char *a[], int low, int high);
int read_line(char str[], int n);
    
int main(void)
{
    char word[MAX_WORD_LEN+1];
    int i, len, num_words = 0;

    for (;;) {
        if (num_words == MAX_WORDS) {
            printf("-- No space left --\n");
            break;
        }

        printf("Enter word: ");
        if ((len = read_line(word, MAX_WORDS)) == 0)
            break;
        
        if ((words[num_words] = malloc(len + 1)) == NULL) {
            printf("-- No space left --\n");
            break;
        }

        strcpy(words[num_words], word);
        num_words++;
    }

    quicksort(words, 0, num_words - 1);

    printf("In sorted order:");
    for (i = 0; i < num_words; i++)
        printf(" %s", words[i]);
    printf("\n");
}

void quicksort(char *a[], int low, int high)
{
    int middle;

    if (low >= high) return;
    middle = split(a, low, high);
    quicksort(a, low, middle - 1);
    quicksort(a, middle + 1, high);
}

int split(char *a[], int low, int high)
{
    char *part_element = a[low];

    for (;;) {
        while (low < high && strcmp(part_element, a[high]) <= 0)
            high--;
        if (low >= high) break;
        a[low++] = a[high];

        while (low < high && strcmp(a[low], part_element) <= 0)
            low++;
        if (low >= high) break;
        a[high--] = a[low];
    }

    a[high] = part_element;
    return high;
}

int read_line(char str[], int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
        if (i < n)
            str[i++] = ch;
    str[i] = '\0';
    return i;
}
