#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int *CreateArray(size_t N, size_t D[])
{
    size_t s = sizeof(int);
    for (size_t n = 0; n < N; ++n)
        s *= D[n];

    return malloc(s);
}

int *Element(int *A, size_t N, size_t D[], size_t I[])
{
    if (N == 0)
        return A;

    int index = I[0];
    for (size_t n = 1; n < N; ++n)
        index = index * D[n] + I[n];
    
    return &A[index];
}

size_t numberOfElements(size_t N, size_t A[]){
    size_t numberOfElements=1;
    for (int i=0;i<N;i++){
        numberOfElements *=A[i];
    }
    return numberOfElements;
}

void secondProcedure(int N, int *A, size_t D[]){
    int _numberOfElements = numberOfElements(N,D);
    int numberOfBlocksToChange = ceil(_numberOfElements/10);
    printf("number of elements to change: %d \n",numberOfBlocksToChange);
    int numberOfBlockesChanged = 0;
    srand(time(NULL));   // generate random seed
    while (numberOfBlockesChanged!=numberOfBlocksToChange){
        int randomPos = rand() % _numberOfElements;
        numberOfBlockesChanged++;
        A[randomPos]=1;
    }
}

int main()
{
    size_t Size[4] = { 3, 3, 3, 5 };

    size_t N = sizeof(Size)/ sizeof(Size[0]);


    printf("Total Number of dimensions: %d \n Total number of elements %d \n",N,numberOfElements(N,Size));

    int *Array = CreateArray(N, Size);

    //  Set element [1][2][3][4][5] to -987.
    *Element(Array, N, Size, (size_t []) { 1, 2, 3, 4, 5 }) = -987;
    printf("element set: %d\n",*Element(Array, N, Size, (size_t []) { 1, 2, 3, 4, 5 }));

    secondProcedure(N,Array,Size);
}
