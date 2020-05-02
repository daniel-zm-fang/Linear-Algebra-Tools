// This is a simple test for linear dependency module

#include "Chapter 2/linear_dependency.h"
#include <assert.h>
#include <stdio.h>

int main(void) {
    double a[3] = {2, -1, 2};
    double b[3] = {-1, 1, 0};
    double c[3] = {2, 0, 5};
    struct vector *v1 = vector_create(3, a);
    struct vector *v2 = vector_create(3, b);
    struct vector *v3 = vector_create(3, c);
    struct sov *s1 = sov_create();
    add_to_set(v1, s1);
    add_to_set(v2, s1);
    add_to_set(v3, s1);
    // print_sov(s1);
    assert(is_linearly_independent(s1));
    //make_linearly_independent(s1);
    print_sov(s1);

    double d[3] = {7, -14, 6};
    double e[3] = {-10, 15, 15.0 / 14.0};
    double f[3] = {-1, 0, 3};
    struct vector *v4 = vector_create(3, d);
    struct vector *v5 = vector_create(3, e);
    struct vector *v6 = vector_create(3, f);
    struct sov *s2 = sov_create();
    add_to_set(v4, s2);
    add_to_set(v5, s2);
    add_to_set(v6, s2);
    // print_sov(s2);
    assert(!is_linearly_independent(s2));
    //make_linearly_independent(s2);
    print_sov(s2);

    vector_destroy(v1);
    vector_destroy(v2);
    vector_destroy(v3);
    vector_destroy(v4);
    vector_destroy(v5);
    vector_destroy(v6);
    sov_destroy(s1);
    sov_destroy(s2);
}