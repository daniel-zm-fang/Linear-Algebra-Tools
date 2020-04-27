// This is a simple test for scalar_equation_of_plane module

#include "scalar_equation_of_plane.h"
#include <assert.h>
#include <stdio.h>

int main(void) {
    struct seop *s1 = seop_create(2, 2, -96, 4);
    struct seop *s2 = seop_create(0, 0, 0, 0);
    struct seop *s3 = seop_create(-1, 3, 5, -999);

    // print_seop(s1);
    // print_seop(s2);

    struct vector *v9 = get_normal_vector(s1);
    struct vector *v10 = get_normal_vector(s2);
    // print_vector(v9);
    // print_vector(v10);

    double a[3] = {3, 1, -1};
    double b[3] = {-1, -1, 5};
    double c[3] = {2, 3, 3};
    double d[3] = {15, 6, 8};
    double e[3] = {15, 5, 8};
    double f[3] = {4, 1, 2};
    double g[3] = {0, 1, 2};
    double h[3] = {0, 0, 0};
    double i[3] = {2, 3, 1};

    struct vector *v1 = vector_create(3, a);
    struct vector *v2 = vector_create(3, b);
    struct vector *v3 = vector_create(3, c);
    struct vector *v4 = vector_create(3, d);
    struct vector *v5 = vector_create(3, e);
    struct vector *v6 = vector_create(3, f);
    struct vector *v7 = vector_create(3, g);
    struct vector *v8 = vector_create(3, h);
    struct vector *v11 = vector_create(3, i);

    struct seop *s4 = vector_to_scalar(v1, v2, v3);
    struct seop *s5 = vector_to_scalar(v1, v2, v3);

    // print_seop(s4);
    // print_seop(s5);

    assert(is_point_on_plane(v3, s4));
    assert(is_point_on_plane(v4, s4));
    assert(!is_point_on_plane(v5, s4));

    struct seop *s6 = seop_create(3, -1, 4, 0);
    struct vector *v12 = proj_onto_plane(v11, s6);
    struct vector *v13 = perp_onto_plane(v11, s6);
    // print_vector(v12);
    // print_vector(v13);

    seop_destroy(s1);
    seop_destroy(s2);
    seop_destroy(s3);
    seop_destroy(s4);
    seop_destroy(s5);
    seop_destroy(s6);

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
    vector_destroy(v12);
    vector_destroy(v13);
}
