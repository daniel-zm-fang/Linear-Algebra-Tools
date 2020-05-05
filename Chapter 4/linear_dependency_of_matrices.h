// This module contains functions that deal with linear dependency of matrices and their documentations

// times: n = number of matrices in the set
//        r = number of rows, c = number of columns

#include "set_of_matrices.h"
#include <stdbool.h>

// is_som_linearly_independent(s) returns true if a set of matrices is linearly independent
// requires: s is not a NULL pointer
// time: O(r * c * n * min(r * c, n))
bool is_som_linearly_independent(const struct som *s);

// make_som_linearly_independent(s) tries to make a set of matrices linearly independent;
//  does nothing if the set is already linearly independent
// requires: s is not a NULL pointer
// effects: may modify *s
// time: O(r * c * n * min(r * c, n))
void make_som_linearly_independent(struct som *s);

// get_som_dimension(s) returns the dimension of the set of matrices s
// requires: s is not a NULL pointer
// time: O(r * c * n * min(r * c, n))
int get_som_dimension(const struct som *s);

// is_som_span(s, row, col) returns true if a set of matrices is a a span for M row * col (R)
// requires: s is not a NULL pointer
//           row >= 0 and col >= 0
// time: O(r * c * n * min(r * c, n))
bool is_som_span(const struct som *s, int row, int col);

// is_som_basis(s, row, col) returns true if a set of matrices is a basis for M row * col (R)
// requires: s is not a NULL pointer
//           row >= 0 and col >= 0
// time: O(r * c * n * min(r * c, n))
bool is_som_basis(const struct som *s, int row, int col);