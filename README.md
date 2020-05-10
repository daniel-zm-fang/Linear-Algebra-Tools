# Linear Algebra Tools
This library is based on the first six chapters of the MATH 136 textbook of the University of Waterloo. In this repo, you will find all sorts of tools that can enhance your experience of learning linear algebra. 

This library is built using the concepts from [CS 136](https://www.student.cs.uwaterloo.ca/~cs136/), namely Abstract Data Type and memory allocation.

Each section consists of 3 files with the same name: an implementation file (.c), an interface file (.h), and a test file (starts with test-). Most tests are from the examples and section problems in the textbook.

Thanks for checking out Linear Algebra Tools!
Dev tem: Daniel Fang and Andy Zhu

<br></br>
***
**Additional Notes on Each Chapter**

**Note:** All structures use double to store their data so that all real numbers will work. Thus some tests require the use of absolute values to pass.

**Chapter 1:**
- subspaces are omitted because the tools are needed to perform a subspace test are beyond the level of CS 136.

**Chapter 2:**

**Chapter 3:**
- Only the 2D rotation matrix is included (rotations in higher dimensions are quite messy).
- Operations on linear mappings are omitted because they are the applications of matrix operations on standard matrices.

**Chapter 4:**
- Like the subspace test in Chapter 1, proving a vector space is beyond the level of CS 136. Thus it is omitted.
- Operations on polynomials are omitted because they can be done by writing polynomials in terms of matrices.

**Chapter 5:**
- Matrix decomposition into elementary matrices is omitted. The idea is to take a matrix as input and return a set of elementary matrices such that, if multiplied in order, their product is equal to the RREF of the original matrix. This function should be similar to the Gauss-Jordan Elimination function with some conversion of each row operation to an elementary matrix and add it to the set.

**Chapter 6:**
- Finding all the eigenvectors and eigenvalues require the need to solve characteristic polynomials, thus all the functions in the eigen module are limited to finding integer eigenvalues.
- While it is easy to prove that two matrices are not similar matrices, it is difficult to prove that they are similar. Thus functions regarding similar matrices are omitted.