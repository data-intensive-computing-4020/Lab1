# ELEN4020 - Data Intensive Computing
## Lab 1 - K Dimensional Arrays
This program has 3 functions that work on a K-dimensional array. Each function takes input parameters of the K-dimensional array and the bounds of the array's dimensions. The behaviour of the functions is as follows:

1. This function initializes each element in the input array to 0. 
2. This function takes 10% of the input array and uniformly initalizes the elements to 1. 
3. This function randomly chooses 5% of the input array and prints out its co-ordinates and the value of the element at this position.

As the input array is not static, that is the array does not have the same defined dimensions on every code execution, it is tedious to continually loop through the array to access the elements at specific positions. However, arrays, regardless of dimension, are stored contiguously in memory. In the C programming language, this is stored using a row major order. 

By transforming the index of the K-dimension array into a 1-dimension co-ordinate system, any element can be accessed easily and trivially, eliminating the need for multiple loops.    
