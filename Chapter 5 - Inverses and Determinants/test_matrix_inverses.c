// This is a simple test for matrix inverses module
// note: we can't use matrices_equal to check the results of left_inverse
//  and right_inverse because there are infinite left/right inverses if they exist

#include "matrix_inverses.h"
#include <assert.h>
#include <stdio.h>

int main(void) {
    double a[3] = {1, 2, 2};
    double b[3] = {-1, 3, 1};
    double c[3] = {0.6, 0.2, 0};
    double d[3] = {-0.4, 0.2, 0};
    struct vector *v1 = vector_create(3, a);
    struct vector *v2 = vector_create(3, b);
    struct vector *v3 = vector_create(3, c);
    struct vector *v4 = vector_create(3, d);
    struct matrix *m1 = matrix_create();
    add_row(v1, m1);
    add_row(v2, m1);
    assert(!is_invertible(m1));
    assert(left_inverse(m1) == NULL);
    // print_matrix(m1);
    struct matrix *m2 = matrix_create();
    add_col(v3, m2);
    add_col(v4, m2);
    assert(!is_invertible(m2));
    assert(right_inverse(m2) == NULL);
    // print_matrix(m2);
    struct matrix *m3 = right_inverse(m1);
    // print_matrix(m3);
    struct matrix *m4 = left_inverse(m2);
    // print_matrix(m4);

    double e[2] = {3, -1};
    double f[2] = {-2, 1};
    double g[2] = {1, 1};
    double h[2] = {2, 3};
    struct vector *v5 = vector_create(2, e);
    struct vector *v6 = vector_create(2, f);
    struct vector *v7 = vector_create(2, g);
    struct vector *v8 = vector_create(2, h);
    struct matrix *m5 = matrix_create();
    add_row(v5, m5);
    add_row(v6, m5);
    // print_matrix(m5);
    assert(is_invertible(m5));
    struct matrix *m6 = inverse(m5);
    // print_matrix(m6);
    struct matrix *m7 = matrix_create();
    add_row(v7, m7);
    add_row(v8, m7);
    assert(matrices_equal(m6, m7));

    double i[3] = {1, -2, 3};
    double j[3] = {-1, 4, 1};
    double k[3] = {1, -1, 4};
    double l[3] = {-8.5, -2.5, 7};
    double m[3] = {-2.5, -0.5, 2};
    double n[3] = {1.5, 0.5, -1};
    struct vector *v9 = vector_create(3, i);
    struct vector *v10 = vector_create(3, j);
    struct vector *v11 = vector_create(3, k);
    struct vector *v12 = vector_create(3, l);
    struct vector *v13 = vector_create(3, m);
    struct vector *v14 = vector_create(3, n);
    struct matrix *m8 = matrix_create();
    add_row(v9, m8);
    add_row(v10, m8);
    add_row(v11, m8);
    // print_matrix(m8);
    assert(is_invertible(m8));
    struct matrix *m9 = inverse(m8);
    // print_matrix(m9);
    struct matrix *m10 = matrix_create();
    add_row(v12, m10);
    add_row(v13, m10);
    add_row(v14, m10);
    assert(matrices_equal(m9, m10));
    struct matrix *m11 = inverse(m9);
    assert(matrices_equal(m8, m11));

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
    matrix_destroy(m1);
    matrix_destroy(m2);
    matrix_destroy(m3);
    matrix_destroy(m4);
    matrix_destroy(m5);
    matrix_destroy(m6);
    matrix_destroy(m7);
    matrix_destroy(m8);
    matrix_destroy(m9);
    matrix_destroy(m10);
}