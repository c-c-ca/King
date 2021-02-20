make
gcc -o merge merge.c

echo "
i
362
Mouse
3
i
528
Disk drive
10
u
528
-2
i
632
Power supply
9
i
730
Graphics card
2
d
inventory1.dat
q" | ./inventory

echo "
i
191
Processor
6
i
362
Mouse
10
i
730
Keyboard
4
i
914
Printer cable
5
d
inventory2.dat
q" | ./inventory


./merge inventory1.dat inventory2.dat inventory3.dat

echo "
r
inventory1.dat
p
q" | ./inventory

echo "
r
inventory2.dat
p
q" | ./inventory

echo "
r
inventory3.dat
p
q" | ./inventory


rm merge *.dat *.o
