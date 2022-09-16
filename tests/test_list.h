#ifndef TEST_LIST_H
#define TEST_LIST_H

#include "../list.h"
#include <stdio.h>

int test_list_init();
int test_list_len();
int test_list_prepend();
int test_list_append();
int test_list_insert();
int test_list_replace();
int test_list_remove_first();
int test_list_remove_last();
int test_list_remove();
int test_list_index();

static int (*tests[])() = {
        test_list_init,
        test_list_append,
        test_list_len,
        test_list_prepend,
        test_list_insert,
        test_list_replace,
        test_list_remove_first,
        test_list_remove_last,
        test_list_remove,
        test_list_index
};

#endif //TEST_LIST_H
