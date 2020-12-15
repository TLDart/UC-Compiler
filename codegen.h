#ifndef CODEGEN 
#define CODEGEN
#include "structures.h"
#include "symbol_table.h"
#include <string.h>
#include "print_lib.h"

char* buf[250];
extern int varcounter;

char* codegen_terminal_type(t_type t);
char* get_expr_value(struct expression* exp);
void codegen(struct program* head, struct scope* scope_head);
void codegen_declaration(struct declaration* dec, int depth, char* scope_name);
void codegen_f_def(struct function_definition* f_def);
void codegen_param_list(struct parameter_list* p_list);
void codegen_param_list_stores(struct parameter_list* p_list);
void codegen_f_body(struct function_body* f_body, char* local_scope_name);
void codegen_statement(struct statement* stt, char* local_scope_name);
void codegen_return(struct return_statement* stt_ret, char* local_scope_name);
int codegen_expression(struct expression* expr, char* local_scope_name);
int codegen_op1(struct op1* op, char* local_scope_name); 
int codegen_op2(struct op2* op, char* local_scope_name);
int codegen_term(struct terminal* t, char* local_scope_name);
int codegen_call(struct call* c, char* local_scope_name);
#endif