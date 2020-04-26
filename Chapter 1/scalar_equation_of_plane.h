// This module contains scalar equation ADT and its documentations

#include "vector.h"

struct seop;

// seop_create(x, y, z, d) creates a new scalar equation of the form
//  a * x + b * y + c * z = d
// effects: allocates memory (client must call seop_destroy)
// time: O(1)
struct seop *seop_create(int x, int y, int z, int d);

// get_normal_vector(s) returns the normal vector of a seop
// requires: s is not a NULL pointer
// time: O(1)
struct vector *get_normal_vector(const struct seop *s);

// vector_to_scalar(v1, v2, v3) returns a new scalar equation form of a vector
//   equation of a plane (plane = s * v1 + t * v2 + v3)
// requires: v1, v2, and v3 are not NULL pointers
//           v1, v2, and v3 must be three dimensional
// effects: allocates memory (client must call seop_destroy)
// time: O(1)
struct seop *vector_to_scalar(const struct vector *v1, const struct vector *v2, const struct vector *v3);

// is_point_on_plane(v, s) returns true if a given point/vector is on the
//  plane described by the seoq
// requires: v and s are not NULL pointers
//           v must be three dimensional
// time: O(1)
bool is_point_on_plane(const struct vector *v, const struct seop *s);

// print_seop(s) prints the scalar equation of s
// requires: s is not a NULL pointer
// effects: produces output
// time: O(1)
void print_seop(const struct seop *s);

// seop_destroy(s) frees all memory for s
// effects: s is no longer valid
// time: O(1)
void seop_destroy(struct seop *s);