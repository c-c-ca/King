## Solution

```
#define islower(c) ((c) >= 'a' && (c) <= 'z')
```

This parameterized macro, which substitutes for a library function, is not considered legal since the parameter `c` is evaluated more than once. Therefore, the macro cannot be expected to behave as a function in all cases.  Namely, those cases where the argument has side-effects (i.e. `islower(ch++)`).
