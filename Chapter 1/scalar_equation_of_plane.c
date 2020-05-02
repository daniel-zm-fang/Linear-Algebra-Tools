// This module contains the implementations of the scalar equation module

#include "scalar_equation_of_plane.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// This is the implementation for scalar equation of a plane
// See scalar_equation_of_plane.h for documentation of functions

struct seop {
    double x1;
    double x2;
    double x3;
    double c;
    struct vector *n;
};

// gcf(x, y) returns the greatest common factor of two numbers
// time: O(x)

static double gcf(int x, int y) {
    int factor = 1;
    double min;
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

struct seop *seop_create(double x, double y, double z, double d) {
    struct seop *s = malloc(sizeof(struct seop));
    int temp = gcf(gcf(x, y), gcf(z, d));
    s->x1 = x / temp;
    s->x2 = y / temp;
    s->x3 = z / temp;
    s->c = d / temp;
    double a[3] = {s->x1, s->x2, s->x3};
    s->n = vector_create(3, a);
    return s;
}

struct vector *get_normal_vector(const struct seop *s) {
    assert(s);
    return s->n;
}

struct seop *vector_to_scalar(const struct vector *v1, const struct vector *v2, const struct vector *v3) {
    assert(v1);
    assert(v2);
    assert(v3);
    assert(get_dimension(v1) == 3);
    assert(get_dimension(v2) == 3);
    assert(get_dimension(v3) == 3);
    struct vector *n = normal_vector(v1, v2);
    int d = vector_get_val(0, n) * vector_get_val(0, v3) +
            vector_get_val(1, n) * vector_get_val(1, v3) +
            vector_get_val(2, n) * vector_get_val(2, v3);
    return seop_create(vector_get_val(0, n), vector_get_val(1, n), vector_get_val(2, n), d);
}

bool is_point_on_plane(const struct vector *v, const struct seop *s) {
    assert(v);
    assert(s);
    return (vector_get_val(0, v) * s->x1 + vector_get_val(1, v) * s->x2 + vector_get_val(2, v) * s->x3) == s->c;
}

struct vector *proj_onto_plane(const struct vector *v, const struct seop *s) {
    assert(v);
    assert(s);
    assert(norm(s->n));
    return perp(v, s->n);
}

struct vector *perp_onto_plane(const struct vector *v, const struct seop *s) {
    assert(v);
    assert(s);
    assert(norm(s->n));
    return proj(v, s->n);
}

void print_seop(const struct seop *s) {
    assert(s);
    printf("scalar equation of a plane:\n");
    printf("%.2fx + %.2fy + %.2fz = %.2f\n", s->x1, s->x2, s->x3, s->c);
}

void seop_destroy(struct seop *s) {
    assert(s);
    vector_destroy(s->n);
    free(s);
    s = NULL;
}
