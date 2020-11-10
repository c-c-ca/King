/* Classifies a poker hand */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5
#define RANK      0
#define SUIT      1

/* external variables */
int hand[NUM_CARDS][2];
bool straight, flush, four, three;
int pairs;   /* can be 0, 1, or 2 */

/* prototypes */
void read_cards(void);
void analyze_hand(void);
void print_result(void);

/**********************************************************
 * main: Calls read_cards, analyze_hand, and print_result *
 *       repeatedly                                       *
 **********************************************************/
int main(void)
{
    for (;;) {
        read_cards();
        analyze_hand();
        print_result();
    }
}

/**********************************************************
 * read_cards:  Reads the cards into external variables;  * 
 *              checks for bad cards and duplicate cards. *
 **********************************************************/
void read_cards(void)
{
    char ch, rank_ch, suit_ch;
    int card_num, rank, suit;
    bool bad_card;
    int cards_read = 0;

    while (cards_read < NUM_CARDS) {
        bad_card = false;

        printf("Enter a card: ");

        rank_ch = getchar();
        switch (rank_ch) {
            case '0':           exit(EXIT_SUCCESS);
            case '2':           rank = 0; break;
            case '3':           rank = 1; break;
            case '4':           rank = 2; break;
            case '5':           rank = 3; break;
            case '6':           rank = 4; break;
            case '7':           rank = 5; break;
            case '8':           rank = 6; break;
            case '9':           rank = 7; break;
            case 't': case 'T': rank = 8; break;
            case 'j': case 'J': rank = 9; break;
            case 'q': case 'Q': rank = 10; break;
            case 'k': case 'K': rank = 11; break;
            case 'a': case 'A': rank = 12; break;
            default:            bad_card = true;
        }

        suit_ch = getchar();
        switch (suit_ch) {
            case 'c': case 'C': suit = 0; break;
            case 'd': case 'D': suit = 1; break;
            case 'h': case 'H': suit = 2; break;
            case 's': case 'S': suit = 3; break;
            default:            bad_card = true;
        }

        while ((ch = getchar()) != '\n')
            if (ch != ' ') bad_card = true;

        if (bad_card) {
            printf("Bad card; ignored.\n");
            continue;
        }

        for (card_num = 0; card_num < cards_read; card_num++)
            if (hand[card_num][RANK] == rank && 
                hand[card_num][SUIT] == suit)
                break;

        if (card_num < cards_read)
            printf("Duplicate card; ignored.\n");
        else {
            hand[cards_read][RANK] = rank;
            hand[cards_read][SUIT] = suit;
            cards_read++;
        }
    }
}

/**********************************************************
 * analyze_hand: Determines whether the hand contains a   *
 *               straight, a flush, four-of-a-kind,       *
 *               and/or three-of-a-kind; determines the   *
 *               number of pairs; stores the result into  *
 *               external variables.                      *
 **********************************************************/
void analyze_hand(void)
{
    int num_consec = 1;
    int card_num, rank, low_rank, count;
    straight = false;
    flush = true;
    four = false;
    three = false;
    pairs = 0;

    /* check for flush */
    for (card_num = 1; card_num < NUM_CARDS; card_num++)
        if (hand[card_num][SUIT] != hand[0][SUIT]) {
            flush = false;
            break;
        }

    /* check for straight */
    low_rank = hand[0][RANK];
    for (card_num = 1; card_num < NUM_CARDS; card_num++)
        if (hand[card_num][RANK] < low_rank)
            low_rank = hand[card_num][RANK];
    for (rank = low_rank + 1; rank < low_rank + NUM_CARDS; rank++)
        for (card_num = 0; card_num < NUM_CARDS; card_num++)
            if (hand[card_num][RANK] == rank) {
                num_consec++;
                break;
            }
    if (num_consec == NUM_CARDS) {
        straight = true;
        return;
    }

    /* check for 4-of-a-kind, 3-of-a-kind, and pairs */
    for (rank = 0; rank < NUM_RANKS; rank++) {
        count = 0;
        for (card_num = 0; card_num < NUM_CARDS; card_num++)
            if (hand[card_num][RANK] == rank)
                count++;
        switch (count) {
            case 4: four = true;  break;
            case 3: three = true; break;
            case 2: pairs++;      break;
        }
    }
}


/**********************************************************
 * print_result: Notifies the user of the result, using   * 
 *               the external variables set by            * 
 *               analyze_hand.                            *
 **********************************************************/
void print_result(void)
{
    if (straight && flush) printf("Straight flush");
    else if (four)         printf("Four of a kind");
    else if (three &&
             pairs == 1)   printf("Full house");
    else if (flush)        printf("Flush");
    else if (straight)     printf("Straight");
    else if (three)        printf("Three of a kind");
    else if (pairs == 2)   printf("Two pairs");
    else if (pairs == 1)   printf("Pair");
    else                   printf("High card");

    printf("\n\n");
}
