// This is a simple test for vector module

#include "vector.h"
#include <assert.h>
#include <stdio.h>

int main(void) {
    int a[5] = {1, 2, 3, 4, 5};
    int b[5] = {1, 2, 3, 4, 6};
    int c[4] = {1, 2, 3, 4};
    int d[3] = {1, 2, 3};
    int e[3] = {1, -2, 1};

    struct vector *v1 = vector_create(5, a);
    struct vector *v2 = vector_create(5, b);
    struct vector *v3 = vector_create(4, c);
    struct vector *v8 = vector_create(3, d);
    struct vector *v9 = vector_create(3, e);

    assert(vectors_are_equal(v1, v1));
    assert(!vectors_are_equal(v1, v2));
    assert(!vectors_are_equal(v1, v3));

    struct vector *v4 = add(v1, v2);
    print_vector(v4);
    struct vector *v5 = subtract(v1, v2);
    print_vector(v5);
    struct vector *v6 = scale_mult(10, v1);
    print_vector(v6);
    struct vector *v7 = scale_mult(0, v1);
    print_vector(v7);

    printf("%d\n", dot_product(v1, v2));
    print_vector(cross_product(v8, v9));
    assert(is_orthogonal(v8, v9));
    printf("%f\n", norm(v1));
    printf("%f\n", norm(v2));
    printf("%f\n", angle(v1, v2));

    vector_destroy(v1);
    vector_destroy(v2);
    vector_destroy(v3);
    vector_destroy(v4);
    vector_destroy(v5);
    vector_destroy(v6);
    vector_destroy(v7);
    vector_destroy(v8);
    vector_destroy(v9);
}
