#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>
#include <stdbool.h>

typedef enum {
    _INIT_ELEM,
    _DECIMAL_ELEM,
    _REAL_ELEM,
    _STRING_ELEM,
} vtype_list_t;

typedef union {
    int64_t decimal;
    double real;
    uint8_t *string;
} value_list_t;

typedef struct List {
	uint8_t index;
    vtype_list_t type;
    value_list_t value;
    struct List *next;
} List;

int _index = 0;
// List *list = new_list("drs", 555, 1.23, "hello, world!");
extern List *new_list(uint8_t *format, ...);
extern void free_list(List *list);

extern List *push_list(List *list, uint8_t *format, ...);
extern List *pop_list(List *list);

extern void print_list(List *list);

extern List *delbyid_list(List *list, size_t index);
extern List *addbyid_list(List *list, size_t index, uint8_t *format, ...);
extern _Bool elemin_list(List *list, uint8_t *format, ...);

int main(void) {
    List *list = new_list("drs", 555, 1.23, "hello, world!");
    List *temp = push_list(list, "d", 571);

    temp = push_list(temp, "ddd", 1, 2, 3);
    print_list(list);
	print_index(list);
    
	if(elemin_list(list,"d", 5545))
	printf("All Right\n");

	print_list(list);
	print_index(list);

	free_list(list);

    return 0;
}

extern List *new_list(uint8_t *format, ...) {
    List *list = (List*)malloc(sizeof(List));
    List *list_ptr = list;
	list-> index = _index;
    list->type = _INIT_ELEM;
    list->next = NULL;
    value_list_t value;
    va_list factor;
    va_start(factor, format);
    while(*format) {
        switch(*format) {
            case 'd': case 'i': // decimal
                value.decimal = va_arg(factor, int64_t);
                list_ptr = push_list(list_ptr, "d", value.decimal);
                break;
            case 'r': case 'f': // real
                value.real = va_arg(factor, double);
                list_ptr = push_list(list_ptr, "r", value.real);
                break;
            case 's': // string
                value.string = va_arg(factor, uint8_t*);
                list_ptr = push_list(list_ptr, "s", value.string);
                break;
        }
        ++format;
    }
    va_end(factor);
    return list;
}

extern List *push_list(List *list, uint8_t *format, ...) {
    if (list == NULL) {
        fprintf(stderr, "%s\n", "list is null");
        return NULL;
    }
    while (list->next != NULL) {
        list = list->next;
    }
    value_list_t value;
    va_list factor;
    va_start(factor, format);
    while(*format) {
        switch(*format) {
            case 'd': case 'i': // decimal
                value.decimal = va_arg(factor, int64_t);
                list->next = (List*)malloc(sizeof(List));
                list = list->next;
                list->type = _DECIMAL_ELEM;
                list->value.decimal = value.decimal;
                list->next = NULL;
                break;
            case 'r': case 'f': // real
                value.real = va_arg(factor, double);
                list->next = (List*)malloc(sizeof(List));
                list = list->next;
                list->type = _REAL_ELEM;
                list->value.real = value.real;
                list->next = NULL;
                break;
            case 's': // string
                value.string = va_arg(factor, uint8_t*);
                list->next = (List*)malloc(sizeof(List));
                list = list->next;
                list->type = _STRING_ELEM;
                list->value.string = value.string;
                list->next = NULL;
                break;
        }
        ++format;
		++ _index;
    }
    va_end(factor);
    return list;
}

extern List *pop_list(List *list) {
    if (list == NULL) {
        fprintf(stderr, "%s\n", "list is null");
        return NULL;
    }
    if (list->next == NULL) {
        return list;
    }
    List *prev_list = list;
    List *past_list = list->next;
    while(past_list->next != NULL) {
        prev_list = past_list;
        past_list = past_list->next;
    }
    prev_list->next = NULL;
    return past_list;
}
extern void print_index(List *list){

	while(list!=NULL){
		printf("%d, ", list->index);
		if(list->next==NULL)
			break;
		list = list->next;
		
	}

} 
extern void print_list(List *list) {
    printf("[ ");
    while (list != NULL) {
        switch (list->type) {
            case _DECIMAL_ELEM:
                printf("%d ", list->value.decimal);
                break;
            case _REAL_ELEM:
                printf("%lf ", list->value.real);
                break;
            case _STRING_ELEM:
                printf("'%s' ", list->value.string);
                break;
        }
        list = list->next;
    }
    printf("]\n");
	printf("\n");
	
}

extern void free_list(List *list) {
    List *list_ptr;
    while (list != NULL) {
        list_ptr = list->next;
        free(list);
        list = list_ptr;
    }
}


extern List *delbyid_list(List *list, size_t index){ 
    if (list == NULL) {
        fprintf(stderr, "%s\n", "list is null");
        return NULL;
    }
    if (index == 0) {
        return list;
    }
	 List *list_ptr;

    List *prev_list = list;
    List *past_list = list->next;
	List *first_list = list;

	while(prev_list->index != index) {
		first_list = prev_list;
		prev_list = past_list;
		past_list = past_list->next;
    }
    prev_list->next = NULL;
	first_list -> next = past_list;
	int i = 0;
	while (list != NULL) {
		list_ptr = list->next;
		list-> index = i;
        list = list_ptr;
		i++;
	}
    return first_list;

}
extern List* insertindex(List *list, size_t index){
	
    List *prev_list = list;
	List *past_list = list ->next;
	List *new_elem ;
	while(prev_list->index != index) {
		prev_list = prev_list ->next;
		past_list = past_list->next;
	} 
		prev_list->next = (List*)malloc(sizeof(List));
		new_elem = prev_list ->next;
		new_elem -> next= past_list;
		prev_list->next = new_elem;

	return new_elem;
}

extern List* normalizedindex(List* list){
	List* list_ptr;
	int i = 0;
	while (list != NULL) {
		list_ptr = list->next;
		list-> index = i;
        list = list_ptr;
		i++;
	}
	return list;
}


extern List *addbyid_list(List *list, size_t index, uint8_t *format, ...){
	value_list_t value;
	va_list factor;
    va_start(factor, format);
    while(*format) {
        switch(*format) {
            case 'd': case 'i': // decimal
                value.decimal = va_arg(factor, int64_t);
				list = insertindex(list,index);
				list->type = _DECIMAL_ELEM;
                list->value.decimal = value.decimal;
                break;
            case 'r': case 'f': // real
                value.real = va_arg(factor, double);
				list-> index = _index;
				list->type = _REAL_ELEM;
                list->value.real = value.real;
                break;
            case 's': // string
                value.string = va_arg(factor, uint8_t*);
				list->next = (List*)malloc(sizeof(List));
                list->type = _STRING_ELEM;
                list->value.string = value.string;
             break;
        }
        ++format;
		++ _index;
    }
    va_end(factor);
}

extern _Bool elemin_list(List *list, uint8_t *format, ...){
	if (list == NULL) {
        fprintf(stderr, "%s\n", "list is null");
        return NULL;
    }

	List * list_ptr;
	List * first_list = list;
	value_list_t value;
	va_list factor;
    va_start(factor, format);
    while(*format) {
        switch(*format) {
            case 'd': case 'i': // decimal
                value.decimal = va_arg(factor, int64_t);
				while(list!=NULL){
					list_ptr = list->next;
					if(list->value.decimal == value.decimal)
						return true;
				    list = list_ptr;
				}
					return false;
					break;
                   }
        ++format;
		++ _index;
    }
    va_end(factor);
    return list;

}
