```c
FILE *fp;

if ((fp = fopen(filename, "r")) == NULL) {
	fprintf(stderr, "Can't open %s\n", filename);
	exit(EXIT_FAILURE);
}

/* read characters until end-of-file */

fclose(fp);
```
