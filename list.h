#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

#define STR(x) #x
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

struct Node {
    long long value;
    struct Node * next;
};

struct List {
    struct Node * begin;
};

typedef struct Node Node;
typedef struct List List;

void list_init(List ** dest);
void list_init_size(List ** dest, unsigned int length);
unsigned int list_len(List ** src);
void list_prepend(List ** dest, long long value);
void list_append(List ** dest, long long value);
void list_insert(List ** dest, unsigned int pos, long long value);
Node * list_get_node(List ** src, unsigned int pos);
long long list_get(List ** src, unsigned int pos);
void list_replace(List ** dest, unsigned int pos, long long value);
void list_remove_first(List ** dest);
void list_remove_last(List ** dest);
void list_remove(List ** dest, unsigned int pos);
char * list_to_str(List ** src);
int list_index(List ** src, long long value);
void list_swap(List ** dest, unsigned int pos1, unsigned int pos2);
void list_sort(List ** dest, int desc);


#endif
