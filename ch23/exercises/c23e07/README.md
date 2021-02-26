Just as `strchr` may be called an arbitrary number of times to find all occurrences of a character, `strrchr` may be used in a similar way.  However, rather than passing a new pointer on each call, the string being searched must be modified as it is being searched to remove the last character found from the string. The following code snippet demonstrates how this can be achieved.

```
char *p, str[] = "Form follows function.";

p = strrchr(str, 'f');   /* finds last 'f' */

*p = '\0';               /* str is "Form follows " *;

p = strrchr(str, 'f');   /* finds 'f' in follows */
```
