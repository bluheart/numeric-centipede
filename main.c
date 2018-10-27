#include <stdio.h>
#include "higher_order.h"

int square(int x) {
    return x*x;
}

int main() {
    int i;
    node_t* head = node_create(1);
    node_t* nhead;
    for (i = 2; i < 11; i++)
        list_add_back(i, &head);
    list_print(head);
    nhead = map( &square, head);
    list_print(nhead);
    return 0;
}


