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
    struct info* newinfo = (struct info*)malloc(sizeof(struct info));
    struct tpspec* newtspec = (struct tpspec*)malloc(sizeof(struct tpspec));

    newtspec->type = t_typespec_int;
    newtspec->lines = -1;
    newtspec->cols = -1;

	newpdec->tsp = newtspec;
	newplist->p_dec = newpdec;
	newplist->next = NULL;
	new->param_list = newplist;

    newtspec = (struct tpspec*)malloc(sizeof(struct tpspec));

    newtspec->type = t_typespec_int;
    newtspec->lines = -1;
    newtspec->cols = -1;

    new->tsp = newtspec;  // return value
	head->symtab= insert_sym_element(head->symtab, create_sym_element("putchar", s_function,create_sym_f_param(new), 0,1));

    newpdec=(struct parameter_declaration*)malloc(sizeof(struct parameter_declaration));
    newinfo = (struct info*)malloc(sizeof(struct info));
    newinfo->id = NULL;	
	newpdec->info = newinfo;

    newtspec = (struct tpspec*)malloc(sizeof(struct tpspec));

    newtspec->type = t_typespec_void;
    newtspec->lines = -1;
    newtspec->cols = -1;
	newpdec->tsp = newtspec;
	newplist->p_dec = newpdec;
	newplist->next = NULL;
	new->param_list = newplist;

    newtspec = (struct tpspec*)malloc(sizeof(struct tpspec));

    newtspec->type = t_typespec_int;
    newtspec->lines = -1;
    newtspec->cols = -1;
    new->tsp = newtspec;  // return value
	head->symtab= insert_sym_element(head->symtab, create_sym_element("getchar", s_function,create_sym_f_param(new), 0,1));
}

int check_f_dec(struct function_declaration* f_dec, char *name){
    int ec = 0;
    int dif = 0;
    int counter = 0;
    int len_symbol_param = 0;
    int len_fdec_func = 0;
    struct parameter_list* void_param_flag = NULL;
    struct scope* s = get_scope_by_name(scope_head, name);
    struct sym_element* sym_elem = NULL;
    struct sym_f_param* current_first;
    struct parameter_list* current_second;
    // Check for void type
    current_second = f_dec->param_list;
    while (current_second){
        counter++;
        if (((s_types)current_second->p_dec->tsp->type == s_void) && (void_param_flag == 0)) {
            void_param_flag = current_second;
        }
        if ((void_param_flag && counter > 1) || (void_param_flag && current_second->p_dec->info && current_second->p_dec->info != NULL)){
            printf("Line %d, col %d: Invalid use of void type in declaration\n",void_param_flag->p_dec->tsp->lines,void_param_flag->p_dec->tsp->cols);
            return ec; // dont add function to the scope neither create a scope of their own
        }
        current_second = current_second->next;
    }
    ec += check_f_dec_param_list(f_dec->param_list);  
    if ((sym_elem = get_token_by_name(s->symtab, f_dec->info->id))) { 
        if (sym_elem->type == s_function){ // Case where the same token is a function 
            /* Checking if Signature is different*/
            // Number of parameters
            current_first = sym_elem->sym_f->params;
            while (current_first) {
                len_symbol_param++;
                current_first = current_first->next;
            }

            current_second = f_dec->param_list;
            while(current_second) {
                len_fdec_func++;
                current_second = current_second->next;
            }

            // Parameter Types matching
            if (len_fdec_func == len_symbol_param){
                current_first = sym_elem->sym_f->params;
                current_second = f_dec->param_list;
                while (current_first && current_second){
                    if (current_first->param_type != (s_types) current_second->p_dec->tsp->type){
                        dif++;
                    }
                    current_first = current_first->next;
                    current_second = current_second->next;
                }
            }
            // In case of Semantic Error
            if ((sym_elem->sym_f->return_value != (s_types) f_dec->tsp->type) || (len_fdec_func != len_symbol_param) || (dif > 0)){
                printf("Line %d, col %d: Conflicting types (got ",f_dec->info->lines,f_dec->info->cols);
                print_scope_f_dec(create_sym_f_param(f_dec));
                printf(", expected ");
                print_scope_f_dec(sym_elem->sym_f);
                printf(")\n");
                ec++;
            }      
        } else { // Case where the same token is not a function 
            // printf("Line %d, col %d: Symbol %s already defined\n",f_dec->info->lines,f_dec->info->cols,f_dec->info->id);
            printf("Line %d, col %d: Conflicting types (got ",f_dec->info->lines,f_dec->info->cols);
            print_scope_f_dec(create_sym_f_param(f_dec));
            printf(", expected ");
            print_s_type(sym_elem->type);
            printf(")\n");
            ec++;
        }
    } else {
        s->symtab= insert_sym_element(s->symtab, create_sym_element(f_dec->info->id, s_function, create_sym_f_param(f_dec), 0, 0));
        //create a local scope to respect the order of functions
        create_scope(scope_head, f_dec->info->id);  
    }
    return ec;
}

