## Solution

```
#define islower(c) ((c) >= 'a' && (c) <= 'z')
```

This macro definition would not be considered legal since the identifier c appears more than once in the macro definition, and cannot be expected to behave as a function in all cases.  Namely, those cases where the argument has side-effects (i.e. `islower(ch++)`).
