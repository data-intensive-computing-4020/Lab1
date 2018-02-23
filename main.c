#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
//_  __           _____  _                          _                   _
//| |/ /          |  __ \(_)                        (_)                 | |
//| ' /   ______  | |  | |_ _ __ ___   ___ _ __  ___ _  ___  _ __   __ _| |
//|  <   |______| | |  | | | '_ ` _ \ / _ \ '_ \/ __| |/ _ \| '_ \ / _` | |
//| . \           | |__| | | | | | | |  __/ | | \__ \ | (_) | | | | (_| | |
//|_|\_\          |_____/|_|_| |_| |_|\___|_| |_|___/_|\___/|_| |_|\__,_|_|
//     _____       _
//    |_   _|     | |                           /\
//      | |  _ __ | |_ ___  __ _  ___ _ __     /  \   _ __ _ __ __ _ _   _
//      | | | '_ \| __/ _ \/ _` |/ _ \ '__|   / /\ \ | '__| '__/ _` | | | |
//     _| |_| | | | ||  __/ (_| |  __/ |     / ____ \| |  | | | (_| | |_| |
//    |_____|_| |_|\__\___|\__, |\___|_|    /_/    \_\_|  |_|  \__,_|\__, |
//                          __/ |                                     __/ |
//                         |___/                                     |___/

//****************************************************
//* ELEN4020 Data Intensive Computing, Laboratory: 1 *
//****************************************************

//+--------------------+----------------+
//|    Student Name    | Student Number |
//+--------------------+----------------+
//| Kavilan Nair       |        1076342 |
//| Christopher Maree  |        1101946 |
//| Iordan Tchaparov   |        1068874 |
//| Laura West         |        1084327 |
//+--------------------+----------------+

//This program enables the creation of an nth dimensional array. The Nth dimensions are mapped to a one dimensional array
//through an indexing system system that scales based on the number of dimensions. As the underlying structure is a
//one dimensional array, traditional access of the array is also permitted enabling random assignment of values over all
//dimensions.

//The Number of elements function takes in the array specifying the dimensions of each dimension and the number of dimensions
// and calculates the total number of elements across all dimensions
int numberOfElements(int N, int A[]) {
    int numberOfElements = 1;
    for (int i = 0; i < N; i++) {
        numberOfElements *= A[i];
    }
    return numberOfElements;
}

//This function calculates the total space needed to store all the elements of the array. It first calculates the total
//number of elements, given the dimensions using the number of elements function, and then calculates the bit size
// needed to store this information. Malloc is used to reserve this memory.
int *allocateArray(int N, int D[]) {
    int spaceRequired = numberOfElements(N, D) * sizeof(D[0]);
    return malloc(spaceRequired);
}

//Next, we need a method of accessing a particular element within the array, based on the dimensions and the coordinate
//required. By multiplying out the dimensions and the required index in an iterative fashion( see README.md for how this
//logic works), the nth dimensional index can be mapped to a one dimensional index
int *Element(int *A, int N, int D[], int I[]) {
    int index = I[0];
    for (int n = 1; n < N; ++n)
        index = index * D[n] + I[n];

    return &A[index];
}

//Used to make the display more functional
void printStarRow() {
    printf("       ****************************************************\n");
}

//Display function, to remove the code from the main program to make the display process cleaner
void printHeader() {
    printf("  _  __           _____  _                          _                   _  \n");
    printf(" | |/ /          |  __ \\(_)                        (_)                 | | \n");
    printf(" | ' /   ______  | |  | |_ _ __ ___   ___ _ __  ___ _  ___  _ __   __ _| | \n");
    printf(" |  <   |______| | |  | | | '_ ` _ \\ / _ \\ '_ \\/ __| |/ _ \\| '_ \\ / _` | | \n");
    printf(" | . \\           | |__| | | | | | | |  __/ | | \\__ \\ | (_) | | | | (_| | | \n");
    printf(" |_|\\_\\          |_____/|_|_| |_| |_|\\___|_| |_|___/_|\\___/|_| |_|\\__,_|_| \n");
    printf("     _____       _                                                         \n");
    printf("    |_   _|     | |                           /\\                           \n");
    printf("      | |  _ __ | |_ ___  __ _  ___ _ __     /  \\   _ __ _ __ __ _ _   _   \n");
    printf("      | | | '_ \\| __/ _ \\/ _` |/ _ \\ '__|   / /\\ \\ | '__| '__/ _` | | | |  \n");
    printf("     _| |_| | | | ||  __/ (_| |  __/ |     / ____ \\| |  | | | (_| | |_| |  \n");
    printf("    |_____|_| |_|\\__\\___|\\__, |\\___|_|    /_/    \\_\\_|  |_|  \\__,_|\\__, |  \n");
    printf("                          __/ |                                     __/ |  \n");
    printf("                         |___/                                     |___/   \n");
    printStarRow();
    printf("       * ELEN4020 Data Intensive Computing, Laboratory: 1 *\n");
    printStarRow();
    printf("             +--------------------+----------------+ \n");
    printf("             |    Student Name    | Student Number | \n");
    printf("             +--------------------+----------------+ \n");
    printf("             | Kavilan Nair       |        1076342 | \n");
    printf("             | Christopher Maree  |        1101946 | \n");
    printf("             | Iordan Tchaparov   |        1068874 | \n");
    printf("             | Laura West         |        1084327 | \n");
    printf("             +--------------------+----------------+ \n");
}

