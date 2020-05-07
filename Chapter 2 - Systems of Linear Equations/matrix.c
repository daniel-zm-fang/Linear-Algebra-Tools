#include "matrix.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// This is the implementation of functions of a matrix
// See matrix.h for documentation of functions

struct matrix {
    int row;
    int col;
    int augmented_col;
    int max_row;
    int max_col;
    double **data;
};

struct matrix *matrix_create() {
    struct matrix *m = malloc(sizeof(struct matrix));
    m->row = 0;
    m->col = 0;
    m->augmented_col = 0;
    m->max_row = 1;
    m->max_col = 1;
    m->data = malloc(m->max_row * sizeof(double *));
    for (int i = 0; i < m->max_row; ++i) {
        m->data[i] = malloc(m->max_col * sizeof(double));
    }
    return m;
}

int num_rows(const struct matrix *m) {
    assert(m);
    return m->row;
}

int num_cols(const struct matrix *m) {
    assert(m);
    return m->col;
}

int num_aug_cols(const struct matrix *m) {
    assert(m);
    return m->augmented_col;
}

double matrix_get_val(int r, int c, const struct matrix *m) {
    assert(m);
    assert(0 <= r);
    assert(r < m->row);
    assert(0 <= c);
    assert(c < m->col);
    return m->data[r][c];
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
    struct vector *temp = vector_create(m->row, a);
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

void change_augmented_col(int aug_col, struct matrix *m) {
    assert(m);
    assert(aug_col >= 0);
    assert(aug_col < m->col);
    m->augmented_col = aug_col;
}

void add_row(const struct vector *v, struct matrix *m) {
    assert(v);
    assert(m);
    if (is_empty(m)) {
        m->col = get_vector_dimension(v);
        m->max_col = m->col;
        m->max_row = 1;
        m->row += 1;
        for (int i = 0; i < m->row; ++i) {
            m->data[i] = realloc(m->data[i], m->max_col * sizeof(double));
        }
        for (int i = 0; i < m->col; ++i) {
            m->data[0][i] = vector_get_val(i, v);
        }
    } else {
        assert(get_vector_dimension(v) == m->col);
        if (m->row == m->max_row) {
            m->max_row *= 2;
            m->data = realloc(m->data, m->max_row * sizeof(double *));
            for (int i = m->max_row / 2; i < m->max_row; ++i) {
                m->data[i] = malloc(m->max_col * sizeof(double));
            }
        }
        for (int i = 0; i < m->col; ++i) {
            m->data[m->row][i] = vector_get_val(i, v);
        }
        m->row += 1;
    }
}

void add_col(const struct vector *v, struct matrix *m) {
    assert(v);
    assert(m);
    if (is_empty(m)) {
        m->row = get_vector_dimension(v);
        m->max_row = m->row;
        m->max_col = 1;
        m->data = realloc(m->data, m->max_row * sizeof(double *));
        for (int i = 0; i < m->row; ++i) {
            m->data[i] = malloc(sizeof(double));
            m->data[i][0] = vector_get_val(i, v);
        }
    } else {
        assert(get_vector_dimension(v) == m->row);
        if (m->col == m->max_col) {
            m->max_col *= 2;
            for (int i = 0; i < m->row; ++i) {
                m->data[i] = realloc(m->data[i], m->max_col * sizeof(double));
            }
        }
        for (int i = 0; i < m->row; ++i) {
            m->data[i][m->col] = vector_get_val(i, v);
        }
    }
    m->col += 1;
}

struct matrix *identity_matrix(int width) {
    assert(width);
    struct matrix *m = matrix_create();
    for (int i = 0; i < width; ++i) {
        double *a = malloc(width * sizeof(double));
        for (int j = 0; j < width; ++j) {
            if (i == j) {
                a[j] = 1;
            } else {
                a[j] = 0;
            }
        }
        add_row(vector_create(width, a), m);
    }
    return m;
}

struct matrix *matrix_copy(const struct matrix *m) {
    assert(m);
    struct matrix *new_m = malloc(sizeof(struct matrix));
    new_m->row = m->row;
    new_m->col = m->col;
    new_m->augmented_col = m->augmented_col;
    new_m->max_row = m->max_row;
    new_m->max_col = m->max_col;
    new_m->data = malloc(new_m->max_row * sizeof(double *));
    for (int i = 0; i < m->max_row; ++i) {
        new_m->data[i] = malloc(new_m->max_col * sizeof(double));
    }
    for (int i = 0; i < m->row; ++i) {
        for (int j = 0; j < m->col; ++j) {
            new_m->data[i][j] = m->data[i][j];
        }
    }
    return new_m;
}

// swap_rows(a, b, n) swap the locations of two rowsof length n of a matrix
// requires: a and b are not NULL pointers
//           n > 0
// effects: may modify *a and *b
// time: O(n)

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

// zero_row(r, m) returns true if a specified row in the matrix contains all zero
// requires: m is not a NULL pointer
//           0 <= r < m->row
// time: O(c)

static bool zero_row(int r, const struct matrix *m) {
    assert(m);
    assert(r >= 0);
    assert(r < m->row);
    for (int j = 0; j < m->col - m->augmented_col; ++j) {
        if (m->data[r][j]) {
            return false;
        }
    }
    return true;
}

void gauss_jordan_elimination(struct matrix *m) {
    assert(m);
    move_zero_rows_bottom(m);
    // find the first non-zero column
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
    int curr_row = 0;
    int stop_col = m->col - m->augmented_col;
    while (nonzero_col < stop_col && curr_row < m->row && !zero_row(curr_row, m)) {
        // get a leading one in the top of the column
        if (m->data[curr_row][nonzero_col] != 1) {
            // if the top of the nonzero_col is 0, try swapping with other rows
            if (m->data[curr_row][nonzero_col] == 0) {
                for (int i = curr_row + 1; i < m->row; ++i) {
                    if (m->data[i][nonzero_col]) {
                        swap_rows(m->data[i], m->data[curr_row], m->col);
                        break;
                    }
                }
            }
            // if swapping is unsuccessful
            if (m->data[curr_row][nonzero_col] == 0) {
                // get to the next nonzero number in the row
                int count = 0;
                for (int i = nonzero_col + 1; i < stop_col; ++i) {
                    if (m->data[curr_row][i]) {
                        count = i - nonzero_col;
                        break;
                    }
                }
                if (count) {
                    // reduce the coeffients of the current row
                    double temp = m->data[curr_row][nonzero_col + count];
                    for (int i = nonzero_col + count; i < stop_col; ++i) {
                        m->data[curr_row][i] /= temp;
                    }
                }
                nonzero_col += count;
                ;
                curr_row += 1;
                continue;
            }
            // now create a leading one in the top row
            double temp = m->data[curr_row][nonzero_col];
            for (int i = 0; i < m->col; ++i) {
                m->data[curr_row][i] /= temp;
            }
        }
        // make all numbers besides the leading one into 0
        for (int i = 0; i < m->row; ++i) {
            double temp = m->data[i][nonzero_col] / m->data[curr_row][nonzero_col];
            if (i < curr_row) {
                for (int j = 0; j < m->col; ++j) {
                    m->data[i][j] -= m->data[curr_row][j] * temp;
                }
            } else if (i != curr_row && m->data[i][nonzero_col]) {
                for (int j = 0; j < m->col; ++j) {
                    m->data[i][j] /= temp;
                    m->data[i][j] -= m->data[curr_row][j];
                }
            }
        }
        nonzero_col += 1;
        curr_row += 1;
        move_zero_rows_bottom(m);
    }
    // convert all -0 to 0
    for (int i = 0; i < m->row; ++i) {
        for (int j = 0; j < m->col; ++j) {
            if (m->data[i][j] == -0.0) {
                m->data[i][j] = +0.0;
            }
        }
    }
}

void move_zero_rows_bottom(struct matrix *m) {
    int num_zero_rows = 0;
    for (int i = 0; i < m->row - num_zero_rows; ++i) {
        int bot_row = m->row - 1 - num_zero_rows;
        if (i != bot_row && zero_row(i, m) && !zero_row(bot_row, m)) {
            swap_rows(m->data[i], m->data[bot_row], m->col);
            num_zero_rows += 1;
        } else if (i != bot_row && !zero_row(i, m) && zero_row(bot_row, m) && i > 0 && zero_row(i - 1, m)) {
            swap_rows(m->data[i], m->data[i - 1], m->col);
            num_zero_rows += 1;
        }
    }
}

bool is_rref(const struct matrix *m) {
    assert(m);
    // test 1: all nonzero rows must be above zero rows
    int zero_row_start = m->row;
    for (int i = 0; i < m->row; ++i) {
        if (zero_row(i, m)) {
            zero_row_start = i;
            break;
        }
    }
    for (int i = zero_row_start + 1; i < m->row; ++i) {
        if (!zero_row(i, m)) {
            return false;
        }
    }
    // test 2: the first nonzero entry in each nonzero row is 1
    int stop_col = m->col - m->augmented_col;
    for (int i = 0; i < zero_row_start; ++i) {
        int one_count = 0;
        for (int j = 0; j < stop_col; ++j) {
            if (m->data[i][j] != 0 && m->data[i][j] != 1 && one_count == 0) {
                return false;
            } else if (m->data[i][j] == 1) {
                one_count += 1;
                // test 3: a leading one is the only nonzero entry in its column
                if (one_count == 1) {
                    for (int k = 0; k < zero_row_start; ++k) {
                        if (m->data[k][j] != 0 && k != i) {
                            return false;
                        }
                    }
                }
            }
        }
    }
    // test 4: leading one each nonzero row is to the right of leading one in any row above it
    int curr_leading_one_col = 0;
    for (int i = 0; i < zero_row_start; ++i) {
        for (int j = 0; j < stop_col; ++j) {
            if (m->data[i][j] == 1 && j > curr_leading_one_col) {
                curr_leading_one_col = j;
                break;
            }
        }
    }
    return true;
}

int get_rank(const struct matrix *m) {
    assert(m);
    struct matrix *temp = matrix_copy(m);
    gauss_jordan_elimination(temp);
    int rank = 0;
    for (int i = 0; i < m->row; ++i) {
        if (zero_row(i, m)) {
            return rank;
        }
        rank += 1;
    }
    matrix_destroy(temp);
    return rank;
}

int get_free_var(const struct matrix *m) {
    assert(m);
    struct matrix *temp = matrix_copy(m);
    gauss_jordan_elimination(temp);
    int free_var = temp->col - temp->augmented_col - get_rank(temp);
    matrix_destroy(temp);
    return free_var;
}

bool is_col_free_var(int c, const struct matrix *m) {
    assert(m);
    assert(c >= 0);
    assert(c < m->col);
    assert(is_rref(m));
    bool one_exists = false;
    int one_pos = -1;
    int nonzero_count = 0;
    for (int i = 0; i < m->row; ++i) {
        if (m->data[i][c]) {
            nonzero_count += 1;
            if (nonzero_count == 2) {
                return true;
            }
            if (m->data[i][c] == 1) {
                one_exists = true;
                one_pos = i;
            }
        }
    }
    if (one_exists) {
        for (int i = 0; i < m->row; ++i) {
            if (m->data[one_pos][i] == 1) {
                if (i < c) {
                    return true;
                } else {
                    return false;
                }
            }
        }
        return false;
    } else {
        return true;
    }
}

struct sov *find_solution(const struct matrix *m) {
    assert(m);
    assert(m->augmented_col == 0 || m->augmented_col == 1);
    assert(is_rref(m));
    // check for inconsistency
    for (int i = 0; i < m->row; i++) {
        if (zero_row(i, m)) {
            for (int j = m->augmented_col; j < m->col; j++) {
                if (m->data[i][j] != 0) {
                    return NULL;
                }
            }
        }
    }
    struct sov *s = sov_create();
    int free_var = get_free_var(m);
    if (m->augmented_col == 0) {
        if (free_var == 0) {
            // not augmented & unique solution
            double *a = malloc(m->col * sizeof(double));
            for (int i = 0; i < m->col; ++i) {
                a[i] = 0;
            }
            add_to_sov(vector_create(m->col, a), s);
        } else {
            // not augmented & infinite solutions
            change_sov_span(true, s);
            for (int i = 0; i < m->col; ++i) {
                if (is_col_free_var(i, m)) {
                    double *a = malloc(m->col * sizeof(double));
                    for (int j = 0; j < m->row; ++j) {
                        a[j] = -1 * m->data[j][i];
                    }
                    a[i] = 1;
                    add_to_sov(vector_create(m->col, a), s);
                }
            }
        }
    } else {
        if (free_var == 0) {
            // augmented & unique solution
            add_to_sov(get_col(m->col - 1, m), s);
        } else {
            // augmented & infinite solutions
            for (int i = 0; i < m->col - 1; ++i) {
                if (is_col_free_var(i, m)) {
                    double *b = malloc((m->col - 1) * sizeof(double));
                    for (int j = 0; j < m->row; ++j) {
                        b[j] = -1 * m->data[j][i];
                    }
                    b[i] = 1;
                    add_to_sov(vector_create(m->col - 1, b), s);
                }
            }
            change_sov_span(true, s);
            double *a = malloc((m->col - 1) * sizeof(double));
            for (int i = 0; i < m->col - 1; ++i) {
                if (i <= free_var) {
                    a[i] = m->data[i][m->col - 1];
                } else {
                    a[i] = 0;
                }
            }
            change_const_vector(vector_create(m->col - 1, a), s);
        }
    }
    return s;
}

bool matrices_equal(const struct matrix *m1, const struct matrix *m2) {
    assert(m1);
    assert(m2);
    struct matrix *m1_rref = matrix_copy(m1);
    struct matrix *m2_rref = matrix_copy(m2);
    gauss_jordan_elimination(m1_rref);
    gauss_jordan_elimination(m2_rref);
    bool result = vectors_sets_equal(find_solution(m1_rref), find_solution(m2_rref));
    matrix_destroy(m1_rref);
    matrix_destroy(m2_rref);
    return result;
}

struct matrix *sov_to_matrix(const struct sov *s) {
    assert(s);
    struct matrix *m = matrix_create();
    for (int i = 0; i < get_num_vectors(s); ++i) {
        add_col(get_vector(i, s), m);
    }
    return m;
}

void print_matrix(const struct matrix *m) {
    assert(m);
    if (is_empty(m)) {
        printf("| empty |\n");
    }
    for (int i = 0; i < m->row; ++i) {
        printf("|");
        for (int j = 0; j < m->col - 1; ++j) {
            if (m->col == j + m->augmented_col + 1) {
                printf("%8.2f    |", m->data[i][j]);
            } else {
                printf("%8.2f", m->data[i][j]);
            }
        }
        printf("%8.2f    |\n", m->data[i][m->col - 1]);
    }
    printf("\n");
}

void matrix_destroy(struct matrix *m) {
    assert(m);
    for (int i = 0; i < m->max_row; ++i) {
        free(m->data[i]);
        m->data[i] = NULL;
    }
    free(m->data);
    free(m);
    m = NULL;
}

void matrix_destroy_keep_ptr(struct matrix *m) {
    assert(m);
    for (int i = 0; i < m->max_row; ++i) {
        free(m->data[i]);
        m->data[i] = NULL;
    }
    free(m->data);
    free(m);
}