int check_f_dec_param_list(struct parameter_list* pl) {
    int ec = 0;
    struct scope* disney_scope = NULL;
    disney_scope = create_scope(disney_scope,"disney");
    struct sym_element* sym_elem = NULL;
    if (disney_scope){
        while(pl){
            if (pl->p_dec->info && pl->p_dec->info->id != NULL) {
                if(!(sym_elem = get_token_by_name(disney_scope->symtab,pl->p_dec->info->id))){// Se não encontrar nenhum simbolo no contexto local aka na própria param list
                    disney_scope->symtab = insert_sym_element(disney_scope->symtab, create_sym_element(pl->p_dec->info->id,(s_types)pl->p_dec->tsp->type, NULL, 1,1));	
                } else {
                    printf("Line %d, col %d: Symbol %s already defined\n",pl->p_dec->info->lines,pl->p_dec->info->cols,pl->p_dec->info->id);
                }
            }
            pl = pl->next;
        }
    }
    /*to free, not completed*/
    // sym_elem = disney_scope->symtab;
    // while(sym_elem){
    //     switch (sym_elem->type) {
    //         case /* constant-expression */:
    //             /* code */
    //             break;
    //     }
    //     sym_elem = sym_elem->next;
    // }
    // free(disney_scope->name);
    // free(disney_scope);
    return ec;
}

//TODO: fix int a; int a; int main(void){int a; int a;} 
int check_dec(struct declaration* dec, char *name){
    int ec = 0;
    int is_global = (int)!strcmp("Global",name);
    struct scope* s = get_scope_by_name(scope_head, name);
    struct declaration* current = dec;
    struct sym_element* sym_elem = NULL;
    int void_type_flag = 0;
    s_types s_type;
    if (s) {
        while(current){
            if((sym_elem = get_token_by_name(s->symtab, current->decl->info->id))){ 
                if (sym_elem->type == s_function){
                    // printf("Line %d, col %d: Symbol %s already defined\n",current->tsp->lines, current->tsp->cols, current->decl->info->id);
                    printf("Line %d, col %d: Conflicting types (got ",current->decl->info->lines, current->decl->info->cols);
                    print_s_type((s_types) current->tsp->type);
                    printf(", expected ");
                    print_scope_f_dec(sym_elem->sym_f);
                    printf(")\n");
                } else if (sym_elem->already_defined) {
                    if(is_global){
                        if (current->decl->expr != NULL) { // If current is a definition
                            printf("Line %d, col %d: Symbol %s already defined\n",current->decl->info->lines, current->decl->info->cols, current->decl->info->id);
                        } else {
                            // Not an error
                        }
                    } else { // Inside a Function
                        printf("Line %d, col %d: Symbol %s already defined\n",current->decl->info->lines, current->decl->info->cols, current->decl->info->id);
                    }
                } else if (!sym_elem->already_defined) { // Only declared, but not defined
                    if (is_global) {
                        if (sym_elem->type == (s_types) current->tsp->type) {
                            sym_elem->already_defined = ((current->decl->expr == NULL) ? 0 : 1);
                        } else {
                            // printf("Line %d, col %d: Symbol %s already defined\n",current->decl->info->lines, current->decl->info->cols, current->decl->info->id);
                        }
                    } else {
                        printf("Line %d, col %d: Symbol %s already defined\n",current->decl->info->lines, current->decl->info->cols, current->decl->info->id);
                    }
                }
                
            } else {
                if ((void_type_flag == 1) || ((s_types) current->tsp->type == s_void)) { // case void a = 1;
                    void_type_flag = 1;
                    printf("Line %d, col %d: Invalid use of void type in declaration\n",current->decl->info->lines,current->decl->info->cols);
                } else {    // case type different from void
                    if (current->decl->expr && compare_types((s_types) current->tsp->type,(s_type = get_expression_type(current->decl->expr,name,false)))) {
                        printf("Line %d, col %d: Conflicting types (got ",current->decl->info->lines, current->decl->info->cols);
                        print_s_type(get_expression_type(current->decl->expr,name,true));
                        printf(", expected ");
                        print_s_type((s_types) current->tsp->type);
                        printf(")\n");
                    }
                    
                    s->symtab = insert_sym_element(s->symtab, create_sym_element(current->decl->info->id,(s_types) dec->tsp->type, NULL, 0, (current->decl->expr == NULL) ? 0 : 1));
                }
                
            }
            current = current->next;
        }
    }
    return ec;
}

