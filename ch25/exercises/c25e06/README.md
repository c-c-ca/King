```c
while ((orig_char = getchar()) != EOF) ??<
    new_char = orig_char ??' KEY;
    if (isprint(orig_char) && isprint(new_char))
        putchar(new_char);
    else
        putchar(orig_char);
??>
```