# ELEN4020 - Data Intensive Computing
## Lab 1 - K Dimensional Arrays
This program has 3 functions that work with a K-Dimensional array. The first function initializes each element in the input array to a 0. The second function takes 10% of the input array and uniformly initalizes the elements to 1. The third function randomly chooses 5% of the array and prints out its co-ordinates and the value of the element.

Arrays, regardless of dimension, are stored contiguously in memory. In the C programming language, this is stored using a row major order. By transforming the index of the K-dimension array into a 1-dimension co-ordinate system, the value can be accessed easily, eliminating the need for loops.   
