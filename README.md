# C-Structs
Three most popular data structures wroted on clean C. Can be used like library. 
# BinaryTree

extern Tree *new_tree(vtype_tree_t key, vtype_tree_t value);
extern void free_tree(Tree *tree);

extern value_tree_t get_tree(Tree *tree, void *key);
extern void set_tree(Tree *tree, void *key, void *value);
extern void del_tree(Tree *tree, void *key);
extern _Bool in_tree(Tree *tree, void *key);

extern void *decimal(int64_t x);
extern void *string(uint8_t *x);
extern void *real(double x);

extern void print_tree(Tree *tree);
extern void print_tree_as_list(Tree *tree);

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
