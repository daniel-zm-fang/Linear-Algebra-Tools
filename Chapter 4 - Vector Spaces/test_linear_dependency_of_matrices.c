// This is a simple test for the linear dependency of matrices module

#include "linear_dependency_of_matrices.h"
#include <assert.h>
#include <stdio.h>

int main(void) {
    double a[2] = {1, 1};
    double b[2] = {0, 1};
    double c[2] = {1, 2};
    double d[2] = {0, -1};
    double e[2] = {1, 3};
    double f[2] = {0, 2};
    struct vector *v1 = vector_create(2, a);
    struct vector *v2 = vector_create(2, b);
    struct vector *v3 = vector_create(2, c);
    struct vector *v4 = vector_create(2, d);
    struct vector *v5 = vector_create(2, e);
    struct vector *v6 = vector_create(2, f);
    struct matrix *m1 = matrix_create();
    add_row(v1, m1);
    add_row(v2, m1);
    struct matrix *m2 = matrix_create();
    add_row(v3, m2);
    add_row(v4, m2);
    struct matrix *m3 = matrix_create();
    add_row(v5, m3);
    add_row(v6, m3);
    struct som *s1 = som_create();
    add_to_som(m1, s1);
    add_to_som(m2, s1);
    add_to_som(m3, s1);
    // print_som(s1);
    assert(is_som_linearly_independent(s1));
    make_som_linearly_independent(s1);
    // print_som(s1);

    double g[2] = {0, 0};
    double h[2] = {1, 0};
    struct vector *v7 = vector_create(2, g);
    struct vector *v8 = vector_create(2, h);
    struct matrix *m4 = matrix_create();
    add_row(v1, m4);
    add_row(v7, m4);
    struct matrix *m5 = matrix_create();
    add_row(v8, m5);
    add_row(v2, m5);
    struct matrix *m6 = matrix_create();
    add_row(v7, m6);
    add_row(v1, m6);
    struct som *s2 = som_create();
    add_to_som(m4, s2);
    add_to_som(m5, s2);
    add_to_som(m6, s2);
    // print_som(s2);
    assert(is_som_linearly_independent(s2));
    make_som_linearly_independent(s2);
    // print_som(s2);

    double i[2] = {2, 4};
    struct vector *v9 = vector_create(2, i);
    struct matrix *m7 = matrix_create();
    add_row(v9, m7);
    add_row(v9, m7);
    struct matrix *m8 = matrix_create();
    add_row(v7, m8);
    add_row(v7, m8);
    struct matrix *m9 = matrix_create();
    add_row(v3, m9);
    add_row(v3, m9);
    struct som *s3 = som_create();
    add_to_som(m7, s3);
    add_to_som(m8, s3);
    add_to_som(m9, s3);
    // print_som(s3);
    assert(!is_som_linearly_independent(s3));
    make_som_linearly_independent(s3);
    // print_som(s3);

    struct som *s4 = som_create();
    change_som_span(true, s4);
    // print_som(s4);
    assert(is_som_linearly_independent(s4));
    assert(is_som_span(s4, 0, 0));
    assert(is_som_basis(s4, 0, 0));

    double j[2] = {3, 4};
    double k[2] = {5, 6};
    double l[2] = {7, 8};
    double m[2] = {9, 0};
    struct vector *v10 = vector_create(2, j);
    struct vector *v11 = vector_create(2, k);
    struct vector *v12 = vector_create(2, l);
    struct vector *v13 = vector_create(2, m);
    struct matrix *m10 = matrix_create();
    add_row(v3, m10);
    add_row(v10, m10);
    struct matrix *m11 = matrix_create();
    add_row(v11, m11);
    add_row(v12, m11);
    struct matrix *m12 = matrix_create();
    add_row(v13, m12);
    add_row(v3, m12);
    struct som *s5 = som_create();
    add_to_som(m10, s5);
    add_to_som(m11, s5);
    add_to_som(m12, s5);
    change_som_span(true, s5);
    // print_som(s5);

    assert(is_som_linearly_independent(s5));
    assert(!is_som_span(s5, 2, 2));
    assert(!is_som_basis(s5, 0, 0));

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
    matrix_destroy(m11);
    matrix_destroy(m12);
    som_destroy(s1);
    som_destroy(s2);
    som_destroy(s3);
    som_destroy(s4);
    som_destroy(s5);
}