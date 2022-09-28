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
    list_append(&list, 1);
    if (list_index(&list, 2) != 1) {
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

int test_list_merge() {
    debug("list_merge");
    List * list1;
    List * list2;
    List * check;

    list_init(&list1);
    list_init(&list2);
    list_init_values(&check, 6, (long long[]) {1,2,3,4,5,6});

    list_append(&list1, 1);
    list_append(&list1, 2);
    list_append(&list1, 3);

    list_append(&list2, 4);
    list_append(&list2, 5);
    list_append(&list2, 6);

    list_merge(&list1, &list2);
    return !list_compare(&check, &list1);
}

int test_list_clear() {
    debug("list_clear");
    List * list;
    list_init(&list);
    list_append(&list, 1);
    list_append(&list, 2);
    list_append(&list, 3);
    list_append(&list, 4);
    list_clear(&list);
    return list->length;
}

int test_list_count() {
    debug("list_count");
    List * list;
    list_init(&list);
    list_append(&list, 1);
    list_append(&list, 1);
    list_append(&list, 1);
    return list_count(&list, 1) != 3;
}

int test_list_remove_value() {
    debug("list_remove_value");
    List * list;
    list_init(&list);
    list_append(&list, 1);
    list_append(&list, 2);
    list_append(&list, 5);
    list_append(&list, 1);
    list_append(&list, 1);
    list_remove_value(&list, 1, 1);
    if (list_get(&list, 0) != 2) return 1;
    list_remove_value(&list, 1, 0);
    if (list_get(&list, -1) != 5) {
        print_list(list);
        return 2;
    }
    return 0;
}

int test_list_reverse() {
    debug("list_reverse");
    List * list;
    List * check;
    list_init_values(&list, 5, (long long[]) {1, 2, 3, 4, 5});
    list_init_values(&check, 5, (long long[]) {5, 4, 3, 2, 1});
    list_reverse(&list);

    return !list_compare(&list, &check);
}

int test_list_sum() {
    debug("list_sum");
    List * list;
    list_init_values(&list, 5, (long long[]) { 1, 2, 3, 4, 5});
    return list_sum(&list) != 15;
}

int test_list_product() {
    debug("list_product");
    List * list;
    list_init_values(&list, 5, (long long[]) {1,2,3,4,5});
    return list_product(&list) != 120;
};

int test_list_min() {
    debug("list_min");
    List * list;
    list_init_values(&list, 10, (long long[]) {10, 9, 8, 1, 7, 6, 5, 4, 3, 2});
    return list_min(&list) != 1;
}

int test_list_max() {
    debug("list_max");
    List * list;
    list_init_values(&list, 10, (long long[]) {10, 9, 8, 1, 7, 6, 5, 4, 3, 2});
    return list_max(&list) != 10;
}

int is_even(long long value) {
    return value % 2 == 0;
}

int test_list_filter() {
    debug("list_filter");
    List * list;
    List * check;
    list_init_values(&list, 10, (long long[]) {1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    list_init_values(&check, 5, (long long[]) {2, 4, 6, 8, 10});
    List * result_list = list_filter(&list, &is_even);
    return !list_compare(&result_list, &check);
}

int is_less_than_11(long long value) {
    return value < 11;
}

int test_list_all() {
    debug("list_all");
    List * list;
    list_init_values(&list, 10, (long long[]) {1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    return !list_all(&list, is_less_than_11);
}

int test_list_any() {
    debug("list_any");
    List * list;
    list_init_values(&list, 10, (long long[]) {1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    return !list_any(&list, is_even);
}

long long multiply_by_2(long long x) {
    return x*2;
}

int test_list_map() {
    debug("list_map");
    List * list;
    List * check;
    list_init_values(&list, 10, (long long[]) {1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    list_init_values(&check, 10, (long long[]) {2, 4, 6, 8, 10, 12, 14, 16, 18, 20});
    list_map(&list, multiply_by_2);
    return !list_compare(&list, &check);
}

int test_sort_flag() {
    debug("sorted flag");
    List * list;
    list_init_values(&list, 5, (long long[]) {1, 2, 3, 4, 5});
    if (list->sorted != 1) return 1;
    list_reverse(&list);
    if (list->sorted != -1) return 2;
    list_append(&list, 0);
    if (list->sorted != -1) return 3;
    list_prepend(&list, 7);
    if (list->sorted != -1) return 4;
    list_insert(&list, 1, 6);
    if (list->sorted != -1) return 5;
    list_append(&list, 4);
    if (list->sorted != 0) return 6;
    return 0;
}
