/* Maintains a parts database (linked list version) */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readline.h"

#define NAME_LEN 25

struct part {
    int number;
    char name[NAME_LEN+1];
    int on_hand;
    struct part *next;
};

struct part *inventory = NULL;   /* points to first part */

struct part *find_part(int number);
FILE *open_file(const char *prompt, const char *mode);
void clear(void);
void insert(void);
void search(void);
void update(void);
void print(void);
void dump(void);
void restore(void);

/**********************************************************
 * main: Prompts the user to enter an operation code.     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/
int main(void)
{
    char code;

    for (;;) {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n')   /* skips to end of line */
            ;
        switch (code) {
            case 'i': insert();
                      break;
            case 's': search();
                      break;
            case 'u': update();
                      break;
            case 'p': print();
                      break;
            case 'd': dump();
                      break;
            case 'r': restore();
                      break;
            case 'q': return 0;
            default: printf("Illegal code\n");
        }
        printf("\n");
    }
}

/**********************************************************
 * find_part: Looks up a part number in the inventory     *
 *            array. Returns a point to the node          *
 *            containing the part number; if the part     *
 *            number is not found, returns NULL.          *
 **********************************************************/
struct part *find_part(int number)
{
    struct part *p;
    
    for (p = inventory;
         p != NULL && number > p->number;
         p = p->next)
        ;

    if (p != NULL && p->number == number)
        return p;
    return NULL;
}

/**********************************************************
 * insert: Prompts the user for information about a new   *
 *         part and then inserts the part into the        *
 *         inventory list; the list remains sorted by     *
 *         part number. Prints an error message and       *
 *         returns prematurely if the part already exists *
 *         or space could not be allocated for the part.  *
 **********************************************************/
void insert(void)
{
    struct part *cur, *prev, *new_node;

    new_node = malloc(sizeof(struct part));
    if (new_node == NULL) {
        printf("Database is full; can't add more parts.\n");
        return;
    }

    printf("Enter part number: ");
    scanf("%d", &new_node->number);

    for (cur = inventory, prev = NULL;
         cur != NULL && new_node->number > cur->number;
         prev = cur, cur = cur->next)
        ;
    if (cur != NULL && new_node->number == cur->number) {
        printf("Part already exists.\n");
        free(new_node);
        return;
    }

    printf("Enter part name: ");
    read_line(new_node->name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &new_node->on_hand);

    new_node->next = cur;
    if (prev == NULL)
        inventory = new_node;
    else
        prev->next = new_node;
}

/**********************************************************
 * search: Prompts the user to enter a part number, then  *
 *         locks up the part in the database. If the part *
 *         exists, prints the name and quantity on hand;  *
 *         if not, prints an error message.               *
 **********************************************************/
void search(void)
{
    int number;
    struct part *p;

    printf("Enter part number: ");
    scanf("%d", &number);
    p = find_part(number);
    if (p != NULL) {
        printf("Part name: %s\n", p->name);
        printf("Quantity on hand: %d\n", p->on_hand);
    } else
        printf("Part not found.\n");
}


/**********************************************************
 * update: Prompts the user to enter a part number.       *
 *         Prints an error message if the part doesn't    *
 *         exist; otherwise, prompts the user to enter    *
 *         change in quantity on hand and updates the     *
 *         database.                                      *
 **********************************************************/
void update(void)
{
    int number, change;
    struct part *p;

    printf("Enter part number: ");
    scanf("%d", &number);
    p = find_part(number);
    if (p != NULL) {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        p->on_hand += change;
    } else
        printf("Part not found.\n");
}

/**********************************************************
 * print: Prints a listing of all parts in the database,  *
 *        showing the part number, part name, and         *
 *        quantity on hand. Part numbers will appear in   *
 *        in ascending order.                             *
 **********************************************************/
void print(void)
{
    struct part *p;

    printf("Part Number   Part Name                  "
           "Quantity on Hand\n");
    for (p = inventory; p != NULL; p = p->next)
        printf("%7d     %-25s%11d\n", p->number, p->name,
                p->on_hand);
}

/**********************************************************
 * open_file: Prompts the user to enter a filename.       *
 *            Opens specified file; otherwise, prints an  *
 *            error message.                              *
 **********************************************************/
FILE *open_file(const char *prompt, const char *mode)
{
    char filename[FILENAME_MAX+1];
    FILE *fp;

    printf("%s\n", prompt);
    scanf("%s", filename);

    if ((fp = fopen(filename, mode)) == NULL) {
        fprintf(stderr, "Can't open %s\n", filename);
        exit(EXIT_FAILURE);
    }

    return fp;
}

/**********************************************************
 * dump: Saves the database to the specified file.        *
 **********************************************************/
void dump(void)
{
    FILE *fp = open_file("Enter name of output file", "wb");
    struct part *p = inventory;

    for (p = inventory; p != NULL; p = p->next) {
        fwrite(&p->number, sizeof(p->number), 1, fp);
        fwrite(p->name, sizeof(p->name), 1, fp);
        fwrite(&p->on_hand, sizeof(p->on_hand), 1, fp);
    }

    fclose(fp);
}

/**********************************************************
 * clear: Removes all parts from the database.            *
 **********************************************************/
void clear(void)
{
    struct part *p, *temp;

    for (p = inventory; p != NULL; p = temp) {
        temp = p->next;
        free(p);
    }
    inventory = NULL;
}

/**********************************************************
 * restore: Loads the database from the specified file.   *
 **********************************************************/
void restore(void)
{
    FILE *fp = open_file("Enter name of input file", "rb");
    struct part **p;
    char name[NAME_LEN+1];
    int number, on_hand;
    
    clear();
    for (p = &inventory;
         fread(&number, sizeof(number), 1, fp) == 1 &&
         fread(name, sizeof(name), 1, fp) == 1 &&
         fread(&on_hand, sizeof(on_hand), 1, fp) == 1;
         p = &(*p)->next) {
        if ((*p = malloc(sizeof(struct part))) == NULL) {
            fprintf(stderr, "Error: malloc failed in restore\n");
            exit(EXIT_FAILURE);
        }
        (*p)->number = number;
        strcpy((*p)->name, name);
        (*p)->on_hand = on_hand;
        (*p)->next = NULL;
    }

    fclose(fp);
}
