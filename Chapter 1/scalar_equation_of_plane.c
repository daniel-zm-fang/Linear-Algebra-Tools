// This module contains the implementations of the scalar equation module

#include "scalar_equation_of_plane.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// This is the implementation for scalar equation of a plane
// See scalar_equation_of_plane.h for documentation of functions

struct seop {
    int x1;
    int x2;
    int x3;
    int c;
};

// gcf(x, y) returns the greatest common factor of two numbers
// time: O(x)

static int gcf(int x, int y) {
    int factor = 1;
    int min;
    if (abs(x) >= abs(y)) {
        min = abs(y);
    } else {
        min = abs(x);
    }
    for (int i = 1; i <= min; i++) {
        if (x % i == 0 && y % i == 0) {
            factor = i;
        }
    }
    return factor;
}

struct seop *seop_create(int x, int y, int z, int d) {
    struct seop *s = malloc(sizeof(struct seop));
    int temp = gcf(gcf(x, y), gcf(z, d));
    s->x1 = x / temp;
    s->x2 = y / temp;
    s->x3 = z / temp;
    s->c = d / temp;
    return s;
}

struct vector *get_normal_vector(const struct seop *s) {
    assert(s);
    int temp[3] = {s->x1, s->x2, s->x3};
    return vector_create(3, temp);
}

struct seop *vector_to_scalar(const struct vector *v1, const struct vector *v2, const struct vector *v3) {
    assert(v1);
    assert(v2);
    assert(v3);
    assert(get_dimension(v1) == 3);
    assert(get_dimension(v2) == 3);
    assert(get_dimension(v3) == 3);
    struct vector *n = normal_vector(v1, v2);
    int d = get_value(0, n) * get_value(0, v3) +
            get_value(1, n) * get_value(1, v3) +
            get_value(2, n) * get_value(2, v3);
    return seop_create(get_value(0, n), get_value(1, n), get_value(2, n), d);
}

bool is_point_on_plane(const struct vector *v, const struct seop *s) {
    assert(v);
    assert(s);
    return (get_value(0, v) * s->x1 + get_value(1, v) * s->x2 + get_value(2, v) * s->x3) == s->c;
}

void print_seop(const struct seop *s) {
    assert(s);
    printf("scalar equation of a plane:\n");
    printf("%dx + %dy + %dz = %d\n", s->x1, s->x2, s->x3, s->c);
}

void seop_destroy(struct seop *s) {
    assert(s);
    free(s);
}
