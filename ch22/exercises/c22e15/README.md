Records are 64 bytes.

### (a) Move to the beginning of a record
```c
fseek(fp, n * 64L, SEEK_SET);
```

### (b) Move to the beginning of the last record in a file.
```c
fseek(fp, -64L, SEEK_END);
```

### (c) Move forward one record.
```c
fseek(fp, 64L, SEEK_CUR);
```

### (d) Move backward two records.
```c
fseek(fp, -128L, SEEK_CUR);
```

