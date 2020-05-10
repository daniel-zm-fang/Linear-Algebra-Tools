#include "matrix_of_linear_mapping.h"
#include <assert.h>

// This is the implementation of functions of determinants
// See determinants.h for documentations

struct matrix *matrix_wrt_basis(const struct matrix *m, const struct sov *s) {
    assert(m);
    assert(s);
    int n = get_num_vectors(s);
    assert(n == num_rows(m));
    assert(n == num_cols(m));
    assert(num_aug_cols(m) == 0);
    assert(is_sov_basis(s, n));
    struct matrix *basis_matrix = matrix_create();
    for (int i = 0; i < n; ++i) {
        struct vector *transformed_basis_v = matrix_vector_mult(m, get_vector(i, s));
        struct matrix *basis_m = sov_to_matrix(s);
        add_col(transformed_basis_v, basis_m);
        change_augmented_col(1, basis_m);
        gauss_jordan_elimination(basis_m);
        add_col(get_col(n, basis_m), basis_matrix);
        vector_destroy(transformed_basis_v);
        matrix_destroy(basis_m);
    }
    return basis_matrix;
}

bool diagonal_matrix(const struct matrix *m) {
    assert(m);
    assert(num_aug_cols(m) == 0);
    assert(num_rows(m) == num_cols(m));
    return is_lower_triangular(m) && is_upper_triangular(m);
}

double trace(const struct matrix *m) {
    assert(m);
    assert(num_aug_cols(m) == 0);
    assert(num_rows(m) == num_cols(m));
    double sum = 0;
    for (int i = 0; i < num_rows(m); ++i) {
        sum += matrix_get_val(i, i, m);
    }
    return sum;
}