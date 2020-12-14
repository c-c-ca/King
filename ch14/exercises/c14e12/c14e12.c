#include <stdio.h>

#define M 10

#if M
#define A "#if M: SUCCESS\n"
#else
#define A "#if M: FAILURE\n"
#endif

#ifdef M
#define B "#ifdef M: SUCCESS\n"
#else
#define B "ifdef M: FAILURE\n"
#endif

#ifndef M
#define C "ifndef M: SUCCESS\n"
#else
#define C "#ifndef M: FAILURE\n"
#endif

#if defined(M)
#define D "if defined(M): SUCCESS\n"
#else
#define D "#if defined(M): FAILURE\n"
#endif

#if !defined(M)
#define E "#if !defined(M): SUCCESS\n"
#else
#define E "#if !defined(M): FAILURE\n"
#endif

int main(void)
{
    printf(A); /* prints "if M: SUCCESS"           */
    printf(B); /* prints "ifdef M: SUCCESS"        */
    printf(C); /* prints "ifndef M: FAILURE"       */
    printf(D); /* prints "if defined(M): SUCCESS"  */
    printf(E); /* prints "if !defined(M): FAILURE" */
    return 0;
}
