// This module contains functions that deal with matrices and its documentations

// time: r = number of rows, c = number of columns

#include "../Chapter 1/vector.h"
#include "../Chapter 2/matrix.h"

// matrix_add(m1, m2) returns the sum of two matrices as a new matrix
// requires: m1 and m2 are not NULL pointers
//           m1 and m2 must have the same number of rows, columns, and augmented columns
// effects: allocates memory (client must call matrix_destroy)
// time: O(r * c)
struct matrix *matrix_add(const struct matrix *m1, const struct matrix *m2);

// matrix_scalar_mult(c, m) returns matrix m scaled by c
// requires: m is not a NULL pointer
// effects: allocates memory (client must call matrix_destroy)
// time: O(r * c)
struct matrix *matrix_scalar_mult(double c, const struct matrix *m);

// transpose(m) returns m with rows turning into columns and vice versa
// requires: m is not a NULL pointer
//           m is not an augmented matrix
// effects: allocates memory (client must call matrix_destroy)
// time: O(r * c)
struct matrix *transpose(struct matrix *m);

// matrix_vector_mult(m, v) returns the product of a vector and a matrix
// requires: v and m are not NULL pointers
//           m is not an augmented matrix
//           dimension of v = number of columns of m
// effects: allocates memory (client must call matrix_destroy)
// time: O(r * c)
struct vector *matrix_vector_mult(const struct matrix *m, const struct vector *v);

// matrix_matrix_mult(m1, m2) returns the product of two matrices
// requires: m1 and m2 are not NULL pointers
//           m1 and m2 are not augmented matrices
//           number of columns of m1 = numer of rows of m2
// effects: allocates memory (client must call matrix_destroy)
// time: O(r1 * c1 * r2 * c2) r1, c1 -> m1; r2, c2 -> m2
struct matrix *matrix_matrix_mult(const struct matrix *m1, const struct matrix *m2);