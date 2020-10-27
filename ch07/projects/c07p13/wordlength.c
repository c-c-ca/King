#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    bool in_word = false;
    float num_words, num_chars;
    char ch;

    printf("Enter a sentence: ");

    num_words = num_chars = 0.0f;
    while ((ch = getchar()) != '\n')
        if (ch != ' ') {
            num_chars++;
            if (!in_word) {
                in_word = true;
                num_words++;
            }
        } else if (in_word)
            in_word = false;

    printf("Average word length: %.1f", num_chars / num_words);

    return 0;
}