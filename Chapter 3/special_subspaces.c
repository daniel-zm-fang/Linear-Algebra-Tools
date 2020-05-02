#include "special_subspaces.h"
#include <assert.h>
#include <stdlib.h>

// This is the implementation for functions for speical subspaces
// See special_subspaces.h for documentations

struct sov *get_nullspace(const struct matrix *m) {
    assert(m);
    assert(num_aug_cols(m) == 0);
    return NULL;
}

struct sov *get_columnspace(const struct matrix *m) {
    assert(m);
    assert(num_aug_cols(m) == 0);
    return NULL;
}

struct sov *get_rowspace(const struct matrix *m) {
    assert(m);
    assert(num_aug_cols(m) == 0);
    return NULL;
}

struct sov *get_left_nullspace(const struct matrix *m) {
    assert(m);
    assert(num_aug_cols(m) == 0);
    return NULL;
}