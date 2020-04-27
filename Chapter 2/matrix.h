// This module contains matrix (system of linear equations) ADT and its documentations

// time: n = row * col of matrix

#include "set_of_vectors.h"
#include "vector.h"
#include <stdbool.h>

struct matrix;

struct matrix *matrix_create();

bool matrix_equal(const struct matrix *m1, const struct matrix *m2);

struct matrix gauss_jordan_elimination(struct matrix *m);

bool is_rref(const struct matrix *m);

// solutions_exist(m) returns 0 if no solution exists; 1 if a unique solution exists;
//  2 if infinite solutions exists
// requires: m must be in RREF form
int solutions_exist(const struct matrix *m);

// requires: m must be in RREF form
//           m must have a unique solution
struct vector *find_unique_solution(const struct matrix *m);

// requires: m must be in RREF form
//           m must have infinite solutions
struct sov *find_solution_system(const struct matrix *m);

void print_matrix(const struct matrix *m);

void matrix_destroy(struct matrix *m);