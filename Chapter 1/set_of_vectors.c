#include "set_of_vectors.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// This is the implementation of set of vectors
// See set_of_vectors.h for documentations

struct sov {
    int num_vectors;
    struct node *vectors;
};

struct node {
    struct vector *value;
    struct node *next;
};

// node_create(v, vnext, is_first) creates a new "node" that can
//  be added to a set of vectors
// requires: v is not a NULL pointer
// effects: allocates memory (client must free)
// time: O(1)

static struct node *node_create(struct vector *v, struct node *vnext) {
    assert(v);
    struct node *new_node = malloc(sizeof(struct node));
    new_node->next = vnext;
    new_node->value = v;
    return new_node;
}

struct sov *sov_create() {
    struct sov *s = malloc(sizeof(struct sov));
    s->num_vectors = 0;
    s->vectors = NULL;
    return s;
}

bool is_set_empty(const struct sov *s) {
    assert(s);
    if (s->num_vectors == 0) {
        return true;
    }
    return false;
}

bool contains_vector(const struct vector *v, const struct sov *s) {
    assert(v);
    assert(s);
    struct node *temp = s->vectors;
    for (int i = 0; i < s->num_vectors; i++) {
        if (vectors_equal(v, temp->value)) {
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

struct sov *dup_sov(const struct sov *s) {
    assert(s);
    struct sov *new_s = sov_create();
    new_s->num_vectors = s->num_vectors;
    new_s->vectors = dup_nodes(s->vectors);
    return new_s;
}

bool are_sets_equal(const struct sov *s1, const struct sov *s2) {
    assert(s1);
    assert(s2);
    if (s1->num_vectors != s2->num_vectors) {
        return false;
    }
    struct node *temp = s1->vectors;
    while (temp) {
        if (!contains_vector(temp->value, s2)) {
            return false;
        }
        temp = temp->next;
    }
    return true;
}

void add_to_set(struct vector *v, struct sov *s) {
    assert(v);
    assert(s);
    if (s->num_vectors == 0) {
        s->vectors = node_create(v, NULL);
    } else {
        assert(get_dimension(s->vectors->value) == get_dimension(v));
        s->vectors = node_create(v, s->vectors);
    }
    s->num_vectors += 1;
}

bool remove_from_set(const struct vector *v, struct sov *s) {
    assert(v);
    assert(s);
    assert(s->num_vectors);
    if (vectors_equal(s->vectors->value, v)) {
        s->num_vectors -= 1;
        struct node *temp = s->vectors;
        s->vectors = s->vectors->next;
        free(temp);
        return true;
    }

    struct node *prev_node = s->vectors;
    while (prev_node->next && !vectors_equal(v, prev_node->next->value)) {
        prev_node = prev_node->next;
    }
    if (prev_node->next == NULL) {
        return false;
    }
    struct node *old_node = prev_node->next;
    prev_node->next = prev_node->next->next;
    free(old_node);
    s->num_vectors -= 1;
    return true;
}

void print_sov(const struct sov *s) {
    assert(s);
    printf("set info:\n");
    printf("    number of vectors: %d\n", s->num_vectors);
    struct node *temp = s->vectors;
    while (temp) {
        printf("    ");
        print_vector(temp->value);
        temp = temp->next;
    }
    printf("\n");
}

void sov_destroy(struct sov *s) {
    assert(s);
    struct node *curr_node = s->vectors;
    struct node *next_node = NULL;
    while (curr_node) {
        next_node = curr_node->next;
        vector_destroy(curr_node->value);
        free(curr_node);
        curr_node = next_node;
    }
    free(s);
}