// This module contains matrix (system of linear equations) ADT and its documentations

// time: n = row * col of matrix

#include "../Chapter 1/set_of_vectors.h"
#include "../Chapter 1/vector.h"
#include <stdbool.h>

struct matrix;

// matrix_create() creates a new empty matrix
// effects: allocates memory (client must call matrix_destroy)
// time: O(1)
struct matrix *matrix_create();

// get_row(r, m) returns a row of m at a specified location
// requires: m is not a NULL pointer
//           0 <= r < m->row
// effects: allocates memory (client must call vector_destroy)
// time: O(number of columns)
struct vector *get_row(int r, const struct matrix *m);

// get_col(c, m) returns a column of m at a specified location
// requires: c is not a NULL pointer
//           0 <= c < m->col
// effects: allocates memory (client must call vector_destroy)
// time: O(number of rows)
struct vector *get_col(int c, const struct matrix *m);

// is_empty(m) returns true if m is doesn't not contain any data
// requires: m is not a NULL pointer
// time: O(1)
bool is_empty(const struct matrix *m);

// is_zero_matrix(m) returns true if m is a zero matrix
// requires: m is not a NULL pointer
//           m is not empty
// time: O(n)
bool is_zero_matrix(const struct matrix *m);

// change_augmented_col(aug_col, m) changes the column where the augmented columns start
// note: 0 augmented column indicates that the matrix is not augmented
// requires: m is not a NULL pointer
//           0 <= aug_col < m->col
// effects: modifies *m
// time: O(1)
void change_augmented_col(int aug_col, struct matrix *m);

// add_row(v, m) adds a row/linear equation to m
// requires: v and m are not NULL pointers
//           get_dimension(v) == m->col when matrix is not empty
// effects: modifies *m
//          allocates memory (client must destroy)
// time: O(number of columns) [amoritized]
void add_row(const struct vector *v, struct matrix *m);

// add_col(v, m) adds a column to m
// requires: v and m are not NULL pointers
//           get_dimension(v) == m->row when matrix is not empty
// effects: modifies *m
//          allocates memory (client must destroy)
// time: O(number of rows) [amoritized]
void add_col(const struct vector *v, struct matrix *m);

// gauss_jordan_elimination(m) reduces a matrix to its RREF form using the
//  Gauss-Jordan Elimination algorithm
// requires: m is not a NULL pointer
// effects: may modify *m
// time: O(n ^ min(row, columns))
void gauss_jordan_elimination(struct matrix *m);

// move_zero_rows_bottom(m) moves all the nonzero rows to the top and
//  zero rows to the bottom (does not check augmented columns' values)
// requires: m is not a NULL pointer
// effects: may modify *m
// time: O(n)
void move_zero_rows_bottom(struct matrix *m);

// is_rref(m) returns true if m is in reduced row echelon form (RREF)
// requires: m is not a NULL pointer
// time: O(n * row)
bool is_rref(const struct matrix *m);

// get_rank(m) returns the rank of an rref matrix
// requries: m is not a NULL pointer
//           m is in RREF
// time: O(n)
int get_rank(const struct matrix *m);

// get_free_var(m) returns the number of free variables of an rref matrix
// requries: m is not a NULL pointer
//           m is in RREF
// time: O(n)
int get_free_var(const struct matrix *m);

// find_solution(m) returns NULL if the matrix is inconsistent; a set of vectors
//  if the matrix is consistent
// requires: m is a NULL pointer
//           m must be in RREF form
// effects: may allocate memory (client must call sov_destroy)
// time:
struct sov *find_solution(const struct matrix *m);

// matrix_equal(m1, m2) returns true if the two matrices are equivalent
//  (have the same solution set)
// requires: m1 and m2 are not NULL pointers
// time:
bool matrix_equal(const struct matrix *m1, const struct matrix *m2);

// print_matrix(m) prints the matrix in a nice format
// requires: m is not a NULL pointer
// effects: produces output
// time: O(n)
void print_matrix(const struct matrix *m);

// matrix_destroy(m) frees all memory for m
// effects: m is no longer valid
// time: O(n)
void matrix_destroy(struct matrix *m);