#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

struct DLL;
typedef struct DLL DLL;

// Creating and Destroying list
DLL * new_node(int value);
void destroy_list(DLL * node);

// Navigating list
DLL * move_right(DLL * node);
DLL * move_left (DLL * node);

// Getters and Setters
int get_val(DLL * node);
void set_val(DLL * node, int value);

#endif 