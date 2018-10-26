#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
//linked list program
typedef struct node {
    int value;
    struct node* next;
} node_t;


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

void list_add_back(const int n, node_t** const node) {
    node_t* tail = node_create(n);
    node_t* init = (*node);
    while ((*node)->next != NULL)
        (*node) = (*node)->next;
    (*node)->next = tail;
    (*node) = init;
}

int list_get(const int n, node_t* const node) {
    node_t* iter = node;
    int i;
    if (n < 0)
        return 0;
    for (i = 0; i < n; i++) {
        iter = iter->next;
        if (iter == NULL)
            return 0;
    }
    return (iter->value);
}

void list_free(node_t** const node) {
    node_t* temp;
    while ((temp = (*node)) != NULL) {
        (*node) = (*node)->next;
        free(temp);
    }
}

int list_length(node_t* const node) {
    node_t* iter = node;
    int i = 0;
    while(iter != NULL) {
        i++;
        iter = iter->next;
    }
    return i;
}

node_t* list_node_at(const int n, node_t* const node) {
    node_t* iter = node;
    int i = 0;
    while(iter != NULL) {
        i++;
        if (i == n)
            return iter;
        iter = iter->next;
    }
    return NULL;
}

int list_sum(node_t* const node) {
    node_t* iter = node;
    int sum = 0;
    while(iter != NULL) {
        sum += iter->value;
        iter = iter->next;
    }
    return sum;
}

int main(){
    node_t* node = node_create(2);
    list_add_front(1, &node);
    list_add_back(3, &node);
    printf("%d\n", node->value);
    printf("%d\n", list_sum(node));
    return 0;
}

