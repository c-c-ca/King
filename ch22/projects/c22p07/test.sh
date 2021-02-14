# Create the file to be encoded
gcc -o texttobin texttobin.c
echo 46 6F 6F 20 62 61 72 21 21 21 20 20 20 20 | ./texttobin >foo.txt 

# Create a compressed file from the original
gcc -o compressfile compressfile.c
./compressfile foo.txt

# Uncompress the encoded file
gcc -o uncompressfile uncompressfile.c
./uncompressfile foo.txt.rle

# Print output
cat foo.txt

# Clean up
rm compressfile foo.txt foo.txt.rle texttobin uncompressfile
