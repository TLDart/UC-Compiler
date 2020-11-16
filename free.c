#include <stdio.h>
#include <stdlib.h>
#include "free.h"
#include "structures.h"


void* free_program(struct program* myprog){
    while(myprog != NULL){
    struct program* current = myprog;
    if(myprog->type == t_f_dec){
        free_function_declaration(myprog->data_program.u_f_dec);
    }    
    if(myprog->type == t_f_def){
        free_function_definition(myprog->data_program.u_f_def);
    }   
    if(myprog->type == t_dec){
        free_dec(myprog->data_program.u_dec);
    }
    myprog = myprog->next;
        free(current);
    }
}

void free_function_definition(struct function_definition* head){
    if(head != NULL){
        free(head->id);
        free_param_list(head->param_list);
        free_function_body(head->f_body);
        free(head);
    }
}

void free_function_declaration(struct function_declaration* head){
    if(head != NULL){
        free(head->id);
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
       free(head->id);
       free(head);
    }
}
void free_function_body(struct function_body* head){
    while(head != NULL){
        struct function_body* current = head;
        if(head->type = t_statement){
            free_statement(head->data_body.u_stt);
        }
        if(head->type = t_declaration){
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
        free(head->id);
        free_expression(head->expr);
        free(head);
    }
}

void free_statement(struct statement* head){
    while(head != NULL){
        struct statement* current = head;
        if(head->type = t_if){
            free_if(head->statement_data.u_if);
        }
        if(head->type = t_return){
            free_return(head->statement_data.u_return);
        }
        if(head->type = t_while){
            free_while(head->statement_data.u_while);
        }
        if(head->type = t_statlist){
            free_statlist(head->statement_data.u_statlist);
        }
        if(head->type = t_expression){
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