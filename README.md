# Linear Algebra Tools
This library is based on the MATH 136 textbook of the University of Waterloo. In this repo, you will find all sorts of tools that can enhance your experience of learning linear algebra. 

This library is built using the concepts from [CS 136](https://www.student.cs.uwaterloo.ca/~cs136/), namely Abstract Data Type and memory allocation.

Each section consists of 3 files with the same name: an implementation file (.c), an interface file (.h), and a test file (starts with test-). Most tests are from the examples and section problems in the textbook.

This project is still under development, so please stay tuned for more updates!
<br></br>
***
**Additional Notes on Each Chapter**

Chapter 1:
- subspaces are omitted because the tools are needed to perform a subspace test are beyond the level of CS 136.

Chapter 2:

Chapter 3:
- Only the 2D rotation matrix is included (rotations in higher dimensions are quite messy).
- Operations on linear mappings are omitted because they are the applications of matrix operations on standard matrices.

Chapter 4:
- Like the subspace test in Chapter 1, proving a vector space is beyond the level of CS 136. Thus it is omitted.
- Operations on polynomials are omitted because they can be done by writing polynomials in terms of matrices.

Chapter 5:
- Matrix decomposition into elementary matrices is omitted. The idea is to take a matrix as input and return a set of elementary matrices such that, if multiplied in order, their product is equal to the RREF of the original matrix. This function should be similar to the Gauss-Jordan Elimination function with some conversion of each row operation to an elementary matrix and add it to the set.