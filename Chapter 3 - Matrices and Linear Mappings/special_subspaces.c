#include "special_subspaces.h"
#include <assert.h>
#include <stdlib.h>

// This is the implementation of functions of speical subspaces
// See special_subspaces.h for documentations

bool is_in_nullspace(const struct vector *v, const struct matrix *m) {
    assert(v);
    assert(m);
    assert(num_aug_cols(m) == 0);
    if (get_vector_dimension(v) != num_cols(m)) {
        return false;
    }
    struct vector *temp_v = matrix_vector_mult(m, v);
    if (is_zero_vector(temp_v)) {
        return true;
    }
    return false;
}

bool is_in_column_space(const struct vector *v, const struct matrix *m) {
    assert(v);
    assert(m);
    assert(num_aug_cols(m) == 0);
    if (get_vector_dimension(v) != num_rows(m)) {
        return false;
    }
    struct matrix *temp_m = matrix_copy(m);
    struct matrix *temp_m2 = matrix_copy(m);
    add_col(v, temp_m);
    gauss_jordan_elimination(temp_m);
    gauss_jordan_elimination(temp_m2);
    bool result = false;
    if (get_free_var(temp_m) != get_free_var(temp_m2)) {
        // if linearly dependent, then vector is part of span
        result = true;
    }
    matrix_destroy(temp_m);
    matrix_destroy(temp_m2);
    return result;
}

bool is_in_row_space(const struct vector *v, const struct matrix *m) {
    assert(v);
    assert(m);
    assert(num_aug_cols(m) == 0);
    if (get_vector_dimension(v) != num_cols(m)) {
        return false;
    }
    struct matrix *temp_m = transpose(m);
    struct matrix *temp_m2 = matrix_copy(temp_m);
    add_col(v, temp_m2);
    gauss_jordan_elimination(temp_m);
    gauss_jordan_elimination(temp_m2);
    bool result = false;
    if (get_free_var(temp_m) != get_free_var(temp_m2)) {
        // if linearly dependent, then vector is part of span
        result = true;
    }
    matrix_destroy(temp_m);
    matrix_destroy(temp_m2);
    return result;
}

bool is_in_left_nullspace(const struct vector *v, const struct matrix *m) {
    assert(v);
    assert(m);
    assert(num_aug_cols(m) == 0);
    if (get_vector_dimension(v) != num_rows(m)) {
        return false;
    }
    struct matrix *temp_m = transpose(m);
    struct vector *temp_v = matrix_vector_mult(temp_m, v);
    bool result = true;
    if (!is_zero_vector(temp_v)) {
        result = false;
    }
    matrix_destroy(temp_m);
    return result;
}

struct sov *find_nullspace(const struct matrix *m) {
    assert(m);
    assert(num_aug_cols(m) == 0);
    struct sov *result = find_solution(m);
    return result;
}

struct sov *find_column_space(const struct matrix *m) {
    assert(m);
    assert(num_aug_cols(m) == 0);
    struct sov *temp = sov_create();
    for (int i = 0; i < num_cols(m); i++) {
        add_to_sov(get_col(i, m), temp);
    }
    make_sov_linearly_independent(temp);
    return temp;
}

struct sov *find_row_space(const struct matrix *m) {
    assert(m);
    assert(num_aug_cols(m) == 0);
    struct sov *temp = sov_create();
    for (int i = 0; i < num_rows(m); i++) {
        add_to_sov(get_row(i, m), temp);
    }
    make_sov_linearly_independent(temp);
    return temp;
}

struct sov *find_left_nullspace(const struct matrix *m) {
    assert(m);
    assert(num_aug_cols(m) == 0);
    struct matrix *temp = matrix_copy(m);
    struct matrix *temp2 = transpose(temp);
    gauss_jordan_elimination(temp2);
    struct sov *result = find_solution(temp2);
    matrix_destroy(temp);
    matrix_destroy(temp2);
    return result;
}