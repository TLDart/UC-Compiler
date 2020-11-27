#include "print_lib.h"

void print_indentation(int depth){
    for(int i = 0; i < depth*2; i++)
        printf(".");
}


void print_ast(struct program* head){
    if(head != NULL){
        print_program(head, 0);
    }
    else{
        printf("head is null");
    }
}


void print_program(struct program* head, int depth){
    printf("Program\n");
    //if(head->next == NULL) printf("next was null");
    while(head != NULL){
        if(head->type == t_f_def){
            print_f_def(head->data_program.u_f_def, depth +1);
        }
        else if(head->type == t_f_dec){
            print_f_dec(head->data_program.u_f_dec, depth +1);
        }
        else if(head->type == t_dec){
            print_declaration(head->data_program.u_dec, depth +1, "Global");
        }
        head = head->next;
    }
   
}

void print_f_def(struct function_definition* f_def, int depth){
    print_indentation(depth);
    printf("FuncDefinition\n");

    print_typespec(f_def->type, depth + 1);
    print_id(f_def->id, depth +1);
    if(f_def->param_list != NULL){
        print_param_list( f_def->param_list, depth + 1);

    }
    if(f_def->f_body != NULL){
        print_f_body(f_def->f_body, depth + 1, f_def->id);
    } else {
        print_indentation(depth + 1);
        printf("FuncBody\n");
    }

}
void print_f_dec(struct function_declaration* f_dec, int depth){
    print_indentation(depth);
    printf("FuncDeclaration\n");

    print_typespec(f_dec->type, depth + 1);
    print_id(f_dec->id, depth +1);
    if(f_dec->param_list != NULL)
        print_param_list(f_dec->param_list, depth + 1);
}


void print_typespec(typespec_type type, int depth){
    print_indentation(depth);
    if(type == t_typespec_char){
        printf("Char\n");
    }
    if(type == t_typespec_int){
        printf("Int\n");
    }
    if(type == t_typespec_void){
        printf("Void\n");
    }
    if(type == t_typespec_short){
        printf("Short\n");
    }
    if(type == t_typespec_double){
        printf("Double\n");
    }
}

void print_id(char* id, int depth){
    print_indentation(depth);
    printf("Id(%s)\n",id);
}

void print_param_list(struct parameter_list* p_list, int depth){
    print_indentation(depth);
    printf("ParamList\n");
    while(p_list != NULL){
        print_param_dec(p_list->p_dec, depth + 1);
        p_list = p_list->next;
    }
}

void print_param_dec(struct parameter_declaration* p_dec, int depth){
        print_indentation(depth);
        printf("ParamDeclaration\n");
            print_typespec(p_dec->type, depth + 1);
        if(p_dec->id != NULL){
            print_id(p_dec->id, depth + 1);
        }
}

void print_f_body(struct function_body* f_body, int depth, char* local_scope_name){
    print_indentation(depth);
    printf("FuncBody\n");
    while(f_body != NULL){
        if(f_body->type == t_statement){
            print_statement(f_body->data_body.u_stt, depth + 1, local_scope_name);
        }
        
        else if(f_body->type == t_declaration){
            print_declaration(f_body->data_body.u_dec, depth + 1,local_scope_name);
        }
        f_body = f_body->next;
    }
}


void print_declaration(struct declaration* dec, int depth, char* local_scope_name){
    struct declaration* head = dec;
    while(dec != NULL){
        print_indentation(depth);
        printf("Declaration\n");
        print_typespec(head->type,depth + 1);
        print_declarator(dec->decl, depth + 1,local_scope_name);
        dec = dec->next;
    }
}

void print_declarator(struct declarator* decl, int depth, char* local_scope_name){
    print_id(decl->id, depth);
    if (decl->expr != NULL){
       print_expression(decl->expr, depth, local_scope_name);
    }
    else{
        //print_indentation(depth);
    }
}

