 #include "codegen.h"

void print_code_indent(int depth){
    for(int i = 0; i < depth * 2; i++)
        printf(" ");
}

char* get_type(struct tpspec * t){
    if(t->type == t_typespec_double)
        return "double";
    else
    {
        return "i32";
    }
}
char* codegen_terminal_type(t_type t){
    switch (t){
    case t_double: case t_reallit:
        return "double";
    
    default:
        return "i32";
    }
}

char* codegen_s_type(s_types s){
        if(s == s_void){
            return "void";
        }
        if(s == s_double){
            return "double";
        }
        else{
            return "i32";
        }

}



char* get_expr_global(struct expression* exp){//TODO Fix this
    if(exp == NULL){
        return "0";
    }
    return "8";
}

void codegen(struct program* head, struct scope* scope_head){
    printf("declare i32 @putchar(i32)\n");
    printf("\n");
    printf("declare i32 @getchar(i32)\n");
    printf("\n");
    
    while(head != NULL){
        if(head->type == t_f_def){
            codegen_f_def(head->data_program.u_f_def);
        }
        else if(head->type == t_f_dec){
            //codegen_f_dec(head->data_program.u_f_dec, 1);
        }
        else if(head->type == t_dec){
            codegen_declaration(head->data_program.u_dec, 0,"Global");
        }
        head = head->next;
    }
}

void codegen_declaration(struct declaration* dec, int depth, char* scope_name){
    struct declaration* head = dec;
    while(dec != NULL){

        if(strcmp(scope_name, "Global") == 0){
            printf("@%s = global %s %s\n", dec->decl->info->id, get_type(head->tsp), get_expr_global(dec->decl->expr));

            dec = dec->next;
        }
        else{
            print_code_indent(depth);
            printf("%%%s = alloca %s\n", dec->decl->info->id, get_type(head->tsp));
            print_code_indent(depth);
            printf("store %s %s, %s* %%%s\n", get_type(head->tsp), get_expr_global(dec->decl->expr),get_type(head->tsp), dec->decl->info->id);
            dec = dec->next;
        }
    }
}

void codegen_f_def(struct function_definition* f_def){
    printf("define %s @%s(", get_type(f_def->tsp), f_def->info->id);
    codegen_param_list(f_def->param_list);
    printf("){\n");
    codegen_param_list_stores(f_def->param_list);
    if(f_def->f_body != NULL){
        codegen_f_body(f_def->f_body, f_def->info->id);
    }
    printf("}\n");
    varcounter = 1;

}

void codegen_param_list(struct parameter_list* p_list){
    while(p_list != NULL){
        if( p_list->p_dec->tsp->type != t_typespec_void)
        printf("%s %%arg.%s", get_type(p_list->p_dec->tsp), p_list->p_dec->info->id);
        p_list = p_list->next;
        if(p_list != NULL){
            printf(",");
        }
    }
}

void codegen_param_list_stores(struct parameter_list* p_list){
    while(p_list != NULL){
        if(p_list->p_dec->tsp->type != t_typespec_void){
            if(strcmp(get_type(p_list->p_dec->tsp), "double") == 0){
                print_code_indent(1);
                printf("%%%s = alloca %s\n", p_list->p_dec->info->id, "double");
                print_code_indent(1);
                printf("store %s %%arg.%s, %s* %%%s\n", "double", p_list->p_dec->info->id, "double", p_list->p_dec->info->id);
            } 
            else{
                print_code_indent(1);
                printf("%%%s = alloca %s\n", p_list->p_dec->info->id, "i32");
                print_code_indent(1);
                printf("store %s %%arg.%s, %s* %%%s\n", "i32", p_list->p_dec->info->id, "i32", p_list->p_dec->info->id);
            }
        }
        p_list = p_list->next;
    }
}

void codegen_f_body(struct function_body* f_body, char* local_scope_name){
    //TODO Maybe save params, not sure it is needed
    
    while(f_body != NULL){
        if(f_body->type == t_statement){
            codegen_statement(f_body->data_body.u_stt, local_scope_name);
        }
        
        else if(f_body->type == t_declaration){
            codegen_declaration(f_body->data_body.u_dec,1,local_scope_name);
        }
        f_body = f_body->next;
    }
}

