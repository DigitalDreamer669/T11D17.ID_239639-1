#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

struct s_node {
    int data;
    struct s_node* next;
};

struct s_node* init_stack(int data);

struct s_node* push(struct s_node* top, int data);

struct s_node* pop(struct s_node* top);

void destroy_stack(struct s_node* top);

#endif
