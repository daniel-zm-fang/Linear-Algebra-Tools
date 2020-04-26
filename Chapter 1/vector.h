// This module contains vector ADT and its documentations

// times: n is the dimension of the vector

#include <stdbool.h>

struct vector;

// vector_create(l, arr) creates a new vector with the specified parameters
// requires: l > 0
//           the length of arr = l (not asserted)
// effects: allocates memory (client must call vector_destroy)
// time: O(1)
struct vector *vector_create(int l, int *arr);

// get_dimension(v) returns the diemnsion of the vector v
// requires: v is not a NULL pointer
// time: O(1)
int get_dimension(const struct vector *v);

// vectors_are_equal(v1, v2) checks whether v1 and v2 have the same length and have the same content
// requires: v1 and v2 are not NULL pointers
// time: O(n of v1)
bool vectors_are_equal(const struct vector *v1, const struct vector *v2);

// add(v1, v2) returns a vector with the result of adding v1 and v2
// requires: v1 and v2 are not NULL pointers
//           v1 and v2 have the same length
// effects: allocates memory (client must call vector_destroy)
// time: O(n of v1)
struct vector *add(const struct vector *v1, const struct vector *v2);

// subtract(v1, v2) returns a vector with the result of subtracting v1 from v2
// requires: v1 and v2 are not NULL pointers
//           v1 and v2 have the same length
// effects: allocates memory (client must call vector_destroy)
// time: O(n of v1)
struct vector *subtract(const struct vector *v1, const struct vector *v2);

// scale_mult(num, v) returns a vector with the result of multiplying v by num
// requires: v is not a NULL pointer
// effects: allocates memory (client must call vector_destroy)
// time: O(n of v)
struct vector *scale_mult(int num, const struct vector *v);

// print_vector(v) prints the length and the contents of v
// requires: v is not a NULL pointer
// effects: produces output
// time: O(n of v)
void print_vector(const struct vector *v);

// stack_destroy(v) frees all memory for v
// effects: v is no longer valid
// time: O(1)
void vector_destroy(struct vector *v);