int check_f_def(struct function_definition* fdef){
	int ec = 0;
    int len_declaration = 0;
    int len_definition = 0;
    int dif = 0;
    int counter = 0;
    struct parameter_list* void_param_flag = NULL;
    struct sym_f_param* current_dec;
    struct parameter_list* current_def;
    struct scope* global_scope = get_scope_by_name(scope_head,"Global");
    struct sym_element* sym_elem = NULL;
    struct function_declaration* f_dec = (struct function_declaration*) malloc(sizeof(struct function_declaration));
    // Check for void type
    current_def = fdef->param_list;
    while (current_def){
        counter++;
        if (((s_types)current_def->p_dec->tsp->type == s_void) && (void_param_flag == 0)){
            void_param_flag = current_def;
        }
        if ((void_param_flag && counter > 1) || (void_param_flag && current_def->p_dec->info && current_def->p_dec->info->id != NULL)){
            printf("Line %d, col %d: Invalid use of void type in declaration\n",void_param_flag->p_dec->tsp->lines,void_param_flag->p_dec->tsp->cols);
            return ec;
        }
        current_def = current_def->next;
    }
    if ((sym_elem = search_symbol(scope_head,fdef->info->id,"Global"))) { //meaning that it found a correct reference
        if(sym_elem->type == s_function){
            /* Checking if Signature is different*/
            // Number of parameters
            current_dec = sym_elem->sym_f->params;
            while (current_dec) {
                len_declaration++;
                current_dec = current_dec->next;
            }

            current_def = fdef->param_list;
            while(current_def) {
                len_definition++;
                current_def = current_def->next;
            }

            // Parameter Types matching
            if (len_declaration == len_definition){
                current_dec = sym_elem->sym_f->params;
                current_def = fdef->param_list;
                while (current_dec && current_def){
                    if (current_dec->param_type != (s_types) current_def->p_dec->tsp->type){
                        dif++;
                    }
                    current_dec = current_dec->next;
                    current_def = current_def->next;
                }
            }
            if (sym_elem->already_defined) {
                printf("Line %d, col %d: Symbol %s already defined\n",fdef->info->lines,fdef->info->cols,fdef->info->id);
            } else { // Caso apenas haja a declaração da função
                if ((sym_elem->sym_f->return_value != (s_types) fdef->tsp->type) || (len_declaration != len_definition) || (dif > 0)){
                    f_dec->tsp = (struct tpspec*) malloc(sizeof(struct tpspec));
                    f_dec->tsp->type = fdef->tsp->type;
                    f_dec->param_list = fdef->param_list;
                    printf("Line %d, col %d: Conflicting types (got ",fdef->info->lines,fdef->info->cols);
                    print_scope_f_dec(create_sym_f_param(f_dec));
                    printf(", expected ");
                    print_scope_f_dec(sym_elem->sym_f);
                    printf(")\n");
                    free(f_dec->tsp);
                    free(f_dec);
                } else {
                    sym_elem->already_defined = 1;
                    ec += check_return_type(fdef->tsp->type, fdef->info->id); // Adicionar o return < type > ao scope da função     | isto caso haja
                    ec += check_param_list(fdef->param_list, fdef->info->id); // Adicionar os params ao scope da funcão             | o scope da funcao
                    ec += check_f_body(fdef->f_body,fdef->info->id);
                }
            }
        } else { // Caso não seja uma função aka, seja uma declaração
            // printf("Line %d, col %d: Symbol %s already defined\n",fdef->info->lines,fdef->info->cols,fdef->info->id);
            f_dec->tsp = (struct tpspec*) malloc(sizeof(struct tpspec));
            f_dec->tsp->type = fdef->tsp->type;
            f_dec->param_list = fdef->param_list;
            printf("Line %d, col %d: Conflicting types (got ",fdef->info->lines,fdef->info->cols);
            print_scope_f_dec(create_sym_f_param(f_dec));
            printf(", expected ");
            print_s_type(sym_elem->type);
            printf(")\n");
            free(f_dec->tsp);
            free(f_dec);
        }
    } else { //Meaning that it did not find a valid definition
        struct tpspec* tpsp = (struct tpspec*) malloc(sizeof(struct tpspec));
        tpsp->type = fdef->tsp->type;
        tpsp->lines = fdef->tsp->lines;
        tpsp->cols = fdef->tsp->cols;

        struct info* infor = (struct info*) malloc(sizeof(struct info));
        infor->id = fdef->info->id;
        infor->lines = fdef->info->lines;
        infor->cols = fdef->info->cols;

        f_dec->tsp = tpsp;
        f_dec->info = infor;
        f_dec->param_list = fdef->param_list;
        global_scope->symtab = insert_sym_element(global_scope->symtab,create_sym_element(fdef->info->id, s_function, create_sym_f_param(f_dec), 0, 1));
		create_scope(scope_head, fdef->info->id);

        ec += check_return_type(fdef->tsp->type, fdef->info->id); // Adicionar o return < type > ao scope da função     | isto caso haja
        ec += check_param_list(fdef->param_list, fdef->info->id); // Adicionar os params ao scope da funcão             | o scope da funcao
        ec += check_f_body(fdef->f_body,fdef->info->id);
    }
	return ec;
}

