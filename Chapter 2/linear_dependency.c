#include "linear_dependency.h"
#include <assert.h>

bool is_linearly_independent(const struct sov *s) {
    assert(s);
    struct matrix *m = matrix_create();
    int num = get_num_vector(s);
    for (int i = 0; i < num; i++) {
        add_col(get_vector(i, s), m);
    }
    gauss_jordan_elimination(m);
    int rank = get_rank(m);
    if (rank == num) {
        return true;
    } else {
        return false;
    }
}

void make_linearly_independent(struct sov *s) {
    assert(s);
    if (is_linearly_independent(s)) {
        return;
    }
    int num_of_vectors = get_num_vector(s);
    int dimension = get_dimension(get_vector(0, s));
    for (int i = 0; i < num_of_vectors; i++) {
        for (int j = i; j < num_of_vectors; j++) {
            struct vector *v1 = get_vector(i, s);
            struct vector *v2 = get_vector(j, s);
            double ratio = vector_get_val(0, v1) / vector_get_val(0, v2);
            for (int count = 0; count < dimension; count++) {
                double quotient = vector_get_val(count, v1) / vector_get_val(count, v2);
                if (quotient != ratio) {
                    break;
                }
            }
            remove_from_set(v1, s);
            i -= 1;
            j -= 1;
        }
    }
}