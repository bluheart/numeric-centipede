#include <stdio.h>
#include <stdlib.h>
#include "list.h"

node_t* node_create(const int n) {
    node_t* head = malloc(sizeof(node_t));
    head->value = n;
    head->next = NULL;
    return head;
}

void list_add_front(const int n, node_t** const node) {
    node_t* head = node_create(n);
    head->next = (*node);
    (*node) = head;
}

void list_add_back(const int n, node_t** node) {
    node_t* last = node_create(n);
    for (;(*node)->next; node = &((*node)->next));
    (*node)->next = last;
}

int list_get(const int n, node_t** node) {
    if (n < 0)
        return 0;
    for (int i = 0; i < n; i++) {
        node = &((*node)->next);
        if (*node == NULL)
            return 0;
    }
    return ((*node)->value);
}

void list_free(node_t** node) {
    node_t* temp;
    while ((temp = (*node)) != NULL) {
        (*node) = (*node)->next;
        free(temp);
    }
}

int list_length(node_t** node) {
    int i = 0;
    for (; *node; i++, node = &((*node)->next));
    return i;
}

node_t* list_node_at(const int n, node_t** node) {
    for(int i = 0; *node; i++) {
        if (i == n)
            return (*node);
        node = &((*node)->next);
    }
    return NULL;
}

int list_sum(node_t** node) {
    int sum = 0;
    for (;*node; sum += (*node)->value,node = &((*node)->next));
    return sum;
}

void list_print(node_t** node) {
    for (;*node; node = &((*node)->next))
        printf("%d ", (*node)->value);
    puts("");
}
