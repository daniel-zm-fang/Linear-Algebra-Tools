// This module contains functions of set of matrices and their documentations

// times: n is the number of matrices in the set

#include "../Chapter 2 - Systems of Linear Equations/matrix.h"
#include "../Chapter 3 - Matrices and Linear Mappings/matrix_operations.h"
struct som;

// som_create() creates a new empty set of matrices
// effects: allocates memory (client must call som_destroy)
// time: O(1)
struct som *som_create();

// is_som_empty(s) returns true if set s is an empty set
// requires: s is not a NULL pointer
// time: O(1)
bool is_som_empty(const struct som *s);

// get_som_span(s) returns true if set s is a span
// requires: s is not a NULL pointer
// time: O(1)
bool get_som_span(const struct som *s);

// get_num_matrices(s) returns the number of matrices in set s
// requires: s is not a NULL pointer
// time: O(1)
int get_num_matrices(const struct som *s);

// get_matrix(pos, s) returns a matrices at a specified position of s
// requires: s is not a NULL pointer
// time: O(n)
struct matrix *get_matrix(int pos, const struct som *s);

// change_som_span(span, s) changes whether a set of matrices represents a span or not
// requires: s is not a NULL pointer
// effects: may modify *s
// time: O(1)
void change_som_span(bool span, struct som *s);

// change_const_matrix(m, s) changes the constant matrix of a span
// requires: m and s are not NULL pointers
//           s is a span
//           s is not empty
//           m has the same num_row as other matrices in s
//           m has the same num_col as other matrices in s
// effects: may modify *s
// time: O(n)
void change_const_matrices(struct matrix *m, struct som *s);

// contains_matrix(m, s) returns true if s contains a matrix that is
//  equavalent to m
// requires: m and s are not NULL pointers
// time: O(n)
bool contains_matrix(const struct matrix *m, const struct som *s);

// dup_som(s) returns a new som that is a duplicate of s
// requires: s is not a NULL pointer
// effects: allocates memory (client must call som_destroy)
// time: O(n)
struct som *dup_som(const struct som *s);

// matrices_sets_equal(s1, s2) returns true if the sets contains the same matrices
// requires: s1 and s2 are not NULL pointers
// time: O(n ^ 2)
bool matrices_sets_equal(const struct som *s1, const struct som *s2);

// add_to_som(m, s) adds matrix m to the back of s
// requires: m and s are not NULL pointers
//           m has the same number of row and colomn
//           m is not an augmented matrix
// effects: modifies s
//          allocates memory (client must free when removing v)
// time: O(1)
void add_to_som(struct matrix *m, struct som *s);

// remove_from_som(m, s) remove matrix m from s if m is in s, returns true if
//  matrix is succfessfully removed
// requires: m and s are not NULL pointers
//           s is not empty
// effects: may modify s
// time: O(n)
bool remove_from_som(const struct matrix *m, struct som *s);

// som_to_matrix(s) returns a matrix such that its columns represent matrices from som
// requires: s is not a NULL pointer
//           s is not empty
// effects: allocates memory (client must call matrix_destroy)
// time: (# columns * # rows * n)
struct matrix *som_to_matrix(const struct som *s);

// print_som(s) prints all the matrices in s
// requires: s is not a NULL pointer
// effects: produces output
// time: O(n)
void print_som(const struct som *s);

// som_destroy(som *s) frees all memory for s
// effects: s is not longer valid
// time: O(n)
void som_destroy(struct som *s);