// This module contains functions that deal with linear dependency and their documentations

#include "matrix.h"
#include <stdbool.h>

// times: d = dimensions of vectors; n = number of vectors in the set

// is_sov_linearly_independent(s) returns true if a set of vectors is linearly independent
// requires: s is not NULL pointer
// time: O(d * n * min(d, n))
bool is_sov_linearly_independent(const struct sov *s);

// make_sov_linearly_independent(s) tries to make a set of vectors linearly
//  independent; does nothing if the set is already linearly independent
// requires: s is not a NULL pointer
// effects: may modify *s
// time: O(n * n * d)
void make_sov_linearly_independent(struct sov *s);

// is_sov_span(s) returns true if a set of vectors is a span for R of n
// requires: s is not a NULL pointer
//           n >= 0
// time: O(d * n * min(d, n)):
bool is_sov_span(const struct sov *s, int n);

// is_sov_basis returns true if a set of vectors is a basis for R of n
// requires: s is not a NULL pointer
//           n >= 0
// time: O(d * n * min(d, n))
bool is_sov_basis(const struct sov *s, int n);