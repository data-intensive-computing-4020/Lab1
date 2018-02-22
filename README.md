# ELEN4020 - Data Intensive Computing
## Lab 1 - K Dimensional Arrays
This program has 3 functions that work on a K-dimensional array. Each function takes input parameters of the K-dimensional array and the bounds of that array's dimensions. The behaviour of the functions is as follows:

1. This function initializes each element in the input array to 0. 
2. This function takes 10% of the input array and uniformly initalizes the elements to 1. 
3. This function randomly chooses 5% of the input array and prints out its co-ordinates and the value of the element at this position.

The elements in arrays are usually accessed through the use of loops. As the input array is not static in this program, that is the array does not have the same defined dimensions on every input, it is computationally expensive to continually loop through the array accodring to the number of dimensions it has. However, arrays, regardless of dimension, are stored contiguously in memory. In the C programming language, this is stored using a row major order. By transforming the K co-ordinates of a K-dimensional array into a 1-dimensional co-ordinate system, any element can be accessed using a pointer, eliminating the need for multiple loops.    

#### Installation instructions

In a terminal:

```bash
# Clone the Repo
git clone https://github.com/data-intensive-computing-4020/Lab1.git

# Compile main.c
gcc -o main main.c 

# Run the executable 
./main
```
