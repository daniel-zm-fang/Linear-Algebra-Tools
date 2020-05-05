// This is a simple test for set of matrices module

#include "Chapter 4/set_of_matrices.h"
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
    add_to_matrices_set(m1, s1);
    add_to_matrices_set(m2, s1);
    add_to_matrices_set(m3, s1);
    // print_som(s1);

    struct som *s2 = dup_som(s1);
    // print_som(s2);
    assert(matrices_sets_equal(s1, s2));

    remove_from_matrices_set(m1, s1);
    remove_from_matrices_set(m2, s1);
    remove_from_matrices_set(m3, s1);
    // print_som(s1);
    remove_from_matrices_set(m1, s2);
    remove_from_matrices_set(m1, s2);
    remove_from_matrices_set(m1, s2);
    // print_som(s2);
    assert(matrices_sets_equal(s1, s2));

    vector_destroy(v1);
    vector_destroy(v2);
    vector_destroy(v3);
    vector_destroy(v4);
    vector_destroy(v5);
    vector_destroy(v6);
    som_destroy(s1);
    som_destroy(s2);
    matrix_destroy(m1);
    matrix_destroy(m2);
    matrix_destroy(m3);
}