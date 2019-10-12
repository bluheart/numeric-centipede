#ifndef __HIGHER_ORDER_H
#define __HIGHER_ORDER_H

#include <stdbool.h>
#include "list.h"

node_t* map(node_t* const *head, int (*func)(int));

void map_mut(node_t* const *head, int (*func)(int));

node_t* filter(node_t* const *head, bool (*func)(int));

int foldl(node_t* const *head, int (*func)(int, int), int acc);

void foreach(node_t* const *head, void (*func)(int));

#endif /* __HIGHER_ORDER_H */
