/* Formats a file of text */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "line.h"
#include "word.h"

#define MAX_WORD_LEN 20

int main(int argc, char *argv[])
{
	FILE *in_fp, *out_fp;
	char word[MAX_WORD_LEN+2];
	int word_len;

	if (argc != 3) {
		fprintf(stderr, "usage: %s infile outfile\n", argv[0]);
		exit(EXIT_FAILURE);
	}


	if ((in_fp = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	if ((out_fp = fopen(argv[2], "w")) == NULL) {
		fprintf(stderr, "Can't open %s\n", argv[2]);
		fclose(in_fp);
		exit(EXIT_FAILURE);
	}
	
	clear_line();
	for (;;) {
		read_word(word, MAX_WORD_LEN+1, in_fp);
		word_len = strlen(word);
		if (word_len == 0) {
			flush_line(out_fp);
			break;
		}
		if (word_len > MAX_WORD_LEN)
			word[MAX_WORD_LEN] = '*';
		if (word_len + 1 > space_remaining()) {
			write_line(out_fp);
			clear_line();
		}
		add_word(word);
	}

	fclose(in_fp);
	fclose(out_fp);
	return 0;
}
