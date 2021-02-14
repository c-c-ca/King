gcc -o viewfile viewfile.c
gcc -o compress_file compress_file.c
gcc -o uncompress_file uncompress_file.c

# Create the file to be encoded
echo foo bar!!!   >foo.txt 
./viewfile foo.txt

# Create a compressed file from the original
./compress_file foo.txt
./viewfile foo.txt.rle

# Uncompress the encoded file
./uncompress_file foo.txt.rle
./viewfile foo.txt

# Clean up
rm compress_file foo.txt foo.txt.rle uncompress_file viewfile
