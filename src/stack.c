#include "stack.h"

struct s_node* init_stack(int data) {
    struct s_node* new_node = malloc(sizeof(struct s_node));
    if (new_node != NULL) {
        new_node->data = data;
        new_node->next = NULL;
    }
    return new_node;
}

struct s_node* push(struct s_node* top, int data) {
    struct s_node* new_node = init_stack(data);
    if (new_node != NULL) {
        new_node->next = top;
    }
    return new_node;
}

struct s_node* pop(struct s_node* top) {
    if (top == NULL) {
        return NULL;
    }
    struct s_node* new_top = top->next;
    free(top);
    return new_top;
}

void destroy_stack(struct s_node* top) {
    struct s_node* current = top;
    struct s_node* next_node;
    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }
}
