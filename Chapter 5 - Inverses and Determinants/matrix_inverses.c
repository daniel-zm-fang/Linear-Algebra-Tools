#include "matrix_inverses.h"
#include <assert.h>
#include <stdlib.h>

// This is the implementation of functions of matrix inverses
// See matrix_inverses.h for documentations

bool is_invertible(const struct matrix *m) {
    assert(m);
    assert(num_aug_cols(m) == 0);
    int r = num_rows(m);
    int c = num_cols(m);
    if (r != c || get_rank(m) != r) {
        return false;
    } else {
        return true;
    }
}

struct matrix *inverse(const struct matrix *m) {
    assert(m);
    assert(num_aug_cols(m) == 0);
    int r = num_rows(m);
    int c = num_cols(m);
    if (!is_invertible(m)) {
        return NULL;
    }
    struct matrix *temp = matrix_copy(m);
    for (int i = 0; i < r; ++i) {
        double *a = malloc(r * sizeof(double));
        for (int j = 0; j < r; ++j) {
            if (i == j) {
                a[j] = 1;
            } else {
                a[j] = 0;
            }
        }
        add_col(vector_create(r, a), temp);
    }
    change_augmented_col(r, temp);
    gauss_jordan_elimination(temp);
    struct matrix *solution = matrix_create();
    for (int i = 0; i < r; ++i) {
        add_col(get_col(r + i, temp), solution);
    }
    matrix_destroy(temp);
    return solution;
}

struct matrix *right_inverse(const struct matrix *m) {
    assert(m);
    assert(num_aug_cols(m) == 0);
    int r = num_rows(m);
    int c = num_cols(m);
    if (r > c) {
        return NULL;
    }
    struct matrix *temp1 = transpose(m);
    struct matrix *temp2 = matrix_matrix_mult(m, temp1);
    struct matrix *temp3 = inverse(temp2);
    struct matrix *solution = matrix_matrix_mult(temp1, temp3);
    matrix_destroy(temp1);
    matrix_destroy(temp2);
    matrix_destroy(temp3);
    return solution;
}

struct matrix *left_inverse(const struct matrix *m) {
    assert(m);
    assert(num_aug_cols(m) == 0);
    int r = num_rows(m);
    int c = num_cols(m);
    if (c > r) {
        return NULL;
    }
    struct matrix *temp1 = transpose(m);
    struct matrix *temp2 = matrix_matrix_mult(temp1, m);
    struct matrix *temp3 = inverse(temp2);
    struct matrix *solution = matrix_matrix_mult(temp3, temp1);
    matrix_destroy(temp1);
    matrix_destroy(temp2);
    matrix_destroy(temp3);
    return solution;
}

bool is_inverse(const struct matrix *m1, const struct matrix *m2) {
    assert(m1);
    assert(m2);
    assert(num_aug_cols(m1) == 0);
    assert(num_aug_cols(m2) == 0);
    int r = num_rows(m1);
    int c = num_cols(m1);
    if (r != num_rows(m2) || c != num_cols(m2)) {
        return false;
    }
    struct matrix *temp = matrix_matrix_mult(m1, m2);
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < r; ++j) {
            double val = matrix_get_val(i, j, temp);
            if (i == j && val != 1) {
                return false;
            } else if (val != 0) {
                return false;
            }
        }
    }
    return true;
}