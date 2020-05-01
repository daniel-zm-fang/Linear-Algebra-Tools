#include "matrix_operations.h"
#include "../Chapter 2/matrix.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// This is the implementation for matrix operations
// See matrix_operations.h for documentation of functions

struct matrix *matrix_add(const struct matrix *m1, const struct matrix *m2) {
    assert(m1);
    assert(m2);
    assert(num_rows(m1) == num_rows(m2));
    assert(num_cols(m1) == num_cols(m2));
    assert(num_aug_cols(m1) == num_aug_cols(m2));
    struct matrix *new_m = matrix_create();
    for (int i = 0; i < num_rows(m1); ++i) {
        double *a = malloc(num_cols(m1) * sizeof(double));
        for (int j = 0; j < num_cols(m1); ++j) {
            a[j] = matrix_get_val(i, j, m1) + matrix_get_val(i, j, m2);
        }
        add_row(vector_create(num_cols(m1), a), new_m);
    }
    return new_m;
}

struct matrix *matrix_scalar_mult(double c, const struct matrix *m) {
    assert(m);
    struct matrix *new_m = matrix_create();
    for (int i = 0; i < num_rows(m); ++i) {
        double *a = malloc(num_cols(m) * sizeof(double));
        for (int j = 0; j < num_cols(m); ++j) {
            a[j] = c * matrix_get_val(i, j, m);
        }
        add_row(vector_create(num_cols(m), a), new_m);
    }
    return new_m;
}

struct matrix *transpose(struct matrix *m) {
    assert(m);
    assert(num_aug_cols(m) == 0);
    struct matrix *new_m = matrix_create();
    for (int i = 0; i < num_cols(m); ++i) {
        double *a = malloc(num_rows(m) * sizeof(double));
        for (int j = 0; j < num_rows(m); ++j) {
            a[j] = matrix_get_val(j, i, m);
        }
        add_row(vector_create(num_rows(m), a), new_m);
    }
    return new_m;
}

struct vector *matrix_vector_mult(const struct matrix *m, const struct vector *v) {
    assert(v);
    assert(m);
    assert(num_aug_cols(m) == 0);
    assert(get_dimension(v) == num_cols(m));
    double *a = malloc(num_rows(m) * sizeof(double));
    for (int i = 0; i < num_rows(m); ++i) {
        a[i] = 0;
        for (int j = 0; j < num_cols(m); ++j) {
            a[i] += matrix_get_val(i, j, m) * vector_get_val(j, v);
        }
    }
    return vector_create(num_rows(m), a);
}

struct matrix *matrix_matrix_mult(const struct matrix *m1, const struct matrix *m2) {
    assert(m1);
    assert(m2);
    assert(num_aug_cols(m1) == 0);
    assert(num_aug_cols(m2) == 0);
    assert(num_cols(m1) == num_rows(m2));
    struct matrix *new_m = matrix_create();
    for (int i = 0; i < num_cols(m2); ++i) {
        add_col(matrix_vector_mult(m1, get_col(i, m2)), new_m);
    }
    return new_m;
}