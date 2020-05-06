// This module contains scalar equation ADT and its documentations

// all functions have time complexity of O(1)

#include "vector.h"

struct seop;

// seop_create(x, y, z, d) creates a new scalar equation of the form
//  a * x + b * y + c * z = d
// effects: allocates memory (client must call seop_destroy)
struct seop *seop_create(double x, double y, double z, double d);

// get_normal_vector(s) returns the normal vector of a seop
// requires: s is not a NULL pointer
struct vector *get_normal_vector(const struct seop *s);

// vector_to_scalar(v1, v2, v3) returns a new scalar equation form of a vector
//   equation of a plane (plane = s * v1 + t * v2 + v3)
// requires: v1, v2, and v3 are not NULL pointers
//           v1, v2, and v3 must be three dimensional
// effects: allocates memory (client must call seop_destroy)
struct seop *vector_to_scalar(const struct vector *v1, const struct vector *v2, const struct vector *v3);

// is_point_on_plane(v, s) returns true if a given point/vector is on the
//  plane described by the seoq
// requires: v and s are not NULL pointers
//           v must be three dimensional
bool is_point_on_plane(const struct vector *v, const struct seop *s);

// proj_onto_plane(v, s) returns the projection of v onto plane s
// requires: v and s are not NULL pointers
//           the normal vector of s is not the zero vector
// effects: allocates memory (client must call vector_destroy)
struct vector *proj_onto_plane(const struct vector *v, const struct seop *s);

// perp_onto_plane(v, s) returns the perpendicular or normal of v onto plane s
// requires: v and s are not NULL pointers
//           the normal vector of s is not the zero vector
// effects: allocates memory (client must call vector_destroy)
struct vector *perp_onto_plane(const struct vector *v, const struct seop *s);

// print_seop(s) prints the scalar equation of s
// requires: s is not a NULL pointer
// effects: produces output
void print_seop(const struct seop *s);

// seop_destroy(s) frees all memory for s
// effects: s is no longer valid
void seop_destroy(struct seop *s);