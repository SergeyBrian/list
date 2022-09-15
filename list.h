#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

#define STR(x) #x

struct Node {
    long long value;
    struct Node * next;
};

struct List {
    struct Node * begin;
};

typedef struct Node Node;
typedef struct List List;

void list_init(List ** dest) {
    List * list = *dest;
    list = (List *) malloc(sizeof(List));
    list->begin = NULL;
    *dest = list;
}

void list_append(List ** dest, long long value) {
    List * list = *dest;
    if (list->begin == NULL) {
        list->begin = (Node *) malloc(sizeof(Node));
        list->begin->value = value;
	list->begin->next = NULL;
        return;
    }

    Node * it = list->begin;
    while (it->next != NULL) {
        it = it->next;
    }
    it->next = (Node *) malloc(sizeof(Node));
    it->next->value = value;
    it->next->next = NULL;
}

int list_len(List ** src) {
    List * list = *src;
    if (list->begin == NULL) return 0;
    Node * it = list->begin;
    int len = 1;
    while (it->next != NULL) {
        len++;
        it = it->next;
    }
    return len;
}

void list_replace(List ** dest, int pos, long long value) {
    List * list = *dest;
    int i = 0;
    Node * it = list->begin;
    while (i != pos) {
        it = it->next;
        i++;
    }

    it->value = value;
}

void list_prepend(List ** dest, long long value) {
    List * list = *dest;
    if (list->begin == NULL) {
        list_append(dest, value);
        return;
    }

    Node * first = list->begin;
    Node * new_element = (Node *) malloc(sizeof(Node));

    list->begin = new_element;
    new_element->value = value;
    new_element->next = first;
}


Node * list_get_node(List ** src, int pos) {
    List * list = *src;
    Node * it = list->begin;
    int i = 0;
    while (it->next != NULL) {
        if (i == pos) {
            break;
        }
        i++;
        it = it->next;
    }
    return it;
}

long long list_get(List ** src, int pos) {
    Node * it = list_get_node(src, pos);
    return it->value;
}

void list_insert(List ** dest, int pos, long long value) {
    List * list = *dest;
    Node * new_element = (Node *) malloc(sizeof(Node));

    Node * prev_element = list_get_node(dest, pos-1);
    Node * next_element = prev_element->next;

    prev_element->next = new_element;
    new_element->next = next_element;
    new_element->value = value;
}

char * list_to_str(List ** src) {
    char * result = (char *) malloc(sizeof(char) * (list_len(src)+1));
    int len = list_len(src);
    for (int i = 0; i < len; i++) {
        result[i] = (char) list_get(src, i);
    }
    result[len] = '\0';
    return result;
}

#endif
