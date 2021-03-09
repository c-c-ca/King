#include <limits.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

#define PRINT_STRING_MEMBER(member) \
	printf(#member " = \"%s\"\n", locale->member)

#define PRINT_CHAR_MEMBER(member)             \
	printf((locale->member) == CHAR_MAX ? \
		#member " = CHAR_MAX\n" :     \
		#member " = %d\n",            \
		locale->member)

#define PRINT_GROUPING_MEMBER(member)           \
	do {                                    \
		printf(#member " = ");          \
		print_grouping(locale->member); \
		printf("\n");                   \
	} while(0)

void print_grouping(char *s);

int main(int argc, char *argv[])
{
	struct lconv *locale;

	if (argc != 2) {
		fprintf(stderr, "usage: %s locale\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if (setlocale(LC_ALL, argv[1]) == NULL) {
		fprintf(stderr, "\"%s\" locale information not available\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	locale = localeconv();

	PRINT_STRING_MEMBER(decimal_point);
	PRINT_STRING_MEMBER(thousands_sep);
	PRINT_GROUPING_MEMBER(grouping);
	PRINT_STRING_MEMBER(mon_decimal_point);
	PRINT_STRING_MEMBER(mon_thousands_sep);
	PRINT_GROUPING_MEMBER(mon_grouping);
	PRINT_STRING_MEMBER(positive_sign);
	PRINT_STRING_MEMBER(negative_sign);
	PRINT_STRING_MEMBER(currency_symbol);
	PRINT_CHAR_MEMBER(frac_digits);
	PRINT_CHAR_MEMBER(p_cs_precedes);
	PRINT_CHAR_MEMBER(n_cs_precedes);
	PRINT_CHAR_MEMBER(p_sep_by_space);
	PRINT_CHAR_MEMBER(n_sep_by_space);
	PRINT_CHAR_MEMBER(p_sign_posn);
	PRINT_CHAR_MEMBER(n_sign_posn);
	PRINT_STRING_MEMBER(int_curr_symbol);
	PRINT_CHAR_MEMBER(int_frac_digits);
	PRINT_CHAR_MEMBER(int_p_cs_precedes);
	PRINT_CHAR_MEMBER(int_n_cs_precedes);
	PRINT_CHAR_MEMBER(int_p_sep_by_space);
	PRINT_CHAR_MEMBER(int_n_sep_by_space);
	PRINT_CHAR_MEMBER(int_p_sign_posn);
	PRINT_CHAR_MEMBER(int_n_sign_posn);

	return 0;
}

void print_grouping(char *s)
{
	while (*s)
		printf("%d", *s++);
}
