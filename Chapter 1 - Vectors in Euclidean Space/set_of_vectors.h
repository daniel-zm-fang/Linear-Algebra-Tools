// This module contains set of vectors ADT and its documentations
// Note: functions that concern with linear independence can be found in chapter 2

// times: n is the number of vectors in the set

#include "vector.h"
#include <stdbool.h>

struct sov;

// sov_create() creates a new empty set of vectors
// effects: allocates memory (client must call sov_destroy)
// time: O(1)
struct sov *sov_create();

// is_sov_empty(s) returns true if set s is an empty set
// requires: s is not a NULL pointer
// time: O(1)
bool is_sov_empty(const struct sov *s);

// get_sov_span(s) returns true if set s is a span
// requires: s is not a NULL pointer
// time: O(1)
bool get_sov_span(const struct sov *s);

// get_num_vectors(s) returns the number of vectors in set s
// requires: s is not a NULL pointer
// time: O(1)
int get_num_vectors(const struct sov *s);

// get_vector(pos, s) returns a vectors at a specified position of s
// requires: s is not a NULL pointer
// time: O(n)
struct vector *get_vector(int pos, const struct sov *s);

// change_sov_span(span, s) changes whether a set of vectors represents a span or not
// requires: s is not a NULL pointer
// effects: may modify *s
// time: O(1)
void change_sov_span(bool span, struct sov *s);

// change_const_vector(v, s) changes the constant vector of a span
// requires: v and s are not NULL pointers
//           s is a span
//           s is not empty
//           v has the same dimension as s->dimension
// effects: may modify *s
// time: O(n)
void change_const_vector(struct vector *v, struct sov *s);

// contains_vector(v, s) returns true if s contains vector vector
// requires: v and s are not NULL pointers
// time: O(n)
bool contains_vector(const struct vector *v, const struct sov *s);

// dup_sov(s) returns a new sov that is a duplicate of s
// requires: s is not a NULL pointer
// effects: allocates memory (client must call sov_destroy)
// time: O(n)
struct sov *dup_sov(const struct sov *s);

// vectors_sets_equal(s1, s2) returns true if the sets contains the same vectors
// requires: s1 and s2 are not NULL pointers
// time: O(n ^ 2)
bool vectors_sets_equal(const struct sov *s1, const struct sov *s2);

// add_to_sov(v, s) adds vector v to the back of s
// requires: v and s are not NULL pointers
//           v has the same dimension as s->dimension
// effects: modifies s
//          allocates memory (client must free when removing v)
// time: O(1)
void add_to_sov(struct vector *v, struct sov *s);

// remove_from_sov(v, s) removes vector v from s if v is in s, returns true if
//  vector is succfessfully removed
// requires: v and s are not NULL pointers
//           s is not empty
// effects: may modify s
// time: O(n)
bool remove_from_sov(const struct vector *v, struct sov *s);

// print_sov(s) prints all the vectors in s
// requires: s is not a NULL pointer
// effects: produces output
// time: O(n)
void print_sov(const struct sov *s);

// sov_destroy(sov *s) frees all memory for s
// effects: s is not longer valid
// time: O(n)
void sov_destroy(struct sov *s);