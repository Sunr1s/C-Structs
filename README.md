# C-Structs
Three most popular data structures wroted on clean C. Can be used like library. 
# BinaryTree
```
extern Tree *new_tree(vtype_tree_t key, vtype_tree_t value); - This function generate new tree struct
extern void free_tree(Tree *tree); - This function clean memory and delete genesis node
extern value_tree_t get_tree(Tree *tree, void *key); - Recursive function for go on tree and print data
extern void set_tree(Tree *tree, void *key, void *value); - Add new data to tree
extern void del_tree(Tree *tree, void *key); - Delete datas from tree
extern _Bool in_tree(Tree *tree, void *key); - Check if some data in tree , return true if have


extern void print_tree(Tree *tree); - Func for tree preaty print
extern void print_tree_as_list(Tree *tree); - Func for tree print as list

```
# List
```
extern List *new_list(uint8_t *format, ...); - Create new list struct
extern void free_list(List *list); - Free memory and gelete genesis node

extern List *push_list(List *list, uint8_t *format, ...); - Add data to list
extern List *pop_list(List *list); - Take data from list

extern void print_list(List *list); - Print list

extern List *delbyid_list(List *list, size_t index); - Delete node with spesial id
extern List *addbyid_list(List *list, size_t index, uint8_t *format, ...); - Add node with spesial id
extern _Bool elemin_list(List *list, uint8_t *format, ...); - Check if list have element

```
