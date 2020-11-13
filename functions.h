#include "structures.h"

struct program* insert_program_func_def(struct function_definition* i_f_def, struct program* rem);
struct program* insert_program_func_def_rem(struct program* head, struct function_definition* i_f_def);
struct program* insert_program_func_dec(struct function_declaration* i_f_dec, struct program* rem);
struct program* insert_program_func_dec_rem(struct program* head, struct function_declaration* i_f_dec);
struct program* insert_program_dec(struct declaration* i_dec, struct program* rem);
struct program* insert_program_dec_rem(struct program* head, struct declaration* i_dec);
struct function_definition* insert_function_definition(int i_typespec, char* i_id, struct parameter_list* i_param_list, struct function_body* i_f_body);
struct function_declaration* insert_function_declaration(int i_typespec, char* i_id, struct parameter_list* i_param_list);
struct parameter_declaration* insert_param_dec(int i_typespec, char* i_id);
struct parameter_list* insert_param_list(struct parameter_declaration* p_dec, struct parameter_list* rem);
struct parameter_list* insert_param_list_rem(struct parameter_list* head, struct parameter_declaration* p_dec);
struct function_body* insert_f_body_statement(struct statement* stt);
struct function_body* insert_f_body_declaration(struct declaration* dec);
struct function_body* insert_f_body_multiple(struct function_body* f_b1, struct function_body* f_b2);
struct declarator* insert_decl(char* i_id, struct expression* i_expr);
struct declaration* insert_dec(int typespec,struct declarator* i_decl, struct declaration* i_dec);
struct declaration* insert_dec_rem(struct declaration* head, struct declarator* i_decl);