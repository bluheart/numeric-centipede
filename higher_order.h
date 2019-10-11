#ifndef __HIGHER_ORDER_H
#define __HIGHER_ORDER_H

node_t* map(node_t* const head, int (*func)(int));

void map_mut(node_t* const head, int (*func)(int));

int foldl(node_t* const head, int (*func)(int, int), int acc);

void foreach(node_t* const head, void (*func)(int));

#endif /* __HIGHER_ORDER_H */
