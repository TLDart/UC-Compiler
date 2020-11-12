#include "structures.h"

struct program* insert_program_func_def(struct function_definition* i_f_def, struct program* rem);
struct program* insert_program_func_def_rem(struct program* head, struct function_definition* i_f_def);
struct program* insert_program_func_dec(struct function_declaration* i_f_dec, struct program* rem);
struct program* insert_program_func_dec_rem(struct program* head, struct function_declaration* i_f_dec);
struct program* insert_program_dec(struct declaration* i_dec, struct program* rem);
struct program* insert_program_dec_rem(struct program* head, struct declaration* i_dec);
struct function_definition* insert_function_definition(int i_typespec, char* i_id, struct parameter_list* i_param_list, struct function_body* i_f_body);
struct function_declaration* insert_function_declaration(int i_typespec, char* i_id, struct parameter_list* i_param_list);

