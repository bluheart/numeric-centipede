#include <stdlib.h>
#include "higher_order.h"

node_t* map(node_t* const head, int (*func)(int)) {
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

void map_mut(node_t* const head, int (*func)(int)) {
    if (head == NULL)
        return;
    node_t* iter = head;
    while (iter != NULL) {
        iter->value = func(iter->value);
        iter = iter->next;
    }
}

node_t* filter(node_t* const head, bool (*func)(int)) {
    if (head == NULL)
        return NULL;
    node_t* iter = head;
    node_t* res_head = node_create(func(head->value));
    iter = iter->next;
    while (iter != NULL) {
        if (func(iter->value)) {
          list_add_back(iter->value, &res_head);
        }
        iter = iter->next;
    }
    return res_head;
}

int foldl(node_t* const head, int (*func)(int, int), int acc) {
    if (head == NULL)
        return 0;
    node_t* iter = head;
    while (iter != NULL) {
        acc = func(acc, iter->value);
        iter = iter->next;
    }
    return acc;
}

void foreach(node_t* const head, void (*func)(int)) {
  if (head == NULL)
    return;
  node_t* iter = head;
  while (iter != NULL) {
    func(iter->value);
    iter = iter->next;
  }
}
