#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

#define STR(x) #x
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))
#define list_iter(list) for(Node * it = list->begin; it != NULL; it = it->next)

struct Node {
    long long value;
    struct Node * next;
};

struct List {
    struct Node * begin;
    int length;
};

typedef struct Node Node;
typedef struct List List;

void list_init(List ** dest);
void list_init_size(List ** dest, int length);
void list_init_values(List ** dest, int length, long long values[]);
int list_len(List ** src);
void list_prepend(List ** dest, long long value);
void list_append(List ** dest, long long value);
void list_insert(List ** dest, int pos, long long value);
Node * list_get_node(List ** src, int pos);
long long list_get(List ** src, int pos);
void list_replace(List ** dest, int pos, long long value);
void list_remove_first(List ** dest);
void list_remove_last(List ** dest);
void list_remove(List ** dest, int pos);
char * list_to_str(List ** src);
int list_index(List ** src, long long value);
void list_swap(List ** dest, int pos1, int pos2);
void list_sort(List ** dest, int desc);
int list_compare(List ** src_first, List ** src_second);
void list_merge(List ** dest, List ** src);
void list_clear(List ** dest);
void list_destroy(List ** dest);
int list_count(List ** src, long long value);
void list_remove_value(List ** dest, long long value, int count);
void list_reverse(List ** dest);


#endif
