make

echo "
i
528
Disk drive
10
i
914
Printer cable
5
u
528
-2
d
inventory.dat
q" | ./inventory

echo "
r
inventory.dat
p
q" | ./inventory

rm *.o inventory.dat
