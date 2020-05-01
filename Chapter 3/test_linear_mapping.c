// This is a simple test for linear mapping module

#include "Chapter 3/linear_mapping.h"
#include <assert.h>
#include <stdio.h>

int main(void) {
    double a[2] = {1, 2};
    double b[3] = {2, -1, -2};
    double c[3] = {1, 2, -3};
    double d[5] = {4, -3, 0, 1, -7};
    double e[4] = {1, 2, 2, 0};
    double f[4] = {1, 1, 1, 3};
    struct vector *v1 = vector_create(2, a);
    struct vector *v2 = vector_create(3, b);
    struct vector *v3 = vector_create(3, c);
    struct vector *v4 = vector_create(5, d);
    struct vector *v5 = vector_create(4, e);
    struct vector *v6 = vector_create(4, f);

    struct matrix *m1 = proj_matrix(v1);
    // print_matrix(m1);
    struct matrix *m2 = proj_matrix(v2);
    // print_matrix(m2);

    struct matrix *m3 = rotation_matrix(1);
    // print_matrix(m3);
    struct matrix *m4 = rotation_matrix(-5);
    // print_matrix(m4);

    struct matrix *m5 = reflection_matrix(v3);
    // print_matrix(m5);
    struct matrix *m6 = reflection_matrix(v4);
    // print_matrix(m6);

    struct vector *v7 = vector_rotation(1, v1);
    // print_vector(v5);

    struct vector *v8 = vector_reflection(v5, v6);
    // print_vector(v8);

    vector_destroy(v1);
    vector_destroy(v2);
    vector_destroy(v3);
    vector_destroy(v4);
    vector_destroy(v5);
    vector_destroy(v6);
    vector_destroy(v7);
    vector_destroy(v8);

    matrix_destroy(m1);
    matrix_destroy(m2);
    matrix_destroy(m3);
    matrix_destroy(m4);
    matrix_destroy(m5);
    matrix_destroy(m6);
}