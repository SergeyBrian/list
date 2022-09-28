# Linked list for C

## Usage
Example program
```c
#include "list.h"

int main {
    List * list = list_init();
    list_append(list, 97);
    list_append(list, 98);
    list_append(list, 99);
    list_append(list, 100);
    printf("%s\n", list_to_str(list)); // Prints abcd
    list_destroy(list);
    return 0;
}
```
More examples can be found in [Functions section](#functions) and [tests code](tests/test_list.c)

## Functions
### Init, destroy
`list_init` to create new list, `list_destroy` to free memory

```c
List * list = list_init();
// Use list
list_destroy(list);
```

`list_init_size(l)` will create list initialized with `l` elements with value 0

`list_init_values(l, vs)` will create list initialized with `l` elements from array `vs`

```c
// Example using additional variable for array
long long values[] = {1, 2, 3, 4, 5};
List * list = list_init_values(5, values);
```

```c
// Example without additional variable
List * list = list_init_values(5, (long long[]) {1, 2, 3, 4, 5});
```

### Append, prepend, insert
Add items to list

```c
list_append(list, 3); // Add to end
list_prepend(list, 1); // Add to beginning
list_insert(list, 1, 2); // Add at position 1
// Result list: {1, 2, 3}
```
### Get by position
`list_get(list, n)` will return value stored at position `n`

### Remove from begin, end and position
```c
list_remove_first(list); // Remove first element
list_remove_last(list); // Remove last element
list_remove(list, 1); // Remove element at position 1
```

### Replace by position
`list_replace(list, n, v)` replace value of element at position `n` with value `v`

### Convert to string
`list_to_str(list)` returns `char *` where each symbol is char corresponding to element number in ASCII table

```c
List * list;
// Let's say that list contains numbers {97, 98, 99, 100}
printf("%s", list_to_str(list)); // Will print abcd
```

### Get position by value
`list_index(list, v)` will return index of first element with value `v`. If such element is not in list, function will return -1

### Sort
`list_str(list, int desc)` sorts list. (Descending if `desc` is not 0)

### Compare lists
`list_compare(list1, list2)` returns 1 if lists have elements with same values, 0 if not

### Merge
`list_merge(list1, list2)` appends all elements from `list2` to `list1`

### Remove all
`list_clear(list)` removes all elements from list

### Count by value
`list_count(list, v)` returns amount of elements with value `v`

### Remove by value
`list_remove_value(list, v, c)` removes first `c` elements with value `v`. If `c` = 0, removes all such elements

### Reverse
`list_revers(list)` reverses list

### Sum, product
`list_sum(list)` returns sum of all elements

`list_product(list)` returns product of all elements

### Min, max
`list_min(list)` returns min element

`list_max(list)` returns max element

### Filter
`list_filter(list, func)` returns a new list that contains only elements for which function `func` returns non-zero value

```c
int is_even(long long v) {
    return v % 2 == 0;
}

List * list;
// Let's say that list has elements {1, 2, 3, 4, 5, 6}
List * list1 = list_filter(list, is_even);
// list1 now has elements {2, 4, 6}
```

### All, any
`list_all(list, func)` returns 1 if function `func` returns non-zero value for all elements. Otherwise, returns 0

`list_any(list, func)` returns 1 if function `func` returns non-zero value for any element. Otherwise, returns 0

### Map
`list_map(list, func)` replaces each element of list with result `func` function for element value

```c
long long multiply_by_2(long long v) {
    return v*2;
}

List * list;
// Let's say that list has elements {1, 2, 3, 4}
list_map(list, multiply_by_2);
// list now has elements {2, 4, 6, 8}
```