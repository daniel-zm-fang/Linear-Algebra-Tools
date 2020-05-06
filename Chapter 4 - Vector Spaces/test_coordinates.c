// This is a simple test for the coordinates module

#include "coordinates.h"
#include <assert.h>
#include <stdio.h>

int main(void) {
    double a[2] = {3, 1};
    double b[2] = {1, 1};
    double c[2] = {1, -1};
    double d[2] = {2, 1};
    struct vector *v1 = vector_create(2, a);
    struct vector *v2 = vector_create(2, b);
    struct vector *v3 = vector_create(2, c);
    struct sov *s1 = sov_create();
    change_sov_span(true, s1);
    add_to_sov(v3, s1);
    add_to_sov(v2, s1);
    // print_sov(s1)
    assert(is_sov_basis(s1, 2));
    struct vector *v4 = coord_vector_wrt_basis_of_vectors(v1, s1);
    struct vector *v5 = vector_create(2, d);
    assert(vectors_equal(v4, v5));

    double e[2] = {0, -1};
    double f[2] = {1, 0};
    double g[2] = {0, 1};
    double h[2] = {1, 2};
    double i[2] = {2, -3};
    struct vector *v6 = vector_create(2, e);
    struct vector *v7 = vector_create(2, f);
    struct vector *v8 = vector_create(2, g);
    struct vector *v9 = vector_create(2, h);
    struct vector *v10 = vector_create(2, i);
    struct matrix *m1 = matrix_create();
    add_row(v2, m1);
    add_row(v6, m1);
    struct matrix *m2 = matrix_create();
    add_row(v7, m2);
    add_row(v2, m2);
    struct matrix *m3 = matrix_create();
    add_row(v8, m3);
    add_row(v9, m3);
    struct matrix *m4 = matrix_create();
    add_row(v10, m4);
    add_row(v8, m4);
    struct som *s2 = som_create();
    add_to_som(m4, s2);
    add_to_som(m3, s2);
    add_to_som(m2, s2);
    add_to_som(m1, s2);
    change_som_span(true, s2);
    // print_som(s2);
    assert(is_som_basis(s2, 2, 2));
    struct matrix *m5 = matrix_create();
    add_col(v9, m5);
    add_col(v1, m5);
    // print_matrix(m5);
    struct vector *v11 = coord_vector_wrt_basis_of_matrices(m5, s2);
    // print_vector(v11);

    double j[3] = {1, 0, 0};
    double k[3] = {0, 1, 0};
    double l[3] = {0, 0, 1};
    struct vector *v12 = vector_create(3, j);
    struct vector *v13 = vector_create(3, k);
    struct vector *v14 = vector_create(3, l);
    struct sov *s3 = sov_create();
    add_to_sov(v14, s3);
    add_to_sov(v13, s3);
    add_to_sov(v12, s3);
    change_sov_span(true, s3);
    // print_sov(s3);
    double m[3] = {1, 3, -1};
    double n[3] = {2, 1, 1};
    double o[3] = {3, 4, 1};
    struct vector *v15 = vector_create(3, m);
    struct vector *v16 = vector_create(3, n);
    struct vector *v17 = vector_create(3, o);
    struct sov *s4 = sov_create();
    add_to_sov(v17, s4);
    add_to_sov(v16, s4);
    add_to_sov(v15, s4);
    change_sov_span(true, s4);
    // print_sov(s4);
    struct matrix *s3_to_s4 = change_of_coord_matrix(s4, s3);
    // print_matrix(s3_to_s4);
    struct matrix *s4_to_s3 = change_of_coord_matrix(s3, s4);
    // print_matrix(s4_to_s3);
    struct matrix *identity = matrix_matrix_mult(s3_to_s4, s4_to_s3);
    // print_matrix(identity);

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
    matrix_destroy(m1);
    matrix_destroy(m2);
    matrix_destroy(m3);
    matrix_destroy(m4);
    matrix_destroy(m5);
    matrix_destroy(s3_to_s4);
    matrix_destroy(s4_to_s3);
    matrix_destroy(identity);
    sov_destroy(s1);
    sov_destroy(s3);
    sov_destroy(s4);
    som_destroy(s2);
}