int check_return_type(typespec_type typ, char *name){
	int ec = 0;
	struct scope *head = get_scope_by_name(scope_head,name);
    if (head){
        head->symtab = insert_sym_element(head->symtab, create_sym_element("return", (s_types) typ, NULL, 0, 1));
    }    
	return ec; 
}

int check_param_list(struct parameter_list* pl, char* name){
	int ec = 0;
	struct scope *head = get_scope_by_name(scope_head,name);
    struct sym_element* sym_elem = NULL;
    struct scope* aux_scope = NULL;
    if (head){
        while (pl) {
            if (pl->p_dec->info && pl->p_dec->info->id != NULL) {
                if(!((aux_scope = get_scope_by_name(head,name)) && (sym_elem = get_token_by_name(aux_scope->symtab,pl->p_dec->info->id)))){// Se não encontrar nenhum simbolo no contexto local aka na própria param list
                    head->symtab = insert_sym_element(head->symtab, create_sym_element(pl->p_dec->info->id,(s_types)pl->p_dec->tsp->type, NULL, 1,1));	
                } else {
                    printf("Line %d, col %d: Symbol %s already defined\n",pl->p_dec->info->lines,pl->p_dec->info->cols,pl->p_dec->info->id);
                }
            }
		    pl = pl->next;
	    }
    }
	return ec;
}

int check_f_body(struct function_body* head, char *name){
	int ec = 0;
	while(head != NULL){
        if(head->type == t_statement){
            ec += check_statement(head->data_body.u_stt, name);
        }
        if(head->type == t_declaration){
            ec += check_dec(head->data_body.u_dec, name);
        }
        head = head->next;
    }
	return ec;
}

