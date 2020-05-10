// This is a simple test for the matrix of linear mapping module

#include "Chapter 6 - Eigenvectors and Diagonalization/matrix_of_linear_mapping.h"
#include <assert.h>
#include <stdio.h>

int main(void) {
    double a[3] = {-6, -2, 9};
    double b[3] = {-5, -1, 7};
    double c[3] = {-7, -2, 10};
    struct vector *v1 = vector_create(3, a);
    struct vector *v2 = vector_create(3, b);
    struct vector *v3 = vector_create(3, c);
    struct matrix *m1 = matrix_create();
    add_row(v1, m1);
    add_row(v2, m1);
    add_row(v3, m1);
    double d[3] = {1, 1, 1};
    double e[3] = {1, 0, 1};
    double f[3] = {1, 3, 2};
    struct vector *v4 = vector_create(3, d);
    struct vector *v5 = vector_create(3, e);
    struct vector *v6 = vector_create(3, f);
    struct sov *s1 = sov_create();
    add_to_sov(v6, s1);
    add_to_sov(v5, s1);
    add_to_sov(v4, s1);
    change_sov_span(true, s1);
    struct matrix *m2 = matrix_wrt_basis(m1, s1);
    // print_matrix(m2);

    double g[3] = {5, 0, -6};
    double h[3] = {0, 2, 0};
    double i[3] = {3, 0, -4};
    struct vector *v7 = vector_create(3, g);
    struct vector *v8 = vector_create(3, h);
    struct vector *v9 = vector_create(3, i);
    struct matrix *m3 = matrix_create();
    add_row(v7, m3);
    add_row(v8, m3);
    add_row(v9, m3);
    double j[3] = {2, -1, -1};
    double k[3] = {1, 1, 1};
    double l[3] = {0, 0, -1};
    struct vector *v10 = vector_create(3, j);
    struct vector *v11 = vector_create(3, k);
    struct vector *v12 = vector_create(3, l);
    struct sov *s2 = sov_create();
    add_to_sov(v12, s2);
    add_to_sov(v11, s2);
    add_to_sov(v10, s2);
    change_sov_span(true, s2);
    struct matrix *m4 = matrix_wrt_basis(m3, s2);
    // print_matrix(m4);

    assert(trace(m1) == 3);
    assert(trace(m3) == 3);

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
    vector_destroy(v11);
    vector_destroy(v12);
    matrix_destroy(m1);
    matrix_destroy(m2);
    matrix_destroy(m3);
    matrix_destroy(m4);
    sov_destroy(s1);
    sov_destroy(s2);
}