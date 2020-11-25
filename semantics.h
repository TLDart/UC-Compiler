#ifndef SEMANTICS
#define SEMANTICS
#include <stdio.h>
#include "symbol_table.h"
extern struct scope* scope_head;


int check_program(struct program* head);
int check_f_dec(struct function_declaration* f_dec, int scope);
int check_dec(struct declaration* dec, int scope);
int check_f_def(struct function_definition* fdef);
#endif
