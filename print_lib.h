#ifndef PRINTLIB_H
#define PRINTLIB_H

#include <stdio.h>
#include <stdlib.h>

#include "structures.h"

void print_indentation(int depth);
void print_ast(struct program* head);
void print_program(struct program* head, int depth);
void print_f_def(struct function_definition* f_dec, int depth);
void print_f_dec(struct function_declaration* f_dec, int depth);
void print_typespec(typespec_type type, int depth);
void print_id(char* id, int depth);
void print_param_list(struct parameter_list* p_list, int depth);
void print_param_dec(struct parameter_declaration* p_dec, int depth);
void print_f_body( struct function_body* f_body, int depth);
void print_statement(struct statement* stt, int depth);
void print_declaration(struct declaration* dec, int depth);
void print_declarator(struct declarator* decl, int depth);
void print_statement(struct statement* stt, int depth);
void print_if(struct if_statement* stt_if, int depth);
void print_return(struct return_statement* stt_ret, int depth);
void print_while(struct while_statement* stt_whi, int depth);
void print_statlist(struct statlist_statement* stt_stl, int depth);
void print_expression(struct expression* expr, int depth);
//new
void print_expression(struct expression* expr, int depth);
void print_op1(struct op1* op, int depth);
void print_op2(struct op2* op, int depth);
void print_term(struct terminal* t, int depth);
void print_call(struct call* c, int depth);
#endif