void print_statement(struct statement* stt, int depth, char* local_scope_name){
    //printf("asdasdasdasd %d\n", stt->type);
    while(stt != NULL){
        if(stt->type == t_if){
            print_if(stt->statement_data.u_if, depth, local_scope_name);
        }
        else if(stt->type == t_return){
             //printf("tf xd\n");
            print_return(stt->statement_data.u_return, depth, local_scope_name);
        }
        else if(stt->type == t_while){
            //printf("here\n");
            print_while(stt->statement_data.u_while, depth, local_scope_name);
        }
        else if(stt->type == t_statlist){
            print_statlist(stt->statement_data.u_statlist, depth, local_scope_name);
        }
        else if(stt->type == t_expression){
            // printf("Here goes h");
            print_expression(stt->statement_data.u_expr, depth,local_scope_name);
        }
        stt = stt->next;
    }

}


void print_if(struct if_statement* stt_if, int depth, char* local_scope_name){
    print_indentation(depth);
    printf("If\n");
    if(stt_if->expr != NULL){
        print_expression(stt_if->expr, depth + 1, local_scope_name);
    }
    else printf("Erro! A menos que as expressions ainda nao estejam feitas\n");
    if(stt_if->if_body == NULL || (stt_if->if_body->type == t_statlist && stt_if->if_body->statement_data.u_statlist->stt == NULL)){
        print_indentation(depth + 1);
        printf("Null\n");
    }
    else{
        print_statement(stt_if->if_body, depth + 1,local_scope_name);
    }
    if(stt_if->else_body == NULL || (stt_if->else_body->type == t_statlist && stt_if->else_body->statement_data.u_statlist->stt == NULL)){
        print_indentation(depth + 1);
        printf("Null\n");
    }
    else{
        print_statement(stt_if->else_body, depth + 1,local_scope_name);
    }
}

void print_return(struct return_statement* stt_ret, int depth,char* local_scope_name){
    print_indentation(depth);
    printf("Return\n");
    if(stt_ret->expr == NULL){
        print_indentation(depth + 1);
        printf("Null\n");
    }
    else{
        print_expression(stt_ret->expr, depth + 1, local_scope_name);
    }
}

void print_while(struct while_statement* stt_whi, int depth, char* local_scope_name){
    print_indentation(depth);
    printf("While\n");
    if(stt_whi->expr == NULL){
        print_expression(stt_whi->expr, depth + 1,local_scope_name);
    }
    else{
        print_expression(stt_whi->expr, depth + 1,local_scope_name);
    }
    if(stt_whi->while_body == NULL || (stt_whi->while_body->type == t_statlist && stt_whi->while_body->statement_data.u_statlist->stt == NULL)){
        print_indentation(depth + 1);
        printf("Null\n");
    }
    else{
        print_statement(stt_whi->while_body, depth + 1,local_scope_name);
    }
}
void print_statlist(struct statlist_statement* stt_stl, int depth, char* local_scope_name){
    if(stt_stl->stt != NULL && stt_stl->stt->next){
        print_indentation(depth);
        printf("StatList\n");
        print_statement(stt_stl->stt, depth +1, local_scope_name);
    }
    else{
        print_statement(stt_stl->stt, depth, local_scope_name);
    }
}

// new
void print_expression(struct expression* expr, int depth,char* local_scope_name){
    print_indentation(depth);
    //printf("Here goes expression\n");
    if (expr->expr_t == t_op1){
        print_op1(expr->expression_morphs.operation1, depth,local_scope_name);
    } else if (expr->expr_t == t_op2){
        print_op2(expr->expression_morphs.operation2, depth, local_scope_name);
    } else if (expr->expr_t == t_term){
        print_term(expr->expression_morphs.t, depth, local_scope_name);
    } else if (expr->expr_t == t_call) {
        print_call(expr->expression_morphs.c, depth, local_scope_name);
    }
}


