#include "linear_mapping.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// This is the implementation for functions for linear_mapping
// See linear_mapping.h for documentations

struct matrix *proj_matrix(const struct vector *v) {
    assert(v);
    int dimension = get_dimension(v);
    struct matrix *m = matrix_create();
    double *a = malloc(dimension * sizeof(double));
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            if (j == i) {
                a[j] = 1;
            } else {
                a[j] = 0;
            }
        }
        struct vector *standard = vector_create(dimension, a);
        struct vector *temp = proj(standard, v);
        add_col(temp, m);
    }
    return m;
}

struct matrix *rotation_matrix(double theta) {
    struct matrix *m = matrix_create();
    double *a1 = malloc(2 * sizeof(double));
    double *a2 = malloc(2 * sizeof(double));
    a1[0] = cos(theta);
    a1[1] = -sin(theta);
    a2[0] = sin(theta);
    a2[1] = cos(theta);
    struct vector *r1 = vector_create(2, a1);
    struct vector *r2 = vector_create(2, a2);
    add_row(r1, m);
    add_row(r2, m);
    return m;
}

struct matrix *reflection_matrix(const struct vector *n) {
    assert(n);
    int dimension = get_dimension(n);
    struct matrix *m = matrix_create();
    double *a = malloc(dimension * sizeof(double));
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            if (j == i) {
                a[j] = 1;
            } else {
                a[j] = 0;
            }
        }
        struct vector *standard = vector_create(dimension, a);
        struct vector *temp = subtract(standard, scale_mult(2, proj(standard, n)));
        add_col(temp, m);
    }
    return m;
}

struct vector *vector_rotation(double theta, const struct vector *v) {
    assert(v);
    assert(get_dimension(v) == 2);
    struct matrix *m = rotation_matrix(theta);
    struct vector *result = matrix_vector_mult(m, v);
    matrix_destroy(m);
    return result;
}

struct vector *vector_reflection(const struct vector *n, const struct vector *x) {
    assert(n);
    assert(x);
    assert(get_dimension(n) == get_dimension(x));
    struct matrix *m = reflection_matrix(n);
    struct vector *v = matrix_vector_mult(m, x);
    matrix_destroy(m);
    return v;
}
