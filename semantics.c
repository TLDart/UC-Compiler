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
                count += check_f_dec(head->data_program.u_f_dec, 0);
            }
            else if(head->type == t_dec){
                count += check_dec(head->data_program.u_dec, 0);
            }
            head = head->next;
        }      
    return count;
}


int check_f_dec(struct function_declaration* f_dec, int scope){
    struct scope* s= get_scope_by_id(scope_head, scope);

    if(get_token_by_name(s->symtab, f_dec->id)){
        printf("Is this a double declaration?\n");//TODO
    }
    else{
        s->symtab= insert_sym_element(s->symtab, create_sym_element(f_dec->id, s_function,create_sym_f_param(f_dec), 0));
    //create a local scope to respect the order of functions
        create_scope(scope_head, f_dec->id);  

    }
}
int check_dec(struct declaration* dec, int scope){
    printf("Is checking dec\n");
    struct scope* s= get_scope_by_id(scope_head, scope);

    if(get_token_by_name(s->symtab, dec->decl->id)){
        printf("Is this a double declaration?\n");
    }
    else{
        printf("Is inserting element\n");
        s->symtab = insert_sym_element(s->symtab, create_sym_element(dec->decl->id,dec->type,NULL, 0));
    }
}
int check_f_def(struct function_definition* fdef){
    struct scope* s= get_scope_by_name(scope_head, fdef->id);
    if(s){ //meaning that it found a correct reference
            //TODO assert that the declaration is correct



    }
    else{ //Meaning that it did not find valid definition
		struct scope *local = create_scope(scope_head, fdef->id);

		local->symtab = insert_sym_element(local->symtab, create_sym_element("return", fdef->type, NULL, 0));
		//TODO check parameter validity 
		struct parameter_list* tp = fdef->param_list;
		while(tp){//TODO in case we have a func(void) or when we have undefined paramters like dumb(int, int)
			local->symtab = insert_sym_element(local->symtab, create_sym_element(tp->p_dec->id,tp->p_dec->type, NULL, 1));	
			//printf("asdawsdasd\n");
			tp = tp->next;
		}
    }

}