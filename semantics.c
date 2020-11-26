#include "semantics.h"


int check_program(struct program* head){
    int count = 0;
    scope_head = create_scope(scope_head,"Global");
	insert_default_values(scope_head);
        while(head != NULL){
            if(head->type == t_f_def){
               count += check_f_def(head->data_program.u_f_def);
            }
            else if(head->type == t_f_dec){
                count += check_f_dec(head->data_program.u_f_dec, "Global");
            }
            else if(head->type == t_dec){
                count += check_dec(head->data_program.u_dec, "Global");
            }
            head = head->next;
        }      
    return count;
}

void insert_default_values(struct scope* head){
    struct function_declaration* new = (struct function_declaration*)malloc(sizeof(struct function_declaration));
    struct parameter_list* newplist = (struct parameter_list*)malloc(sizeof(struct parameter_list));
    struct parameter_declaration* newpdec = (struct parameter_declaration*)malloc(sizeof(struct parameter_declaration));
	
	newpdec->id = NULL;
	newpdec->type = t_typespec_int;
	newplist->p_dec = newpdec;
	newplist->next = NULL;
	new->param_list = newplist;
    new->type = t_typespec_int;  // return value
	head->symtab= insert_sym_element(head->symtab, create_sym_element("putchar", s_function,create_sym_f_param(new), 0));

    newpdec=(struct parameter_declaration*)malloc(sizeof(struct parameter_declaration));
	newpdec->id = NULL;
	newpdec->type = t_typespec_void;
	newplist->p_dec = newpdec;
	newplist->next = NULL;
	new->param_list = newplist;
    new->type = t_typespec_int;  // return value
	head->symtab= insert_sym_element(head->symtab, create_sym_element("getchar", s_function,create_sym_f_param(new), 0));
}

int check_f_dec(struct function_declaration* f_dec, char *name){
    int ec = 0;
    struct scope* s = get_scope_by_name(scope_head, name);

    if (get_token_by_name(s->symtab, f_dec->id)) {
        printf("Is this a double declaration?\n");//TODO
    } else {
        s->symtab= insert_sym_element(s->symtab, create_sym_element(f_dec->id, s_function, create_sym_f_param(f_dec), 0));
        //create a local scope to respect the order of functions
        create_scope(scope_head, f_dec->id);  
    }
    return ec;
}

int check_dec(struct declaration* dec, char *name){
    int ec = 0;
    //printf("Is checking dec\n");
    struct scope* s = get_scope_by_name(scope_head, name);
    struct declaration* current = dec;
    while(current){
        if(get_token_by_name(s->symtab, current->decl->id)){ //TODO: Isto só vê no próprio scope, não sei se para o tratamento de erros não é necessário ver também no global 
            printf("Is this a double declaration?\n");
        } else {
            //printf("Is inserting element\n");
            s->symtab = insert_sym_element(s->symtab, create_sym_element(current->decl->id, dec->type, NULL, 0));
        }
        current = current->next;
    }
    return ec;
}

int check_f_def(struct function_definition* fdef){
	int ec = 0;
    int len_declaration = 0;
    int len_definition = 0;

    struct sym_f_param* current_dec;
    struct parameter_list* current_def;
    struct sym_element* table_element;
    struct scope* global_scope = get_scope_by_name(scope_head,"Global");
    struct scope* s = get_scope_by_name(scope_head, fdef->id);
    struct function_declaration* f_dec = (struct function_declaration*) malloc(sizeof(struct function_declaration));

    if (s) { //meaning that it found a correct reference
        /* Checking Return Value */
        table_element = get_token_by_name(global_scope->symtab,s->name);
        if ((int) table_element->sym_f->return_value == (int) fdef->type) {
            printf("TEMPORARY: Return types match in Declaration and Definition\n");
        } else {
            printf("TEMPORARY: Return types don't match!\n"); 
            ec++;
        }
        /* Checking argc */
        // For the Declaration
        current_dec = table_element->sym_f->params;
        while(current_dec) {
            len_declaration++;
            current_dec = current_dec -> next;
        }
        // For the Definition
        current_def = fdef->param_list;
        while (current_def) {
            len_definition++;
            current_def = current_def->next;
        }
        if(len_declaration == len_definition){
            printf("TEMPORARY: Equal number of args in Declaration and Definition\n");
            current_dec = table_element->sym_f->params;
            current_def = fdef->param_list;
            while (current_dec && current_def) {
                if ((int) current_dec->param_type != (int) current_def->p_dec->type) {
                    printf("TEMPORARY: Diferentes tipos!!!\n");
                    ec++;
                } 
                current_dec = current_dec->next;   
                current_def = current_def->next;   
            }
        } else {
            printf("TEMPORARY: Different number of args!\n");
            ec++;
        }
    } else { //Meaning that it did not find a valid definition
        f_dec->type = fdef->type;
        f_dec->id = fdef->id;
        f_dec->param_list = fdef->param_list;
        global_scope->symtab = insert_sym_element(global_scope->symtab,create_sym_element(fdef->id, s_function, create_sym_f_param(f_dec), 0));
		create_scope(scope_head, fdef->id);
    }
    ec += check_return(fdef->type, fdef->id);
    ec += check_param_list(fdef->param_list, fdef->id);
    ec += check_f_body(fdef->f_body,fdef->id);
	return ec;
}

int check_return(typespec_type typ, char *name){
	//TODO check possible errors here
	int ec = 0;
	struct scope *head = get_scope_by_name(scope_head,name);
	head->symtab = insert_sym_element(head->symtab, create_sym_element("return", typ, NULL, 0));
	return ec; 
}

int check_param_list(struct parameter_list* pl, char* name){
	//TODO	 check possible errors
	int ec = 0;
	struct scope *head = get_scope_by_name(scope_head,name);
	while (pl) {
        if (pl->p_dec->id != NULL) {
            head->symtab = insert_sym_element(head->symtab, create_sym_element(pl->p_dec->id,pl->p_dec->type, NULL, 1));	
        }
		pl = pl->next;
	}
	return ec;
}

int check_f_body(struct function_body* head, char *name){
	int ec = 0;
	while(head != NULL){
        if(head->type == t_statement){
            //ec += check_statement(head->data_body.u_stt);
        }
        if(head->type == t_declaration){
            ec += check_dec(head->data_body.u_dec, name);
        }
        head = head->next;
    }
	return ec;
}

