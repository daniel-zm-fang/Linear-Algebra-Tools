// This is a simple test for special subspaces module

#include "special_subspaces.h"
#include <assert.h>
#include <stdio.h>

int main(void) {
    double a[3] = {1, 3, 2};
    double b[3] = {2, 5, 2};
    struct vector *v1 = vector_create(3, a);
    struct vector *v2 = vector_create(3, b);
    struct matrix *m1 = matrix_create();
    add_row(v1, m1);
    add_row(v2, m1);
    struct matrix *m2 = matrix_copy(m1);
    // print_matrix(m1);
    gauss_jordan_elimination(m1);
    // print_matrix(m1);
    assert(is_rref(m1));
    struct sov *s1 = find_nullspace(m1);
    struct sov *s2 = find_column_space(m1);
    struct sov *s3 = find_row_space(m1);
    struct sov *s4 = find_left_nullspace(m1);
    // printf("Nullspace:\n");
    // print_sov(s1);
    // printf("Column space:\n");
    // print_sov(s2);
    // printf("Row space\n");
    // print_sov(s3);
    // printf("Left null space\n");
    // print_sov(s4);

    double c[3] = {8, -4, 2};
    double d[3] = {0, 0, 0};
    double e[3] = {0, 0, 1};
    struct vector *v3 = vector_create(3, c);
    struct vector *v4 = vector_create(3, d);
    struct vector *v5 = vector_create(3, e);
    assert(is_in_nullspace(v3, m2));
    assert(is_in_nullspace(v4, m2));
    assert(!is_in_nullspace(v5, m2));

    double f[2] = {3, 5};
    double g[2] = {0, 0};
    double k[2] = {1, 1};
    struct vector *v6 = vector_create(2, f);
    struct vector *v7 = vector_create(2, g);
    struct vector *v10 = vector_create(2, k);
    assert(!is_in_column_space(v3, m2));
    assert(is_in_column_space(v6, m2));
    assert(is_in_column_space(v7, m2));
    assert(is_in_column_space(v10, m2));

    double h[3] = {1, 3, 2};
    double i[3] = {2, 5, 1};
    struct vector *v8 = vector_create(3, h);
    struct vector *v9 = vector_create(3, i);
    assert(is_in_row_space(v8, m2));
    assert(is_in_row_space(v4, m2));
    assert(!is_in_row_space(v9, m2));

    assert(!is_in_left_nullspace(v6, m2));
    assert(is_in_left_nullspace(v7, m2));

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
    matrix_destroy(m1);
    matrix_destroy(m2);
    sov_destroy(s1);
    sov_destroy(s2);
    sov_destroy(s3);
    sov_destroy(s4);
}