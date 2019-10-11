#ifndef __HIGHER_ORDER_H
#define __HIGHER_ORDER_H

node_t* map(int (*func)(int), node_t* const head);

void map_mut(int (*func)(int), node_t* const head);

int foldl(int (*func)(int, int), int acc, node_t* const head);

void foreach(void (*func)(int), node_t* const head);

#endif /* __HIGHER_ORDER_H */
