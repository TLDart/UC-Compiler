#include "semantics.h"


int check_program(struct program* head){
    int count = 0;
    int scope = 0;

    scope_head = create_scope(scope_head,"Global");
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


int check_f_dec(struct function_declaration* f_dec, char *name){
    struct scope* s= get_scope_by_name(scope_head, name);

    if(get_token_by_name(s->symtab, f_dec->id)){
        printf("Is this a double declaration?\n");//TODO
    }
    else{
        s->symtab= insert_sym_element(s->symtab, create_sym_element(f_dec->id, s_function,create_sym_f_param(f_dec), 0));
    //create a local scope to respect the order of functions
        create_scope(scope_head, f_dec->id);  

    }
}
int check_dec(struct declaration* dec, char *name){
    //printf("Is checking dec\n");
    struct scope* s= get_scope_by_name(scope_head, name);

    if(get_token_by_name(s->symtab, dec->decl->id)){
        printf("Is this a double declaration?\n");
    }
    else{
        //printf("Is inserting element\n");
        s->symtab = insert_sym_element(s->symtab, create_sym_element(dec->decl->id,dec->type,NULL, 0));
    }
}
int check_f_def(struct function_definition* fdef){
	int ec = 0;
    struct scope* s= get_scope_by_name(scope_head, fdef->id);
    if(s){ //meaning that it found a correct reference
            //TODO assert that the declaration is correct



    }
    else{ //Meaning that it did not find valid definition
		struct scope *local = create_scope(scope_head, fdef->id);

		ec += check_return(fdef->type, fdef->id);
		ec += check_param_list(fdef->param_list, fdef->id);
		ec += check_f_body(fdef->f_body,fdef->id);
    }
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
	int ec;
	struct scope *head = get_scope_by_name(scope_head,name);
	while(pl){//TODO in case we have a func(void) or when we have undefined paramters like dumb(int, int)
		head->symtab = insert_sym_element(head->symtab, create_sym_element(pl->p_dec->id,pl->p_dec->type, NULL, 1));	
		//printf("asdawsdasd\n");
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

