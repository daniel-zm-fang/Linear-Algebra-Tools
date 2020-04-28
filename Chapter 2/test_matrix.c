// This is a simple test for matrix module

#include "Chapter 2/matrix.h"
#include <assert.h>
#include <stdio.h>

int main(void) {
    double a[3] = {2, 2, 3};
    double b[3] = {1, -13, 9};
    double c[3] = {-10, 7, 2};
    double d[1] = {0};

    struct vector *v1 = vector_create(3, a);
    struct vector *v2 = vector_create(3, b);
    struct vector *v3 = vector_create(3, c);
    struct vector *v6 = vector_create(1, d);

    struct matrix *m1 = matrix_create(false);
    // print_matrix(m1);
    assert(is_empty(m1));

    add_row(v1, m1);
    assert(!is_empty(m1));
    struct vector *v4 = get_row(0, m1);
    assert(vectors_equal(v4, v1));

    add_row(v2, m1);
    add_row(v3, m1);
    print_matrix(m1);

    struct vector *v5 = get_row(1, m1);
    assert(vectors_equal(v5, v2));
    struct vector *v7 = get_col(2, m1);
    // print_vector(v7);

    gauss_jordan_elimination(m1);
    print_matrix(m1);

    struct matrix *m2 = matrix_create(false);
    add_row(v6, m2);
    add_row(v6, m2);
    add_row(v6, m2);
    assert(is_zero_matrix(m2));
    add_col(v1, m2);
    add_col(v3, m2);
    // print_matrix(m2);

    matrix_destroy(m1);
    matrix_destroy(m2);

    vector_destroy(v1);
    vector_destroy(v2);
    vector_destroy(v3);
    vector_destroy(v4);
    vector_destroy(v5);
    vector_destroy(v6);
}