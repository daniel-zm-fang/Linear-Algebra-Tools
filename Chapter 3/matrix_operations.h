// This module contains functions that deal with matrices and its documentations

#include "matrix.h"
#include "vector.h"

// matrix_add(m1, m2) returns the sum of two matrices as a new matrix
// requires: m1 and m2 are not NULL pointers
//           m1 and m2 must have the same number of rows, columns, and augmented columns
// effects: allocates memory (client must call matrix_destroy)
// time:
struct matrix *matrix_add(const struct matrix *m1, const struct matrix *m2);

struct matrix *matrix_scalar_mult(double c, const struct matrix *m);

void transpose(struct matrix *m);

struct matrix *matrix_vector_mult(const struct vector *v, const struct matrix *m);

struct matrix *matrix_matrix_mult(const struct matrix *m1, const struct matrix *m2);
