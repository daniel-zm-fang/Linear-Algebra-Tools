#include "linear_dependency_of_vectors.h"
#include <assert.h>

// This is the implementation of linear dependency of a set of vectors
// See linear_dependency_of_vectors.h for documentations

bool is_sov_linearly_independent(const struct sov *s) {
    assert(s);
    struct matrix *m = sov_to_matrix(s);
    gauss_jordan_elimination(m);
    int rank = get_rank(m);
    matrix_destroy(m);
    if (rank == get_num_vectors(s)) {
        return true;
    } else {
        return false;
    }
}

void make_sov_linearly_independent(struct sov *s) {
    assert(s);
    if (is_sov_linearly_independent(s)) {
        return;
    }
    struct matrix *m = sov_to_matrix(s);
    gauss_jordan_elimination(m);
    int length = get_num_vectors(s);
    int remove_count = 0;
    for (int i = 0; i < length; ++i) {
        if (is_col_free_var(i, m)) {
            remove_from_sov(get_vector(i - remove_count, s), s);
            remove_count += 1;
        }
    }
    matrix_destroy(m);
}

bool is_sov_span(const struct sov *s, int n) {
    assert(s);
    assert(n >= 0);
    if (!get_sov_span(s) || get_num_vectors(s) < n) {
        return false;
    }
    struct matrix *m = sov_to_matrix(s);
    gauss_jordan_elimination(m);
    int rank = get_rank(m);
    int row = num_rows(m);
    matrix_destroy(m);
    if (rank == row) {
        return true;
    } else {
        return false;
    }
}

bool is_sov_basis(const struct sov *s, int n) {
    assert(s);
    assert(n >= 0);
    return is_sov_linearly_independent(s) && is_sov_span(s, n);
}