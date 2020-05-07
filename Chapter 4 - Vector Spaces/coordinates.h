// This module contains functions of coordinate vectors and their documentations

// time: n = # of vectors/matrices in a set
//       r = # of rows of a matrix; c = # of columns of a matrix

#include "../Chapter 2 - Systems of Linear Equations/linear_dependency_of_vectors.h"
#include "linear_dependency_of_matrices.h"

// coord_vector_wrt_basis_of_vectors(v, s) returns the coordinate
//   vector of v with respect to a basis of vectors
// requires: v and s are not NULL pointers
//           s is not empty
//           dimension of v > 0
//           dimension of v == dimension of vectors in s
//           s is a basis of R(dimension of v)
// effects: allocates memory (client must call vector_destroy)
// time: O(d * n * min(d, n))
struct vector *coord_vector_wrt_basis_of_vectors(const struct vector *v, const struct sov *s);

// coord_vector_wrt_basis_of_matrices(m, s) returns the coordinate
//  vector of m with respect to a basis of matrices
// requires: m and s are not NULL pointers
//           s is not empty
//           r and c of m > 0
//           r and c of m == r and c of s of matrices in s
//           m is not an augmented matrix
//           s is a basis of M r*c (R)
// effects: allocates memory (client must call matrix_destroy)
// time: O(r * c * n * min(r * c, n))
struct vector *coord_vector_wrt_basis_of_matrices(const struct matrix *m, const struct som *s);

// change_of_coord_matrix(from, to) returns the change of coordinates
//  matrix from one basis to another
// requires: from and to are not NULL pointers
//           from and to are not empty set
//           number of vectors in from > 0
//           from and to have the same number of vectors
//           vectors in from and to have the same dimension
//           both from and to are bases of M r*c (R)
// effects: allocates memory (client must call matrix_destroy)
// time: O(r * c * min(r, c))
struct matrix *change_of_coord_matrix(const struct sov *from, const struct sov *to);