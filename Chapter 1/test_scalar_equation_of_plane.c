// This is a simple test for scalar_equation_of_plane module

#include "scalar_equation_of_plane.h"
#include <assert.h>
#include <stdio.h>

int main(void) {
    struct seop *s1 = seop_create(2, 2, -96, 4);
    struct seop *s2 = seop_create(0, 0, 0, 0);
    struct seop *s3 = seop_create(-1, 3, 5, -999);

    print_seop(s1);
    print_seop(s2);

    print_vector(get_normal_vector(s1));
    print_vector(get_normal_vector(s2));

    int a[3] = {3, 1, -1};
    int b[3] = {-1, -1, 5};
    int c[3] = {2, 3, 3};
    int d[3] = {15, 6, 8};
    int e[3] = {15, 5, 8};
    int f[3] = {4, 1, 2};
    int g[3] = {0, 1, 2};
    int h[3] = {0, 0, 0};

    struct vector *v1 = vector_create(3, a);
    struct vector *v2 = vector_create(3, b);
    struct vector *v3 = vector_create(3, c);
    struct vector *v4 = vector_create(3, d);
    struct vector *v5 = vector_create(3, e);
    struct vector *v6 = vector_create(3, f);
    struct vector *v7 = vector_create(3, g);
    struct vector *v8 = vector_create(3, h);

    struct seop *s4 = vector_to_scalar(v1, v2, v3);
    struct seop *s5 = vector_to_scalar(v1, v2, v3);

    print_seop(s4);
    print_seop(s5);

    assert(is_point_on_plane(v3, s4));
    assert(is_point_on_plane(v4, s4));
    assert(!is_point_on_plane(v5, s4));

    seop_destroy(s1);
    seop_destroy(s2);
    seop_destroy(s3);
    seop_destroy(s4);
    seop_destroy(s5);

    vector_destroy(v1);
    vector_destroy(v2);
    vector_destroy(v3);
    vector_destroy(v4);
    vector_destroy(v5);
    vector_destroy(v6);
    vector_destroy(v7);
    vector_destroy(v8);
}
