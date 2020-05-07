#include "elementary_matrices.h"
#include <assert.h>
#include <stdlib.h>

int is_elementary_matrix(const struct matrix *m) {
    assert(m);
    assert(num_aug_cols(m) == 0);
    int r = num_rows(m);
    int c = num_rows(m);
    assert(r);
    assert(c);
    if (r != c) {
        return false;
    }
    // check for multipying a row by a nonzero scalar
    int mult_by_nonzero_scalar_count = 0;
    for (int i = 0; i < r; ++i) {
        int nonzero_count = 0;
        bool is_scaled = false;
        bool flag = false;
        for (int j = 0; j < r; ++j) {
            double val = matrix_get_val(i, j, m);
            if (val) {
                nonzero_count += 1;
                if (nonzero_count == 2) {
                    mult_by_nonzero_scalar_count = -1;
                    flag = true;
                    break;
                }
                if (i == j && val != 1) {
                    is_scaled = true;
                }
            }
        }
        if (flag) {
            break;
        }
        if (is_scaled && nonzero_count == 1) {
            mult_by_nonzero_scalar_count += 1;
            if (mult_by_nonzero_scalar_count == 2) {
                break;
            }
        }
    }
    if (mult_by_nonzero_scalar_count == 1) {
        return 1;
    }
    // check for adding a multiple of one row to another
    int add_multiple_row_count = 0;
    for (int i = 0; i < r; ++i) {
        int nonzero_count = 0;
        bool is_mult_row = false;
        bool flag = false;
        for (int j = 0; j < r; ++j) {
            double val = matrix_get_val(i, j, m);
            if (val) {
                nonzero_count += 1;
                if ((i == j && val != 1) || nonzero_count == 3) {
                    add_multiple_row_count = -1;
                    flag = true;
                    break;
                }
                if (i != j && val != 1) {
                    is_mult_row = true;
                }
            }
        }
        if (flag) {
            break;
        }
        if (is_mult_row && nonzero_count == 2) {
            add_multiple_row_count += 1;
            if (add_multiple_row_count == 2) {
                break;
            }
        }
    }
    if (add_multiple_row_count == 1) {
        return 2;
    }
    // check for swapping two rows
    int swapping_count = 0;
    for (int i = 0; i < r; ++i) {
        double diagonal = matrix_get_val(i, i, m);
        if (diagonal != 0 && diagonal != 1) {
            return 0;
        }
        if (matrix_get_val(i, i, m) == 0) {
            swapping_count += 1;
            int ones_count = 0;
            for (int j = 0; j < r; ++j) {
                double val = matrix_get_val(j, i, m);
                if (val != 0 && val != 1) {
                    return 0;
                }
                if (val == 1) {
                    ones_count += 1;
                    if (ones_count == 2) {
                        return 0;
                    }
                }
            }
        }
    }
    if (swapping_count == 2) {
        return 3;
    } else {
        return 0;
    }
}

struct matrix *matrices_mult(const struct som *s) {
    assert(s);
    assert(get_num_matrices(s) > 1);
    assert(!get_som_span(s));
    struct som *dup = dup_som(s);
    struct matrix *result = identity_matrix(num_rows(get_matrix(0, dup)));
    while (!is_som_empty(dup)) {
        struct matrix *temp = matrix_matrix_mult(result, get_matrix(0, dup));
        remove_from_som(get_matrix(0, dup), dup);
        matrix_destroy_keep_ptr(result);
        result = matrix_copy(temp);
        matrix_destroy(temp);
    }
    som_destroy(dup);
    return result;
}