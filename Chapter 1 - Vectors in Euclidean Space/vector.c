#include "vector.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// This is the implementation of functions of a vector
// See vector.h for documentation of functions

struct vector {
    int dimension;
    double *a;
};

struct vector *vector_create(int l, double *arr) {
    assert(l > 0);
    struct vector *v = malloc(sizeof(struct vector));
    v->dimension = l;
    v->a = malloc(v->dimension * sizeof(double));
    for (int i = 0; i < v->dimension; ++i) {
        v->a[i] = arr[i];
    }
    return v;
}

int get_vector_dimension(const struct vector *v) {
    assert(v);
    return v->dimension;
}

double vector_get_val(int pos, const struct vector *v) {
    assert(v);
    assert(pos >= 0);
    assert(pos < v->dimension);
    return v->a[pos];
}

bool is_zero_vector(const struct vector *v) {
    assert(v);
    for (int i = 0; i < v->dimension; i++) {
        if (v->a[i] != 0) {
            return false;
        }
    }
    return true;
}

bool vectors_equal(const struct vector *v1, const struct vector *v2) {
    assert(v1);
    assert(v2);
    if (v1->dimension == v2->dimension) {
        for (int i = 0; i < v1->dimension; ++i) {
            if (v1->a[i] != v2->a[i]) {
                return false;
            }
        }
        return true;
    } else {
        return false;
    }
}

struct vector *add(const struct vector *v1, const struct vector *v2) {
    assert(v1);
    assert(v2);
    assert(v1->dimension == v2->dimension);
    double *arr = malloc(v1->dimension * sizeof(double));
    for (int i = 0; i < v1->dimension; ++i) {
        arr[i] = v1->a[i] + v2->a[i];
    }
    struct vector *v = vector_create(v1->dimension, arr);
    free(arr);
    return v;
}

struct vector *subtract(const struct vector *v1, const struct vector *v2) {
    assert(v1);
    assert(v2);
    assert(v1->dimension == v2->dimension);
    double *arr = malloc(v1->dimension * sizeof(double));
    for (int i = 0; i < v1->dimension; ++i) {
        arr[i] = v1->a[i] - v2->a[i];
    }
    struct vector *v = vector_create(v1->dimension, arr);
    free(arr);
    return v;
}

struct vector *scale_mult(double num, const struct vector *v) {
    assert(v);
    double *arr = malloc(v->dimension * sizeof(double));
    for (int i = 0; i < v->dimension; ++i) {
        arr[i] = v->a[i] * num;
    }
    struct vector *temp = vector_create(v->dimension, arr);
    free(arr);
    return temp;
}

double dot_product(const struct vector *v1, const struct vector *v2) {
    assert(v1);
    assert(v2);
    assert(v1->dimension == v2->dimension);
    double result = 0;
    for (int i = 0; i < v1->dimension; i++) {
        result += v1->a[i] * v2->a[i];
    }
    return result;
}

double norm(const struct vector *v) {
    assert(v);
    double sum = 0;
    sum = dot_product(v, v);
    return sqrt(sum);
}

double angle(const struct vector *v1, const struct vector *v2) {
    assert(v1);
    assert(v2);
    assert(v1->dimension == v2->dimension);
    return acos(dot_product(v1, v2) / (norm(v1) * norm(v2)));
}

bool is_orthogonal(const struct vector *v1, const struct vector *v2) {
    assert(v1);
    assert(v2);
    assert(v1->dimension == v2->dimension);
    return dot_product(v1, v2) == 0;
}

struct vector *cross_product(const struct vector *v1, const struct vector *v2) {
    assert(v1);
    assert(v2);
    assert(v1->dimension == 3);
    assert(v2->dimension == 3);
    double temp[3] = {v1->a[1] * v2->a[2] - v1->a[2] * v2->a[1],
                      v1->a[2] * v2->a[0] - v1->a[0] * v2->a[2],
                      v1->a[0] * v2->a[1] - v1->a[1] * v2->a[0]};
    return vector_create(3, temp);
}

struct vector *normal_vector(const struct vector *v1, const struct vector *v2) {
    assert(v1);
    assert(v2);
    assert(v1->dimension == 3);
    assert(v2->dimension == 3);
    struct vector *normal = cross_product(v1, v2);
    return normal;
}

struct vector *proj(const struct vector *v1, const struct vector *v2) {
    assert(v1);
    assert(v2);
    assert(norm(v2));
    return scale_mult(dot_product(v1, v2) / pow(norm(v2), 2), v2);
}

struct vector *perp(const struct vector *v1, const struct vector *v2) {
    assert(v1);
    assert(v2);
    assert(norm(v2));
    return subtract(v1, proj(v1, v2));
}

void print_vector(const struct vector *v) {
    assert(v);
    printf("+-        -+\n");
    for (int i = 0; i < v->dimension; ++i) {
        printf("|%8.2f  |\n", v->a[i]);
    }
    printf("+-        -+\n\n");
}

void vector_destroy(struct vector *v) {
    assert(v);
    free(v->a);
    free(v);
    v = NULL;
}