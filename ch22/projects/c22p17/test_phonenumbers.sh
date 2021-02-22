gcc -o phonenumbers phonenumbers.c

echo "404.817.6900
(215) 686-1776
312-746-6000
877 275 5273
6173434200" >phonenumbers.dat

./phonenumbers phonenumbers.dat

rm phonenumbers *.dat
