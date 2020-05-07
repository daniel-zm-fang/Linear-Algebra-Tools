// This module contains functions concerning elementary matrices and their documentations

// time: n = # of matrices in a set
//       r = number of rows, c = number of columns

#include "../Chapter 3 - Matrices and Linear Mappings/matrix_operations.h"
#include "../Chapter 4 - Vector Spaces/set_of_matrices.h"
#include <stdbool.h>

// is_elementary_matrix(m)
//  returns 0 if m is not an elementary matrix
//  returns 1 if m represents multiplying a row by a nonzero scalar
//  returns 2 if m represents adding a multiple of one row to another
//  returns 3 if m represents swapping two rows
// requires: m is not a NULL pointer
//           m is not an augmented matrix
//           number of rows of and columns of m > 0
// time: O(r * c)
int is_elementary_matrix(const struct matrix *m);

// matrices_mult(s) returns the product of all matrices in a
//  set of matrices multipling in order
// requires: s is not a NULL pointer
//           number of matrices in s > 1
//           s is not a span
// effects: allocates memory (client must call som_destroy)
// time: (n * r ^ 2 * c ^ 2)
struct matrix *matrices_mult(const struct som *s);