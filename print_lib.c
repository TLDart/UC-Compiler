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
            printf("\n");
            break;
        case t_minus:
            printf("Minus");
            printf("\n");
            break;
        case t_plus:
            printf("Plus");
            printf("\n");
            break;
    }
    print_expression(op->exp, depth + 1,local_scope_name);
}

void print_op2(struct op2* op, int depth, char* local_scope_name){
    switch (op->type){
        case t_or:
            printf("Or");
            printf("\n");
            break;
        case t_and:
            printf("And");
            printf("\n");
            break;
        case t_eq:
            printf("Eq");
            printf("\n");
            break;
        case t_ne:
            printf("Ne");
            printf("\n");
            break;
        case t_lt:
            printf("Lt");
            printf("\n");
            break;
        case t_gt:
            printf("Gt");
            printf("\n");
            break;
        case t_ge:
            printf("Ge");
            printf("\n");
            break;
        case t_add:
            printf("Add");
            printf("\n");
            break;
        case t_sub:
            printf("Sub");
            printf("\n");
            break;
        case t_mul:
            printf("Mul");
            printf("\n");
            break;
        case t_div:
            printf("Div");
            printf("\n");
            break;
        case t_mod:
            printf("Mod");   
            printf("\n"); 
            break;
        case t_store:
            printf("Store");
            if (ASTnoted){
                printf(" - ");
                //TODO: Fazer uma função "get_type() para deduzir qual o tipo de (1+1.0) + 'A'  "  
            }
            printf("\n");
            break;
        case t_comma:
            printf("Comma");
            printf("\n");
            break;
        case t_bitwiseand:
            printf("BitWiseAnd"); 
            printf("\n");   
            break;
        case t_bitwisexor:
            printf("BitWiseXor");
            printf("\n");
            break;
        case t_bitwiseor:
            printf("BitWiseOr");
            printf("\n");
            break;
        case t_le:
            printf("Le");
            printf("\n");    
            break;
    }
    print_expression(op->exp1, depth + 1, local_scope_name);
    print_expression(op->exp2, depth + 1, local_scope_name);
}

void print_term(struct terminal* t, int depth, char* local_scope_name){
    switch (t->type){
        case t_charlit:
            printf("ChrLit('%s)",t->id);
            if (ASTnoted) printf(" - int");
            printf("\n");
            break;
        case t_id:
            printf("Id(%s)",t->id);
            if (ASTnoted){
                print_id_ast_noted(t->id,local_scope_name);
                printf("\n");   
            }
            break;
        case t_intlit:
            printf("IntLit(%s)",t->id);
            if (ASTnoted) printf(" - int");
            printf("\n");
            break;
        case t_reallit:
            printf("RealLit(%s)",t->id);
            if (ASTnoted) printf(" - double");
            printf("\n");
            break;
        default:
            break;
    }
}

void print_call(struct call* c, int depth, char* local_scope_name){
    struct call* current;
    for (current = c; current; current = current->next_arg){
        if (current->ct == call_name) {
            printf("Call");
            if (ASTnoted) {
                printf(" - ");   
                print_s_type(search_symbol(scope_head,current->call_morphs.id, local_scope_name)->sym_f->return_value);   
            }
            printf("\n");
            print_indentation(depth + 1);
            printf("Id(%s)",current->call_morphs.id);
            if(ASTnoted){
                print_id_ast_noted(current->call_morphs.id,local_scope_name);
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

void print_id_ast_noted(char* id,char* local_scope_name){
    struct sym_element* symbol = search_symbol(scope_head,id, local_scope_name);
    switch (symbol->type) {
        case s_char: 
            printf(" - char");
            break;
        case s_int:
            printf(" - int");
            break; 
        case s_void:
            printf(" - void");
            break;
        case s_short:
            printf(" - short");
            break;
        case s_double:
            printf(" - double");
            break;
        case s_function:
            printf(" - ");
            print_scope_f_dec(symbol->sym_f);
            break;
        default:
            break;
    }
}
