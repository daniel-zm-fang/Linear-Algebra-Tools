// This module contains vector ADT and its documentations

// times: n is the dimension of the vector

#include <stdbool.h>

struct vector;

// vector_create(l, arr) creates a new vector with the specified parameters
// requires: l > 0
//           the dimension of arr = l (not asserted)
// effects: allocates memory (client must call vector_destroy)
// time: O(1)
struct vector *vector_create(int l, double *arr);

// get_dimension(v) returns the dimension of the vector v
// requires: v is not a NULL pointer
// time: O(1)
int get_dimension(const struct vector *v);

// vector_get_val(pos, v) returns the number at a given position of a vector
// require: pos >= 0
//          pos < v->dimension
// time: O(1)
double vector_get_val(int pos, const struct vector *v);

// vectors_equal(v1, v2) checks whether v1 and v2 have the same dimension and have the same content
// requires: v1 and v2 are not NULL pointers
// time: O(n)
bool vectors_equal(const struct vector *v1, const struct vector *v2);

// add(v1, v2) returns a vector with the result of adding v1 and v2
// requires: v1 and v2 are not NULL pointers
//           v1 and v2 have the same dimension
// effects: allocates memory (client must call vector_destroy)
// time: O(n)
struct vector *add(const struct vector *v1, const struct vector *v2);

// subtract(v1, v2) returns a vector with the result of subtracting v1 from v2
// requires: v1 and v2 are not NULL pointers
//           v1 and v2 have the same dimension
// effects: allocates memory (client must call vector_destroy)
// time: O(n)
struct vector *subtract(const struct vector *v1, const struct vector *v2);

// scale_mult(num, v) returns a vector with the result of multiplying v by num
// requires: v is not a NULL pointer
// effects: allocates memory (client must call vector_destroy)
// time: O(n)
struct vector *scale_mult(double num, const struct vector *v);

// dot_product(v1, v2) returns the dot product of the two vectors
// requires: v1 and v2 are not NULL pointers
//           v1 and v2 have the same dimension
// time: O(n)
double dot_product(const struct vector *v1, const struct vector *v2);

// norm(v) returns the norm or the length of the vector
// requires: v is not a NULL pointer
// time: O(n)
double norm(const struct vector *v);

// angle(v1, v2) returns the angle between the two vectors in radian
// requires: v1 and v2 are not NULL pointers
//           v1 and v2 have the same dimension
// time: O(n)
double angle(const struct vector *v1, const struct vector *v2);

// is_orthogonal(v1, v2) returns true if the the two vectors are orthogonal
// requires: v1 and v2 are not NULL pointers
//           v1 and v2 have the same dimension
// time: O(n)
bool is_orthogonal(const struct vector *v1, const struct vector *v2);

// cross_product(v1, v2) returns the result vector of the cross product of the two vectors
// require: v1 and v2 are not NULL pointers
//          v1 and v2 must be three dimensional
// effects: allocates memory (client must call vector_destroy)
// time: O(n)
struct vector *cross_product(const struct vector *v1, const struct vector *v2);

// normal_vector(v1, v2) returns the normal vector of the two vectors
// require: v1 and v2 are not NULL pointers
//          v1 and v2 must be three dimensional
// effects: allocates memory (client must call vector_destroy)
// time: O(n)
struct vector *normal_vector(const struct vector *v1, const struct vector *v2);

// proj(v1, v2) returns the projection of v1 onto v2
// requires: v1 and v2 are not NULL pointers
//           norm(v2) != 0
// effects: allocates memory (client must call vector_destroy)
// time: O(n)
struct vector *proj(const struct vector *v1, const struct vector *v2);

// perp(v1, v2) returns the perpendicular of v1 onto v2
// requires: v1 and v2 are not NULL pointers
//           norm(v2) != 0
// effects: allocates memory (client must call vector_destroy)
// time: O(n)
struct vector *perp(const struct vector *v1, const struct vector *v2);

// print_vector(v) prints the dimension and the contents of v
// requires: v is not a NULL pointer
// effects: produces output
// time: O(n)
void print_vector(const struct vector *v);

// stack_destroy(v) frees all memory for v
// effects: v is no longer valid
// time: O(1)
void vector_destroy(struct vector *v);