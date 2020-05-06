// This is a simple test for vector module

#include "vector.h"
#include <assert.h>
#include <stdio.h>

int main(void) {
    double a[5] = {1, 2, 3, 4, 5};
    double b[5] = {1, 2, 3, 4, 6};
    double c[4] = {1, 2, 3, 4};
    double d[3] = {1, 2, 3};
    double e[3] = {1, -2, 1};
    double f[3] = {8, 2, -4};
    double g[2] = {2, 3};
    double h[2] = {2, 1};

    struct vector *v1 = vector_create(5, a);
    struct vector *v2 = vector_create(5, b);
    struct vector *v3 = vector_create(4, c);

    assert(vectors_equal(v1, v1));
    assert(!vectors_equal(v1, v2));
    assert(!vectors_equal(v1, v3));

    struct vector *v4 = add(v1, v2);
    // print_vector(v4);
    struct vector *v5 = subtract(v1, v2);
    // print_vector(v5);
    struct vector *v6 = scale_mult(10, v1);
    // print_vector(v6);
    struct vector *v7 = scale_mult(0, v1);
    // print_vector(v7);

    assert(dot_product(v1, v2) == 60);

    struct vector *v8 = vector_create(3, d);
    struct vector *v9 = vector_create(3, e);
    struct vector *v10 = vector_create(3, f);
    assert(vectors_equal(cross_product(v8, v9), v10));

    assert(is_orthogonal(v8, v9));
    // printf("%.2f\n", norm(v1));
    // printf("%.2f\n", norm(v2));
    // printf("%.2f\n", angle(v1, v2));

    struct vector *v11 = vector_create(2, g);
    struct vector *v12 = vector_create(2, h);
    // print_vector(proj(v11, v12));
    // print_vector(proj(v12, v11));
    // print_vector(perp(v11, v12));
    // assert(vectors_equal(proj(v1, v1), v1));
    // print_vector(proj(v8, v9));

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
}