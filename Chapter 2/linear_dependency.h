#include "matrix.h"
#include <stdbool.h>

// This module contains functions that deal with linear dependency and its documentations

// time: r = number of rows, c = number of columns

// is_linearly_independent(s) returns true if a set of vectors are linearly independent
// requires: s is not NULL pointer
// time: O(r * c * min(r, c))
bool is_linearly_independent(const struct sov *s);

// make_linearly_independent(s) turns a set of vectors into a basis by removing
//  some vectors; does nothing if the set is already linearly independent
// requires: s is not a NULL pointer
// effects: may modify *s
// time:
void make_linearly_independent(struct sov *s);