#include "determinants.h"
#include <assert.h>

// This is the implementation of functions of determinants
// See determinants.h for documentations

bool is_upper_triangular(const struct matrix *m) {
    assert(m);
    int row = num_rows(m);
    int col = num_cols(m);
    if (row == 1) {
        return true;
    }
    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            if (r > c && matrix_get_val(r, c, m)) {
                return false;
            }
        }
    }
    return true;
}

bool is_lower_triangular(const struct matrix *m) {
    assert(m);
    int row = num_rows(m);
    int col = num_cols(m);
    if (col == 1) {
        return true;
    }
    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            if (r < c && matrix_get_val(r, c, m)) {
                return false;
            }
        }
    }
    return true;
}

// move_zero_rows_bottom_determinant(m, co) is the same function as the move_zero_rows_bottom
//   function in matrix.h, but it updates the coefficient for finding the determinant
// requires: m and co are not NULL pointers
// effects: may modify *m and *co
// time: O(r * c)

static void move_zero_rows_bottom_determinant(struct matrix *m, double *co) {
    assert(m);
    assert(co);
    int row = num_rows(m);
    int col = num_cols(m);
    int num_zero_rows = 0;
    for (int i = 0; i < row - num_zero_rows; ++i) {
        int bot_row = row - 1 - num_zero_rows;
        if (i != bot_row && zero_row(i, m) && !zero_row(bot_row, m)) {
            swap_rows(get_row_ptr(i, m), get_row_ptr(bot_row, m), col);
            *co *= -1;
            num_zero_rows += 1;
        } else if (i != bot_row && !zero_row(i, m) && zero_row(bot_row, m) && i > 0 && zero_row(i - 1, m)) {
            swap_rows(get_row_ptr(i, m), get_row_ptr(i - 1, m), col);
            *co *= -1;
            num_zero_rows += 1;
        }
    }
}

// gauss_jordan_elimination(m, co) is the same function as the gauss_jordan_elimination function
//  in matrix.h, but it updates the coefficient for find the determinant
// requires: m and co are not NULL pointers
// effects: may modify *m and *co
// time: O(r * c * min(r, c))

static void gje_determinant(struct matrix *m, double *co) {
    assert(m);
    assert(co);
    int row = num_rows(m);
    int col = num_cols(m);
    move_zero_rows_bottom_determinant(m, co);
    // find the first non-zero column
    int nonzero_col = 0;
    bool flag = false;
    for (int i = 0; i < col; ++i) {
        for (int j = 0; j < row; ++j) {
            if (matrix_get_val(j, i, m)) {
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
    int stop_col = col - num_aug_cols(m);
    while (nonzero_col < stop_col && curr_row < row && !zero_row(curr_row, m)) {
        // get a leading one in the top of the column
        if (matrix_get_val(curr_row, nonzero_col, m) != 1) {
            // if the top of the nonzero_col is 0, try swapping with other rows
            if (matrix_get_val(curr_row, nonzero_col, m) == 0) {
                for (int i = curr_row + 1; i < row; ++i) {
                    if (matrix_get_val(i, nonzero_col, m)) {
                        swap_rows(get_row_ptr(i, m), get_row_ptr(curr_row, m), col);
                        *co *= -1;
                        break;
                    }
                }
            }
            // if swapping is unsuccessful
            if (matrix_get_val(curr_row, nonzero_col, m) == 0) {
                // get to the next nonzero number in the row
                int count = 0;
                for (int i = nonzero_col + 1; i < stop_col; ++i) {
                    if (matrix_get_val(curr_row, i, m)) {
                        count = i - nonzero_col;
                        break;
                    }
                }
                if (count) {
                    // reduce the coeffients of the current row
                    double temp = matrix_get_val(curr_row, nonzero_col + count, m);
                    for (int i = nonzero_col + count; i < stop_col; ++i) {
                        matrix_set_val(curr_row, i, m, matrix_get_val(curr_row, i, m) / temp);
                    }
                    *co *= temp;
                }
                nonzero_col += count;
                curr_row += 1;
                continue;
            }
            // now create a leading one in the top row
            double temp = matrix_get_val(curr_row, nonzero_col, m);
            for (int i = 0; i < col; ++i) {
                matrix_set_val(curr_row, i, m, matrix_get_val(curr_row, i, m) / temp);
            }
            *co *= temp;
        }
        // make all numbers besides the leading one into 0
        for (int i = 0; i < row; ++i) {
            double temp = matrix_get_val(i, nonzero_col, m) / matrix_get_val(curr_row, nonzero_col, m);
            if (i < curr_row) {
                for (int j = 0; j < col; ++j) {
                    matrix_set_val(i, j, m, matrix_get_val(i, j, m) - matrix_get_val(curr_row, j, m) * temp);
                }
            } else if (i != curr_row && matrix_get_val(i, nonzero_col, m)) {
                for (int j = 0; j < col; ++j) {
                    matrix_set_val(i, j, m, matrix_get_val(i, j, m) / temp);
                    matrix_set_val(i, j, m, matrix_get_val(i, j, m) - matrix_get_val(curr_row, j, m));
                }
                *co *= temp;
            }
        }
        nonzero_col += 1;
        curr_row += 1;
        move_zero_rows_bottom_determinant(m, co);
    }
}

double determinant(const struct matrix *m) {
    assert(m);
    int r = num_rows(m);
    int c = num_cols(m);
    assert(r == c);
    if (r == 1) {
        return matrix_get_val(0, 0, m);
    } else {
        double coefficient = 1;
        struct matrix *temp = matrix_copy(m);
        gje_determinant(temp, &coefficient);
        assert(is_upper_triangular(temp) || is_lower_triangular(temp));
        for (int i = 0; i < r; ++i) {
            coefficient *= matrix_get_val(i, i, temp);
        }
        matrix_destroy(temp);
        return coefficient;
    }
}