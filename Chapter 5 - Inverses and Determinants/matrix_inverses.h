// This module contains functions of finding matrix inverses and their documentations

// time: r = number of rows, c = number of columns

#include "../Chapter 3 - Matrices and Linear Mappings/matrix_operations.h"
#include <stdbool.h>

// is_invertible(m) returns true if a matrix is invertible
// requires: m is not a NULL pointer
//           m is not an augmented matrix
// time: O(r * c * min(r, c))
bool is_invertible(const struct matrix *m);

// inverse(m) returns a matrix's inverse if it exists, NULL otherwise
// note: inverse exists iff left and right inverses exist and are equal
// requires: m is not a NULL pointer
//           m is not an augmented matrix
// effects: may allocate memory (client must call matrix_destroy)
// time: O(r * c * min(r, c))
struct matrix *inverse(const struct matrix *m);

// right_inverse(m) returns one of a matrix's right inverses if they exist, NULL otherwise
// requires: m is not a NULL pointer
//           m is not an augmented matrix
// effects: may allocate memory (client must call matrix_destroy)
// time: (r ^ 2 * c ^ 2)
struct matrix *right_inverse(const struct matrix *m);

// left_inverse(m) returns one of a matrix's left inverses if they exist, NULL otherwise
// requires: m is not a NULL pointer
//           m is not an augmented matrix
// effects: may allocate memory (client must call matrix_destroy)
// time: (r ^ 2 * c ^ 2)
struct matrix *left_inverse(const struct matrix *m);

// is_inverse(m1, m2) returns true if m1 and m2 are each other's inverses
// requires: m1 and m2 are not NULL pointers
//           m1 and m2 are not augmented matrices
// time: O(r1 * c1 * r2 * c2) r1, c1 -> m1; r2, c2 -> m2
bool is_inverse(const struct matrix *m1, const struct matrix *m2);