void print_op1(struct op1* op, int depth,char* local_scope_name){
    switch (op->type){
        case t_not:
            printf("Not");
            break;
        case t_minus:
            printf("Minus");
            break;
        case t_plus:
            printf("Plus");
            break;
    }
    if (ASTnoted) {
        printf(" - ");
        print_s_type(get_op1_type(op,local_scope_name));
    }
    printf("\n");
    print_expression(op->exp, depth + 1,local_scope_name);
}

void print_op2(struct op2* op, int depth, char* local_scope_name){
    switch (op->type){
        case t_or:
            printf("Or");
            break;
        case t_and:
            printf("And");
            break;
        case t_eq:
            printf("Eq");
            break;
        case t_ne:
            printf("Ne");
            break;
        case t_lt:
            printf("Lt");
            break;
        case t_gt:
            printf("Gt");
            break;
        case t_ge:
            printf("Ge");
            break;
        case t_add:
            printf("Add");
            break;
        case t_sub:
            printf("Sub");
            break;
        case t_mul:
            printf("Mul");
            break;
        case t_div:
            printf("Div");
            break;
        case t_mod:
            printf("Mod");
            break;
        case t_store:
            printf("Store");
            break;
        case t_comma:
            printf("Comma");
            break;
        case t_bitwiseand:
            printf("BitWiseAnd");  
            break;
        case t_bitwisexor:
            printf("BitWiseXor");
            break;
        case t_bitwiseor:
            printf("BitWiseOr");
            break;
        case t_le:
            printf("Le");
            break;
    }
    if (ASTnoted) {
        printf(" - ");
        print_s_type(get_op2_type(op,local_scope_name));
    }
    printf("\n");
    print_expression(op->exp1, depth + 1, local_scope_name);
    print_expression(op->exp2, depth + 1, local_scope_name);
}

void print_term(struct terminal* t, int depth, char* local_scope_name){
    switch (t->type){
        case t_charlit:
            printf("ChrLit('%s)",t->id);
            break;
        case t_id:
            printf("Id(%s)",t->id);
            break;
        case t_intlit:
            printf("IntLit(%s)",t->id);
            break;
        case t_reallit:
            printf("RealLit(%s)",t->id);
            break;
        default:
            break;
    }
    if (ASTnoted){
        printf(" - ");
        print_s_type(get_terminal_type(t,local_scope_name));
    }
    printf("\n");
}

void print_call(struct call* c, int depth, char* local_scope_name){
    struct call* current;
    for (current = c; current; current = current->next_arg){
        if (current->ct == call_name) {
            printf("Call");
            if (ASTnoted) {
                printf(" - ");   
                // print_s_type(search_symbol(scope_head,current->call_morphs.id, local_scope_name)->sym_f->return_value);
                print_s_type(get_call_type(current,local_scope_name));   
            }
            printf("\n");
            print_indentation(depth + 1);
            printf("Id(%s)",current->call_morphs.id);
            if(ASTnoted){
                printf(" - ");
                print_s_type(get_id_type(current->call_morphs.id,local_scope_name));
            }
            printf("\n");
        } else if (current->ct == call_exp){
            print_expression(current->call_morphs.exp, depth + 1,local_scope_name);
        }
    }
}



//------------------------------------------------------------------------------------------------------------------//
//Printing the symbol table

void showTable(struct scope* head){
    struct scope* current = head;
    while(current){
        if(strcmp(current->name, "Global") == 0){
            printf("===== Global Symbol Table =====\n");
        }
        else{
            printf("\n===== Function %s Symbol Table =====\n",current->name);
        }
        print_scope(current->symtab);
        current = current->next;
    }
}
void print_scope(struct sym_element* head){
    struct sym_element* current = head;
    while(current){
        print_sym_element(current);
        current = current->next;
    }
}

void print_sym_element(struct sym_element* s_el){
    if(s_el->name)
        printf("%s\t", s_el->name);
    if(s_el->type == s_function){
        print_scope_f_dec(s_el->sym_f);
        printf("\n");
        //printf("is func\n");
    }
    else{
        print_s_type(s_el->type);

        if(s_el->parameter == 1){
            printf("\tparam");
        }
        printf("\n");
    }
}

