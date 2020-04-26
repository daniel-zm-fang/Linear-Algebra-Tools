#include "vector.h"
#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// This is the implementation for vector
// See vector.h for documentation of functions

struct vector {
    int dimension;
    int *a;
};

struct vector *vector_create(int l, int *arr) {
    assert(l > 0);
    struct vector *v = malloc(sizeof(struct vector));
    v->dimension = l;
    v->a = malloc(v->dimension * sizeof(int));
    for (int i = 0; i < v->dimension; ++i) {
        v->a[i] = arr[i];
    }
    return v;
}

int get_dimension(const struct vector *v) {
    assert(v);
    return v->dimension;
}

bool vectors_are_equal(const struct vector *v1, const struct vector *v2) {
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
    return 0;
}

struct vector *add(const struct vector *v1, const struct vector *v2) {
    assert(v1);
    assert(v2);
    assert(v1->dimension == v2->dimension);
    int *arr = malloc(v1->dimension * sizeof(int));
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
    int *arr = malloc(v1->dimension * sizeof(int));
    for (int i = 0; i < v1->dimension; ++i) {
        arr[i] = v1->a[i] - v2->a[i];
    }
    struct vector *v = vector_create(v1->dimension, arr);
    free(arr);
    return v;
}

struct vector *scale_mult(int num, const struct vector *v) {
    assert(v);
    int *arr = malloc(v->dimension * sizeof(int));
    for (int i = 0; i < v->dimension; ++i) {
        arr[i] = v->a[i] * num;
    }
    struct vector *temp = vector_create(v->dimension, arr);
    free(arr);
    return temp;
}

int dot_product(const struct vector *v1, const struct vector *v2) {
    assert(v1);
    assert(v2);
    assert(v1->dimension == v2->dimension);
    int result = 0;
    for (int i = 0; i < v1->dimension; i++) {
        result += v1->a[i] * v2->a[i];
    }
    return result;
}

double norm(const struct vector *v) {
    assert(v);
    int sum = 0;
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
    int temp[3] = {v1->a[1] * v2->a[2] - v1->a[2] * v2->a[1],
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

void print_vector(const struct vector *v) {
    assert(v);
    printf("length: %d\n[", v->dimension);
    for (int i = 0; i < v->dimension - 1; ++i) {
        printf("%d ", v->a[i]);
    }
    printf("%d]\n", v->a[v->dimension - 1]);
}

void vector_destroy(struct vector *v) {
    assert(v);
    free(v->a);
    free(v);
}