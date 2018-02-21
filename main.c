#include <stdio.h>
#include <stdlib.h>

/*  Note:  For demonstration purposes only.  Depending on needs, other types
    might be used for indices and sizes, and the array type might be wrapped
    in an opaque struct rather than exposed as "int *".
*/


//  Create an array with N dimensions with sizes specified in D.
int *CreateArray(size_t N, size_t D[])
{
    //  Calculate size needed.
    size_t s = sizeof(int);
    for (size_t n = 0; n < N; ++n)
        s *= D[n];

    //  Allocate space.
    return malloc(s);
}

/*  Return a pointer to an element in an N-dimensional A array with sizes
    specified in D and indices to the particular element specified in I.
*/
int *Element(int *A, size_t N, size_t D[], size_t I[])
{
    //  Handle degenerate case.
    if (N == 0)
        return A;

    //  Map N-dimensional indices to one dimension.
    int index = I[0];
    for (size_t n = 1; n < N; ++n)
        index = index * D[n] + I[n];

    //  Return address of element.
    return &A[index];
}

int main()
{
    //  Create a 3*3*7*7*9 array.
    size_t Size[5] = { 3, 3, 7, 7, 9 };
    int *Array = CreateArray(5, Size);

    //  Set element [1][2][3][4][5] to -987.
    *Element(Array, 5, Size, (size_t []) { 1, 2, 3, 4, 5 }) = -987;
    printf("element set: %d",*Element(Array, 5, Size, (size_t []) { 1, 2, 3, 4, 5 }));
}
