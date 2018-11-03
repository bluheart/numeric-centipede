#include "list.h"

node_t* map(int (*func)(int), node_t* const head) {
    if (head == NULL)
        return NULL;
    node_t* iter = head;
    node_t* res_head = node_create(func(head->value));
    iter = iter->next;
    while (iter != NULL) {
        list_add_back(func(iter->value), &res_head);
        iter = iter->next;
    }
    return res_head;
}

int foldl(int (*func)(int, int), int acc, node_t* const head) {
    if (head == NULL)
        return 0;
    node_t* iter = head;
    while (iter != NULL) {
        acc = func(acc, iter->value);
        iter = iter->next;
    }
    return acc;
}

