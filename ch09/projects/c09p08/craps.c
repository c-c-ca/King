#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

#define NUM_DICE 2

int roll_dice(void);
bool play_game(void);
int main(void)
{
	char ch;
	int num_wins = 0, num_losses = 0;

	srand((unsigned) time(NULL));

	do {
		if (play_game()) {
			num_wins++;
			printf("You win!\n");
		} else {
			num_losses++;
			printf("You lose!\n");
		}
		
		printf("\nPlay again? ");
		scanf(" %c", &ch);
	} while (tolower(ch) == 'y');

	printf("\nWins: %d   Losses: %d\n", num_wins, num_losses);

	return 0;
}

int roll_dice(void)
{
	int i, sum = 0;

	for (i = 0; i < NUM_DICE; i++)
		sum += rand() % 6 + 1;

	return sum;
}

bool play_game(void)
{
	int sum, point;
	
	sum = roll_dice();
	printf("\nYou rolled: %d\n", sum);

	switch (sum) {
		case 7: case 11:
			return true;
		case 2: case 3: case 12:
			return false;
		default:
			point = sum; break;
	}

	printf("Your point is %d\n", point);

	do {
		sum = roll_dice();
		printf("You rolled: %d\n", sum);	
	} while (sum != point && sum != 7);

	return sum == point;
}
