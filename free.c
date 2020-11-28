#include "free.h"

void free_program(struct program* myprog){
    while(myprog != NULL){
    struct program* current = myprog;
    if(myprog->type == t_f_dec){
        free_function_declaration(myprog->data_program.u_f_dec);
    }    
    if(myprog->type == t_f_def){
        free_function_definition(myprog->data_program.u_f_def);
    }   
    if(myprog->type == t_dec){
        free_declaration(myprog->data_program.u_dec);
    }
    myprog = myprog->next;
        free(current);
    }
}

void free_function_definition(struct function_definition* head){
    if(head != NULL){
        //TODOfree(head->id);
        free_param_list(head->param_list);
        free_function_body(head->f_body);
        free(head);
    }
}

void free_function_declaration(struct function_declaration* head){
    if(head != NULL){
        //TODOfree(head->id);
        free_param_list(head->param_list);
        free(head);
    }
}
void free_param_list(struct parameter_list* head){
    while(head != NULL){
        struct parameter_list* current = head;
        free_param_declaration(head->p_dec);
        head = head->next;
        free(current);
    }
}
void free_param_declaration(struct parameter_declaration* head){
    if(head != NULL){
       //TODOfree(head->id);
       free(head);
    }
}
void free_function_body(struct function_body* head){
    while(head != NULL){
        struct function_body* current = head;
        if(head->type == t_statement){
            free_statement(head->data_body.u_stt);
        }
        if(head->type == t_declaration){
            free_declaration(head->data_body.u_dec);
        }
        head = head->next;
        free(current);
    }
}
void free_declaration(struct declaration* head){
    while(head != NULL){
        struct declaration* current = head;
        free_declarator(head->decl);
        head = head->next;
        free(current);
    }
}

void free_declarator(struct declarator* head){
    if(head != NULL){
        //TODOfree(head->id);
        free_expression(head->expr);
        free(head);
    }
}

void free_statement(struct statement* head){
    while(head != NULL){
        struct statement* current = head;
        if(head->type == t_if){
            free_if(head->statement_data.u_if);
        }
        if(head->type == t_return){
            free_return(head->statement_data.u_return);
        }
        if(head->type == t_while){
            free_while(head->statement_data.u_while);
        }
        if(head->type == t_statlist){
            free_statlist(head->statement_data.u_statlist);
        }
        if(head->type == t_expression){
            free_expression(head->statement_data.u_expr);
        }
        head = head->next;
        free(current);
    }
}

void free_if(struct if_statement* head){
    if(head != NULL){
        free_expression(head->expr);
        free_statement(head->if_body);
        free_statement(head->else_body);
        free(head);
    }
}

void free_return(struct return_statement* head){
    if(head != NULL){
        free_expression(head->expr);
        free(head);
    }
}
void free_while(struct while_statement* head){
    if(head != NULL){
        free_expression(head->expr);
        free_statement(head->while_body);
        free(head);
    }
}
void free_statlist(struct statlist_statement* head){
    if(head != NULL){
        free_statement(head->stt);
        free(head);
    }
}

//new 



void free_expression(struct expression* expr){
    if (expr != NULL){
        if (expr->expr_t == t_op1){
            free_op1(expr->expression_morphs.operation1);
        } else if (expr->expr_t == t_op2){
            free_op2(expr->expression_morphs.operation2);
        } else if (expr->expr_t == t_term){
            free_term(expr->expression_morphs.t);
        } else if (expr->expr_t == t_call) {
            free_call(expr->expression_morphs.c);
        }
        free(expr);
    }
}

void free_op1(struct op1* op){
    if (op != NULL){
        free_expression(op->exp);
        free(op);
    }
}
void free_op2(struct op2* op){
    if (op != NULL){
        free_expression(op->exp1);
        free_expression(op->exp2);
        free(op);
    }
}

void free_term(struct terminal* t){
    if (t != NULL){
        //TODOfree(t->id);
        free(t);
    }
}
void free_call(struct call* c){
    if (c != NULL){
        free_call(c->next_arg);
        if (c->ct == call_name){
            //TODOfree(c->call_morphs.id);
        } else if (c->ct == call_exp) {
            free_expression(c->call_morphs.exp);
        }
        free(c);
    }
}