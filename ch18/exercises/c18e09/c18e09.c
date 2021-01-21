#include <stdio.h>

typedef void (*Fcn_ptr_arg)(int);
typedef void (*Fcn_ptr(int, Fcn_ptr_arg))(int);
Fcn_ptr x;

int main(void)
{
    return 0;
}


