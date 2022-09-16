#include <stdio.h>
#include "list.h"


void print_list(List * list) {
    for (int i = 0; i < list_len(&list); i++) {
        printf("%d: %lli\n", i, list_get(&list, i));
    }
    printf("===\n\n");
}

// Function tests
int main() {
    List * list;
    list_init(&list);
    list_append(&list, 4);
    print_list(list);
    list_prepend(&list, 8);
    print_list(list);
    list_insert(&list, 1, 12);
    print_list(list);
    list_replace(&list, 1, 20);
    print_list(list);
    list_remove(&list, 1);
    print_list(list);
    list_remove(&list, 1);
    print_list(list);
    list_remove(&list, 0);
    print_list(list);
    list_append(&list, 8);
    list_append(&list, 9);
    list_append(&list, 10);
    printf("Value 8 is at position %d\n", list_index(&list, 8));
    printf("Value 9 is at position %d\n", list_index(&list, 9));
    printf("Value 10 is at position %d\n", list_index(&list, 10));
    printf("Value 14 is at position %d\n", list_index(&list, 14));
    print_list(list);

    // Char examples
    List * list1;
    list_init(&list1);
    char str[4] = "test";
    for (int i = 0; i < 4; i++) {
        list_append(&list1, (long long) str[i]);
    }
    print_list(list1);
    printf("Convert list to str: %s\n", list_to_str(&list1));

    return 0;
}