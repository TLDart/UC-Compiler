 #include "codegen.h"

void print_code_indent(int depth){
    for(int i = 0; i < depth * 2; i++)
        printf(" ");
}

char* get_type(struct tpspec * t){
    if(t->type == t_typespec_double)
        return "double";
    else if(t->type == t_typespec_void)
        return "void";
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


void codegen(struct program* head, struct scope* scope_head){
    printf("declare i32 @putchar(i32)\n\n");
    printf("declare i32 @getchar()\n\n");
    
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
    add_default_main();//If there is no main, then we should add one
}

void codegen_declaration(struct declaration* dec, int depth, char* scope_name){
    struct declaration* head = dec;
    int result;
    s_types op1type;
    double globnr;
    while(dec != NULL){
        if(strcmp(scope_name, "Global") == 0){// If is global we will have to calculate the value of the expression in place, else we will calculate with the help of variables
			globnr = dec->decl->expr ? calc_global_expression(dec->decl->expr) : 0; 
                if(strcmp(get_type(head->tsp), "double") == 0){
                    if(globnr == (int) globnr)
                        printf("@%s = global %s %.2lf\n", dec->decl->info->id, get_type(head->tsp), globnr);
                    else
                        printf("@%s = global %s %lf\n", dec->decl->info->id, get_type(head->tsp), globnr);
                }
                else
                    printf("@%s = global %s %.0lf\n", dec->decl->info->id, get_type(head->tsp), globnr);
        }
        else{ // If it is in scope local aka inside a function
            printf("  %%%s = alloca %s\n", dec->decl->info->id, get_type(head->tsp));

            if(dec->decl->expr != NULL){
                result = codegen_expression(dec->decl->expr, scope_name); // Get value of the expression
                op1type = get_expression_type(dec->decl->expr, scope_name,0);
                if(op1type != s_double && strcmp(get_type(head->tsp), "double") == 0){ //Convert to double if required
                    printf("  %%%d = sitofp %s %%%d to %s\n", varcounter++, "i32", result, "double");
					result++;
				}
                printf("  store %s %%%d, %s* %%%s\n", get_type(head->tsp), result,get_type(head->tsp), dec->decl->info->id);
            }
            else{
                char * val = strcmp(get_type(head->tsp), "double") == 0 ? "0.0" : "0";  
                printf("  store %s %s, %s* %%%s\n", get_type(head->tsp), val, get_type(head->tsp), dec->decl->info->id);
            }
        }
            dec = dec->next;
	}
}

void codegen_f_def(struct function_definition* f_def){
    char* tp, *rt;
    printf("define %s @%s(", get_type(f_def->tsp), f_def->info->id);
    codegen_param_list(f_def->param_list);
    printf("){\n");
    codegen_param_list_stores(f_def->param_list);

    if(f_def->f_body != NULL)
        codegen_f_body(f_def->f_body, f_def->info->id);
    
	//Add a default return type
    tp = strcmp(get_type(f_def->tsp), "i32") == 0 ? "i32" : strcmp(get_type(f_def->tsp), "void") == 0 ? "void" :"double";
    rt = strcmp(get_type(f_def->tsp), "i32") == 0 ? "0" : strcmp(get_type(f_def->tsp), "void") == 0 ? "" : "0.0";
    printf("  ret %s %s\n", tp, rt);

    printf("}\n");
    varcounter = 1; // Reset varcounter each time we leave a function

}

void codegen_param_list(struct parameter_list* p_list){
    while(p_list != NULL){
        if(p_list->p_dec->tsp->type != t_typespec_void)
			printf("%s %%arg.%s", get_type(p_list->p_dec->tsp), p_list->p_dec->info->id);
        p_list = p_list->next;
        if(p_list != NULL) printf(","); //Check if one should print "," on the last instance
        
    }
}

void codegen_param_list_stores(struct parameter_list* p_list){
    while(p_list != NULL){
        if(p_list->p_dec->tsp->type != t_typespec_void){// If it is not void
            char * tp = strcmp(get_type(p_list->p_dec->tsp), "double") == 0 ? "double" : "i32";
            printf("  %%%s = alloca %s\n", p_list->p_dec->info->id, tp);
            printf("  store %s %%arg.%s, %s* %%%s\n",tp, p_list->p_dec->info->id, tp, p_list->p_dec->info->id);
        }
        p_list = p_list->next;
    }
}

void codegen_f_body(struct function_body* f_body, char* local_scope_name){
    
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

int codegen_statement(struct statement* stt, char* local_scope_name){
    while(stt != NULL){
        if(stt->type == t_if){
            codegen_if(stt->statement_data.u_if, local_scope_name);
        }
        else if(stt->type == t_return){
            codegen_return(stt->statement_data.u_return, local_scope_name);
        }
        else if(stt->type == t_while){
            codegen_while(stt->statement_data.u_while, local_scope_name);
        }
        else if(stt->type == t_statlist){
            codegen_statlist(stt->statement_data.u_statlist, local_scope_name);
        }
        else if(stt->type == t_expression){
            codegen_expression(stt->statement_data.u_expr, local_scope_name);
        }
        stt = stt->next;
    }
    return -1;

}


int codegen_if(struct if_statement* stt_if, char* local_scope_name){
    int result = codegen_expression(stt_if->expr, local_scope_name);
    int label1 = labelcounter++, label2 = labelcounter++, label3 = labelcounter++;
    printf("  %%%d = icmp ne %s %%%d, %s\n", varcounter++, "i32", result, "0");
    printf("  br %s %%%d, label %%label%d, label %%label%d\n", "i1", varcounter - 1, label1,label2);

    printf("\nlabel%d:\n", label1);
    if(stt_if->if_body != NULL)
        codegen_statement(stt_if->if_body, local_scope_name);
    printf("  br label %%label%d\n", label3);

    printf("\nlabel%d:\n", label2);

    if(stt_if->else_body != NULL) codegen_statement(stt_if->else_body, local_scope_name);
    
    printf("  br label %%label%d\n", label3);

    printf("\nlabel%d:\n", label3);

    return varcounter;
}

int codegen_while(struct while_statement* stt_whi, char* local_scope_name){
    int label1 = labelcounter++, label2 = labelcounter++, label3 = labelcounter++, result;

    printf("  br label %%label%d\n", label1);
    printf("\nlabel%d:\n", label1);

    result = codegen_expression(stt_whi->expr, local_scope_name);
    printf("  %%%d = icmp ne %s %%%d, %s\n", varcounter++, "i32", result, "0");
    printf("  br %s %%%d, label %%label%d, label %%label%d\n", "i1", varcounter - 1, label2,label3);

    printf("\nlabel%d:\n", label2);

    if(stt_whi->while_body != NULL) codegen_statement(stt_whi->while_body, local_scope_name);
    printf("  br label %%label%d\n", label1);

    printf("\nlabel%d:\n", label3);

    return varcounter;
}
int codegen_statlist(struct statlist_statement* stt_stl, char* local_scope_name){
    codegen_statement(stt_stl->stt, local_scope_name);
    return varcounter;
}

int codegen_return(struct return_statement* stt_ret, char* local_scope_name){
    int result ;
    if(stt_ret->expr) {
        result = codegen_expression(stt_ret->expr, local_scope_name);   
        s_types t = get_expression_type(stt_ret->expr, local_scope_name, 0);
        struct sym_element* sm = get_token_by_name(scope_head->symtab, local_scope_name);
        //if the operator is of type i32 but the function is of type double we need to convert
        if(sm->sym_f->return_value == s_double && t != s_double){
            printf("  %%%d = sitofp %s %%%d to %s\n", varcounter++, "i32", result, "double");
            result = varcounter - 1;
        }

        printf("  ret %s %%%d\n",codegen_s_type(sm->sym_f->return_value) , result);
    }
    else{
        printf("  ret void\n");
    }
    return varcounter++;

}
int codegen_expression(struct expression* expr, char* local_scope_name){
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
    int op1 = codegen_expression(op->exp, local_scope_name);
    s_types op1type = get_expression_type(op->exp, local_scope_name, 0);
    switch (op->type){
        case t_not:
            if(op1type == s_double) printf("  %%%d = fcmp une %s %%%d, %s\n", varcounter++, "double", op1, "0.0");
            else printf("  %%%d = icmp ne %s %%%d, %s\n", varcounter++, "i32", op1, "0");

            printf("  %%%d = xor %s %%%d, %s\n", varcounter, "i1", varcounter - 1 , "true");
            varcounter++;
            printf("  %%%d = zext %s %%%d to %s\n", varcounter, "i1", varcounter - 1, "i32");
            return varcounter++;
            break;
        case t_minus:
            if(op1type == s_double){
                printf("  %%%d = fneg %s %%%d\n", varcounter++, "double", op1);
                return varcounter - 1;
            }
            else{
                printf("  %%%d = sub %s %s, %%%d\n", varcounter++, "i32", "0",op1);
                return varcounter - 1;
            }
            
            break;
        case t_plus:
            return varcounter - 1;
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
	int label0,label1, label2, result;
    s_types t = get_op2_type(op, local_scope_name, 0);
    s_types op1type = get_expression_type(op->exp1, local_scope_name, 0);
    s_types op2type = get_expression_type(op->exp2, local_scope_name, 0);
    struct sym_element* se = NULL;
    struct scope* s = NULL;
    switch (op->type){
        case t_and:
            label0 = labelcounter++;
            label1 = labelcounter++;
            label2 = labelcounter++;    

            printf("  br label %%label%d\n", label0);
            printf("\nlabel%d:\n", label0);

            if(op1type == s_double ){
                printf("  %%%d = fcmp une %s %%%d, %s\n", varcounter++, "double", op1, "0.0");
                result = varcounter - 1;
            }
            else{
                printf("  %%%d = icmp ne %s %%%d, %s\n", varcounter++, "i32", op1, "0");
                result = varcounter - 1;
            }
            printf("  br %s %%%d, label %%label%d, label %%label%d\n", "i1", result,label1, label2);
            printf("\nlabel%d:\n", label1);

            if(op2type == s_double ){
                printf("  %%%d = fcmp une %s %%%d, %s\n", varcounter++, "double", op2, "0.0");
                result = varcounter - 1;
            }
            else{
                printf("  %%%d = icmp ne %s %%%d, %s\n", varcounter++, "i32", op2, "0");
                result = varcounter - 1;
            }	
            printf("  br label %%label%d\n", label2);

            printf("\nlabel%d:\n", label2);

            printf("  %%%d = phi %s [ false, %%label%d ], [ %%%d, %%label%d ]\n", varcounter++, "i1",label0, result, label1);
            printf("  %%%d = zext %s %%%d to %s\n",varcounter, "i1", varcounter - 1, "i32");
            return varcounter++;
            break;
        case t_or:
				label0 = labelcounter++;
				label1 = labelcounter++;
				label2 = labelcounter++;


                printf("  br label %%label%d\n", label0);
                printf("\nlabel%d:\n", label0);

            	if(op1type == s_double ){
                    printf("  %%%d = fcmp une %s %%%d, %s\n", varcounter++, "double", op1, "0.0");
                    result = varcounter - 1;
                }
				else{
                    printf("  %%%d = icmp ne %s %%%d, %s\n", varcounter++, "i32", op1, "0");
                    result = varcounter - 1;
				}
				printf("  br %s %%%d, label %%label%d, label %%label%d\n", "i1", result,label2, label1);
				printf("\nlabel%d:\n", label1);

				if(op2type == s_double ){
                    printf("  %%%d = fcmp une %s %%%d, %s\n", varcounter++, "double", op2, "0.0");
                    result = varcounter - 1;
                }
				else{
                    printf("  %%%d = icmp ne %s %%%d, %s\n", varcounter++, "i32", op2, "0");
                    result = varcounter - 1;
				}	
				printf("  br label %%label%d\n", label2);

				printf("\nlabel%d:\n", label2);

            printf("  %%%d = phi %s [ true, %%label%d ], [ %%%d, %%label%d ]\n", varcounter++, "i1",label0, result, label1);
            printf("  %%%d = zext %s %%%d to %s\n",varcounter, "i1", varcounter - 1, "i32");
            return varcounter++;
            break;
        case t_eq:
            if(op1type == s_double || op2type == s_double){// If atleast one of the operators is a double we need to check for conversion
                if(op1type != s_double ){
                    printf("  %%%d = sitofp %s %%%d to %s\n", varcounter++, "i32", op1, "double");
                    op1 = varcounter - 1;
                }
                if(op2type != s_double){
                    printf("  %%%d = sitofp %s %%%d to %s\n", varcounter++, "i32", op2, "double");
                    op2 = varcounter - 1;
                }
                printf("  %%%d = fcmp oeq %s %%%d, %%%d\n", varcounter++, "double", op1, op2);
            }
            else 
                printf("  %%%d = icmp eq %s %%%d, %%%d\n", varcounter++, "i32", op1, op2);
            printf("  %%%d = zext %s %%%d to %s\n", varcounter, "i1", varcounter - 1, "i32");
            return varcounter++;
            break;
        case t_ne:
            if(op1type == s_double || op2type == s_double){
                if(op1type != s_double ){
                    printf("  %%%d = sitofp %s %%%d to %s\n", varcounter++, "i32", op1, "double");
                    op1 = varcounter - 1;
                }
                if(op2type != s_double){
                    printf("  %%%d = sitofp %s %%%d to %s\n", varcounter++, "i32", op2, "double");
                    op2 = varcounter - 1;
                }
                printf("  %%%d = fcmp one %s %%%d, %%%d\n", varcounter++, "double", op1, op2);
            }
            else
                printf("  %%%d = icmp ne %s %%%d, %%%d\n", varcounter++, "i32", op1, op2);
            printf("  %%%d = zext %s %%%d to %s\n", varcounter, "i1", varcounter - 1, "i32");
            return varcounter++;
            break;
        case t_lt:
            if(op1type == s_double || op2type == s_double){
                if(op1type != s_double ){
                    printf("  %%%d = sitofp %s %%%d to %s\n", varcounter++, "i32", op1, "double");
                    op1 = varcounter - 1;
                }
                if(op2type != s_double){
                    printf("  %%%d = sitofp %s %%%d to %s\n", varcounter++, "i32", op2, "double");
                    op2 = varcounter - 1;
                }
                printf("  %%%d = fcmp olt %s %%%d, %%%d\n", varcounter++, "double", op1, op2);
            }
            else
                printf("  %%%d = icmp slt %s %%%d, %%%d\n", varcounter++, "i32", op1, op2);
            printf("  %%%d = zext %s %%%d to %s\n", varcounter, "i1", varcounter - 1, "i32");
            return varcounter++;
            break;
        case t_le:
            if(op1type == s_double || op2type == s_double){
                if(op1type != s_double ){
                    printf("  %%%d = sitofp %s %%%d to %s\n", varcounter++, "i32", op1, "double");
                    op1 = varcounter - 1;
                }
                if(op2type != s_double){
                    printf("  %%%d = sitofp %s %%%d to %s\n", varcounter++, "i32", op2, "double");
                    op2 = varcounter - 1;
                }
                printf("  %%%d = fcmp ole %s %%%d, %%%d\n", varcounter++, "double", op1, op2);
            }
            else
                printf("  %%%d = icmp sle %s %%%d, %%%d\n", varcounter++, "i32", op1, op2);
            printf("  %%%d = zext %s %%%d to %s\n", varcounter, "i1", varcounter - 1, "i32");
            return varcounter++;
            break;
        case t_gt:
            if(op1type == s_double || op2type == s_double){
                if(op1type != s_double ){
                    printf("  %%%d = sitofp %s %%%d to %s\n", varcounter++, "i32", op1, "double");
                    op1 = varcounter - 1;
                }
                if(op2type != s_double){
                    printf("  %%%d = sitofp %s %%%d to %s\n", varcounter++, "i32", op2, "double");
                    op2 = varcounter - 1;
                }
                printf("  %%%d = fcmp ogt %s %%%d, %%%d\n", varcounter++, "double", op1, op2);
            }
            else
                printf("  %%%d = icmp sgt %s %%%d, %%%d\n", varcounter++, "i32", op1, op2);
            printf("  %%%d = zext %s %%%d to %s\n", varcounter, "i1", varcounter - 1, "i32");
            return varcounter++;
            break;
        case t_ge:
            if(op1type == s_double || op2type == s_double){
                if(op1type != s_double ){
                    printf("  %%%d = sitofp %s %%%d to %s\n", varcounter++, "i32", op1, "double");
                    op1 = varcounter - 1;
                }
                if(op2type != s_double){
                    printf("  %%%d = sitofp %s %%%d to %s\n", varcounter++, "i32", op2, "double");
                    op2 = varcounter - 1;
                }
                printf("  %%%d = fcmp oge %s %%%d, %%%d\n", varcounter++, "double", op1, op2);
            }
            else
                printf("  %%%d = icmp sge %s %%%d, %%%d\n", varcounter++, "i32", op1, op2);
            printf("  %%%d = zext %s %%%d to %s\n", varcounter, "i1", varcounter - 1, "i32");
            return varcounter++;
            break;
        case t_add:
            if(t == s_double){
                if(op1type != s_double ){
                    printf("  %%%d = sitofp %s %%%d to %s\n", varcounter++, "i32", op1, "double");
                    op1 = varcounter - 1;
                }
                if(op2type != s_double){
                    printf("  %%%d = sitofp %s %%%d to %s\n", varcounter++, "i32", op2, "double");
                    op2 = varcounter - 1;
                }
                printf("  %%%d = fadd %s %%%d, %%%d\n", varcounter++, "double", op1, op2);
                return varcounter  -1;
            }
            else{
                printf("  %%%d = add %s %%%d, %%%d\n", varcounter++, "i32", op1, op2);
                return varcounter - 1;
            }
            break;
        case t_sub:
            if(t == s_double){
                if(op1type != s_double ){
                    printf("  %%%d = sitofp %s %%%d to %s\n", varcounter++, "i32", op1, "double");
                    op1 = varcounter - 1;
                }
                if(op2type != s_double){
                    printf("  %%%d = sitofp %s %%%d to %s\n", varcounter++, "i32", op2, "double");
                    op2 = varcounter - 1;
                }
                printf("  %%%d = fsub %s %%%d, %%%d\n", varcounter++, "double", op1, op2);
                return varcounter - 1;
            }
            else{
                printf("  %%%d = sub %s %%%d, %%%d\n", varcounter++, "i32", op1, op2);
                return varcounter -1;
            }
            break;
        case t_mul:
            if(t == s_double){
                if(op1type != s_double ){
                    printf("%%%d = sitofp %s %%%d to %s\n", varcounter++, "i32", op1, "double");
                    op1 = varcounter - 1;
                }
                if(op2type != s_double){
                    printf("  %%%d = sitofp %s %%%d to %s\n", varcounter++, "i32", op2, "double");
                    op2 = varcounter - 1;
                }
                printf("  %%%d = fmul %s %%%d, %%%d\n", varcounter++, "double", op1, op2);
                return varcounter -1;
            }
            else{
                printf("  %%%d = mul %s %%%d, %%%d\n", varcounter++, "i32", op1, op2);
                return varcounter -1;
            }
            break;
        case t_div:
            if(t == s_double){
                if(op1type != s_double ){
                    printf("  %%%d = sitofp %s %%%d to %s\n", varcounter++, "i32", op1, "double");
                    op1 = varcounter - 1;
                }
                if(op2type != s_double){
                    printf("  %%%d = sitofp %s %%%d to %s\n", varcounter++, "i32", op2, "double");
                    op2 = varcounter - 1;
                }
                printf("  %%%d = fdiv %s %%%d, %%%d\n", varcounter++, "double", op1, op2);
                return varcounter -1;
            }
            else{
                printf("  %%%d = sdiv %s %%%d, %%%d\n", varcounter++, "i32", op1, op2);
                return varcounter -1;
            }
            break;
        case t_mod:
                printf("  %%%d = srem %s %%%d, %%%d\n", varcounter++, "i32", op1, op2);
                return varcounter - 1;
            break;
        case t_store:
            if(op2type == s_double){
                if ((s = get_scope_by_name(scope_head,local_scope_name)) && (se = get_token_by_name(s->symtab,op->exp1->expression_morphs.t->info->id)) &&  strcmp(codegen_s_type(se->type), "double") == 0){
                    printf("  store %s %%%d, %s* %%%s\n", "double", op2, "double", op->exp1->expression_morphs.t->info->id);
                }
                else{
                    printf("  store %s %%%d, %s* @%s\n", "double", op2, "double", op->exp1->expression_morphs.t->info->id);
                }
            } 
            else{
                if ((s = get_scope_by_name(scope_head,local_scope_name)) && (se = get_token_by_name(s->symtab,op->exp1->expression_morphs.t->info->id))){
                    if(strcmp(codegen_s_type(se->type), "double") == 0){
                        printf("  %%%d = sitofp %s %%%d to %s\n", varcounter, "i32", op2, "double");
                        op2 = varcounter++;
                        printf("  store %s %%%d, %s* %%%s\n", "double", op2, "double", op->exp1->expression_morphs.t->info->id);
                    }
                    else{
                        printf("  store %s %%%d, %s* %%%s\n", "i32", op2, "i32", op->exp1->expression_morphs.t->info->id);
                    }
                   
                }
                if ((s = get_scope_by_name(scope_head,"Global")) && (se = get_token_by_name(s->symtab,op->exp1->expression_morphs.t->info->id))){
                    if(strcmp(codegen_s_type(se->type), "double") == 0){
                        printf("  %%%d = sitofp %s %%%d to %s\n", varcounter, "i32", op2, "double");
                        op2 = varcounter++;
                        printf("  store %s %%%d, %s* @%s\n", "double", op2, "double", op->exp1->expression_morphs.t->info->id);
                    }
                    else{
                        printf("  store %s %%%d, %s* @%s\n", "i32", op2, "i32", op->exp1->expression_morphs.t->info->id);
                    }
                }
            }
            codegen_expression(op->exp1, local_scope_name);
            return varcounter - 1;
            break;
        case t_comma://here
            return op1;
            break;
        case t_bitwiseand:
            printf("  %%%d = and %s %%%d, %%%d\n", varcounter++, "i32", op1, op2);
            return varcounter - 1;
            break;
        case t_bitwisexor:
            printf("  %%%d = xor %s %%%d, %%%d\n", varcounter++, "i32", op1, op2);
            return varcounter - 1;
            break;
        case t_bitwiseor:
            printf("  %%%d = or %s %%%d, %%%d\n", varcounter++, "i32", op1, op2);
            return varcounter - 1;
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
            printf("%%%d = load %s, %s* %%%s\n", varcounter,codegen_s_type(se->type), codegen_s_type(se->type),t->info->id);
        } else if ((s = get_scope_by_name(scope_head,"Global")) && (se = get_token_by_name(s->symtab,t->info->id))) {
            print_code_indent(1);
            printf("%%%d = load %s, %s* @%s\n", varcounter,codegen_s_type(se->type), codegen_s_type(se->type),t->info->id);
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
            //TODO Se for type \000 then what do I do?
            if(strncmp(t->info->id, "\\n",2) == 0)
                printf("%%%d = add %s %d, 0\n", varcounter,"i32", 10);
            else if(strncmp(t->info->id, "\\t",2) == 0)
                printf("%%%d = add %s %d, 0\n", varcounter,"i32", 9);
            else if(strncmp(t->info->id, "\\\"",2) == 0)
                printf("%%%d = add %s %d, 0\n", varcounter,"i32", 34);
            else if(strncmp(t->info->id, "\\\'",2) == 0)
                printf("%%%d = add %s %d, 0\n", varcounter,"i32", 39);
            else if(strlen(t->info->id) == 5){
                int r = (t->info->id[1] - '0') * (8 * 8) +  (t->info->id[2]- '0') * (8) + (t->info->id[3] -'0') * (1);
                printf("%%%d = add %s %d, 0\n", varcounter,"i32", r);
            }
            else if(strlen(t->info->id) == 4){
                int r = (t->info->id[1] - '0') * (8) +  (t->info->id[2]- '0') * (1);
                printf("%%%d = add %s %d, 0\n", varcounter,"i32", r);
            }
            else if(strlen(t->info->id) == 3){
                int r = (t->info->id[1]- '0') * (1);
                printf("%%%d = add %s %d, 0\n", varcounter,"i32", r);
            }
            else
                printf("%%%d = add %s %d, 0\n", varcounter,"i32", t->info->id[0]);
            return varcounter++;
        }
        else if(t->type == t_intlit && t->info->id[0] == '0'){
            printf("%%%d = add %s %d, 0\n", varcounter,"i32", calc_octal(t->info->id));
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
    struct sym_element* sm = get_token_by_name(scope_head->symtab, c->call_morphs.info->id);//FIXME Might need to do a verification here
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
    if(strcmp(codegen_s_type(sm->sym_f->return_value), "void") == 0 ){
        printf("call %s @%s(",codegen_s_type(sm->sym_f->return_value), c->call_morphs.info->id);
        varcounter--; // Doing this here to neutralize varcounter em returning

    }

    else{
        printf("%%%d = call %s @%s(", varcounter,codegen_s_type(sm->sym_f->return_value), c->call_morphs.info->id);
    }

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

//=====================================================Helper funcs=======================================================

double calc_global_expression(struct expression* expr){// Global expressions can only be constants and therefore neither call nor id types are possible
	if(expr){
		if(expr->expr_t == t_op1){
			return calc_op1(expr->expression_morphs.operation1);
		}
		else if(expr->expr_t == t_op2){
			return calc_op2(expr->expression_morphs.operation2);
		}

		else if(expr->expr_t == t_term){
			return calc_term(expr->expression_morphs.t);
		}
		else{
			printf("Something went very wrong");
			return -1;
		}
	}
	else{
		return 0;
	}
}

double calc_op1(struct op1* op){
    switch (op->type){
        case t_not:
            return !calc_global_expression(op->exp);
        case t_minus:
            return -calc_global_expression(op->exp);
        case t_plus:
            return +calc_global_expression(op->exp);
		default:
			return 0;
    }
}

double calc_op2(struct op2* op){
	switch (op->type){
        case t_or:
			return calc_global_expression(op->exp1) || calc_global_expression(op->exp2);
        case t_and:
			return calc_global_expression(op->exp1) && calc_global_expression(op->exp2);
        case t_eq:
			return calc_global_expression(op->exp1) == calc_global_expression(op->exp2);
        case t_ne:
			return calc_global_expression(op->exp1) != calc_global_expression(op->exp2);
        case t_lt:
			return calc_global_expression(op->exp1) < calc_global_expression(op->exp2);
        case t_le:
			return calc_global_expression(op->exp1) <= calc_global_expression(op->exp2);
        case t_gt:
			return calc_global_expression(op->exp1) > calc_global_expression(op->exp2);
        case t_ge:
			return calc_global_expression(op->exp1) >= calc_global_expression(op->exp2);
        case t_add:
			return calc_global_expression(op->exp1) + calc_global_expression(op->exp2);
        case t_sub:
			return calc_global_expression(op->exp1) - calc_global_expression(op->exp2);
        case t_mul:
			return calc_global_expression(op->exp1) * calc_global_expression(op->exp2);
        case t_div:
			return calc_global_expression(op->exp1) / calc_global_expression(op->exp2);
        case t_mod:
			return (int) calc_global_expression(op->exp1) % (int) calc_global_expression(op->exp2);
        case t_store://TODO confirm this
			return calc_global_expression(op->exp2);
        case t_comma://TODO confirm This
			return calc_global_expression(op->exp1);
        case t_bitwiseand:
			return (int) calc_global_expression(op->exp1) & (int) calc_global_expression(op->exp2);
        case t_bitwisexor:
			return (int) calc_global_expression(op->exp1) ^ (int) calc_global_expression(op->exp2);
        case t_bitwiseor:
			return (int) calc_global_expression(op->exp1) | (int) calc_global_expression(op->exp2);
		default:
			return 0;
    }
}

double calc_term(struct terminal* t){
	switch (t->type){
		case t_charlit://How to we behave for \???
			if(strncmp(t->info->id, "\\n",2) == 0)
				return 10;
            else if(strncmp(t->info->id, "\\t",2) == 0)
				return 9;
            else if(strncmp(t->info->id, "\\\"",2) == 0)
				return 34;
            else if(strncmp(t->info->id, "\\\'",2) == 0)
				return 39;
            else if(strlen(t->info->id) == 5)
                return (t->info->id[1] - '0') * (8 * 8) +  (t->info->id[2]- '0') * (8) + (t->info->id[3] -'0') * (1);
			else // Are there more cases that I am not covering
                return (int) t->info->id[0];
        case t_id:
            printf("This is illegal in global vars\n");
			return 0;
        case t_intlit:
        case t_reallit:
            return atof(t->info->id);
            break;
        default:
			return 0;
    }
}
void add_default_main(){//If there is no main defined, then define a main
    struct scope* s = NULL;
    s = get_scope_by_name(scope_head,"main");
    if(s == NULL)
        printf("\ndefine i32 @main(){\n  ret i32 0\n}\n");
}

int calc_octal(char* str){
    int i = strlen(str) - 1;
    int r = 0;
    int p = 1;
    for(i = strlen(str) - 1; i > 0;i--){
        //printf("%d // %d", str[i], p);
        r += (str[i] -  '0') *  p;
        p *=8;
    }

    return r;
}
