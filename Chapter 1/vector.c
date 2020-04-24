#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector.h>

// This is the implementation for vector
// See vector.h for documentation of functions

struct vector {
    int len;
    int *a;
};

struct vector *vector_create(int l, int *arr) {
    assert(l > 0);
    struct vector *v = malloc(sizeof(struct vector));
    v->len = l;
    v->a = malloc(v->len * sizeof(int));
    for (int i = 0; i < v->len; ++i) {
        v->a[i] = arr[i];
    }
    return v;
}

bool vectors_are_equal(const struct vector *v1, const struct vector *v2) {
    assert(v1);
    assert(v2);
    if (v1->len == v2->len) {
        for (int i = 0; i < v1->len; ++i) {
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
    assert(v1->len == v2->len);
    int *arr = malloc(v1->len * sizeof(int));
    for (int i = 0; i < v1->len; ++i) {
        arr[i] = v1->a[i] + v2->a[i];
    }
    struct vector *v = vector_create(v1->len, arr);
    free(arr);
    return v;
}

struct vector *subtract(const struct vector *v1, const struct vector *v2) {
    assert(v1);
    assert(v2);
    assert(v1->len == v2->len);
    int *arr = malloc(v1->len * sizeof(int));
    for (int i = 0; i < v1->len; ++i) {
        arr[i] = v1->a[i] - v2->a[i];
    }
    struct vector *v = vector_create(v1->len, arr);
    free(arr);
    return v;
}

struct vector *scale_mult(int num, const struct vector *v) {
    assert(v);
    int *arr = malloc(v->len * sizeof(int));
    for (int i = 0; i < v->len; ++i) {
        arr[i] = v->a[i] * num;
    }
    struct vector *temp = vector_create(v->len, arr);
    free(arr);
    return temp;
}

void print_vector(const struct vector *v) {
    assert(v);
    printf("length: %d\n[", v->len);
    for (int i = 0; i < v->len - 1; ++i) {
        printf("%d ", v->a[i]);
    }
    printf("%d]\n", v->a[v->len - 1]);
}

void vector_destroy(struct vector *v) {
    assert(v);
    free(v->a);
    free(v);
}