void print_indentation(int depth);
void print_ast(struct program* head);
void print_program(struct program* head, int depth);
void print_f_def(struct function_definition* f_dec, int depth);
void print_f_dec(struct function_declaration* f_dec, int depth);
void print_dec(struct declaration* f_dec, int depth);