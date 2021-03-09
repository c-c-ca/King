#include <limits.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

#define PRINT_LOCALE_STRING(member) \
	printf(#member " = \"%s\"\n", locale->member)

#define PRINT_LOCALE_CHAR(member)             \
	printf((locale->member) == CHAR_MAX ? \
		#member " = CHAR_MAX\n" :     \
		#member " = %d\n",            \
		(locale->member))

#define PRINT_LOCALE_GROUPING(member)                  \
	do {                                           \
		printf(#member " = ");                 \
		print_locale_grouping(locale->member); \
		printf("\n");                          \
	} while(0)

void print_locale_grouping(char *s);

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

	PRINT_LOCALE_STRING(decimal_point);
	PRINT_LOCALE_STRING(thousands_sep);
	PRINT_LOCALE_GROUPING(grouping);
	PRINT_LOCALE_STRING(mon_decimal_point);
	PRINT_LOCALE_STRING(mon_thousands_sep);
	PRINT_LOCALE_GROUPING(mon_grouping);
	PRINT_LOCALE_STRING(positive_sign);
	PRINT_LOCALE_STRING(negative_sign);
	PRINT_LOCALE_STRING(currency_symbol);
	PRINT_LOCALE_CHAR(frac_digits);
	PRINT_LOCALE_CHAR(p_cs_precedes);
	PRINT_LOCALE_CHAR(n_cs_precedes);
	PRINT_LOCALE_CHAR(p_sep_by_space);
	PRINT_LOCALE_CHAR(n_sep_by_space);
	PRINT_LOCALE_CHAR(p_sign_posn);
	PRINT_LOCALE_CHAR(n_sign_posn);
	PRINT_LOCALE_STRING(int_curr_symbol);
	PRINT_LOCALE_CHAR(int_frac_digits);
	PRINT_LOCALE_CHAR(int_p_cs_precedes);
	PRINT_LOCALE_CHAR(int_n_cs_precedes);
	PRINT_LOCALE_CHAR(int_p_sep_by_space);
	PRINT_LOCALE_CHAR(int_n_sep_by_space);
	PRINT_LOCALE_CHAR(int_p_sign_posn);
	PRINT_LOCALE_CHAR(int_n_sign_posn);

	return 0;
}

void print_locale_grouping(char *s)
{
	while (*s)
		printf("%d", *s++);
}
