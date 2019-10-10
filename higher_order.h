#ifndef __HIGHER_ORDER_H
#define __HIGHER_ORDER_H

node_t* map(int (*func)(int), node_t* const head);

int foldl(int (*func)(int, int), int acc, node_t* const head);

#endif
