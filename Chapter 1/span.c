#include "span.h"
#include <assert.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct span {
    int num_vectors;
    struct vector *vectors;
};

struct span *span_create(int n, const struct vector *v, ...) {
    return NULL;
}

bool is_vector_in_span(const struct vector *v, const struct span *s) {
    return NULL;
}

bool is_linearly_independent(const struct span *s) {
    return NULL;
}

bool simplify_span(struct span *s) {
    return NULL;
}

bool are_spans_equal(const struct span *s1, const struct span *s2) {
    return NULL;
}

bool is_basis(const struct span *s) {
    return NULL;
}

void print_span(const struct span *s) {
}

void span_destroy(struct span *s) {
}