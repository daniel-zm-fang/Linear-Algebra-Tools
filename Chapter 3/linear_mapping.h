#include "../Chapter 2/matrix.h"
#include "matrix_operations.h"

// note: the equivalent of vector_proj function is proj from vector.h
// time: n is the dimension of vector

// proj_matrix(v) returns the standard matrix of projecting onto vector v
// requires: v is not a NULL pointer
// effects: allocates memory (client must call matrix_destroy)
// time: O(n ^ 3)
struct matrix *proj_matrix(const struct vector *v);

// rotation_matrix(theta) returns the standard matrix of rotating a 2D
//  vector about the orign by angle theta (radian)
// effects: allocates memory (client must call matrix_destroy)
// time: O(n)
struct matrix *rotation_matrix(const double theta);

// reflection_matrix(n) returns the standard matrix of reflecting a vector
//  in the hyperplane with normal vector n
// requires: n is not a NULL pointer
// effects: allocates memory (client must call matrix_destroy)
// time: O(n ^ 3)
struct matrix *reflection_matrix(const struct vector *n);

// vector_rotation(theta, v) returns the resulting vector of rotating 2D v
//  by rotating angle theta (radian)
// requires: v is not a NULL pointer
//           dimension of v = 2
// effects: allocates memory (client must call vector_destroy)
// time: 0(n ^ 2)
struct vector *vector_rotation(double theta, const struct vector *v);

// vector_reflection(n, x) returns the resulting vector from reflecting
//  vector x over the hyperplane with the normal vector n.
// requires: n is not a NULL pointer
//           x is not a NULL pointer
//           dimension of n == dimension of x
// effects: allocates memory (client must call vector_destroy)
// time: O(n ^ 3)
struct vector *vector_reflection(const struct vector *n, const struct vector *x);