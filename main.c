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

int list_get(const int n, node_t** const node) {
    node_t* iter = (*node);
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


int main(){
    node_t* test = node_create(7);
    printf("%d\n", test->value);
    list_add_front(10, &test);
    printf("%d\n", test->value);
    list_add_back(3, &test);
    printf("%d\n", list_get(2, &test));
    printf("%d\n", test->value);
    list_free(&test);
    printf("%d\n", test==NULL);
    return 0;
}