int check_statement(struct statement* head, char* name){
    int ec = 0;
    while(head != NULL){
        if(head->type == t_if){
            ec += check_if(head->statement_data.u_if, name);
        }
        if(head->type == t_return){
            ec += check_return(head->statement_data.u_return, name);
        }
        if(head->type == t_while){
            ec += check_while(head->statement_data.u_while, name);
        }
        if(head->type == t_statlist){
            ec += check_statlist(head->statement_data.u_statlist, name);
        }
        if(head->type == t_expression){
            ec += check_expression(head->statement_data.u_expr, name);
        }
        head = head->next;
    }
    return ec;
}

int check_return(struct return_statement* rs, char* name) {
    int ec = 0;
    int lines = 0;
    int cols = 0;
    struct sym_element* sym_elem = search_symbol(scope_head,name,"Global");
    s_types s_type;
    if (rs != NULL) {
        ec += check_expression(rs->expr, name);
        if (sym_elem && (sym_elem->type == s_function) && compare_types(sym_elem->sym_f->return_value,(s_type = get_expression_type(rs->expr,name,false)))){
            lines = rs->opl->lines;
            if (s_type == s_void) { // fica o erro no 'r' do return
                cols = rs->opl->cols;
            } else {
                cols = get_expression_col(rs->expr);
            }
            printf("Line %d, col %d: Conflicting types (got ",lines, cols);
            print_s_type(get_expression_type(rs->expr,name,true));
            printf(", expected ");
            print_s_type(sym_elem->sym_f->return_value);
            printf(")\n");
        }
    }
    return ec;
}

int check_if(struct if_statement* head, char* name){
    int ec = 0;
    s_types s_type;
    if(head != NULL){
        ec += check_expression(head->expr, name);
        s_type = get_expression_type(head->expr,name,false);
        /*if (s_type == s_undef && head->expr->expr_t == t_op2){
            // Já deu erro, não vai dar again
        } else */
        if (s_type == s_char || s_type == s_short || s_type == s_int) {
            ec += check_statement(head->if_body, name);
            ec += check_statement(head->else_body, name);
        } else {
            printf("Line %d,",head->opl->lines); 
            if (s_type == s_function){ // case where int f(void){return 0;} if(f){}
                printf(" col %d: Conflicting types (got ",head->expr->expression_morphs.t->info->cols);
                get_expression_type(head->expr,name,true); 
            } else if (head->expr->expr_t == t_call){
                printf(" col %d: Conflicting types (got ",head->expr->expression_morphs.c->call_morphs.info->cols);
                print_s_type(s_type);
            } else { 
                printf(" col %d: Conflicting types (got ", get_expression_col(head->expr));
                print_s_type(s_type);
            }
            printf(", expected int)\n");
        }
    }
    return ec;
}

int check_while(struct while_statement* head, char* name){
    int ec = 0;
    s_types s_type;
    if(head != NULL){
        ec += check_expression(head->expr, name);
        s_type = get_expression_type(head->expr,name,false);
         /*if (s_type == s_undef && head->expr->expr_t == t_op2){
            // Já deu erro, não vai dar again
        } else*/ if (s_type == s_char || s_type == s_short || s_type == s_int) {
            ec += check_statement(head->while_body, name);
        } else {
            printf("Line %d,",head->opl->lines); 
            if (s_type == s_function){ // case where int f(void){return 0;} if(f){}
                printf(" col %d: Conflicting types (got ",head->expr->expression_morphs.t->info->cols);
                get_expression_type(head->expr,name,true); 
            } else if (head->expr->expr_t == t_call){
                printf(" col %d: Conflicting types (got ",head->expr->expression_morphs.c->call_morphs.info->cols);
                print_s_type(s_type);
            } else { 
                printf(" col %d: Conflicting types (got ", get_expression_col(head->expr));
                print_s_type(s_type);
            }
            printf(", expected int)\n");
        }
    }
    return ec;
}

int check_statlist(struct statlist_statement* head, char* name){
    int ec = 0;
    if(head != NULL){
        ec += check_statement(head->stt, name);
    }
    return ec;
}

