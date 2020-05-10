// This module contains functions of eigenvalues and eigenvectors and their documentations

#include "../Chapter 3 - Matrices and Linear Mappings/matrix_operations.h"
#include "../Chapter 5 - Inverses and Determinants/determinants.h"
#include <stdbool.h>

// times: r = number of rows, c = number of columns

// is_eigenvector(m, v) returns true if v is an eigenvector of a matrix
// requires: m and v are not NULL pointers
//           m is not an augmented matrix
//           r == c == dimension of v
// time: O(r * c)
bool is_eigenvector(const struct matrix *m, const struct vector *v);

// eigenvalue(m, v) returns the eigenvalue of m according to v
// requires: m and v are not NULL pointers
//           m is not an augmented matrix
//           r == c == dimension of v
//           v is an eigenvector of A
// time: O(r * c)
double eigenvalue(const struct matrix *m, const struct vector *v);

// is_eigenvalue(m, x) returns true if x is an eigenvalue of m and false otherwise
// requires: m is not a NULL pointer
//           m is not an augmented matrix
//           r == c
// time: O(r * c * min(r, c))
bool is_eigenvalue(const struct matrix *m, double x);

// eigenvectors(m, x) returns the span of eigenvectors with the given eigenvalue x and matrix
// requires: m is not a NULL pointer
//           m is not an augmented matrix
//           r == c
//           x is an eigenvalue of m
// effects: allocates memory (client must call sov_destroy)
// time: O(r * c * min(r, c))
struct sov *eigenvectors(const struct matrix *m, double x);

// all_eigenvalues(m) returns an array of all the eigenvalues of m
// note: this function only finds the integer eigenvalues
// requires: m is not a NULL pointer
//           m is not an augmented matrix
//           r == c
// effects : allocates memory(client must call free)
// time: O(r * c * det(m))
int *all_eigenvalues(const struct matrix *m);

// all_eigenvectors(m) returns an array of sov of all the eigenvectors of m
// note: this function only finds eigenvectors whose eigenvalues are integers
// requires: m is not a NULL pointer
//           m is not an augmented matrix
//           r == c
// time: O(r * c * min(r, c) * # of eigenvalues)
struct sov **all_eigenvectors(const struct matrix *m);

// geometric_multiplicity(m, x) returns the geometric multiplicity
//  of an eigenvalue of a matrix (dimension of its eigenspace)
// note: this function only finds multiplicity for integer eigenvalue
// requires: m is not a NULL pointer
//           m is not an augmented matrix
//           r == c
//           x is an eigenvalue of m
// time: O(r * c * min(r, c))
int geometric_multiplicity(const struct matrix *m, int x);