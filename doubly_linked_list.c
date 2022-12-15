#include "doubly_linked_list.h"

#include <stdlib.h>

struct DLL {
    DLL * left;
    DLL * right;

    int value;
};

DLL * new_node(int value){
    DLL * dll = malloc(sizeof(DLL));
    
    dll->left = NULL;
    dll->right = NULL;
    dll->value = value;
    
    return dll;
}

int get_val(DLL * node){
    return node->value;
}
void set_val(DLL * node, int value){
    node->value = value;
}

void destroy_list(DLL * node){
    DLL * far_left = node;
    DLL * far_right = node->right;

    // Free left side
    while (far_left->left != NULL){
        far_left = far_left->left;
        free(far_left->right);
    }
    
    // Free right side
    while (far_right->right != NULL){
        far_right = far_right->right;
        free(far_right->left);
    }
}

DLL * move_right(DLL * node){
    if (node->right == NULL){ // No node to the right
        DLL * new_node = malloc(sizeof(DLL));

        node->right = new_node;

        new_node->left = node;
        new_node->right = NULL;
        new_node->value = 0;

        return new_node;
    } else { // There is a node to the right
        return node->right;
    }
}

DLL * move_left(DLL * node){
    if (node->left == NULL){ // No node to the left
        DLL * new_node = malloc(sizeof(DLL));

        node->left = new_node;

        new_node->left = NULL;
        new_node->right = node;
        new_node->value = 0;

        return new_node;
    } else { // There is a node to the left
        return node->left;
    }
}