int check_expression(struct expression* exp, char* name){
    if(exp != NULL){
        switch (exp->expr_t) {
            case t_op1:
                return check_op1(exp->expression_morphs.operation1, name);
            case t_op2:
                return check_op2(exp->expression_morphs.operation2, name);
            case t_term:
                return check_terminal(exp->expression_morphs.t, name);
            case t_call:
                return check_call(exp->expression_morphs.c, name);
        }
    }
    return 0;
}

int check_op1(struct op1* op, char* name) {
    int ec = 0;
    if (op != NULL){
        ec += check_expression(op->exp, name);
        s_types exp_type = get_expression_type(op->exp, name, false);
        if (exp_type == s_function || exp_type == s_undef || ((exp_type == s_double) && (op->type == t_not))){
            printf("Line %d, col %d: Operator ",op->lines,op->cols);
            print_op1_symbol(op->type);
            printf(" cannot be applied to type ");
            print_s_type(get_expression_type(op->exp, name, true));
            printf("\n");
        }
    }
    return ec;
}

int check_op2(struct op2* op, char* name) {
    int ec = 0;
    struct sym_element* sym_elem = NULL;
    if (op != NULL){
        ec += check_expression(op->exp1, name);
        ec += check_expression(op->exp2, name);
        s_types exp1_s_type = get_expression_type(op->exp1,name,false);
        s_types exp2_s_type = get_expression_type(op->exp2,name,false);
        /*if (exp1_s_type == s_undef || exp2_s_type == s_undef) {
            // Já deu erro, não vai dar again
        } else {*/
            switch (op->type) {
                /* Os que não podem receber um double como argumento */
                case t_mod: case t_or: case t_and: case t_bitwiseand:
                case t_bitwiseor: case t_bitwisexor:
                    if (exp1_s_type == s_undef || exp2_s_type == s_undef || exp1_s_type == s_double || exp2_s_type == s_double || exp1_s_type == s_function || exp2_s_type == s_function) {
                        printf("Line %d, col %d: Operator ",op->lines,op->cols);
                        print_op2_symbol(op->type);
                        printf(" cannot be applied to types ");
                        print_s_type(get_expression_type(op->exp1,name,true));
                        printf(", "); 
                        print_s_type(get_expression_type(op->exp2,name,true));
                        printf("\n"); 
                    }
                    break;
                case t_le: case t_lt: case t_eq: case t_ne: case t_ge: case t_gt:
                case t_add: case t_sub: case t_mul: case t_div: case t_comma:
                    if (exp1_s_type == s_undef || exp2_s_type == s_undef || exp1_s_type == s_function || exp2_s_type == s_function) {
                        printf("Line %d, col %d: Operator ",op->lines,op->cols);
                        print_op2_symbol(op->type);
                        printf(" cannot be applied to types ");
                        print_s_type(get_expression_type(op->exp1,name,true));
                        printf(", "); 
                        print_s_type(get_expression_type(op->exp2,name,true));
                        printf("\n"); 
                    }
                    break;
                case t_store:
                    if (exp1_s_type == s_undef || exp2_s_type == s_undef || ((exp1_s_type != s_double) && (exp2_s_type == s_double)) || exp1_s_type == s_function || exp2_s_type == s_function){
                        printf("Line %d, col %d: Operator ",op->lines,op->cols);
                        print_op2_symbol(op->type);
                        printf(" cannot be applied to types ");
                        print_s_type(get_expression_type(op->exp1,name,true));
                        printf(", "); 
                        print_s_type(get_expression_type(op->exp2,name,true));
                        printf("\n"); 
                    }
                    if (op->exp1->expr_t == t_term) {
                        if (op->exp1->expression_morphs.t->type == t_id) {
                            if (!(sym_elem = search_symbol(scope_head, op->exp1->expression_morphs.t->info->id,name))){
                                //TODO: remover isto e passar para o check_term - aqui não faz nada
                            }
                        } else {
                            printf("Line %d, col %d: Lvalue required\n",op->lines, get_expression_col(op->exp1));
                        }
                    } else {
                        printf("Line %d, col %d: Lvalue required\n",op->lines,get_expression_col(op->exp1));
                    }
                    break;
            }
        // }
    }
    return ec;
}

