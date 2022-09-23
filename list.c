#include "list.h"

void list_init(List ** dest) {
    List * list = *dest;
    list = (List *) malloc(sizeof(List));
    list->begin = NULL;
    list->length = 0;
    *dest = list;
}

void list_init_size(List ** dest, int length) {
    list_init(dest);
    for (int i = 0; i < length; i++) {
        list_append(dest, 0);
    }
}

void list_init_values(List ** dest, int length, long long values[]) {
    list_init(dest);
    for (int i = 0; i < length; i++) {
        list_append(dest, values[i]);
    }
}

void list_append(List ** dest, long long value) {
    List * list = *dest;
    list->length++;
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
    return (*src)->length;
}


void list_prepend(List ** dest, long long value) {
    List * list = *dest;
    if (list->begin == NULL) {
        list_append(dest, value);
        return;
    }

    list->length++;
    Node * first = list->begin;
    Node * new_element = (Node *) malloc(sizeof(Node));

    list->begin = new_element;
    new_element->value = value;
    new_element->next = first;
}


Node * list_get_node(List ** src, int pos) {
    List * list = *src;
    if (pos < 0) {
        pos = list->length + pos;
    }
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

long long list_get(List ** src, int pos) {
    Node * it = list_get_node(src, pos);
    return it->value;
}

void list_replace(List ** dest, int pos, long long value) {
    Node * it = list_get_node(dest, pos);

    it->value = value;
}

void list_insert(List ** dest, int pos, long long value) {
    List * list = *dest;

    if (pos == 0) {
        list_prepend(dest, value);
        return;
    }

    if (pos >= list_len(dest)) {
        return;
    }

    if (list->begin == NULL) {
        list_append(dest, value);
        return;
    }

    list->length++;

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
    list->length--;
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

    if (list->begin == NULL) {
        return;
    }

    if (list_len(dest) <= 1) {
        list_remove_first(dest);
        return;
    }

    Node * prev = list_get_node(dest, list_len(dest) - 2);
    free(prev->next);
    list->length--;
    prev->next = NULL;
}

void list_remove(List ** dest, int pos) {
    if (pos == 0) {
        list_remove_first(dest);
        return;
    }

    if (pos == list_len(dest) - 1) {
        list_remove_last(dest);
        return;
    }

    (*dest)->length--;

    Node * prev_element = list_get_node(dest, pos-1);
    Node * rm_element = prev_element->next;
    Node * next_element = rm_element->next;

    free(rm_element);
    prev_element->next = next_element;
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

void list_swap(List ** dest, int pos1, int pos2) {
    List * list = *dest;

    Node * first  = list_get_node(dest, pos1);
    Node * second  = list_get_node(dest, pos2);
    long long tmp = second->value;
    second->value = first->value;
    first->value = tmp;
}

void merge_sort(List ** dest, List ** buff, int l, int r, int desc) {
    if (l < r) {
        int m = (l + r) / 2;
        merge_sort(dest, buff, l, m, desc);
        merge_sort(dest, buff, m + 1, r, desc);

        int k = l;
        for (int i = l, j = m + 1; i <= m || j <= r; ) {
            if (j > r || (i <= m && ((desc) ? 1 : -1) * list_get(dest, i) > ((desc) ? 1 : -1) * list_get(dest, j))) {
                list_replace(buff, k, list_get(dest, i));
                i++;
            } else {
                list_replace(buff, k, list_get(dest, j));
                j++;
            }
            k++;
        }
        for (int i = l; i <= r; i++) {
            list_replace(dest, i, list_get(buff, i));
        }
    }
}

void list_sort(List ** dest, int desc) {
    List * list = *dest;
    List * buffer;
    list_init_size(&buffer, list_len(dest));
    merge_sort(dest, &buffer, 0, list_len(dest) - 1, desc);
}

int list_compare(List ** src_first, List ** src_second) {
    List * first = *src_first;
    List * second = *src_second;

    if (first->length != second->length) return 0;

    for (int i = 0; i < first->length - 1; i++) {
        if (list_get(src_first, i) != list_get(src_second, i)) return 0;
    }

    return 1;
}

void list_merge(List ** dest, List ** src) {
    List * list = *src;
    list_iter(list) {
        list_append(dest, it->value);
    }
}

void destroy_node(Node * node) {
    if (node->next == NULL) {
        free(node);
        return;
    }
    destroy_node(node->next);
    node->next = NULL;
}

void list_clear(List ** dest) {
    List * list = *dest;
    destroy_node(list->begin);
    list->begin = NULL;
    list->length = 0;
}

void list_destroy(List ** dest) {
    list_clear(dest);
    free(*dest);
}

int list_count(List ** src, long long value) {
    List * list = *src;
    int result = 0;
    list_iter(list) {
        if (it->value == value) {
            result++;
        }
    }

    return result;
}

// If count is 0, remove all occurrences, else remove first 'count' elements
void list_remove_value(List ** dest, long long value, int count) {
    int pos = 0;
    if (count == 0) {
        count = -1;
    }
    List * list = *dest;
    list_iter(list) {
        if (count == 0) {
            return;
        }
        if (it->value == value) {
            list_remove(dest, pos);
            count--;
            list_remove_value(dest, value, count);
            return;
        }
        pos++;
    }
}

void list_reverse(List ** dest) {
    for (int i = 0; i < (*dest)->length / 2; i++) {
        list_swap(dest, i, -1-i);
    }
}

long long list_sum(List ** src) {
    List * list = *src;
    long long result = 0;

    list_iter(list) {
        result += it->value;
    }

    return result;
}

long long list_product(List ** src) {
    List * list = *src;
    long long result = 1;

    list_iter(list) {
        result *= it->value;
    }

    return result;
}

long long list_min(List ** src) {
    List * list = *src;
    long long result = LLONG_MAX;

    list_iter(list) {
        if (it->value < result) {
            result = it->value;
        }
    }

    return result;
}

long long list_max(List ** src) {
    List * list = *src;
    long long result = LLONG_MIN;

    list_iter(list) {
        if (it->value > result) {
            result = it->value;
        }
    }

    return result;
}
