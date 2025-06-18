#include "stack.h"

#include <stdio.h>

#define SUCCESS 1
#define FAIL 0

int test_push();
int test_pop();

int main() {
    int push_result = test_push();
    int pop_result = test_pop();

    printf("%s: push\n", push_result == SUCCESS ? "SUCCESS" : "FAIL");
    printf("%s: pop\n", pop_result == SUCCESS ? "SUCCESS" : "FAIL");

    return 0;
}

int test_push() {
    int result = FAIL;
    struct s_node* top = NULL;

    top = push(top, 10);
    if (top != NULL && top->data == 10) {
        top = push(top, 20);
        if (top != NULL && top->data == 20 && top->next != NULL && top->next->data == 10) {
            result = SUCCESS;
        }
    }

    destroy_stack(top);
    return result;
}

int test_pop() {
    int result = FAIL;
    struct s_node* top = NULL;

    top = push(top, 20);
    top = push(top, 10);

    top = pop(top);

    if (top != NULL && top->data == 20) {
        top = pop(top);
        if (top == NULL) {
            result = SUCCESS;
        }
    }

    destroy_stack(top);
    return result;
}
