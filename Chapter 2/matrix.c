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
        m->col = get_dimension(v);
        m->max_col = m->col;
        m->max_row = 1;
        m->row += 1;
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
        m->row += 1;
    }
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
// time: O(number of columns)

static bool zero_row(int r, const struct matrix *m) {
    assert(m);
    assert(r >= 0);
    assert(r < m->row);
    int stop_col = m->augmented_col;
    if (m->augmented_col == 0) {
        stop_col = m->col;
    }
    for (int j = 0; j < stop_col; ++j) {
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
    int stop_col = m->col;
    if (m->augmented_col) {
        stop_col = m->augmented_col;
    }
    while (nonzero_col < stop_col && curr_row < m->row && !zero_row(curr_row, m)) {
        // get a leading one in the top of the column
        if (m->data[curr_row][nonzero_col] != 1) {
            // try to find a row with a leading one and swap with it
            // check if there's already a leading one
            bool swap_first_row = false;
            for (int i = 0; i < m->row; ++i) {
                if (m->data[i][nonzero_col] == 1) {
                    swap_rows(m->data[i], m->data[curr_row], m->col);
                    swap_first_row = true;
                    break;
                }
            }
            // if there is no row with a leading one
            if (!swap_first_row) {
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
    int stop_col = m->col;
    if (m->augmented_col) {
        stop_col = m->augmented_col;
    }
    for (int i = 0; i < zero_row_start; ++i) {
        bool seen_one = false;
        for (int j = 0; j < stop_col; ++j) {
            if (m->data[i][j] != 0 && m->data[i][j] != 1 && !seen_one) {
                return false;
            } else if (m->data[i][j] == 1) {
                seen_one = true;
                // test 3: a leading one is the only nonzero entry in its column
                for (int k = 0; k < zero_row_start; ++k) {
                    if (m->data[k][j] != 0 && k != i) {
                        return false;
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
    assert(is_rref(m));
    int rank = 0;
    for (int i = 0; i < m->row; ++i) {
        if (zero_row(i, m)) {
            return rank;
        }
        rank += 1;
    }
    return rank;
}

int get_free_var(const struct matrix *m) {
    assert(m);
    assert(is_rref(m));
    int stop_col = m->col;
    if (m->augmented_col) {
        stop_col = m->augmented_col;
    }
    return stop_col - get_rank(m);
}

// get_solution(m) returns a set of vectors as the solution of the matrix
// requires: m is not NULL pointer
//           m must be consistent (not asserted)
// effects: allocates memory (client must call sov_destroy)
// time:

static struct sov *get_solution(const struct matrix *m) {
    assert(m);
    assert(is_rref(m));
    if (m->augmented_col) {
        int stop_col = m->col;
        if (m->augmented_col) {
            stop_col = m->augmented_col;
        }
        struct sov *s = sov_create();
        for (int i = stop_col; i < m->col; ++i) {
            double *a = malloc(m->row * sizeof(double));
            for (int j = 0; j < m->row; ++j) {
                a[i] = m->data[j][i];
            }
            add_to_set(vector_create(m->row, a), s);
        }
        return s;
    } else {
        return NULL;
    }
}

struct sov *find_solution(const struct matrix *m) {
    assert(m);
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
    int rank = get_rank(m);
    int stop_col = m->col;
    if (m->augmented_col) {
        stop_col = m->augmented_col;
    }
    struct sov *s = get_solution(m);
    if (rank == stop_col) {
        // there exists a unique solution
        change_span(false, s);
        return s;
    } else {
        // there exists infinite solutions
        change_span(true, s);
        return s;
    }
}

bool matrix_equal(const struct matrix *m1, const struct matrix *m2) {
    assert(m1);
    assert(m2);
    return NULL;
}

void print_matrix(const struct matrix *m) {
    assert(m);
    if (is_empty(m)) {
        printf("| empty |\n");
    }
    for (int i = 0; i < m->row; ++i) {
        printf("|");
        for (int j = 0; j < m->col - 1; ++j) {
            if (m->augmented_col == j && j) {
                printf("|%8.2f", m->data[i][j]);
            } else if (j + 1 == m->augmented_col) {
                printf("%8.2f    ", m->data[i][j]);
            } else {
                printf("%8.2f", m->data[i][j]);
            }
        }
        if (m->col - 1 == m->augmented_col) {
            printf("|%8.2f    |\n", m->data[i][m->col - 1]);
        } else {
            printf("%8.2f    |\n", m->data[i][m->col - 1]);
        }
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