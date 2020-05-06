// This is a simple test for matrix operations module

#include "matrix_operations.h"
#include <assert.h>
#include <stdio.h>

int main(void) {
    double c = -1;
    double a[4] = {1, 2, 3, 4};
    double b[4] = {5, 6, 7, 8};
    double d[2] = {1, 2};
    double e[4] = {11, 14, 17, 20};
    double f[2] = {170, 418};
    double g[3] = {1, 3, 2};
    double h[3] = {-1, 0, -3};
    double i[3] = {-2, -4, 0};
    double j[3] = {4, 5, 0};

    struct vector *v1 = vector_create(4, a);
    struct vector *v2 = vector_create(4, b);
    struct vector *v3 = vector_create(2, d);
    struct vector *v5 = vector_create(4, e);
    struct vector *v7 = vector_create(3, g);
    struct vector *v8 = vector_create(3, h);
    struct vector *v9 = vector_create(3, i);
    struct vector *v10 = vector_create(3, j);

    struct matrix *m1 = matrix_create();
    add_row(v1, m1);
    add_row(v2, m1);
    struct matrix *m2 = matrix_add(m1, m1);
    // print_matrix(m1);
    // print_matrix(m2);
    struct matrix *m3 = matrix_scalar_mult(c, m1);
    // print_matrix(m3);
    struct matrix *m4 = transpose(m1);
    // print_matrix(m4);
    struct vector *v4 = matrix_vector_mult(m4, v3);
    assert(vectors_equal(v4, v5));
    struct vector *v6 = matrix_vector_mult(m1, v5);
    assert(vectors_equal(v6, matrix_vector_mult(m1, v5)));

    struct matrix *m5 = matrix_create();
    struct matrix *m6 = matrix_create();
    add_row(v7, m5);
    add_row(v8, m5);
    add_col(v9, m6);
    add_col(v10, m6);
    struct matrix *m7 = matrix_matrix_mult(m5, m6);
    // print_matrix(m7);
    struct matrix *m8 = matrix_matrix_mult(m6, m5);
    // print_matrix(m8);

    matrix_destroy(m1);
    matrix_destroy(m2);
    matrix_destroy(m3);
    matrix_destroy(m4);
    matrix_destroy(m5);
    matrix_destroy(m6);
    matrix_destroy(m7);
    matrix_destroy(m8);
    vector_destroy(v1);
    vector_destroy(v2);
    vector_destroy(v3);
    vector_destroy(v4);
    vector_destroy(v5);
    vector_destroy(v6);
    vector_destroy(v7);
    vector_destroy(v8);
    vector_destroy(v9);
    vector_destroy(v10);
}