#include <stdio.h>
#include "list.h"
#include "higher_order.h"

int square(int x) {
    return x*x;
}

bool is_even(int x) {
  return x%2==0;
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
// small tests
int main() {
    int i;
    int fold_res;
    node_t* head = node_create(1);
    node_t* nhead;
    node_t* filter_head;
    for (i = 2; i < 11; i++)
        list_add_back(i, &head);
    list_print(&head);
    foreach(&head, &square_print);
    printf("char at %d is %d\n", 4, list_get(4, &head));
    printf("list length is %d\n", list_length(&head));
    nhead = map(&head, &square);
    list_print(&nhead);
    filter_head = filter(&head, &is_even);
    list_print(&filter_head);
    map_mut(&head, &square);
    list_print(&head);
    fold_res = foldl(&head, &sum, 0);
    printf("foldl result: %d\n", fold_res);
    printf("the sum is: %d\n", list_sum(&head));
    list_free(&filter_head);
    list_free(&head);
    list_free(&nhead);
    return 0;
}
