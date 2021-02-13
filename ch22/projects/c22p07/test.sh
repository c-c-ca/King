# Create the file to be encoded
gcc -o texttobin texttobin.c
echo 46 6F 6F 20 62 61 72 21 21 21 20 20 20 20 6F 6F | ./texttobin >foo.txt 

echo Before: `cat foo.txt`

# Create a compressed file from the original
gcc -o compressfile compressfile.c
./compressfile foo.txt >temp

# Uncompress the encoded file
gcc -o uncompressfile uncompressfile.c
./uncompressfile temp >output

# Print output
echo After: `cat output`

# Clean up
rm compressfile foo.txt output temp texttobin uncompressfile
