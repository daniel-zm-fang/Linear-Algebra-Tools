#include "eigenvalues_and_eigenvectors.h"
#include <assert.h>
#include <math.h>
#include <stdlib.h>

// This is the implementation of functions regarding eigenvalues and eigenvectors
// See eigenvalues_and_eigenvectors.h for documentations

bool is_eigenvector(const struct matrix *m, const struct vector *v) {
    assert(m);
    assert(v);
    assert(num_aug_cols(m) == 0);
    assert(get_vector_dimension(v) == num_rows(m));
    assert(num_rows(m) == num_cols(m));
    struct vector *temp = matrix_vector_mult(m, v);
    bool result = false;
    if (are_vectors_scalar_multiples(v, temp)) {
        result = true;
    }
    vector_destroy(temp);
    return result;
}

double eigenvalue(const struct matrix *m, const struct vector *v) {
    assert(m);
    assert(v);
    assert(num_aug_cols(m) == 0);
    assert(is_eigenvector(m, v));
    struct vector *temp = matrix_vector_mult(m, v);
    double ratio = vector_get_val(0, temp) / vector_get_val(0, v);
    vector_destroy(temp);
    return ratio;
}

bool is_eigenvalue(const struct matrix *m, double x) {
    assert(m);
    assert(num_aug_cols(m) == 0);
    assert(num_rows(m) == num_cols(m));
    struct matrix *temp1 = matrix_copy(m);
    struct matrix *temp2 = identity_matrix(num_rows(m));
    struct matrix *temp3 = matrix_scalar_mult(-x, temp2);
    struct matrix *temp4 = matrix_add(temp1, temp3);
    double det = determinant(temp4);
    matrix_destroy(temp1);
    matrix_destroy(temp2);
    matrix_destroy(temp3);
    matrix_destroy(temp4);
    if (det) {
        return false;
    } else {
        return true;
    }
}

struct sov *eigenvectors(const struct matrix *m, double x) {
    assert(m);
    assert(num_aug_cols(m) == 0);
    assert(num_rows(m) == num_cols(m));
    assert(is_eigenvalue(m, x));
    struct matrix *temp1 = matrix_copy(m);
    struct matrix *temp2 = identity_matrix(num_rows(m));
    struct matrix *temp3 = matrix_scalar_mult(-x, temp2);
    struct matrix *temp4 = matrix_add(temp1, temp3);
    gauss_jordan_elimination(temp4);
    struct sov *result = find_solution(temp4);
    matrix_destroy(temp1);
    matrix_destroy(temp2);
    matrix_destroy(temp3);
    matrix_destroy(temp4);
    return result;
}

int *all_eigenvalues(const struct matrix *m) {
    assert(m);
    assert(num_aug_cols(m) == 0);
    assert(num_rows(m) == num_cols(m));
    int det = fabs(floor(determinant(m)));
    int *a = malloc(det * sizeof(int));
    int count = 0;
    for (int i = -det; i <= det; ++i) {
        if (i != 0 && det % i == 0 && is_eigenvalue(m, i)) {
            a[count] = i;
            count += 1;
        }
    }
    return a;
}

struct sov **all_eigenvectors(const struct matrix *m) {
    assert(m);
    assert(num_aug_cols(m) == 0);
    assert(num_rows(m) == num_cols(m));
    int *eigenval = all_eigenvalues(m);
    int length = sizeof(eigenval) / sizeof(int);
    struct sov **a = malloc(length * sizeof(struct sov *));
    for (int i = 0; i < length; i++) {
        struct sov *temp = eigenvectors(m, eigenval[i]);
        a[i] = temp;
    }
    free(eigenval);
    return a;
}

int geometric_multiplicity(const struct matrix *m, int x) {
    assert(m);
    assert(num_rows(m) == num_cols(m));
    assert(num_aug_cols(m) == 0);
    assert(is_eigenvalue(m, x));
    struct sov *temp = eigenvectors(m, x);
    int geo = get_num_vectors(temp);
    sov_destroy(temp);
    return geo;
}