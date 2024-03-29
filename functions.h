#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structures.h"

struct oplines* getopl(int lines, int cols);
struct info* getInfo(char* name, int lines, int cols);
struct program* insert_program_func_def(struct function_definition* i_f_def, struct program* rem);
struct program* insert_program_func_def_rem(struct program* head, struct function_definition* i_f_def);
struct program* insert_program_func_dec(struct function_declaration* i_f_dec, struct program* rem);
struct program* insert_program_func_dec_rem(struct program* head, struct function_declaration* i_f_dec);
struct program* insert_program_dec(struct declaration* i_dec, struct program* rem);
struct program* insert_program_dec_rem(struct program* head, struct declaration* i_dec);
struct function_definition* insert_function_definition(struct tpspec* tsp, struct info* i_id, struct parameter_list* i_param_list, struct function_body* i_f_body);
struct function_declaration* insert_function_declaration(struct tpspec* tsp, struct info* i_id, struct parameter_list* i_param_list);
struct parameter_declaration* insert_param_dec(struct tpspec* tsp, struct info* i_id);
struct parameter_list* insert_param_list(struct parameter_declaration* p_dec, struct parameter_list* rem);
struct parameter_list* insert_param_list_rem(struct parameter_list* head, struct parameter_declaration* p_dec);
struct function_body* insert_f_body_statement(struct statement* stt);
struct function_body* insert_f_body_declaration(struct declaration* dec);
struct function_body* insert_f_body_multiple(struct function_body* f_b1, struct function_body* f_b2);
struct declarator* insert_decl(struct info* i_id, struct expression* i_expr);
struct declaration* insert_dec(struct tpspec* tsp,struct declarator* i_decl, struct declaration* i_dec);
struct declaration* insert_dec_rem(struct declaration* head, struct declarator* i_decl);
struct tpspec* insert_tpspec(int i_typespec, int lines, int cols);
struct statement* insert_statement(struct statement* head, struct statement* new);
struct statement* insert_return(struct expression* i_expr,struct oplines* opl);
struct statement* insert_if_statement(struct expression* i_expr, struct statement* i_if_body, struct statement* i_else_body, struct oplines* opl);
struct statement* insert_while_statement(struct expression* i_expr, struct statement* i_while_body, struct oplines* opl);
struct statement* insert_statlist(struct statement* i_statlist_body);
struct statement* insert_expr_statement(struct expression* i_expr);
//new
struct expression* insert_expression_op1(int operation,struct oplines* opl, struct expression* arg);
struct expression* insert_expression_op2(struct expression* arg1,struct  oplines* opl, int operation, struct expression* arg2);
struct expression* insert_expression_call(struct info* id, struct expression* exp, struct call* exp_list);
struct expression* insert_expression_terminal(struct info* id, int type);
struct call* insert_expression_kleen(struct call* head, struct expression* exp);

#endif