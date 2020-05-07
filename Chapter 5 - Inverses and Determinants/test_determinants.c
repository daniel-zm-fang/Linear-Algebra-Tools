// This is a simple test for the determinant module

#include "determinants.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>

const double epsilon = 0.00001;

// are_equal(a, b) returns true if two doubles are within a given range of accurracy
// time: O(1)

static bool are_equal(double a, double b) {
    return fabs(a - b) < epsilon;
}

int main(void) {
    double a[2] = {11};
    struct vector *v1 = vector_create(1, a);
    struct matrix *m1 = matrix_create();
    add_row(v1, m1);
    assert(determinant(m1) == 11);

    double b[2] = {3, 5};
    double c[2] = {-1, 2};
    struct vector *v2 = vector_create(2, b);
    struct vector *v3 = vector_create(2, c);
    struct matrix *m2 = matrix_create();
    add_row(v2, m2);
    add_row(v3, m2);
    assert(determinant(m2) == 11);

    double g[2] = {3, 6};
    double h[2] = {2, 4};
    struct vector *v7 = vector_create(2, g);
    struct vector *v8 = vector_create(2, h);
    struct matrix *m4 = matrix_create();
    add_row(v7, m4);
    add_row(v8, m4);
    assert(determinant(m4) == 0);

    double d[3] = {1, 0, 2};
    double e[3] = {0, 1, 1};
    double f[3] = {-2, 2, 3};
    struct vector *v4 = vector_create(3, d);
    struct vector *v5 = vector_create(3, e);
    struct vector *v6 = vector_create(3, f);
    struct matrix *m3 = matrix_create();
    add_row(v4, m3);
    add_row(v5, m3);
    add_row(v6, m3);
    assert(determinant(m3) == 5);

    double i[4] = {3, 2, -1, 1};
    double j[4] = {2, -1, 0, -3};
    double k[4] = {5, 2, 3, -2};
    double l[4] = {1, 3, -1, 4};
    struct vector *v9 = vector_create(4, i);
    struct vector *v10 = vector_create(4, j);
    struct vector *v11 = vector_create(4, k);
    struct vector *v12 = vector_create(4, l);
    struct matrix *m5 = matrix_create();
    add_row(v9, m5);
    add_row(v10, m5);
    add_row(v11, m5);
    add_row(v12, m5);
    assert(are_equal(determinant(m5), 0));

    double m[3] = {1, 0, 0};
    double n[3] = {-2, 3, 0};
    double o[3] = {10, 3, 0};
    struct vector *v13 = vector_create(3, m);
    struct vector *v14 = vector_create(3, n);
    struct vector *v15 = vector_create(3, o);
    struct matrix *m6 = matrix_create();
    add_row(v13, m6);
    add_row(v14, m6);
    add_row(v15, m6);
    assert(is_lower_triangular(m6) && !is_upper_triangular(m6));

    double p[3] = {2, -3, 5};
    double q[3] = {0, 2, 3};
    double r[3] = {0, 0, 2};
    struct vector *v16 = vector_create(3, p);
    struct vector *v17 = vector_create(3, q);
    struct vector *v18 = vector_create(3, r);
    struct matrix *m7 = matrix_create();
    add_row(v16, m7);
    add_row(v17, m7);
    add_row(v18, m7);
    assert(!is_lower_triangular(m7) && is_upper_triangular(m7));

    double s[3] = {3, 0, 1};
    double t[3] = {2, 1, 0};
    double u[3] = {1, 0, 0};
    struct vector *v19 = vector_create(3, s);
    struct vector *v20 = vector_create(3, t);
    struct vector *v21 = vector_create(3, u);
    struct matrix *m8 = matrix_create();
    add_row(v19, m8);
    add_row(v20, m8);
    add_row(v21, m8);
    assert(!is_lower_triangular(m8) && !is_upper_triangular(m8));

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
    vector_destroy(v14);
    vector_destroy(v15);
    vector_destroy(v16);
    vector_destroy(v17);
    vector_destroy(v19);
    vector_destroy(v20);
    vector_destroy(v21);
    matrix_destroy(m1);
    matrix_destroy(m2);
    matrix_destroy(m3);
    matrix_destroy(m4);
    matrix_destroy(m5);
    matrix_destroy(m6);
    matrix_destroy(m7);
    matrix_destroy(m8);
}