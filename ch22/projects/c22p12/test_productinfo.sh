gcc -o productinfo productinfo.c

echo "583,13.5,10/24/2005
3912,599.99,7/27/2008" > productinfo.dat

./productinfo productinfo.dat

rm productinfo *.dat
