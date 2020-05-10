// This is a simple test for the matrix of eigenvalues and eigenvectors module

#include "Chapter 6 - Eigenvectors and Diagonalization/eigenvalues_and_eigenvectors.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    double a[3] = {1, 6, 3};
    double b[3] = {0, -2, 0};
    double c[3] = {3, 6, 1};
    double f[3] = {-2, 1, 0};
    double g[3] = {-5, 1, 3};
    struct vector *v1 = vector_create(3, a);
    struct vector *v2 = vector_create(3, b);
    struct vector *v3 = vector_create(3, c);
    struct vector *v6 = vector_create(3, f);
    struct vector *v7 = vector_create(3, g);
    struct matrix *m1 = matrix_create();
    add_row(v1, m1);
    add_row(v2, m1);
    add_row(v3, m1);
    assert(!is_eigenvector(m1, v1));
    assert(is_eigenvector(m1, v6));
    assert(eigenvalue(m1, v6) == -2);
    assert(eigenvalue(m1, v7) == -2);
    assert(is_eigenvalue(m1, -2));
    assert(is_eigenvalue(m1, 4));
    struct sov *s1 = eigenvectors(m1, -2);
    // print_sov(s1);
    struct sov *s2 = eigenvectors(m1, 4);
    // print_sov(s2);

    double d[2] = {-4, 3};
    double e[2] = {2, 1};
    double h[2] = {3, 6};
    struct vector *v4 = vector_create(2, d);
    struct vector *v5 = vector_create(2, e);
    struct vector *v8 = vector_create(2, h);
    struct matrix *m2 = matrix_create();
    add_row(v4, m2);
    add_row(v5, m2);
    assert(!is_eigenvector(m2, v4));
    assert(!is_eigenvector(m2, v5));
    assert(is_eigenvector(m2, v8));
    assert(!is_eigenvalue(m2, 4));
    assert(is_eigenvalue(m2, 2));
    assert(is_eigenvalue(m2, -5));
    struct sov *s3 = eigenvectors(m2, 2);
    // print_sov(s3);
    struct sov *s4 = eigenvectors(m2, -5);
    // print_sov(s4);

    int *x = all_eigenvalues(m2);
    int length = sizeof(x) / sizeof(int);
    for (int i = 0; i < length; ++i) {
        // printf("%d\n", x[i]);
    }

    struct sov **ss = all_eigenvectors(m2);
    for (int i = 0; i < 2; ++i) {
        // print_sov(ss[i]);
    }

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
    sov_destroy(s1);
    sov_destroy(s2);
    sov_destroy(s3);
    sov_destroy(s4);
    free(x);
    for (int i = 0; i < 2; ++i) {
        sov_destroy(ss[i]);
    }
}