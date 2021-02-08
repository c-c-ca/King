## Solution

1. Identifiers that begin with an underscore followed by an upper-case letter are reserved for use within the library.  Programs should never use names of this form for any purpose. The names for these macros are reserved specifically for use within `<ctype.h>`, such that no other program may have access to them.

2. `_ctype` is array an array of `int`s whose individual bits have been set according to the bit macros defined above and the properties of the character that each element in the array is meant to represent. 

```
_ctype[9] == _CONTROL | _SPACE == 0x08 | 0x20 == 0x28

_ctype[32] == _SPACE | _BLANK == 0x20 | 0x80 == 0xa0

_ctype[65] == _UPPER | _HEX == 0x01 | 0x40 == 0x41

_ctype[94] == _PUNCT == 0x10
```

3. The advantage of using such an array to implement these macros comes from the increased speed in performance than other alternatives.
