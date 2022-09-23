#ifndef TEST_LIST_H
#define TEST_LIST_H

#include "../list.h"
#include <stdio.h>

int test_list_init();
int test_list_init_size();
int test_list_len();
int test_list_prepend();
int test_list_append();
int test_list_insert();
int test_list_replace();
int test_list_remove_first();
int test_list_remove_last();
int test_list_remove();
int test_list_index();
int test_list_swap();
int test_list_sort();
int test_list_compare();
int test_list_merge();
int test_list_clear();
int test_list_count();
int test_list_remove_value();
int test_list_reverse();
int test_list_sum();
int test_list_product();
int test_list_min();
int test_list_max();
int test_list_filter();
int test_list_all();
int test_list_any();
int test_list_map();

static int (*tests[])() = {
        test_list_init,
        test_list_init_size,
        test_list_append,
        test_list_clear,
        test_list_len,
        test_list_prepend,
        test_list_insert,
        test_list_replace,
        test_list_remove_first,
        test_list_remove_last,
        test_list_remove,
        test_list_remove_value,
        test_list_index,
        test_list_swap,
        test_list_sort,
        test_list_compare,
        test_list_merge,
        test_list_count,
        test_list_reverse,
        test_list_sum,
        test_list_product,
        test_list_min,
        test_list_max,
        test_list_filter,
        test_list_all,
        test_list_any,
        test_list_map
};

#endif //TEST_LIST_H
