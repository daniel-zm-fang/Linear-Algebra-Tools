#include "set_of_matrices.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// This is the implementation for set of matrices
// See set_of_matrices.h for documentations

struct som {
    bool is_span;
    int num_matrices;
    struct matrix *const_matrix;
    struct node *matrices;
};

struct node {
    struct matrix *value;
    struct node *next;
};

// node_create(m, vnext) creates a new "node" that can
//  be added to a set of matrices
// requires: m is not a NULL pointer
// effects: allocates memory (client must free)
// time: O(1)

static struct node *node_create(struct matrix *m, struct node *mnext) {
    assert(m);
    struct node *new_node = malloc(sizeof(struct node));
    new_node->next = mnext;
    new_node->value = matrix_copy(m);
    return new_node;
}

struct som *som_create() {
    struct som *s = malloc(sizeof(struct som));
    s->num_matrices = 0;
    s->matrices = NULL;
    s->const_matrix = NULL;
    s->is_span = false;
    return s;
}

bool is_set_matrices_span(const struct som *s) {
    assert(s);
    return s->is_span;
}

int get_num_matrices(const struct som *s) {
    assert(s);
    return s->num_matrices;
}

struct matrix *get_matrix(int pos, const struct som *s) {
    assert(pos >= 0);
    assert(pos < s->num_matrices);
    int count = 0;
    struct node *temp = s->matrices;
    while (count < pos) {
        count += 1;
        temp = temp->next;
    }
    return temp->value;
}

bool is_set_matrices_empty(const struct som *s) {
    assert(s);
    if (s->num_matrices == 0) {
        return true;
    }
    return false;
}

void change_som_span(bool span, struct som *s) {
    assert(s);
    s->is_span = span;
    if (!span) {
        matrix_destroy(s->const_matrix);
        s->const_matrix = NULL;
    }
}

void change_const_matrices(struct matrix *m, struct som *s) {
    assert(m);
    assert(s);
    s->const_matrix = m;
}

bool contains_matrix(const struct matrix *m, const struct som *s) {
    assert(m);
    assert(s);
    struct node *temp = s->matrices;
    for (int i = 0; i < s->num_matrices; i++) {
        if (matrices_equal(m, temp->value)) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// dup_nodes(old_node) creates a copy of a linked list of nodes starting from old_node
// effects: allocates memory (client must free)
// time: O(n), n = # of nodes connected to old_node

static struct node *dup_nodes(const struct node *old_node) {
    if (old_node == NULL) {
        return NULL;
    }
    return node_create(old_node->value, dup_nodes(old_node->next));
}

struct som *dup_som(const struct som *s) {
    assert(s);
    struct som *new_s = som_create();
    new_s->is_span = s->is_span;
    new_s->num_matrices = s->num_matrices;
    new_s->matrices = dup_nodes(s->matrices);
    if (s->const_matrix) {
        struct matrix *temp = matrix_create();
        temp = matrix_copy(s->const_matrix);
        new_s->const_matrix = temp;
    } else {
        new_s->const_matrix = NULL;
    }
    return new_s;
}

bool matrices_sets_equal(const struct som *s1, const struct som *s2) {
    assert(s1);
    assert(s2);
    if (s1->num_matrices != s2->num_matrices) {
        return false;
    }
    if (s1->is_span == s2->is_span) {
        if (s1->const_matrix && s2->const_matrix &&
            !matrices_equal(s1->const_matrix, s2->const_matrix)) {
            return false;
        }
    } else {
        return false;
    }
    struct node *temp = s1->matrices;
    while (temp) {
        if (!contains_matrix(temp->value, s2)) {
            return false;
        }
        temp = temp->next;
    }
    return true;
}

void add_to_matrices_set(struct matrix *m, struct som *s) {
    assert(m);
    assert(s);
    assert(num_aug_cols(m) == 0);
    if (s->num_matrices == 0) {
        s->matrices = node_create(m, NULL);
    } else {
        assert(num_rows(s->matrices->value) == num_rows(m));
        assert(num_cols(s->matrices->value) == num_cols(m));
        s->matrices = node_create(m, s->matrices);
    }
    s->num_matrices += 1;
}

bool remove_from_matrices_set(const struct matrix *m, struct som *s) {
    assert(m);
    assert(s);
    assert(s->num_matrices);
    if (matrices_equal(s->matrices->value, m)) {
        s->num_matrices -= 1;
        struct node *temp = s->matrices;
        s->matrices = s->matrices->next;
        free(temp);
        return true;
    }
    struct node *prev_node = s->matrices;
    while (prev_node->next && !matrices_equal(m,
                                              prev_node->next->value)) {
        prev_node = prev_node->next;
    }
    if (prev_node->next == NULL) {
        return false;
    }
    struct node *old_node = prev_node->next;
    prev_node->next = prev_node->next->next;
    free(old_node);
    s->num_matrices -= 1;
    return true;
}

void print_som(const struct som *s) {
    assert(s);
    if (s->is_span) {
        printf("span\n");
        if (s->const_matrix) {
            printf("constant matrix:\n");
            print_matrix(s->const_matrix);
        } else {
            printf("NULL constant matrix\n");
        }
    } else {
        printf("not a span\n");
    }
    printf("number of matrices: %d\n", s->num_matrices);
    if (s->num_matrices == 0) {
        printf("\n");
    }
    struct node *temp = s->matrices;
    while (temp) {
        print_matrix(temp->value);
        temp = temp->next;
    }
}

void som_destroy(struct som *s) {
    assert(s);
    struct node *curr_node = s->matrices;
    struct node *next_node = NULL;
    while (curr_node) {
        next_node = curr_node->next;
        matrix_destroy(curr_node->value);
        free(curr_node);
        curr_node = next_node;
    }
    if (s->const_matrix) {
        matrix_destroy(s->const_matrix);
    }
    free(s);
    s = NULL;
}