void print_scope_f_dec(struct sym_function* sf){
    struct sym_f_param* current = sf->params;
    print_s_type(sf->return_value); 
    printf("(");
    while(current){
        print_s_type(current->param_type);
        if(current->next != NULL) printf(",");
        current = current->next;
    }
    printf(")");
}

void print_s_type(s_types s){
        if(s == s_char){
            printf("char");
        }
        if(s == s_int){
            printf("int");
        }
        if(s == s_void){
            printf("void");
        }
        if(s == s_short){
            printf("short");
        }
        if(s == s_double){
            printf("double");
        }
}

//======================================================================================
s_types get_expression_type(struct expression* exp, char* local_scope_name){
    switch (exp->expr_t){
        case t_op1:
            return get_op1_type(exp->expression_morphs.operation1,local_scope_name);
        case t_op2:
            return get_op2_type(exp->expression_morphs.operation2,local_scope_name); 
        case t_term:
            return get_terminal_type(exp->expression_morphs.t, local_scope_name);
        case t_call:
            return get_call_type(exp->expression_morphs.c, local_scope_name);
    }
    printf("Não devia ter acontecido!!\n");
    return s_void;
}

s_types get_op1_type(struct op1* op, char* local_scope_name) {
    switch (op->type){
        case t_not:
            return s_int;
        default:
            return get_expression_type(op->exp,local_scope_name);
    }
}
    

s_types get_op2_type(struct op2* op, char* local_scope_name){
    s_types t_exp1 = get_expression_type(op->exp1, local_scope_name);
    s_types t_exp2 = get_expression_type(op->exp2, local_scope_name);

    switch (op->type) {
        case t_or: case t_and: case t_eq:case t_ne: case t_lt: case t_gt: case t_ge:
        case t_bitwiseand: case t_bitwisexor: case t_bitwiseor: case t_le: case t_mod:
            return s_int;
        case t_store:
            return t_exp1;
        case t_comma:
            return t_exp2;
        case t_add: case t_sub: case t_mul: case t_div: 
            // char < short < int < double  
            if (t_exp1 == t_exp2){
                return t_exp1;
            } else {
                if (t_exp1 == s_char){ 
                    return t_exp2;
                } else if (t_exp1 == s_double) {
                    return t_exp1;
                } else if (t_exp1 == s_short) {
                    if (t_exp2 == s_int || t_exp2 == s_double) {
                        return t_exp2;
                    }
                    return t_exp1;
                } else if (t_exp1 == s_int) {
                    if (t_exp2 == s_double){
                        return t_exp2;
                    }
                    return t_exp1;
                } else {
                    printf("Não devia ter acontecido!!\n");
                    return s_void;
                }
            }

    }
    printf("Não devia ter acontecido!!\n");
    return s_void;  
}

s_types get_terminal_type(struct terminal* t, char* local_scope_name){
    switch (t->type) {
        case t_charlit:
            return s_int;
        case t_id:
            return get_id_type(t->id,local_scope_name);
        case t_intlit:
            return s_int;
        case t_reallit:
            return s_double;
        default:
            printf("Não devia ter acontecido!!\n");
            return s_void;
    }
}

s_types get_call_type(struct call* c, char* local_scope_name){
    struct sym_element* sym_elem = NULL;
    if ((sym_elem = search_symbol(scope_head,c->call_morphs.id, local_scope_name))) {
        return sym_elem->sym_f->return_value;
    }
    printf("Nao devia chegar aqui!!\n");
    return s_void;
}

s_types get_id_type(char* id, char* local_scope_name){
    struct sym_element* sym_elem = NULL;
    if((sym_elem = search_symbol(scope_head,id,local_scope_name))){
        switch (sym_elem->type){
        case s_char: case s_int: case s_void: case s_short: case s_double:
            return sym_elem->type;
        case s_function:
            print_scope_f_dec(sym_elem->sym_f);
            return s_function;
        default:
            break;
        }
    }
    printf("Nao devia chegar aqui!!\n");
    return s_void;
}