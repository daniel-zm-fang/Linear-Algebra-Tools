#include "matrix.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// This is the implementation for matrix
// See matrix.h for documentation of functions

struct matrix {
    int row;
    int col;
    bool augmented;
    int max_row;
    int max_col;
    double **data;
};

struct matrix *matrix_create(bool is_augmented) {
    struct matrix *m = malloc(sizeof(struct matrix));
    m->row = 0;
    m->col = 0;
    m->augmented = is_augmented;
    m->max_row = 1;
    m->max_col = 1;
    m->data = malloc(m->max_row * sizeof(double *));
    for (int i = 0; i < m->max_row; ++i) {
        m->data[i] = malloc(m->max_col * sizeof(double));
    }
    return m;
}

struct vector *get_row(int r, const struct matrix *m) {
    assert(m);
    assert(r >= 0);
    assert(r < m->row);
    double *a = malloc(m->col * sizeof(double));
    for (int i = 0; i < m->col; ++i) {
        a[i] = m->data[r][i];
    }
    struct vector *temp = vector_create(m->col, a);
    return temp;
}

struct vector *get_col(int c, const struct matrix *m) {
    assert(m);
    assert(c >= 0);
    assert(c < m->col);
    double *a = malloc(m->row * sizeof(double));
    for (int i = 0; i < m->row; i++) {
        a[i] = m->data[i][c];
    }
    struct vector *temp = vector_create(m->col, a);
    return temp;
}

bool is_empty(const struct matrix *m) {
    assert(m);
    return m->col == 0 || m->max_row == 0;
}

bool is_zero_matrix(const struct matrix *m) {
    assert(m);
    assert(!is_empty(m));
    for (int i = 0; i < m->row; ++i) {
        for (int j = 0; j < m->col; ++j) {
            if (m->data[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void add_row(const struct vector *v, struct matrix *m) {
    assert(v);
    assert(m);
    if (is_empty(m)) {
        m->col = get_dimension(v);
        m->max_col = m->col;
        m->max_row = 1;
        for (int i = 0; i < m->row; ++i) {
            m->data[i] = realloc(m->data[i], m->max_col * sizeof(double));
        }
        for (int i = 0; i < m->col; ++i) {
            m->data[0][i] = get_value(i, v);
        }
    } else {
        assert(get_dimension(v) == m->col);
        if (m->row == m->max_row) {
            m->max_row *= 2;
            m->data = realloc(m->data, m->max_row * sizeof(double *));
            for (int i = m->max_row / 2; i < m->max_row; ++i) {
                m->data[i] = malloc(m->max_col * sizeof(double));
            }
        }
        for (int i = 0; i < m->col; ++i) {
            m->data[m->row][i] = get_value(i, v);
        }
    }
    m->row += 1;
}

void add_col(const struct vector *v, struct matrix *m) {
    assert(v);
    assert(m);
    if (is_empty(m)) {
        m->row = get_dimension(v);
        m->max_row = m->row;
        m->max_col = 1;
        m->data = realloc(m->data, m->max_row * sizeof(double *));
        for (int i = 0; i < m->row; ++i) {
            m->data[i] = malloc(sizeof(double));
            m->data[i][0] = get_value(i, v);
        }
    } else {
        assert(get_dimension(v) == m->row);
        if (m->col == m->max_col) {
            m->max_col *= 2;
            for (int i = 0; i < m->row; ++i) {
                m->data[i] = realloc(m->data[i], m->max_col * sizeof(double));
            }
        }
        for (int i = 0; i < m->row; ++i) {
            m->data[i][m->col] = get_value(i, v);
        }
    }
    m->col += 1;
}

// swap_rows(a, b, n) swap the locations of two rowsof length n of a matrix
// requires: a and b are not NULL pointers
//           n > 0
// effects: may modify *a and *b
// time: O(1)

static void swap_rows(double *a, double *b, int n) {
    assert(a);
    assert(b);
    assert(n);
    for (int i = 0; i < n; ++i) {
        double temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}

void gauss_jordan_elimination(struct matrix *m) {
    assert(m);
    if (is_zero_matrix(m)) {
        return;
    }
    // step 1: find the first non-zero column
    int nonzero_col = 0;
    bool flag = false;
    for (int i = 0; i < m->col; ++i) {
        for (int j = 0; j < m->row; ++j) {
            if (m->data[j][i]) {
                nonzero_col = i;
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }
    // step 2: get a leading one in the top of the column
    if (m->data[0][nonzero_col] != 1) {
        // try to find a row with a leading one and swap with it
        // check if there's already a leading one
        bool swap_first_row = false;
        for (int i = 0; i < m->row; ++i) {
            if (m->data[i][nonzero_col] == 1) {
                swap_rows(m->data[i], m->data[0], m->col);
                swap_first_row = true;
                break;
            }
        }
        if (!swap_first_row) {
        }
    }
}

bool is_rref(const struct matrix *m) {
    assert(m);
    return NULL;
}

int solutions_exist(const struct matrix *m) {
    assert(m);
    return 0;
}

struct vector *find_unique_solution(const struct matrix *m) {
    assert(m);
    return NULL;
}

struct sov *find_solution_system(const struct matrix *m) {
    assert(m);
    return NULL;
}

bool matrix_equal(const struct matrix *m1, const struct matrix *m2) {
    assert(m1);
    assert(m2);
    return NULL;
}

void print_matrix(const struct matrix *m) {
    assert(m);
    for (int i = 0; i < m->row; ++i) {
        printf("|");
        for (int j = 0; j < m->col - 1; ++j) {
            printf("%8.2f", m->data[i][j]);
        }
        printf("%8.2f|\n", m->data[i][m->col - 1]);
    }
    printf("\n");
}

void matrix_destroy(struct matrix *m) {
    assert(m);
    for (int i = 0; i < m->row; ++i) {
        free(m->data[i]);
        m->data[i] = NULL;
    }
    free(m->data);
    free(m);
}