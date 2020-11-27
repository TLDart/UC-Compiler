#ifndef SEMANTICS
#define SEMANTICS

#include <stdio.h>

#include "symbol_table.h"
#include "print_lib.h"

extern struct scope* scope_head;
extern int columns, lines, yyleng;
int check_program(struct program* head);
void insert_default_values(struct scope* head);
int check_f_dec(struct function_declaration* f_dec,char *name);
int check_dec(struct declaration* dec, char* name);
int check_f_def(struct function_definition* fdef);
int check_return_type(typespec_type typ, char *name);
int check_param_list(struct parameter_list* pl, char* name);
int check_f_body(struct function_body* head, char *name);
int check_statement(struct statement* head, char* name);
int check_if(struct if_statement* head, char* name);
int check_return(struct return_statement* rs, char* name);
int check_while(struct while_statement* head, char* name);
int check_statlist(struct statlist_statement* head, char* name);
int check_expression(struct expression* exp, char* name);
int check_op1(struct op1* op, char* name);
int check_op2(struct op2* op, char* name);
int check_terminal(struct terminal* t, char* name);
int check_call(struct call* c, char* name);
#endif
