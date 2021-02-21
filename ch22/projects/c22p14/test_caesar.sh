gcc -o caesar caesar.c

echo "Go ahead. make my day." > message.txt

echo "
message.txt
3" | ./caesar

cat message.txt.enc

echo "
message.txt.enc
23" | ./caesar

cat message.txt

rm caesar *.txt *.enc
