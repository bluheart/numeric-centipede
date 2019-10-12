#include <stdlib.h>
#include "higher_order.h"

node_t* map(node_t* const *head, int (*func)(int)) {
    if (*head == NULL)
        return NULL;
    node_t* res_head = node_create(func((*head)->value));
    head = &((*head)->next);
    while (*head != NULL) {
        list_add_back(func((*head)->value), &res_head);
        head = &((*head)->next);
    }
    return res_head;
}

void map_mut(node_t* const *head, int (*func)(int)) {
    if (*head == NULL)
        return;
    while (*head != NULL) {
        (*head)->value = func((*head)->value);
        head = &((*head)->next);
    }
}

node_t* filter(node_t* const *head, bool (*func)(int)) {
    if (*head == NULL)
        return NULL;
    node_t* res_head = node_create(func((*head)->value));
    head = &((*head)->next);
    while (*head != NULL) {
        if (func((*head)->value)) {
          list_add_back((*head)->value, &res_head);
        }
        head = &((*head)->next);
    }
    return res_head;
}

int foldl(node_t* const *head, int (*func)(int, int), int acc) {
    if (*head == NULL)
        return 0;
    while (*head != NULL) {
        acc = func(acc, (*head)->value);
        head = &((*head)->next);
    }
    return acc;
}

void foreach(node_t* const *head, void (*func)(int)) {
  if (*head == NULL)
    return;
  while (*head != NULL) {
    func((*head)->value);
    head = &((*head)->next);
  }
}