//This returns an array with the coordinates of an element, if the linear location is provided. This means that one can
//feed in the number of dimensions, an array storing the size of each dimension and the requested position from the linear
// array and the function returns an array storing what position, in each domension the element is stored
int *getLocation(const int D, const int Size[], int pos) {
    int *locationArray;
    locationArray = malloc(D * sizeof(int));
    for (int i = D - 1; i >= 0; i--) {
        locationArray[i] = pos % Size[i];
        pos = pos / Size[i];
    }
    return locationArray;
}

//Function used to print the contents of an array. Prints directly inline with the current string
void printArray(int A[], int N) {
    printf("[");
    for (int i = 0; i < N; i++) {
        if (i == N - 1) {
            printf("%d]", A[i]);
        } else {
            printf("%d, ", A[i]);
        }
    }
}

//Before any processes can be applied, we first set all elements in the array to zero
void firstProcedure(int N, int *A, int D[]) {
    int _numberOfElements = numberOfElements(N, D);
    for (int i = 0; i < _numberOfElements; i++) {
        A[i] = 0;
    }
    printf("***First Procedure** set %d elements to 0***\n",_numberOfElements);
}

//This is the second procedure that sets 10% of all the elements in the array to a 1. As the array is passed in by
//reference, this function can be a void and operate directly on the original memory alocated to the array
void secondProcedure(int N, int *A, int D[]) {
    int _numberOfElements = numberOfElements(N, D);
    int numberOfBlockesChanged = 0;
    int iterator = 0;

    while(iterator < _numberOfElements){
        A[iterator] = 1;
        iterator += 10;
        numberOfBlockesChanged++;
    }

    printf("***Second procedure set %d elements to 1 ***\n", numberOfBlockesChanged);
}

//This function prints a random 5% of all elements, with their value and coordinate. It ensures that the same element is
// not printed two times
void thirdProcedure(int N, int *A, int D[]) {
    int _numberOfElements = numberOfElements(N, D);
    int numberOfElementsToCheck = ceil(_numberOfElements * 0.05); //we cast this statically to an int
    int numberOfElementsChecked = 0;
    int printedValues[numberOfElementsToCheck]; //an array to store the indecies that have been printed
    for (int i =0; i <numberOfElementsToCheck;i++){
        printedValues[i]=-1;
    }
    bool dropLoop = false;
    while (numberOfElementsChecked != numberOfElementsToCheck) {
        int randomPos = rand() % _numberOfElements;
        // we need to check if the location has been printed before.
        for (int i=0; i< numberOfElementsToCheck;i++){
            if(printedValues[i]==randomPos){ //if it has, set the boolean and drop out of this loop
                dropLoop=true;
                break;
            }
        }
        if(dropLoop==true){ //continue in the while loop to generate a new random value
            dropLoop=false;
            continue;
        }
        //set the element that has been printed, at the location of the current number printed, to the random position
        printedValues[numberOfElementsChecked]=randomPos;
        numberOfElementsChecked++;
        printf("Random element chosen at location: ");
        int *coordArray = getLocation(N, D, randomPos);
        printArray(coordArray, N);
        printf(" with a value of: %d \n", A[randomPos]);
    }
    printf("\n***Third procedure printed %d values and locations*** \n", numberOfElementsToCheck );
}

int main() {
    srand(time(NULL));   // generate random seed to fill normally distributed number of values
    printHeader();

    char response = ' ';

    do{
        int numberOfDimensions; //stores the number of dimensions
        printf("\nEnter the number of dimensions to generate: ");
        scanf("%d", &numberOfDimensions);


        printf("Enter the size of each dimension:\n");

        int *sizeArray;
        sizeArray = malloc(numberOfDimensions * sizeof(int));

        for (int i = 0; i < numberOfDimensions; i++) {
            printf("Dimension %d: ", i);
            scanf("%d", &sizeArray[i]);
        }
        printStarRow();
        printf("Total number of dimensions: %d \nTotal number of elements: %d \n", numberOfDimensions,
            numberOfElements(numberOfDimensions, sizeArray));

        int *storageArray = allocateArray(numberOfDimensions, sizeArray);
        printStarRow();
        printf("\n");
        firstProcedure(numberOfDimensions, storageArray, sizeArray);
        printf("\n");
        secondProcedure(numberOfDimensions, storageArray, sizeArray);
        printf("\n");
        thirdProcedure(numberOfDimensions, storageArray, sizeArray);

        printf("Would you like to enter another array? [y/n]\n");
        scanf(" %c", &response);

    }
    while (response != 'n');
    
}