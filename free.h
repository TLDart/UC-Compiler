#ifndef FREELIB_H
#define FREELIB_H

#include <stdio.h>
#include <stdlib.h>

#include "structures.h"

void free_program(struct program* myprog);
void free_function_definition(struct function_definition* head);
void free_function_declaration(struct function_declaration* head);
void free_param_list(struct parameter_list* head);
void free_param_declaration(struct parameter_declaration* head);
void free_function_body(struct function_body* head);
void free_declaration(struct declaration* head);
void free_declarator(struct declarator* head);
void free_statement(struct statement* head);
void free_if(struct if_statement* head);
void free_return(struct return_statement* head);
void free_while(struct while_statement* head);
void free_statlist(struct statlist_statement* head);
/*new*/ 
void free_expression(struct expression* expr);
void free_op1(struct op1* op);
void free_op2(struct op2* op);
void free_term(struct terminal* t);
void free_call(struct call* c);
#endif
