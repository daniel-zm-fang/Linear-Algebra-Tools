// This is a simple test for the elementary matrices module

#include "elementary_matrices.h"
#include <assert.h>
#include <stdio.h>

int main(void) {
    double a[3] = {1, 0, 2};
    double b[3] = {0, 1, 0};
    double c[3] = {0, 0, 1};
    struct vector *v1 = vector_create(3, a);
    struct vector *v2 = vector_create(3, b);
    struct vector *v3 = vector_create(3, c);
    struct matrix *m1 = matrix_create();
    add_row(v1, m1);
    add_row(v2, m1);
    add_row(v3, m1);
    assert(is_elementary_matrix(m1) == 2);

    double d[2] = {0, 1};
    double e[2] = {1, 0};
    struct vector *v4 = vector_create(2, d);
    struct vector *v5 = vector_create(2, e);
    struct matrix *m2 = matrix_create();
    add_row(v4, m2);
    add_row(v5, m2);
    assert(is_elementary_matrix(m2) == 3);

    double f[3] = {3, 0, 0};
    double g[3] = {0, 3, 0};
    double h[3] = {0, 0, 3};
    struct vector *v6 = vector_create(3, f);
    struct vector *v7 = vector_create(3, g);
    struct vector *v8 = vector_create(3, h);
    struct matrix *m3 = matrix_create();
    add_row(v6, m3);
    add_row(v7, m3);
    add_row(v8, m3);
    assert(is_elementary_matrix(m3) == 0);

    double i[3] = {-1, 0, 0};
    struct vector *v9 = vector_create(3, i);
    struct matrix *m4 = matrix_create();
    add_row(v9, m4);
    add_row(v2, m4);
    add_row(v3, m4);
    assert(is_elementary_matrix(m4) == 1);

    double j[4] = {0, 0, 0, 1};
    double k[4] = {1, 0, 0, 0};
    double l[4] = {0, 1, 0, 1};
    double m[4] = {0, 0, 0, 1};
    struct vector *v10 = vector_create(4, j);
    struct vector *v11 = vector_create(4, k);
    struct vector *v12 = vector_create(4, l);
    struct vector *v13 = vector_create(4, m);
    struct matrix *m5 = matrix_create();
    add_row(v10, m5);
    add_row(v11, m5);
    add_row(v12, m5);
    add_row(v13, m5);
    assert(is_elementary_matrix(m5) == 0);

    double n[2] = {-3, 1};
    double o[2] = {0, -2};
    double p[2] = {1, 3};
    double q[2] = {0, 1};
    double r[2] = {19, -6};
    double s[2] = {6, -2};
    struct vector *v14 = vector_create(2, n);
    struct vector *v15 = vector_create(2, o);
    struct vector *v16 = vector_create(2, p);
    struct vector *v17 = vector_create(2, q);
    struct vector *v18 = vector_create(2, r);
    struct vector *v19 = vector_create(2, s);
    struct matrix *m6 = matrix_create();
    add_row(v5, m6);
    add_row(v14, m6);
    struct matrix *m7 = matrix_create();
    add_row(v5, m7);
    add_row(v15, m7);
    struct matrix *m8 = matrix_create();
    add_row(v16, m8);
    add_row(v17, m8);
    struct som *s1 = som_create();
    add_to_som(m6, s1);
    add_to_som(m7, s1);
    add_to_som(m8, s1);
    struct matrix *product = matrices_mult(s1);
    struct matrix *m9 = matrix_create();
    add_row(v18, m9);
    add_row(v19, m9);
    assert(matrices_equal(product, m9));

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
    vector_destroy(v13);
    vector_destroy(v14);
    vector_destroy(v15);
    vector_destroy(v16);
    vector_destroy(v17);
    vector_destroy(v18);
    vector_destroy(v19);
    matrix_destroy(m1);
    matrix_destroy(m2);
    matrix_destroy(m3);
    matrix_destroy(m4);
    matrix_destroy(m5);
    matrix_destroy(m6);
    matrix_destroy(m7);
    matrix_destroy(m8);
    matrix_destroy(product);
    matrix_destroy(m9);
    som_destroy(s1);
}