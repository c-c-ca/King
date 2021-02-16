```
FILE *fp;

if ((fp = fopen(filename, "r")) != NULL) {
	/* read characters until end-of-file */
	fclose(fp);
}
```
