#include "linear_dependency.h"
#include <assert.h>

bool is_sov_linearly_independent(const struct sov *s) {
    assert(s);
    struct matrix *m = matrix_create();
    int num = get_num_vector(s);
    for (int i = 0; i < num; i++) {
        add_col(get_vector(i, s), m);
    }
    gauss_jordan_elimination(m);
    int rank = get_rank(m);
    matrix_destroy(m);
    if (rank == num) {
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
    struct matrix *m = matrix_create();
    int length = get_num_vector(s);
    for (int i = 0; i < length; ++i) {
        add_col(get_vector(i, s), m);
    }
    gauss_jordan_elimination(m);
    int remove_count = 0;
    for (int i = 0; i < length; ++i) {
        if (is_col_free_var(i, m)) {
            remove_from_set(get_vector(i - remove_count, s), s);
            remove_count += 1;
        }
    }
    matrix_destroy(m);
}

bool is_sov_span(const struct sov *s, int n) {
    assert(s);
    assert(n >= 0);
    struct matrix *m = matrix_create();
    int length = get_num_vector(s);
    for (int i = 0; i < length; ++i) {
        add_col(get_vector(i, s), m);
    }
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