#ifndef PRINTLIB_H
#define PRINTLIB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structures.h"
#include "symbol_table.h"

#define true 1
#define false 0

extern int ASTnoted;
extern struct scope* scope_head;

void print_indentation(int depth);
void print_ast(struct program* head);
void print_program(struct program* head, int depth);
void print_f_def(struct function_definition* f_dec, int depth);
void print_f_dec(struct function_declaration* f_dec, int depth);
void print_typespec(struct tpspec* tsp, int depth);
void print_id(char* id, int depth);
void print_param_list(struct parameter_list* p_list, int depth);
void print_param_dec(struct parameter_declaration* p_dec, int depth);
void print_f_body( struct function_body* f_body, int depth,char* local_scope_name);
void print_statement(struct statement* stt, int depth,char* local_scope_name);
void print_declaration(struct declaration* dec, int depth,char* local_scope_name);
void print_declarator(struct declarator* decl, int depth,char* local_scope_name);
void print_if(struct if_statement* stt_if, int depth,char* local_scope_name);
void print_return(struct return_statement* stt_ret, int depth,char* local_scope_name);
void print_while(struct while_statement* stt_whi, int depth,char* local_scope_name);
void print_statlist(struct statlist_statement* stt_stl, int depth,char* local_scope_name);
void print_expression(struct expression* expr, int depth,char* local_scope_name);
void print_op1(struct op1* op, int depth,char* local_scope_name);
void print_op2(struct op2* op, int depth,char* local_scope_name);
void print_term(struct terminal* t, int depth,char* local_scope_name);
void print_call(struct call* c, int depth,char* local_scope_name);

// Print Symbol Table

void showTable(struct scope* head);
void print_scope(struct sym_element* head);
void print_sym_element(struct sym_element* s_el);
void print_scope_f_dec(struct sym_function* sf);
void print_s_type(s_types s);

void print_op2_symbol(op2_type type);
// gets for Print AST-noted 
s_types get_expression_type(struct expression* exp, char* local_scope_name, int print_func);
s_types get_op1_type(struct op1* op, char* local_scope_name, int print_func);
s_types get_op2_type(struct op2* op, char* local_scope_name, int print_func);
s_types get_terminal_type(struct terminal* t, char* local_scope_name, int print_func);
s_types get_call_type(struct call* c, char* local_scope_name, int print_func);
s_types get_id_type(char* id, char* local_scope_name, int print_func);

#endif