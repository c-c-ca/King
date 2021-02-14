# Create the file to be encoded
gcc -o texttobin texttobin.c
echo 46 6F 6F 20 62 61 72 21 21 21 20 20 20 20 | ./texttobin >foo.txt 

# Create a compressed file from the original
gcc -o compress_file compress_file.c
./compress_file foo.txt

# Uncompress the encoded file
gcc -o uncompress_file uncompress_file.c
./uncompress_file foo.txt.rle

# Print output
cat foo.txt

# Clean up
rm compress_file foo.txt foo.txt.rle texttobin uncompress_file
