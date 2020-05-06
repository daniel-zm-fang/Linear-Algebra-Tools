#include "coordinates.h"
#include <assert.h>
#include <stdlib.h>

// This is the implementation of functions that concern with coordinates of vectors/set_of_matrices
// See coordinates.h for documentations

struct vector *coord_vector_wrt_basis_of_vectors(const struct vector *v, const struct sov *s) {
    assert(v);
    assert(s);
    int n = get_num_vectors(s);
    assert(n > 0);
    int d = get_vector_dimension(v);
    assert(d > 0);
    assert(d == get_vector_dimension(get_vector(0, s)));
    assert(is_sov_basis(s, d));

    struct matrix *temp = sov_to_matrix(s);
    add_col(v, temp);
    change_augmented_col(1, temp);
    gauss_jordan_elimination(temp);
    struct vector *solution = get_col(num_cols(temp) - 1, temp);
    matrix_destroy(temp);
    return solution;
}

struct vector *coord_vector_wrt_basis_of_matrices(const struct matrix *m, const struct som *s) {
    assert(m);
    assert(s);
    int n = get_num_matrices(s);
    assert(n > 0);
    int r = num_rows(m);
    int c = num_cols(m);
    assert(r > 0);
    assert(c > 0);
    assert(r == num_rows(get_matrix(0, s)));
    assert(c == num_cols(get_matrix(0, s)));
    assert(is_som_basis(s, r, c));

    struct matrix *temp = som_to_matrix(s);
    double *a = malloc(r * c * sizeof(double));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            a[i * r + j] = matrix_get_val(i, j, m);
        }
    }
    add_col(vector_create(r * c, a), temp);
    change_augmented_col(1, temp);
    gauss_jordan_elimination(temp);
    struct vector *solution = get_col(num_cols(temp) - 1, temp);
    matrix_destroy(temp);
    return solution;
}

struct matrix *change_of_coord_matrix(const struct sov *from, const struct sov *to) {
    assert(from);
    assert(to);
    int n = get_num_vectors(from);
    assert(n > 0);
    assert(n == get_num_vectors(to));
    int d = get_vector_dimension(get_vector(0, from));
    assert(d == get_vector_dimension(get_vector(0, to)));
    assert(is_sov_basis(from, d));
    assert(is_sov_basis(to, d));

    struct matrix *m1 = sov_to_matrix(from);
    struct matrix *m2 = sov_to_matrix(to);
    for (int i = 0; i < n; ++i) {
        add_col(get_col(i, m1), m2);
    }
    change_augmented_col(n, m2);
    gauss_jordan_elimination(m2);
    struct matrix *solution = matrix_create();
    for (int i = 0; i < n; ++i) {
        add_col(get_col(n + i, m2), solution);
    }
    matrix_destroy(m1);
    matrix_destroy(m2);
    return solution;
}