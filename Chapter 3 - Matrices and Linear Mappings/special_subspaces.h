// This module contains functions that deal with special subspaces and their documentations

// time: r = number of rows, c = number of columns

#include "../Chapter 2 - Systems of Linear Equations/linear_dependency_of_vectors.h"
#include "../Chapter 2 - Systems of Linear Equations/matrix.h"
#include "matrix_operations.h"

// is_in_nullspace(v, m) returns true if a vector is in the nullspace of a matrix
// note: nullspace = kernel
// requires: v and m are not NULL pointers
//           m is not an augmented matrix
// time: O(r * c)
bool is_in_nullspace(const struct vector *v, const struct matrix *m);

// is_in_column_space(v, m) returns true if a vector is in the columnspace of a matrix
// note: columnspace = range = image
// requires: v and m are not NULL pointers
//           m is not an augmented matrix
// time: O(r * c * min(r, c))
bool is_in_column_space(const struct vector *v, const struct matrix *m);

// is_in_row_space(v, m) returns true if a vector is in the rowspace of a matrix
// requires: v and m are not NULL pointers
//           m is not an augmented matrix
// time: O(r * c * min(r, c))
bool is_in_row_space(const struct vector *v, const struct matrix *m);

// is_in_left_nullspace(v, m) returns true if a vector is in the left nullspace
// requires: v and m are not NULL pointers
//           m is not an augmented matrix
// time: O(r * c)
bool is_in_left_nullspace(const struct vector *v, const struct matrix *m);

// find_nullspace(m) returns the span of a matrix's vectors in the domain that
//   are mapped to the zero vector
// requires: m is not a NULL pointer
//           m is not an augmented matrix
// effects: allocates memory (client must call sov_destroy)
// time: O(r * r * c)
struct sov *find_nullspace(const struct matrix *m);

// find_column_space(m) returns the span of a matrix's column vectors
// requires: m is not a NULL pointer
//           m is not an augmented matrix
// effects: allocates memory (client must call sov_destroy)
// time: O(r * c *c)
struct sov *find_column_space(const struct matrix *m);

// find_row_space(m) returns the span of a matrix's row vectors
// requires: m is not a NULL pointer
//           m is not an augmented matrix
// effects: allocates memory (client must call sov_destroy)
// time: O(r * r * c)
struct sov *find_row_space(const struct matrix *m);

// find_left_nullspace(m) returns the nullspace of the transpose of a matrix
// requires: m is not a NULL pointer
//           m is not an augmented matrix
// effects: allocates memory (client must call sov_destroy)
// time: O(r * r * c)
struct sov *find_left_nullspace(const struct matrix *m);