void codegen_statement(struct statement* stt, char* local_scope_name){
    //printf("asdasdasdasd %d\n", stt->type);
    while(stt != NULL){
        if(stt->type == t_if){
            //print_if(stt->statement_data.u_if, depth, local_scope_name);
        }
        else if(stt->type == t_return){
            codegen_return(stt->statement_data.u_return, local_scope_name);
        }
        else if(stt->type == t_while){
            //printf("here\n");
            //print_while(stt->statement_data.u_while, depth, local_scope_name);
        }
        else if(stt->type == t_statlist){
            //print_statlist(stt->statement_data.u_statlist, depth, local_scope_name);
        }
        else if(stt->type == t_expression){
            // printf("Here goes h");
            //print_expression(stt->statement_data.u_expr, depth,local_scope_name);
        }
        stt = stt->next;
    }

}


void codegen_if(struct if_statement* stt_if, char* local_scope_name){}
void codegen_return(struct return_statement* stt_ret, char* local_scope_name){
    int result = codegen_expression(stt_ret->expr, local_scope_name);   
    s_types t = get_expression_type(stt_ret->expr, local_scope_name, 0);

    //if the operator is of type i32 but the function is of type double we need to convert
    struct sym_element* sm = get_token_by_name(scope_head->symtab, local_scope_name);
    if(sm->sym_f->return_value == s_double){
        if(t != s_double ){
            print_code_indent(1);
            printf("%%%d = sitofp %s %%%d to %s\n", varcounter, "i32", result, "double");
            result = varcounter;
            varcounter++;
        }
    }

    print_code_indent(1);
    printf("ret %s %%% d\n",codegen_s_type(sm->sym_f->return_value) , result);
}
int codegen_expression(struct expression* expr, char* local_scope_name){//TODO Fix this
    if (expr->expr_t == t_op1){
            return codegen_op1(expr->expression_morphs.operation1, local_scope_name);
        } else if (expr->expr_t == t_op2){
            return codegen_op2(expr->expression_morphs.operation2, local_scope_name);
        } else if (expr->expr_t == t_term){
            return codegen_term(expr->expression_morphs.t, local_scope_name);
        } else if (expr->expr_t == t_call) {
            return codegen_call(expr->expression_morphs.c, local_scope_name);
        }
        return -1;
}


