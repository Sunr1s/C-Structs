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
# HashTable
As we know HashTable based on which of the structures, like list or tree. In this case HashTable bulid on tree, witch we write already. So code contains tree.h and showing , how to use this code as Lib.
This is func, witch create hash taked in book K&R. This is very light hash interpritait method, and not orintable on cryptographic resistance against hacking. Do not recomendateusing in hight loaded projects. It takes each character of the string and adds 31 times the number of the character's place in the string, returning the remainder after dividing the result by the size of the string.
```
static uint32_t _strhash(uint8_t *s, size_t size){
	uint32_t hashval;
	for (hashval = 0; *s != '\0'; ++s){
		hashval = *s + 31 *hashval;
	}
	return hashval % size;
}
```
```
extern HashTab *new_hastab(size_t size, vtype_tree_t key, vtype_tree_t value); - Create new HashTable struct
extern void free_hastab(HashTab *hashtab); - This function clean memory and delete genesis node

extern value_tree_t get_hashtab(HashTab *hashtab, void *key); - Return elements from table
extern void set_hashtab(HashTab *hashtab, void *key, void *value); - Insert elements to table
extern void del_hashtab(HashTab *hashtab, void *key); - Delete element in table
extern _Bool in_hashtab(HashTab *hashtab, void *key); - Check if tabel contain element

extern void print_hashtab(HashTab *hashtab); - Print table
