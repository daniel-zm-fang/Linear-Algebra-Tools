// This is a simple test for matrix module

#include "matrix.h"
#include <assert.h>
#include <stdio.h>

int main(void) {
    double a[3] = {2, 2, 3};
    double b[3] = {1, -13, 9};
    double c[3] = {-10, 7, 2};
    double d[1] = {0};
    double e[3] = {0, 0, 0};
    double f[3] = {0, -2, 3};
    double g[3] = {1, 4, -9};
    double h[5] = {-1, 9, 8, 11, 13};
    double i[5] = {31, 7, 8, 0, -17};
    double j[5] = {0, 5, 8, -11, 23};

    struct vector *v1 = vector_create(3, a);
    struct vector *v2 = vector_create(3, b);
    struct vector *v3 = vector_create(3, c);
    struct vector *v6 = vector_create(1, d);
    struct vector *v8 = vector_create(3, e);
    struct vector *v9 = vector_create(3, f);
    struct vector *v10 = vector_create(3, g);
    struct vector *v11 = vector_create(5, h);
    struct vector *v12 = vector_create(5, i);
    struct vector *v13 = vector_create(5, j);

    struct matrix *m1 = matrix_create();
    // print_matrix(m1);
    assert(is_empty(m1));
    add_row(v1, m1);
    assert(!is_empty(m1));
    struct vector *v4 = get_row(0, m1);
    assert(vectors_equal(v4, v1));
    add_row(v2, m1);
    add_row(v3, m1);
    assert(!is_rref(m1));
    // print_matrix(m1);
    change_augmented_col(1, m1);
    // print_matrix(m1);
    struct vector *v5 = get_row(1, m1);
    assert(vectors_equal(v5, v2));
    struct vector *v7 = get_col(2, m1);
    // print_vector(v7);
    gauss_jordan_elimination(m1);
    assert(get_rank(m1) == 2);
    assert(get_free_var(m1) == 0);
    // print_matrix(m1);
    assert(find_solution(m1) == NULL);
    matrix_destroy(m1);

    struct matrix *m2 = matrix_create();
    add_row(v6, m2);
    add_row(v6, m2);
    add_row(v6, m2);
    assert(is_zero_matrix(m2));
    add_col(v1, m2);
    add_col(v3, m2);
    // print_matrix(m2);
    gauss_jordan_elimination(m2);
    assert(get_rank(m2) == 2);
    assert(get_free_var(m2) == 1);
    // print_matrix(m2);
    struct sov *s1 = find_solution(m2);
    // print_sov(s1);
    matrix_destroy(m2);
    sov_destroy(s1);

    struct matrix *m3 = matrix_create();
    add_col(v8, m3);
    add_col(v9, m3);
    add_col(v10, m3);
    change_augmented_col(2, m3);
    assert(is_rref(m3));
    // print_matrix(m3);
    gauss_jordan_elimination(m3);
    is_rref(m3);
    assert(get_rank(m3) == 0);
    assert(get_free_var(m3) == 1);
    // print_matrix(m3);
    matrix_destroy(m3);

    struct matrix *m4 = matrix_create();
    add_row(v11, m4);
    add_row(v12, m4);
    add_row(v13, m4);
    assert(!is_rref(m4));
    // print_matrix(m4);
    gauss_jordan_elimination(m4);
    // print_matrix(m4);
    assert(is_rref(m4));
    assert(get_rank(m4) == 3);
    assert(get_free_var(m4) == 2);
    struct sov *s2 = find_solution(m4);
    // print_sov(s2);
    matrix_destroy(m4);
    sov_destroy(s2);

    struct matrix *m5 = matrix_create();
    add_row(v1, m5);
    add_row(v8, m5);
    add_row(v1, m5);
    add_row(v8, m5);
    change_augmented_col(1, m5);
    assert(!is_rref(m5));
    // print_matrix(m5);
    gauss_jordan_elimination(m5);
    assert(is_rref(m5));
    assert(get_rank(m5) == 1);
    assert(get_free_var(m5) == 1);
    // print_matrix(m5);
    struct sov *s3 = find_solution(m5);
    // print_sov(s3);
    sov_destroy(s3);
    matrix_destroy(m5);

    struct matrix *m6 = matrix_create();
    add_col(v11, m6);
    struct matrix *m7 = matrix_copy(m6);
    // print_matrix(m7);
    matrix_destroy(m7);

    gauss_jordan_elimination(m6);
    // print_matrix(m6);
    struct sov *s4 = find_solution(m6);
    // print_sov(s4);
    sov_destroy(s4);
    matrix_destroy(m6);

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
}