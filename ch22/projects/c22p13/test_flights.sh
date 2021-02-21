gcc -o flights flights.c

echo "13:01" | ./flights flights.dat
echo "7:00" | ./flights flights.dat
echo "22:00" | ./flights flights.dat

rm flights
