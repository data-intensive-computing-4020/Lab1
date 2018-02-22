#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "omp.h"

//This program enables the creation of an nth dimensional array. The Nth dimensions are mapped to a one dimensional array
//through an indexing system system that scales based on the number of dimensions. As the underlying structure is a
//one dimensional array, traditional access of the array is also permitted enabling random assignment of values over all
//dimensions.

//The Number of elements function takes in the array specifying the dimensions of each dimension and the number of dimensions
// and calculates the total number of elements across all dimensions
int numberOfElements(int N, int A[]){
    int numberOfElements=1;
    for (int i=0;i<N;i++){
        numberOfElements *=A[i];
    }
    return numberOfElements;
}

//This function calculates the total space needed to store all the elements of the array. It first calculates the total
//number of elements, given the dimensions using the number of elements function, and then calculates the bit size
// needed to store this information. Malloc is used to reserve this memory.
int *allocateArray(int N, int D[])
{
    int spaceRequired = numberOfElements(N,D)*sizeof(D[0]);
    return malloc(spaceRequired);
}

//Next, we need a method of accessing a particular element within the array, based on the dimensions and the coordinate
//required. By multiplying out the dimensions and the required index in an iterative fashion( see README.md for how this
//logic works), the nth dimensional index can be mapped to a one dimensional index
int *Element(int *A, int N, int D[], int I[])
{
    int index = I[0];
    for (int n = 1; n < N; ++n)
        index = index * D[n] + I[n];

    return &A[index];
}

//This is the second procedure that sets 10% of all the elements in the array to a 1. As the array is passed in by
//reference, this function can be a void and operate directly on the original memory alocated to the array
void secondProcedure(int N, int *A, int D[]){
    int _numberOfElements = numberOfElements(N,D);
    int numberOfBlocksToChange = ceil(_numberOfElements/10); //we cast this statically to an int
    printf("Number of elements to change for Second Procedure: %d \n",numberOfBlocksToChange);
    int numberOfBlockesChanged = 0;
    srand(time(NULL));   // generate random seed to fill normally distributed number of values
    while (numberOfBlockesChanged!=numberOfBlocksToChange){
        int randomPos = rand() % _numberOfElements;
        numberOfBlockesChanged++;
        A[randomPos]=1;
    }
}

int *getCoord(int D, const int Size[],int pos) {

    int *coord;
    int temp = pos;
    coord = malloc(D* sizeof(int));

    for (int i = D- 1; i >= 0; i--) {
        coord[i] = temp % Size[i];
        temp = temp / Size[i];
    }
    return coord;
}

void thirdProcedure(int N, int *A, int D[]){
    int _numberOfElements = numberOfElements(N,D);
    int numberOfElementsToCheck = ceil(_numberOfElements/5); //we cast this statically to an int
    printf("Number of elements to change for third procedure: %d \n",numberOfElementsToCheck);
    int numberOfElementsChecked = 0;
    srand(time(NULL));   // generate random seed to fill normally distributed number of values
    while (numberOfElementsChecked!=numberOfElementsToCheck){
        int randomPos = rand() % _numberOfElements;
        numberOfElementsChecked++;
        printf("Random element chosen at location: [");
        int *coordArray = getCoord(N,D,randomPos);
        for (int i=0;i<N;i++){
            if(i==N-1){
                printf("%d]",coordArray[i]);
            }
            else {
                printf("%d, ",coordArray[i]);
            }
        }
        printf(" with a value of: %d \n",A[randomPos]);
    }
}


int main()
{
    int Size[4] = { 3, 3, 3, 5 };
    //Calculate the number of dimensions, as the dimension of the size array. This is done just to make the execution
    //of latter code easier as this var does not need to be fed into each function respectivly
    int N = sizeof(Size)/ sizeof(Size[0]);
    printf("Total Number of dimensions: %d \n Total number of elements %d \n",N,numberOfElements(N,Size));

    int *Array = allocateArray(N, Size);
    //  Set element [1][2][3][4][5] to -987.
//    *Element(Array, N, Size, (int []) { 1, 2, 3, 4, 5 }) = -987;
//    printf("element set: %d\n",*Element(Array, N, Size, (int []) { 1, 2, 3, 4, 5 }));

    secondProcedure(N,Array,Size);
    thirdProcedure(N,Array,Size);

    int temp[2]={3,3};
    int *outputArray = getCoord(2,temp,5);
    printf("location %d\n",outputArray[0]);
}