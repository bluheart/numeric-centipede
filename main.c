#include <stdio.h>
#include "list.h"
#include "higher_order.h"

int square(int x) {
    return x*x;
}

void square_print(int x) {
  printf("the square of %d is %d\n", x, x*x);
}

int sum(int a, int b) {
    return a+b;
}

int max(int a, int b) {
    return (a > b)?a:b;
}

int min(int a, int b) {
    return (a > b)?b:a;
}

int main() {
    int i;
    int fold_res;
    node_t* head = node_create(1);
    node_t* nhead;
    for (i = 2; i < 11; i++)
        list_add_back(i, &head);
    list_print(head);
    foreach(head, &square_print);
    nhead = map(head, &square);
    list_print(nhead);
    list_print(head);
    map_mut(head, &square);
    list_print(head);
    fold_res = foldl(head, &sum, 0);
    printf("foldl result: %d\n", fold_res);
    list_free(&head);
    list_free(&nhead);
    return 0;
}
