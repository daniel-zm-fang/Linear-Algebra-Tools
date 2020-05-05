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
    assert(is_sov_linearly_independent(s1));
    make_sov_linearly_independent(s1);
    // print_sov(s1);
    assert(is_sov_span(s1, 3));
    assert(is_sov_basis(s1, 3));

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
    assert(!is_sov_linearly_independent(s2));
    make_sov_linearly_independent(s2);
    assert(is_sov_linearly_independent(s2));
    // print_sov(s2);

    double g[3] = {-2, 0, 6};
    struct vector *v7 = vector_create(3, g);
    struct sov *s3 = sov_create();
    add_to_set(v6, s3);
    add_to_set(v7, s3);
    // print_sov(s3);
    assert(!is_sov_linearly_independent(s3));
    assert(!is_sov_span(s3, 0));
    assert(!is_sov_span(s3, 1));
    assert(!is_sov_span(s3, 3));
    make_sov_linearly_independent(s3);
    assert(is_sov_linearly_independent(s3));
    // print_sov(s3);

    double h[3] = {1, 2, 3};
    double i[3] = {2, 4, 4};
    double j[3] = {3, 6, 5};
    double k[3] = {4, 8, 6};
    struct vector *v8 = vector_create(3, h);
    struct vector *v9 = vector_create(3, i);
    struct vector *v10 = vector_create(3, j);
    struct vector *v11 = vector_create(3, k);
    struct sov *s4 = sov_create();
    add_to_set(v8, s4);
    add_to_set(v9, s4);
    add_to_set(v10, s4);
    add_to_set(v11, s4);
    // print_sov(s4);
    assert(!is_sov_linearly_independent(s4));
    make_sov_linearly_independent(s4);
    assert(is_sov_linearly_independent(s4));
    // print_sov(s4);
    assert(!is_sov_span(s4, 2));
    assert(!is_sov_span(s4, 3));

    double l[4] = {0, 0, 0, 0};
    double m[4] = {3, 1, 3, 5};
    double n[4] = {6, 4, -3, 4};
    double o[4] = {0, 2, -1, 8};
    struct vector *v12 = vector_create(4, l);
    struct vector *v13 = vector_create(4, m);
    struct vector *v14 = vector_create(4, n);
    struct vector *v15 = vector_create(4, o);
    struct sov *s5 = sov_create();
    add_to_set(v12, s5);
    add_to_set(v13, s5);
    add_to_set(v14, s5);
    add_to_set(v15, s5);
    // print_sov(s5);
    assert(!is_sov_linearly_independent(s5));
    make_sov_linearly_independent(s5);
    // print_sov(s5);
    assert(!is_sov_span(s5, 3));
    assert(!is_sov_span(s5, 4));

    struct sov *s6 = sov_create();
    assert(is_sov_linearly_independent(s6));
    assert(is_sov_span(s6, 0));
    assert(is_sov_basis(s6, 0));

    sov_destroy(s1);
    sov_destroy(s2);
    sov_destroy(s3);
    sov_destroy(s4);
    sov_destroy(s5);
    sov_destroy(s6);
    vector_destroy(v1);
    vector_destroy(v2);
    vector_destroy(v3);
    vector_destroy(v4);
    vector_destroy(v5);
    vector_destroy(v6);
    vector_destroy(v7);
    vector_destroy(v8);
    vector_destroy(v9);
    vector_destroy(v10);
    vector_destroy(v11);
}