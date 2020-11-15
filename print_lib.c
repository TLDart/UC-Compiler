#include "structures.h"
#include "print_lib.h"
#include <stdlib.h>
#include <stdio.h>


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
            print_declaration(head->data_program.u_dec, depth +1);
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
    if(f_def->f_body != NULL)
        print_f_body(f_def->f_body, depth + 1);

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

void print_f_body(struct function_body* f_body, int depth){
    print_indentation(depth);
    printf("FuncBody\n");
    while(f_body != NULL){
        if(f_body->type == t_statement){
            print_statement(f_body->data_body.u_stt, depth + 1);
        }
        
        else if(f_body->type == t_declaration){
            print_declaration(f_body->data_body.u_dec, depth + 1);
        }
        f_body = f_body->next;
    }
}


void print_declaration(struct declaration* dec, int depth){
    struct declaration* head = dec;
    while(dec != NULL){
        print_indentation(depth);
        printf("Declaration\n");
        print_typespec(head->type,depth + 1);
        print_declarator(dec->decl, depth + 1);
        dec = dec->next;
    }
}

void print_declarator(struct declarator* decl, int depth){
    print_id(decl->id, depth);
    if (decl->expr != NULL){
       print_expression(decl->expr, depth);
    }
    else{
        //print_indentation(depth);
    }
}

void print_statement(struct statement* stt, int depth){
    //printf("asdasdasdasd %d\n", stt->type);
    while(stt != NULL){
        if(stt->type == t_if){
            print_if(stt->statement_data.u_if, depth);
        }
        else if(stt->type == t_return){
             //printf("tf xd\n");
            print_return(stt->statement_data.u_return, depth);
        }
        else if(stt->type == t_while){
            //printf("here\n");
            print_while(stt->statement_data.u_while, depth);
        }
        else if(stt->type == t_statlist){
            print_statlist(stt->statement_data.u_statlist, depth);
        }
        else if(stt->type == t_expression){
            // printf("Here goes h");
            print_expression(stt->statement_data.u_expr, depth);
        }
        stt = stt->next;
    }

}


void print_if(struct if_statement* stt_if, int depth){
    print_indentation(depth);
    printf("If\n");
    if(stt_if->expr != NULL){
        print_expression(stt_if->expr, depth + 1);
    }
    else printf("Erro! A menos que as expressions ainda nao estejam feitas\n");
    if(stt_if->if_body == NULL || (stt_if->if_body->type == t_statlist && stt_if->if_body->statement_data.u_statlist->stt == NULL)){
        print_indentation(depth + 1);
        printf("Null\n");
    }
    else{
        print_statement(stt_if->if_body, depth + 1);
    }
    if(stt_if->else_body == NULL || (stt_if->else_body->type == t_statlist && stt_if->else_body->statement_data.u_statlist->stt == NULL)){
        print_indentation(depth + 1);
        printf("Null\n");
    }
    else{
        print_statement(stt_if->else_body, depth + 1);
    }
}

void print_return(struct return_statement* stt_ret, int depth){
    print_indentation(depth);
    printf("Return\n");
    if(stt_ret->expr == NULL){
        print_indentation(depth + 1);
        printf("Null\n");
    }
    else{
        print_expression(stt_ret->expr, depth + 1);
    }
}

void print_while(struct while_statement* stt_whi, int depth){
    print_indentation(depth);
    printf("While\n");
    if(stt_whi->expr == NULL){
        print_expression(stt_whi->expr, depth + 1);
    }
    else{
        print_expression(stt_whi->expr, depth + 1);
    }
    if(stt_whi->while_body == NULL || (stt_whi->while_body->type == t_statlist && stt_whi->while_body->statement_data.u_statlist->stt == NULL)){
        print_indentation(depth + 1);
        printf("Null\n");
    }
    else{
        print_statement(stt_whi->while_body, depth + 1);
    }
}
void print_statlist(struct statlist_statement* stt_stl, int depth){
    if(stt_stl->stt != NULL && stt_stl->stt->next){
        print_indentation(depth);
        printf("StatList\n");
        print_statement(stt_stl->stt, depth +1);
    }
    else{
        print_statement(stt_stl->stt, depth);
    }
}

// new
void print_expression(struct expression* expr, int depth){
    print_indentation(depth);
    //printf("Here goes expression\n");
    if (expr->expr_t == t_op1){
        print_op1(expr->expression_morphs.operation1, depth);
    } else if (expr->expr_t == t_op2){
        print_op2(expr->expression_morphs.operation2, depth);
    } else if (expr->expr_t == t_term){
        print_term(expr->expression_morphs.t, depth);
    } else if (expr->expr_t == t_call) {
        print_call(expr->expression_morphs.c, depth);
    }
}


void print_op1(struct op1* op, int depth){
    switch (op->type){
        case t_not:
            printf("Not\n");
            break;
        case t_minus:
            printf("Minus\n");
            break;
        case t_plus:
            printf("Plus\n");
            break;
    }
    print_expression(op->exp, depth + 1);
}

void print_op2(struct op2* op, int depth){
    switch (op->type){
        case t_or:
            printf("Or\n");
            break;
        case t_and:
            printf("And\n");
            break;
        case t_eq:
            printf("Eq\n");
            break;
        case t_ne:
            printf("Ne\n");
            break;
        case t_lt:
            printf("Lt\n");
            break;
        case t_gt:
            printf("Gt\n");
            break;
        case t_ge:
            printf("Ge\n");
            break;
        case t_add:
            printf("Add\n");
            break;
        case t_sub:
            printf("Sub\n");
            break;
        case t_mul:
            printf("Mul\n");
            break;
        case t_div:
            printf("Div\n");
            break;
        case t_mod:
            printf("Mod\n");    
            break;
        case t_store:
            printf("Store\n");
            break;
        case t_comma:
            printf("Comma\n");
            break;
        case t_bitwiseand:
            printf("BitWiseAnd\n");    
            break;
        case t_bitwisexor:
            printf("BitWiseXor\n");
            break;
        case t_bitwiseor:
            printf("BitWiseOr\n");
            break;
        case t_le:
            printf("Le\n");    
            break;
    }
    print_expression(op->exp1, depth + 1);
    print_expression(op->exp2, depth + 1);
}

void print_term(struct terminal* t, int depth){
    switch (t->type){
        case t_charlit:
            printf("ChrLit('%s)\n",t->id);
            break;
        case t_id:
            printf("Id(%s)\n",t->id);
            break;
        case t_intlit:
            printf("IntLit(%s)\n",t->id);
            break;
        case t_reallit:
            printf("RealLit(%s)\n",t->id);
            break;
        default:
            break;
    }
}

void print_call(struct call* c, int depth){
    struct call* current;
    for (current = c; current; current = current->next_arg){
        if (current->ct == call_name) {
            printf("Call\n");
            print_indentation(depth + 1);
            printf("Id(%s)\n",current->call_morphs.id);
        } else if (current->ct == call_exp){
            print_expression(current->call_morphs.exp, depth + 1);
        }
    }
}
