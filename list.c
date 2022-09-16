#include "list.h"

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

unsigned int list_len(List ** src) {
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


Node * list_get_node(List ** src, unsigned int pos) {
    List * list = *src;
    if (list->begin == NULL || pos >= list_len(src)) {
        return NULL;
    }
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

long long list_get(List ** src, unsigned int pos) {
    Node * it = list_get_node(src, pos);
    return it->value;
}

void list_replace(List ** dest, unsigned int pos, long long value) {
    Node * it = list_get_node(dest, pos);

    it->value = value;
}

void list_insert(List ** dest, unsigned int pos, long long value) {
    List * list = *dest;

    if (pos >= list_len(dest)) {
        return;
    }

    if (list->begin == NULL || pos == (list_len(dest) - 1)) {
        list_append(dest, value);
        return;
    }

    if (pos == 0) {
        list_prepend(dest, value);
    }

    Node * new_element = (Node *) malloc(sizeof(Node));

    Node * prev_element = list_get_node(dest, pos-1);
    Node * next_element = prev_element->next;

    prev_element->next = new_element;
    new_element->next = next_element;
    new_element->value = value;
}

void list_remove_first(List ** dest) {
    List * list = *dest;
    if (list->begin == NULL) {
        return;
    }
    if (list->begin->next == NULL) {
        list->begin = NULL;
        return;
    }

    Node * next_element = list->begin->next;
    free(list->begin);
    list->begin = next_element;
}

void list_remove_last(List ** dest) {
    List * list = *dest;
    if (list_len(dest) <= 1) {
        list_remove_first(dest);
        return;
    }
    Node * prev = list_get_node(dest, list_len(dest) - 2);
    free(prev->next);
    prev->next = NULL;
}

void list_remove(List ** dest, unsigned int pos) {
    if (pos == 0) {
        list_remove_first(dest);
        return;
    }

    if (pos == list_len(dest) - 1) {
        list_remove_last(dest);
        return;
    }

    Node * prev_element = list_get_node(dest, pos-1);
    Node * rm_element = prev_element->next;
    Node * next_element = rm_element->next;

    free(rm_element);
    prev_element->next = next_element;
}

char * list_to_str(List ** src) {
    char * result = (char *) malloc(sizeof(char) * (list_len(src)+1));
    unsigned int len = list_len(src);
    for (int i = 0; i < len; i++) {
        result[i] = (char) list_get(src, i);
    }
    result[len] = '\0';
    return result;
}

int list_index(List **src, long long int value) {
    List * list = *src;
    int pos = 0;
    if (list->begin != NULL) {
        Node * it = list->begin;
        while (it->value == value || it->next != NULL) {
            if (it->value == value) return pos;
            it = it->next;
            pos++;
        }
    }
    return -1;
}
