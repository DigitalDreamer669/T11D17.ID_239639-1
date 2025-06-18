#include "list.h"

struct node* init(struct door* door) {
    struct node* new_node = malloc(sizeof(struct node));

    if (new_node != NULL) {
        new_node->d = *door;
        new_node->next = NULL;
    }
    return new_node;
}

struct node* add_door(struct node* elem, struct door* door) {
    if (elem == NULL || door == NULL) {
        return NULL;
    }

    struct node* new_node = init(door);

    if (new_node != NULL) {
        new_node->next = elem->next;
        elem->next = new_node;
    }
    return new_node;
}

struct node* find_door(int door_id, struct node* root) {
    struct node* current = root;
    while (current != NULL) {
        if (current->d.id == door_id) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

struct node* remove_door(struct node* elem, struct node* root) {
    if (elem == NULL || root == NULL) {
        return root;
    }

    if (root == elem) {
        struct node* new_root = root->next;
        free(root);
        return new_root;
    }

    struct node* current = root;
    while (current->next != NULL && current->next != elem) {
        current = current->next;
    }

    if (current->next != NULL) {
        current->next = elem->next;
        free(elem);
    }

    return root;
}

void destroy(struct node* root) {
    struct node* current = root;
    struct node* next_node;
    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }
}
