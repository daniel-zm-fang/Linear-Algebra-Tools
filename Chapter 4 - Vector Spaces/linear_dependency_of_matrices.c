#include "linear_dependency_of_matrices.h"
#include <assert.h>
#include <stdlib.h>

// This is the implementation of functions of linear dependency of matrices
// See linear_dependency_of_matrices.h for documentations

bool is_som_linearly_independent(const struct som *s) {
    assert(s);
    if (get_num_matrices(s) == 0) {
        return true;
    }
    struct matrix *temp = som_to_matrix(s);
    gauss_jordan_elimination(temp);
    int rank = get_rank(temp);
    matrix_destroy(temp);
    if (rank == get_num_matrices(s)) {
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
    struct matrix *temp = som_to_matrix(s);
    gauss_jordan_elimination(temp);
    int remove_count = 0;
    for (int i = 0; i < get_num_matrices(s); ++i) {
        if (is_col_free_var(i, temp)) {
            remove_from_som(get_matrix(i - remove_count, s), s);
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
    if (!get_som_span(s)) {
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
    struct matrix *temp = som_to_matrix(s);
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