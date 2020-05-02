// This module contains functions that deal with special subspaces and their documentations

#include "../Chapter 2/matrix.h"

// get_nullspace(m) returns the span of a matrix's vectors in the domain that
//   are mapped to the zero vector
// note: nullspace = kernel
// requires: m is not a NULL pointer
//           m is not an augmented matrix
// effects: allocates memory (client must call sov_destroy)
// time:
struct sov *get_nullspace(const struct matrix *m);

// get_columnspace(m) returns the span of a matrix's column vectors
// note: columnspace = range = image
// requires: m is not a NULL pointer
//           m is not an augmented matrix
// effects: allocates memory (client must call sov_destroy)
// time:
struct sov *get_columnspace(const struct matrix *m);

// get_rowspace(m) returns the span of a matrix's row vectors
// requires: m is not a NULL pointer
//           m is not an augmented matrix
// effects: allocates memory (client must call sov_destroy)
// time:
struct sov *get_rowspace(const struct matrix *m);

// get_left_nullspace(m) returns the nullspace of the transpose of a matrix
// requires: m is not a NULL pointer
//           m is not an augmented matrix
// effects: allocates memory (client must call sov_destroy)
// time:
struct sov *get_left_nullspace(const struct matrix *m);