int codegen_op1(struct op1* op, char* local_scope_name) {
    //s_types s_type;
    int op1 = codegen_expression(op->exp, local_scope_name);
    s_types op1type = get_expression_type(op->exp, local_scope_name, 0);
    switch (op->type){
        case t_not:
            if(op1type == s_double){
                print_code_indent(1); 
                printf("%%%d = fcmp une %s %%%d, %%%s\n", varcounter, "double", op1, "0.0");
                varcounter++;
            }
            else{
                print_code_indent(1); 
                printf("%%%d = icmp ne %s %%%d, %%%s\n", varcounter, "i32", op1, "0");
                varcounter++;
            }
            print_code_indent(1); 
            printf("%%%d = xor %s %%%d, %s\n", varcounter, "i1", varcounter - 1 , "true");
            varcounter++;
            print_code_indent(1); 
            printf("%%%d = zext %s %%%d to %s\n", varcounter, "i1", varcounter - 1, "i32");
            return varcounter++;
            break;
        case t_minus:
            if(op1type == s_double){
                print_code_indent(1); 
                printf("%%%d = fneg %s %%%d\n", varcounter, "double", op1);
                return varcounter++;
            }
            else{
                print_code_indent(1); 
                printf("%%%d = sub %s %%%s, %%%d\n", varcounter, "i32",  "0",op1);
                return varcounter++;
            }
            
            break;
        case t_plus: //Nao se faz nada
            break;
        default:
            return -1;
            break;
    }
    return -1;
} 
int codegen_op2(struct op2* op, char* local_scope_name){//TODO Beware of chars and converstion required to i32 from string
    int op1 = codegen_expression(op->exp1, local_scope_name);
    int op2 = codegen_expression(op->exp2, local_scope_name);
    s_types t = get_op2_type(op, local_scope_name, 0);
    s_types op1type = get_expression_type(op->exp1, local_scope_name, 0);
    s_types op2type = get_expression_type(op->exp2, local_scope_name, 0);
    switch (op->type){
        case t_or:
            print_code_indent(1); 
            printf("%%%d = or %s %%%d, %%%d\n", varcounter, "i1", op1, op2);
            varcounter++;
            print_code_indent(1); 
            printf("%%%d = zext %s %%%d to %s\n",varcounter, "i1", varcounter - 1, "i32");
            return varcounter++;
            break;
        case t_and:
            print_code_indent(1); 
            printf("%%%d = and %s %%%d, %%%d\n", varcounter, "i1", op1, op2);
            varcounter++;
            print_code_indent(1); 
            printf("%%%d = zext %s %%%d to %s\n",varcounter, "i1", varcounter - 1, "i32");
            return varcounter++;
            break;
        case t_eq:
            print_code_indent(1); 
            printf("%%%d = imcp eq %s %%%d, %%%d\n", varcounter, "i32", op1, op2);
            return varcounter++;
            break;
        case t_ne:
            print_code_indent(1); 
            printf("%%%d = imcp ne %s %%%d, %%%d\n", varcounter, "i32", op1, op2);
            return varcounter++;
            break;
        case t_lt:
            print_code_indent(1);
            printf("%%%d = imcp slt %s %%%d, %%%d\n", varcounter, "i32", op1, op2);
            return varcounter++;
            break;
        case t_le:
            print_code_indent(1);
            printf("%%%d = imcp sle %s %%%d, %%%d\n", varcounter, "i32", op1, op2);
            return varcounter++;
            break;
        case t_gt:
            print_code_indent(1);
            printf("%%%d = imcp sgt %s %%%d, %%%d\n", varcounter, "i32", op1, op2);
            return varcounter++;
            break;
        case t_ge:
            print_code_indent(1);
            printf("%%%d = imcp sge %s %%%d, %%%d\n", varcounter, "i32", op1, op2);
            return varcounter++;
            break;
        case t_add:
            if(t == s_double){
                if(op1type != s_double ){
                    print_code_indent(1);
                    printf("%%%d = sitofp %s %%%d to %s\n", varcounter, "i32", op1, "double");
                    op1 = varcounter;
                    varcounter++;
                }
                if(op2type != s_double){
                    print_code_indent(1); 
                    printf("%%%d = sitofp %s %%%d to %s\n", varcounter, "i32", op2, "double");
                    op2 = varcounter;
                    varcounter++;
                }
                print_code_indent(1);
                printf("%%%d = fadd %s %%%d, %%%d\n", varcounter, "double", op1, op2);
                return varcounter++;
            }
            else{
                print_code_indent(1); 
                printf("%%%d = add %s %%%d, %%%d\n", varcounter, "i32", op1, op2);
                return varcounter++;
            }
            break;
        case t_sub:
            if(t == s_double){
                if(op1type != s_double ){
                    print_code_indent(1);
                    printf("%%%d = sitofp %s %%%d to %s\n", varcounter, "i32", op1, "double");
                    op1 = varcounter;
                    varcounter++;
                }
                if(op2type != s_double){
                    print_code_indent(1);
                    printf("%%%d = sitofp %s %%%d to %s\n", varcounter, "i32", op2, "double");
                    op2 = varcounter;
                    varcounter++;
                }
                print_code_indent(1);
                printf("%%%d = fsub %s %%%d, %%%d\n", varcounter, "double", op1, op2);
                return varcounter++;
            }
            else{
                print_code_indent(1);
                printf("%%%d = sub %s %%%d, %%%d\n", varcounter, "i32", op1, op2);
                return varcounter++;
            }
            break;
        case t_mul:
            if(t == s_double){
                if(op1type != s_double ){
                    print_code_indent(1); 
                    printf("%%%d = sitofp %s %%%d to %s\n", varcounter, "i32", op1, "double");
                    op1 = varcounter;
                    varcounter++;
                }
                if(op2type != s_double){
                    print_code_indent(1); 
                    printf("%%%d = sitofp %s %%%d to %s\n", varcounter, "i32", op2, "double");
                    op2 = varcounter;
                    varcounter++;
                }
                print_code_indent(1); 
                printf("%%%d = fmul %s %%%d, %%%d\n", varcounter, "double", op1, op2);
                return varcounter++;
            }
            else{
                print_code_indent(1); 
                printf("%%%d = mul %s %%%d, %%%d\n", varcounter, "i32", op1, op2);
                return varcounter++;
            }
            break;
        case t_div:
            if(t == s_double){
                if(op1type != s_double ){
                    print_code_indent(1); 
                    printf("%%%d = sitofp %s %%%d to %s\n", varcounter, "i32", op1, "double");
                    op1 = varcounter;
                    varcounter++;
                }
                if(op2type != s_double){
                    print_code_indent(1); 
                    printf("%%%d = sitofp %s %%%d to %s\n", varcounter, "i32", op2, "double");
                    op2 = varcounter;
                    varcounter++;
                }
                print_code_indent(1); 
                printf("%%%d = fdiv %s %%%d, %%%d\n", varcounter, "double", op1, op2);
                return varcounter++;
            }
            else{
                print_code_indent(1); 
                printf("%%%d = sdiv %s %%%d, %%%d\n", varcounter, "i32", op1, op2);
                return varcounter++;
            }
            break;
        case t_mod:
                print_code_indent(1); 
                printf("%%%d = srem %s %%%d, %%%d\n", varcounter, "i32", op1, op2);
                return varcounter++;
            break;
        case t_store:
            if(op2type == s_double){
                printf("store %s %%%d, %s* %%%d", "double", op2, "double", op1);
            } 
            else{
                printf("store %s %%%d, %s* %%%d", "i32", op2, "i32", op1);
            }
            break;
        case t_comma:
            printf("Comma");
            break;
        case t_bitwiseand:
            print_code_indent(1);
            printf("%%%d = or %s %%%d, %%%d\n", varcounter, "i32", op1, op2);
            return varcounter++;
            break;
        case t_bitwisexor:
            print_code_indent(1);
            printf("%%%d = xor %s %%%d, %%%d\n", varcounter, "i32", op1, op2);
            return varcounter++;
            break;
        case t_bitwiseor:
            print_code_indent(1);
            printf("%%%d = or %s %%%d, %%%d\n", varcounter, "i32", op1, op2);
            return varcounter++;
            break;
    }
    return -1;
}
int codegen_term(struct terminal* t, char* local_scope_name){
    if(t->type == t_id){
        struct sym_element* se = NULL;
        struct scope* s = NULL;

        if ((s = get_scope_by_name(scope_head,local_scope_name)) && (se = get_token_by_name(s->symtab,t->info->id))){
            print_code_indent(1);
            printf("%%%d = load %s, %s* %%%s\n", varcounter,codegen_terminal_type(t->type), codegen_terminal_type(t->type),t->info->id);
        } else if ((s = get_scope_by_name(scope_head,"Global")) && (se = get_token_by_name(s->symtab,t->info->id))) {
            print_code_indent(1);
            printf("%%%d = load %s, %s* @%s\n", varcounter,codegen_terminal_type(t->type), codegen_terminal_type(t->type),t->info->id);
        }
        return varcounter++;
    }
    else{ 
        print_code_indent(1);
        s_types tp = get_terminal_type(t, local_scope_name, 0);
        if(tp == s_double){
            printf("%%%d = fadd %s %s, 0.0\n", varcounter,"double", t->info->id);
            return varcounter++;
        }
        else if(t->type == t_charlit){
            printf("%%%d = add %s %d, 0\n", varcounter,"i32", t->info->id[0]);
            return varcounter++;
        }
        else{
            printf("%%%d = add %s %s, 0\n", varcounter,"i32", t->info->id);
            return varcounter++;
        }
    }
     
}
int codegen_call(struct call* c, char* local_scope_name){
    struct call* current;
    int paramregs[1024];
    int paramnr = 0, i;
    struct sym_element* sm = get_token_by_name(scope_head->symtab, local_scope_name);
    struct sym_f_param* par_list = sm->sym_f->params;
    struct sym_f_param* par_list_copy = sm->sym_f->params;
    for (current = c; current; current = current->next_arg){
        if (current->ct == call_exp){//TODO conversion to correct type
            paramregs[paramnr]  = codegen_expression(current->call_morphs.exp, local_scope_name);
            paramnr++;
        }
    }
    for (current = c, i = 0; current; current = current->next_arg){
        if (current->ct == call_exp){
        
                if(par_list_copy->param_type  == s_double && get_expression_type(current->call_morphs.exp, local_scope_name, 0) != s_double){
                    print_code_indent(1); 
                    printf("%%%d = sitofp %s %%%d to %s\n", varcounter, "i32", paramregs[i], "double");
                    paramregs[i]  = varcounter;
                    varcounter++;
                }
            i++;
			par_list_copy = par_list_copy->next;
        }
    }
    print_code_indent(1); 
    printf("%%%d = call %s @%s(", varcounter,codegen_s_type(sm->sym_f->return_value), c->call_morphs.info->id);
    //Print Param list
    for (current = c, i = 0; current; current = current->next_arg){
        if (current->ct == call_exp){

            printf("%s %%%d", codegen_s_type(par_list->param_type), paramregs[i]);
            i++;
			par_list = par_list->next;
            if(i != paramnr){
                printf(", ");
            }
        }
    }   
        
    printf(")\n");
    return varcounter++;
}