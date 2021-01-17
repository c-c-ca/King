#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define CMD_LEN   10
#define CMD_COUNT (sizeof(file_cmd) / sizeof(file_cmd[0]))

void new_cmd(void);
void open_cmd(void);
void close_cmd(void);
void close_all_cmd(void);
void save_cmd(void);
void save_as_cmd(void);
void save_all_cmd(void);
void print_cmd(void);
void exit_cmd(void);
void run_file_cmd(char *cmd_str);
int read_line(char str[], int n);

struct {
    char *cmd_name;
    void (*cmd_pointer) (void);
} file_cmd[] =
 {{"new",       new_cmd},
  {"open",      open_cmd},
  {"close",     close_cmd},
  {"close all", close_all_cmd},
  {"save",      save_cmd},
  {"save as",   save_as_cmd},
  {"save all",  save_all_cmd},
  {"print",     print_cmd},
  {"exit",      exit_cmd}
 };

int main(void)
{
    char cmd[CMD_LEN+1];

    for (;;) {
        printf("\nEnter command: ");
        read_line(cmd, CMD_LEN);

        if (cmd[0] == 'q')
            return 0;

        run_file_cmd(cmd);
    }

    return 0;
}

void run_file_cmd(char *cmd_str)
{
    int i;

    for (i = 0; i < CMD_COUNT; i++)
        if (strcmp(cmd_str, file_cmd[i].cmd_name) == 0) {
            (*file_cmd[i].cmd_pointer)();
            return;
        }

    printf("Error: command %s not found\n", cmd_str);
}

void new_cmd(void)
{
    printf("Creating new file...\n");
}

void open_cmd(void)
{
    printf("Opening file...\n");
}

void close_cmd(void)
{
    printf("Closing file...\n");
}

void close_all_cmd(void)
{
    printf("Closing all files...\n");
}

void save_cmd(void)
{
    printf("Saving file...\n");
}

void save_as_cmd(void)
{
    printf("Saving file as...\n");
}

void save_all_cmd(void)
{
    printf("Saving all files...\n");
}

void print_cmd(void)
{
    printf("Printing file...\n");
}

void exit_cmd(void)
{
    printf("Exiting file...\n");
}

int read_line(char str[], int n)
{
    int ch, i = 0;

    while (isspace(ch = getchar()))
        ;
    while (ch != '\n' && ch != EOF) {
        if (i < n)
            str[i++] = ch;
        ch = getchar();
    }
    str[i] = '\0';
    return i;
}
