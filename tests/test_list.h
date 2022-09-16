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

static int (*tests[])() = {
        test_list_init,
        test_list_init_size,
        test_list_append,
        test_list_len,
        test_list_prepend,
        test_list_insert,
        test_list_replace,
        test_list_remove_first,
        test_list_remove_last,
        test_list_remove,
        test_list_index,
        test_list_swap,
        test_list_sort,
        test_list_compare,
        test_list_merge
};

#endif //TEST_LIST_H
