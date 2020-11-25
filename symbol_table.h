#ifndef SYMTAB
#define SYMTAB
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"

extern struct scope* scope_list;

struct scope{
    int id;
    char* name;
    struct sym_element* symtab;
    struct scope* next;
};

typedef enum {s_char ,s_int, s_void, s_short, s_double, s_return, s_function} s_types;

struct sym_element{
    s_types type;
    char* name;
    struct sym_function* sym_f;
    int parameter;
    struct sym_element* next; 
};

struct sym_function{
    s_types return_value;
    struct sym_f_param* params;
};

struct sym_f_param{
    s_types param_type;
    struct sym_f_param* next;
};


struct scope* get_scope_by_id(struct scope* head, int id);
struct scope* get_scope_by_name(struct scope* head, char* name);
struct scope* create_scope(struct scope* head, char* name);
struct sym_element* get_token_by_name(struct sym_element* head, char* name);
struct sym_element* insert_sym_element(struct sym_element* head,struct sym_element* new);
struct sym_element* create_sym_element(char* name, s_types type, struct sym_function* f, int parameter);
struct sym_function* create_sym_f_param(struct function_declaration* f);


#endif