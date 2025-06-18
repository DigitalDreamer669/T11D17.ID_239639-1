#include "list.h"

#include <stdio.h>

#define SUCCESS 1
#define FAIL 0

int test_add_door();
int test_remove_door();

int main() {
    int add_result = test_add_door();
    int remove_result = test_remove_door();

    printf("%s: add_door\n", add_result == SUCCESS ? "SUCCESS" : "FAIL");
    printf("%s: remove_door\n", remove_result == SUCCESS ? "SUCCESS" : "FAIL");

    return 0;
}

int test_add_door() {
    struct door d1 = {1, 1};
    struct door d2 = {2, 0};
    int result = FAIL;

    struct node* root = init(&d1);
    if (root == NULL) return FAIL;

    struct node* added_node = add_door(root, &d2);

    if (added_node != NULL && root->next == added_node && added_node->d.id == 2) {
        result = SUCCESS;
    }

    destroy(root);
    return result;
}

int test_remove_door() {
    struct door d1 = {10, 1};
    struct door d2 = {20, 0};
    struct door d3 = {30, 1};
    int result = FAIL;

    struct node* root = init(&d1);
    if (root == NULL) return FAIL;
    struct node* node2 = add_door(root, &d2);
    if (node2 == NULL) {
        destroy(root);
        return FAIL;
    }
    add_door(node2, &d3);

    root = remove_door(node2, root);

    if (find_door(20, root) == NULL && root->next != NULL && root->next->d.id == 30) {
        result = SUCCESS;
    }

    destroy(root);
    return result;
}
