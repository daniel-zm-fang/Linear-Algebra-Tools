// These are simple tests for set_of_vectors module

#include "Chapter 1/set_of_vectors.h"
#include <assert.h>

int main(void) {
    // a set of 2D vectors
    double a[2] = {1, 2};
    double b[2] = {3, 4};
    double c[2] = {5, 6};
    double d[2] = {7, 8};
    struct vector *v1 = vector_create(2, a);
    struct vector *v2 = vector_create(2, b);
    struct vector *v3 = vector_create(2, c);
    struct vector *v4 = vector_create(2, d);

    struct sov *s1 = sov_create();
    change_sov_span(true, s1);
    // print_sov(s1);

    assert(is_set_empty(s1));
    assert(!contains_vector(v1, s1));

    add_to_set(v1, s1);
    add_to_set(v2, s1);
    add_to_set(v3, s1);
    add_to_set(v1, s1);
    // print_sov(s1);

    assert(contains_vector(v1, s1));
    assert(contains_vector(v2, s1));
    assert(!contains_vector(v4, s1));

    struct sov *s2 = dup_sov(s1);
    // print_sov(s2);
    assert(vectors_sets_equal(s1, s2));

    struct sov *s3 = sov_create();
    change_sov_span(true, s3);
    add_to_set(v1, s3);
    add_to_set(v3, s3);
    add_to_set(v2, s3);
    add_to_set(v1, s3);
    // print_sov(s3);
    assert(vectors_sets_equal(s1, s3));

    assert(!remove_from_set(v4, s1));
    assert(remove_from_set(v1, s1));
    assert(remove_from_set(v2, s1));
    assert(remove_from_set(v3, s1));
    assert(!remove_from_set(v2, s1));
    // print_sov(s1);

    // a set of 3D vectors
    double e[3] = {0, 0, 0};
    double f[3] = {-1, 0, 1};
    double g[3] = {10, 20, 30};
    struct vector *v5 = vector_create(3, e);
    struct vector *v6 = vector_create(3, f);
    struct vector *v7 = vector_create(3, g);

    struct sov *s4 = sov_create();
    assert(is_set_empty(s4));

    add_to_set(v5, s4);
    add_to_set(v6, s4);
    add_to_set(v7, s4);
    // print_sov(s4);

    assert(remove_from_set(v5, s4));
    assert(remove_from_set(v6, s4));
    assert(remove_from_set(v7, s4));
    // print_sov(s4);

    sov_destroy(s1);
    sov_destroy(s2);
    sov_destroy(s3);
    sov_destroy(s4);

    vector_destroy(v1);
    vector_destroy(v2);
    vector_destroy(v3);
    vector_destroy(v4);
    vector_destroy(v5);
    vector_destroy(v6);
    vector_destroy(v7);
}
