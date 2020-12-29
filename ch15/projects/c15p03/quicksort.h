#ifndef QUICKSORT_H
#define QUICKSORT_H

/***********************************************************
 * quicksort: Sorts all numbers in a from low to hight.    *
 ***********************************************************/
void quicksort(int a[], int low, int high);

/***********************************************************
 * split: Places all numbers in a from low to high so that *
 *        all elements greater than the pivot element      *
 *        occur after it.  Returns the pivot element.      *
 ***********************************************************/
int split(int a[], int low, int high);

#endif
