// This module contains span ADT and its documentations

// times: n is the dimension of the vector

#include "vector.h"
#include <stdbool.h>

struct span;

// span_create(n, v, ...) creates a new span with n number of vectors
// requires: n > 0
//           the length of v is n (not asserted)
//           each vector in v has the same dimensions
// effects: allocates memory (cilent must call span_destroy)
// time:
struct span *span_create(int n, const struct vector *v, ...);

// is_vector_in_span(v, s) returns true if vector v is in span s,
//    false otherwise
// requires: v and s are not NULL pointers
// time:
bool is_vector_in_span(const struct vector *v, const struct span *s);

// is_linearly_independent(s) returns true is s is a linearly independent set,
//  and false if it is a linearly dependent set
// requires: s is not a NULL pointer
// time:
bool is_linearly_independent(const struct span *s);

// simplify_span(s) attempts to simplify the span, returns true if it can be
//  simplified, false otherwise
// requires: s is a NULL pointer
// effects: may modify *s
// time:
bool simplify_span(struct span *s);

// are_spans_equal(s1, s2) returns true if s1 and s2 are equal, false otherwise
// requires: s1 and s2 are not NULL pointers
// time:
bool are_spans_equal(const struct span *s1, const struct span *s2);

// is_basis(s) returns true if s is an basis, false otherwise
// requires: s is not a NULL pointer
// time:
bool is_basis(const struct span *s);

// print_span(s) prints each vectors in s
// requires: s is not a NULL pointer
// effects: produces output
// time:
void print_span(const struct span *s);

// span_destroy(s) frees all memory for s
// effects: s is not longer valid
// time:
void span_destroy(struct span *s);