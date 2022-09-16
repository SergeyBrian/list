#include "test_list.h"

void debug(char * msg) {
    printf("Running test %s\n", msg);
}

void print(char * msg) {
    printf("%s\n", msg);
}

void print_list(List * list) {
    for (int i = 0; i < list_len(&list); i++) {
        printf("%d: %lli\n", i, list_get(&list, i));
    }
    printf("===\n\n");
}

int test_list_init() {
    debug("list_init");
    List * list;
    list_init(&list);

    return 0;
}

int test_list_init_size() {
    debug("list_init_size");
    List * list;
    list_init_size(&list, 10);
    return list_len(&list) != 10;
}

int test_list_len() {
    debug("list_len");
    List * list;
    list_init(&list);
    if (list_len(&list) != 0) return 1;
    list_append(&list, 1);
    if (list_len(&list) != 1) return 2;
    return 0;
}

int test_list_prepend() {
    debug("list_prepend");
    List * list;
    list_init(&list);
    list_prepend(&list, 2);
    list_prepend(&list, 1);
    if (list_get(&list, 0) != 1 || list_get(&list, 1) != 2) return 1;
    return 0;
}

int test_list_append() {
    debug("list_append");
    List * list;
    list_init(&list);
    list_append(&list, 1);
    list_append(&list, 2);
    if (list_get(&list, 0) != 1 || list_get(&list, 1) != 2) return 1;
    return 0;
}

int test_list_insert() {
    debug("list_insert");
    List * list;
    list_init(&list);
    list_insert(&list, 0, 3);
    list_insert(&list, 0, 1);
    list_insert(&list, 1, 2);
    if (list_get(&list, 0) != 1 || list_get(&list, 1) != 2 || list_get(&list, 2) != 3) {
        print_list(list);
        return 1;
    }
    return 0;
}

int test_list_replace() {
    debug("list_replace");
    List * list;
    list_init(&list);
    list_append(&list, 4);
    list_append(&list, 3);
    list_replace(&list, 0, 8);
    list_replace(&list, 1, 6);
    if (list_get(&list, 0) != 8 || list_get(&list, 1) != 6) {
        print_list(list);
        return 1;
    }
    return 0;
}

int test_list_remove_first() {
    debug("list_remove_first");
    List * list;
    list_init(&list);
    list_append(&list, 5);
    list_append(&list, 2);
    list_remove_first(&list);
    if (list_get(&list, 0) != 2) {
        print_list(list);
        return 1;
    }
    return 0;
}

int test_list_remove_last() {
    debug("list_remove_last");
    List * list;
    list_init(&list);
    list_append(&list, 5);
    list_append(&list, 2);
    list_remove_last(&list);
    if (list_get(&list, 0) != 5) {
        print_list(list);
        return 1;
    }
    return 0;
}

int test_list_remove() {
    debug("list_remove");
    List * list;
    list_init(&list);
    list_append(&list, 5);
    list_append(&list, 2);
    list_append(&list, 7);
    list_remove(&list, 1);
    if (list_get(&list, 1) != 7) {
        print_list(list);
        return 1;
    }
    return 0;
}

int test_list_index() {
    debug("list_index");
    List * list;
    list_init(&list);
    list_append(&list, 5);
    list_append(&list, 2);
    list_append(&list, 7);
    if (list_get(&list, 1) != 2) {
        print_list(list);
        return 1;
    }
    return 0;
}

int test_list_swap() {
    debug("list_swap");
    List * list;
    list_init(&list);
    list_append(&list, 1);
    list_append(&list, 2);
    list_swap(&list, 0, 1);
    if (list_get(&list, 0) != 2 || list_get(&list, 1) != 1) {
        print_list(list);
        return 1;
    }
    return 0;
}

int test_list_sort() {
    debug("list_sort");
    List * list;
    list_init(&list);
    list_append(&list, 5);
    list_append(&list, 0);
    list_append(&list, 8);
    list_append(&list, 199);
    list_append(&list, 12);
    list_append(&list, 4);
    list_sort(&list, 0);
    long long prev = -1;
    list_iter(list) {
        if (prev > it->value) {
            print_list(list);
            return 1;
        }
        prev = it->value;
    }
    return 0;
}

int test_list_compare() {
    debug("list_compare");
    List * list1;
    List * list2;

    list_init(&list1);
    list_init(&list2);

    list_append(&list1, 1);
    list_append(&list2, 1);
    list_append(&list1, 2);
    list_append(&list2, 2);
    list_append(&list1, 3);
    list_append(&list2, 3);
    return !list_compare(&list1, &list2);
}