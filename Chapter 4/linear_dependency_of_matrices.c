#include "linear_dependency_of_matrices.h"
#include <assert.h>
#include <stdlib.h>

bool is_som_linearly_independent(const struct som *s) {
    assert(s);
    if (get_num_matrices(s) == 0) {
        return true;
    }
    int length = get_num_matrices(s);
    int r = num_rows(get_matrix(0, s));
    int c = num_cols(get_matrix(0, s));
    struct matrix *temp = matrix_create();
    for (int i = 0; i < length; ++i) {
        double *a = malloc(r * c * sizeof(double));
        for (int j = 0; j < r; ++j) {
            for (int k = 0; k < c; ++k) {
                a[j * c + k] = matrix_get_val(j, k, get_matrix(i, s));
            }
        }
        add_col(vector_create(r * c, a), temp);
    }
    gauss_jordan_elimination(temp);
    int rank = get_rank(temp);
    matrix_destroy(temp);
    if (rank == length) {
        return true;
    } else {
        return false;
    }
}

void make_som_linearly_independent(struct som *s) {
    assert(s);
    if (is_som_linearly_independent(s)) {
        return;
    }
    int length = get_num_matrices(s);
    int r = num_rows(get_matrix(0, s));
    int c = num_cols(get_matrix(0, s));
    struct matrix *temp = matrix_create();
    for (int i = 0; i < length; ++i) {
        double *a = malloc(r * c * sizeof(double));
        for (int j = 0; j < r; ++j) {
            for (int k = 0; k < c; ++k) {
                a[j * c + k] = matrix_get_val(j, k, get_matrix(i, s));
            }
        }
        add_col(vector_create(r * c, a), temp);
    }
    gauss_jordan_elimination(temp);
    int remove_count = 0;
    for (int i = 0; i < length; ++i) {
        if (is_col_free_var(i, temp)) {
            remove_from_matrices_set(get_matrix(i - remove_count, s), s);
            remove_count += 1;
        }
    }
    matrix_destroy(temp);
}

int get_som_dimension(const struct som *s) {
    assert(s);
    struct som *temp = dup_som(s);
    make_som_linearly_independent(temp);
    int result = get_num_matrices(temp);
    som_destroy(temp);
    return result;
}

bool is_som_span(const struct som *s, int row, int col) {
    assert(s);
    assert(row >= 0);
    assert(col >= 0);
    if (!is_set_matrices_span(s)) {
        return false;
    }
    int length = get_num_matrices(s);
    if (row == 0 && col == 0 && length == 0) {
        return true;
    }
    int r = num_rows(get_matrix(0, s));
    int c = num_cols(get_matrix(0, s));
    if (length < r * c) {
        return false;
    }
    struct matrix *temp = matrix_create();
    for (int i = 0; i < length; ++i) {
        double *a = malloc(r * c * sizeof(double));
        for (int j = 0; j < r; ++j) {
            for (int k = 0; k < c; ++k) {
                a[j * c + k] = matrix_get_val(j, k, get_matrix(i, s));
            }
        }
        add_col(vector_create(r * c, a), temp);
    }
    gauss_jordan_elimination(temp);
    int rank = get_rank(temp);
    free(temp);
    if (rank == r * c) {
        return true;
    } else {
        return false;
    }
}

bool is_som_basis(const struct som *s, int row, int col) {
    assert(s);
    assert(row >= 0);
    assert(col >= 0);
    return is_som_linearly_independent(s) && is_som_span(s, row, col);
}