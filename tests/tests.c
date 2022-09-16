#include <stdio.h>
#include "test_list.h"

int main () {
    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i ++) {
        int res = tests[i]();
        if (res) printf("[ERROR] ");
        else printf("[OK] ");
        printf("Result code: %d\n", res);
    }
    return 0;
}