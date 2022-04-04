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
```

extern void print_tree(Tree *tree); - Func for tree preaty print
extern void print_tree_as_list(Tree *tree); - Func for tree print as list

static tree_node *_new_node(vtype_tree_t tkey, vtype_tree_t tvalue, void *key, void *value);
static void _set_tree(tree_node *node, vtype_tree_t tkey, vtype_tree_t tvalue, void *key, void *value);
static void _set_key(tree_node *node, vtype_tree_t tkey, void *key);
static void _set_value(tree_node *node, vtype_tree_t tvalue, void *value);
static void _free_tree(tree_node *node);
static void _print_tree_as_list(tree_node *node, vtype_tree_t tkey, vtype_tree_t tvalue);
static void _print_tree(tree_node *node, vtype_tree_t tkey, vtype_tree_t tvalue);
static void _print_tree_elem(tree_node *node, vtype_tree_t tkey, vtype_tree_t tvalue);
static tree_node *_get_tree(tree_node *node, vtype_tree_t tkey, void *key);
static tree_node *_del1_tree(Tree *tree, vtype_tree_t tkey, void *key);
static void _del2_tree(Tree *tree, tree_node *node);
static void _del3_tree(tree_node *node);
