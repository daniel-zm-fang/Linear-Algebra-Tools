// This module contains set of vectors ADT and its documentations
// Note: functions that determine linear independence can be found in chapter 2

// times: n is the number of vectors in the set

#include "vector.h"
#include <stdbool.h>

struct sov;

// sov_create() creates a new empty set of vectors
// effects: allocates memory (client must call sov_destroy)
// time: O(1)
struct sov *sov_create();

// is_set_empty(s) returns true if set s is an empty set
// requires: s is not a NULL pointer
// time: O(1)
bool is_set_empty(const struct sov *s);

// is_set_span(s) returns true if set s is a span
// requires: s is not a NULL pointer
// time: O(1)
bool is_set_span(const struct sov *s);

// change_span(span, s) changes whether a set of vectors represents a span or not
// requires: s is not a NULL pointer
// effects: may modify *s
// time: O(1)
void change_span(bool span, struct sov *s);

// contains_vector(v, s) returns true if s contains vector vector
// requires: v and s are not NULL pointers
// time: O(n)
bool contains_vector(const struct vector *v, const struct sov *s);

// dup_sov(s) returns a new sov that is a duplicate of s
// requires: s is not a NULL pointer
// effects: allocates memory (client must call sov_destroy)
// time: O(n)
struct sov *dup_sov(const struct sov *s);

// are_sets_equal(s1, s2) returns true if the sets contains the same vectors
// requires: s1 and s2 are not NULL pointers
// time: O(n ^ 2)
bool are_sets_equal(const struct sov *s1, const struct sov *s2);

// add_to_set(v, s) adds vector v to the back of s
// requires: v and s are not NULL pointers
//           v has to have the same dimension as s->dimension
// effects: modifies s
//          allocates memory (client must free when removing v)
// time: O(1)
void add_to_set(struct vector *v, struct sov *s);

// remove_from_set(v, s) removes vector v from s if v is in s, returns true if
//  vector is succfessfully removed
// requires: v and s are not NULL pointers
//           s is not empty
// effects: may modify s
// time: O(n)
bool remove_from_set(const struct vector *v, struct sov *s);

// print_sov(s) prints all the vectors in s
// requires: s is not a NULL pointer
// effects: produces output
// time: O(n)
void print_sov(const struct sov *s);

// sov_destroy(sov *s) frees all memory for s
// effects: s is not longer valid
// time: O(n)
void sov_destroy(struct sov *s);