int check_terminal(struct terminal* t, char* name) {
    if (t->type == t_id && !search_symbol(scope_head,t->info->id,name)) {
        printf("Line %d, col %d: Unknown symbol %s\n",t->info->lines, t->info->cols,t->info->id);
        return 1;
    }
    return 0;
}

//TODO: int foo(int, char); foo(1,2.2);
//TODO: unknown ou is not a function?
int check_call(struct call* c, char* name) {
    int ec = 0;
    int required_args = 0;
    int got_args = 0;
    struct sym_element* sym_elem = NULL; 
    struct sym_f_param* current_sym_param = NULL;
    struct call* call_id = NULL;
    struct call* current = c;
    s_types s_type;
    while(current) {
        switch (current->ct) {
            case call_name: 
                if ((sym_elem = search_symbol(scope_head, current->call_morphs.info->id, name))){
                    if (sym_elem->type != s_function) {
                        printf("Line %d, col %d: Symbol %s is not a function\n", current->call_morphs.info->lines, current->call_morphs.info->cols, current->call_morphs.info->id);
                    } else { // é uma função e portanto é necessário ver se não dá wrong number of args
                        current_sym_param = sym_elem->sym_f->params;
                        while(current_sym_param){
                            if (current_sym_param->param_type != s_void){
                                required_args++;
                            }                            
                            current_sym_param = current_sym_param->next;
                        }
                        if ((got_args = count_call_params(current)) != required_args){
                            printf("Line %d, col %d: Wrong number of arguments to function %s (got %d, required %d)\n", current->call_morphs.info->lines, current->call_morphs.info->cols,current->call_morphs.info->id,got_args,required_args);
                            return ec;
                        }
                        current_sym_param = sym_elem->sym_f->params; // for the call_exp: current is already on the head, just ->next to next param
                        call_id = c;
                    }
                } else { // Se o simbolo não for encontrado
                    printf("Line %d, col %d: Unknown symbol %s\n", current->call_morphs.info->lines, current->call_morphs.info->cols,current->call_morphs.info->id);
                    printf("Line %d, col %d: Symbol %s is not a function\n", current->call_morphs.info->lines, current->call_morphs.info->cols, current->call_morphs.info->id);
                }
                break;
            case call_exp:
                ec += check_expression(current->call_morphs.exp, name);
                if (current_sym_param && sym_elem && (sym_elem->type == s_function)) {
                    s_type = get_expression_type(current->call_morphs.exp,name,false);
                    if (compare_types(current_sym_param->param_type, s_type)){
                        printf("Line %d, col %d: Conflicting types (got ",call_id->call_morphs.info->lines, get_expression_col(current->call_morphs.exp));
                        print_s_type(get_expression_type(current->call_morphs.exp,name,true));
                        printf(", expected ");
                        print_s_type(current_sym_param->param_type);
                        printf(")\n");
                    }
                    current_sym_param = current_sym_param->next;
                }
                break;   
        }
        current = current->next_arg;
    }
    return ec;   
}

// ==================================================================== Aux funcs

int get_expression_col(struct expression* exp){
    switch (exp->expr_t) {
        case t_op1:
            return exp->expression_morphs.operation1->cols;
        case t_op2:
            return exp->expression_morphs.operation2->cols;
        case t_call:
            return exp->expression_morphs.c->call_morphs.info->cols;
        case t_term:
            return exp->expression_morphs.t->info->cols;
    }
    return -1;
}

int count_call_params(struct call* head){
    int counter = 0;
    while (head){
        switch (head->ct) {
            case call_name:
                break;
            case call_exp:
                counter++;
                break;
        }
        head = head->next_arg;
    }
    return counter;
}

int compare_types(s_types type1, s_types type2){
    if (type1 == s_function || type2 == s_function || type1 == s_undef || type2 == s_undef) {
        return 1;    
    }
    if (type2 == s_double && (type1 == s_char || type1 == s_short || type1 == s_int)){
        return 1;
    }
    if ((type1 == s_void) && (type2 != s_void)){
        return 1;
    }
    
    if ((type1 != s_void) && (type2 == s_void)){
        return 1;
    }
    
    return 0;
}