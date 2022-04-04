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
