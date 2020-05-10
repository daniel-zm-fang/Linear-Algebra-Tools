// This module contains functions of matrix of linear mappings and their documentations

#include "../Chapter 2 - Systems of Linear Equations/linear_dependency_of_vectors.h"
#include "../Chapter 4 - Vector Spaces/set_of_matrices.h"
#include "../Chapter 5 - Inverses and Determinants/determinants.h"
#include <stdbool.h>

// matrix_wrt_basis(m, s) returns a transformed matrix with respect to a basis
// requires: m and s are not NULL pointers
//           n == r == c
//           m is not an augmented matrix
//           s is a basis
// effects: allocates memory (client must call matrix_destroy)
// time: O(r * c * min(r, c))
struct matrix *matrix_wrt_basis(const struct matrix *m, const struct sov *s);

// is_diagonal_matrix(m) returns true if m is an diagonal matrix
// requires: m is not a NULL pointer
//           m is not an augmented matrix
//           r == c
// time: O(r * c)
bool diagonal_matrix(const struct matrix *m);

// trace(m) returns the trace of a matrix (sum of values of a matrix on main diagonal)
// requires: m is not a NULL pointer
//           m is not an augmented matrix
//           r == c
// time: O(r)
double trace(const struct matrix *m);