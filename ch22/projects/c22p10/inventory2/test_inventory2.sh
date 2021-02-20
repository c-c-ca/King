make

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
inventory.dat
q" | ./inventory2

echo "
r
inventory.dat
p
q" | ./inventory2


rm inventory2 *.dat *.o
