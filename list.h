#ifndef __LIST_H
#define __LIST_H

typedef struct node {
    int value;
    struct node* next;
} node_t;

node_t* node_create(const int n);

void list_add_front(const int n, node_t** const node);

void list_add_back(const int n, node_t** const node);

int list_get(const int n, node_t* const node);

void list_free(node_t** const node);

int list_length(node_t* const node);

node_t* list_node_at(const int n, node_t* const node);

int list_sum(node_t* const node);

void list_print(node_t* const node);

#endif /* __LIST_H */
