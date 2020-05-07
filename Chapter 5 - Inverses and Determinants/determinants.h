// This module contains functions concerning determinants and their documentations

// time: r = number of rows, c = number of columns

#include "../Chapter 2 - Systems of Linear Equations/matrix.h"
#include <stdbool.h>

// is_upper_triangular(m) returns true if the matrix m is upper triangular and returns false if the
//  matrix m is not upper triangular
// requires: m is not a NULL pointer
// time: O(r * c)
bool is_upper_triangular(const struct matrix *m);

// is_lower_triangular(m) returns true if the matrix m is lower triangular and returns false if the
//  matrix m is not lower triangular
// requires: m is not a NULL pointer
// time: O(r * c)
bool is_lower_triangular(const struct matrix *m);

// determinant(m) returns the determinant of a n * n matrix using row operations
// requires: m is not a NULL pointer
//           r of m == c of m
// time: O(r * c * min(r, c))
double determinant(const struct matrix *m);