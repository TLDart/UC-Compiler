#include "functions.h"

struct info* getInfo(char* name, int lines, int cols){
	struct info* new=(struct info*)malloc(sizeof(struct info));
    new->id = (char*) strdup(name);
    new->cols = cols;
    new->lines = lines;
    return new;
}

//Func Definition
struct program* insert_program_func_def(struct function_definition* i_f_def, struct program* rem){
	struct program* new=(struct program*)malloc(sizeof(struct program));

    new->type = t_f_def;
    new->data_program.u_f_def = i_f_def;
    new->next = NULL;

   
    if(rem != NULL)
        new->next = rem;

    return new;
}

struct program* insert_program_func_def_rem(struct program* head, struct function_definition* i_f_def){

    struct program* new=(struct program*)malloc(sizeof(struct program));

    new->type = t_f_def;
    new->data_program.u_f_def = i_f_def;
    new->next = NULL;

    if(head == NULL)
        return new;

    else{
        struct program* looper = head;
        while(looper->next != NULL) looper = looper->next;
        looper->next = new;
    }
    return head;


}

// Program declaration
struct program* insert_program_func_dec(struct function_declaration* i_f_dec, struct program* rem){
	struct program* new=(struct program*)malloc(sizeof(struct program));
    new->type = t_f_dec;
    new->data_program.u_f_dec = i_f_dec;
    new->next = NULL;
   

    if(rem != NULL){
        new->next = rem;
    }
    else{
        //printf("asdasd\n");
    }
    return new;
}

struct program* insert_program_func_dec_rem(struct program* head, struct function_declaration* i_f_dec){

    struct program* new=(struct program*)malloc(sizeof(struct program));
    new->type = t_f_dec;
    new->data_program.u_f_dec = i_f_dec;
    new->next = NULL;

    if(head == NULL)
        return new;

    else{
        struct program* looper = head;
        while(looper->next != NULL) looper = looper->next;
        looper->next = new;
    }
    return head;
}
// Declaration
struct program* insert_program_dec(struct declaration* i_dec, struct program* rem){
	struct program* new=(struct program*)malloc(sizeof(struct program));

    new->type = t_dec;
    new->data_program.u_dec = i_dec;
    new->next = NULL;

   
    if(rem != NULL)
        new->next = rem;

    return new;
}

struct program* insert_program_dec_rem(struct program* head, struct declaration* i_dec){

    struct program* new=(struct program*)malloc(sizeof(struct program));

    new->type = t_dec;
    new->data_program.u_dec = i_dec;
    new->next = NULL;

    if(head == NULL)
        return new;

    else{
        struct program* looper = head;
        while(looper->next != NULL) looper = looper->next;
        looper->next = new;
    }
    return head;
}

struct function_definition* insert_function_definition(int i_typespec, struct info* i_id, struct parameter_list* i_param_list, struct function_body* i_f_body){
    struct function_definition* new = (struct function_definition*)malloc(sizeof(struct function_definition));

    if(i_typespec == 0){
         new->type = t_typespec_char;
    }
    if(i_typespec == 1){
         new->type = t_typespec_int;
    }
    if(i_typespec == 2){
         new->type = t_typespec_void;
    }
    if(i_typespec == 3){
         new->type = t_typespec_short;
    }
    if(i_typespec == 4){
         new->type = t_typespec_double;
    }

    new->info = i_id;
    new->param_list = i_param_list;
    new->f_body = i_f_body;

    return new;
}

struct function_declaration* insert_function_declaration(int i_typespec, struct info* i_id, struct parameter_list* i_param_list){
    struct function_declaration* new = (struct function_declaration*)malloc(sizeof(struct function_declaration));

    if(i_typespec == 0){
         new->type = t_typespec_char;
    }
    if(i_typespec == 1){
         new->type = t_typespec_int;
    }
    if(i_typespec == 2){
         new->type = t_typespec_void;
    }
    if(i_typespec == 3){
         new->type = t_typespec_short;
    }
    if(i_typespec == 4){
         new->type = t_typespec_double;
    }

    new->info = i_id;
    new->param_list = i_param_list;

    return new;
}

struct parameter_declaration* insert_param_dec(int i_typespec, struct info* i_id){
    struct parameter_declaration* new = (struct parameter_declaration*)malloc(sizeof(struct parameter_declaration));

    if(i_typespec == 0){
         new->type = t_typespec_char;
    }
    if(i_typespec == 1){
         new->type = t_typespec_int;
    }
    if(i_typespec == 2){
         new->type = t_typespec_void;
    }
    if(i_typespec == 3){
         new->type = t_typespec_short;
    }
    if(i_typespec == 4){
         new->type = t_typespec_double;
    }

    if(i_id == NULL){
        new->info = NULL;
    }
    else
        new->info = i_id;
        //new->id = (char*)strdup(i_id);

    return new;

}
struct parameter_list* insert_param_list(struct parameter_declaration* p_dec, struct parameter_list* rem){
	struct parameter_list* new=(struct parameter_list*)malloc(sizeof(struct parameter_list));

    new->p_dec = p_dec;
    new->next = NULL;

    if(rem != NULL)
        new->next = rem;

    return new;
}

struct parameter_list* insert_param_list_rem(struct parameter_list* head, struct parameter_declaration* p_dec){

    struct parameter_list* new=(struct parameter_list*)malloc(sizeof(struct parameter_list));

    new->p_dec = p_dec;
    new->next = NULL;

    if(head == NULL)
        return new;

    else{
        struct parameter_list* looper = head;
        while(looper->next != NULL) looper = looper->next;
        looper->next = new;
    }
    return head;
}

struct function_body* insert_f_body_statement(struct statement* stt){
 struct function_body* new=(struct function_body*)malloc(sizeof(struct function_body));

    //printf("%d", stt->type);
    new->type = t_statement;
    new->data_body.u_stt = stt;
    new->next = NULL;
    return new;
}
struct function_body* insert_f_body_declaration(struct declaration* dec){
 struct function_body* new=(struct function_body*)malloc(sizeof(struct function_body));

    new->type = t_declaration;
    new->data_body.u_dec = dec;
    new->next = NULL;
    return new;
}

struct function_body* insert_f_body_multiple(struct function_body* f_b1, struct function_body* f_b2){
    struct function_body* temp = f_b1;
    while(temp->next != NULL) temp = temp->next;
    temp->next = f_b2;
    return f_b1;
}

struct declarator* insert_decl(struct info* i_id, struct expression* i_expr){
    struct declarator* new=(struct declarator*)malloc(sizeof(struct declarator));
    new->info = i_id;
    new->expr = i_expr;
    return new;
}
struct declaration* insert_dec(int typespec,struct declarator* i_decl, struct declaration* i_dec){
    struct declaration* new=(struct declaration*)malloc(sizeof(struct declaration));
    new->type = typespec;
    new->decl = i_decl;
    new->next = i_dec;
    return new;
}

struct declaration* insert_dec_rem(struct declaration* head, struct declarator* i_decl){
    struct declaration* new=(struct declaration*)malloc(sizeof(struct declaration));

    new->type = typespec_null;
    new->decl = i_decl;

   if(head == NULL)
        return new;

    else{
        struct declaration* looper = head;
        while(looper->next != NULL) looper = looper->next;
        looper->next = new;
    }
    return head;
    
}
struct statement* insert_statement(struct statement* head, struct statement* new){

    if(head == NULL)
        return new;

    else{
        struct statement* looper = head;
        while(looper->next != NULL) looper = looper->next;
        looper->next = new;
    }
    return head;
}
struct statement* insert_return(struct expression* i_expr){
    //printf("insert return\n");
    struct statement* new=(struct statement*)malloc(sizeof(struct statement));
    struct return_statement* new_return=(struct return_statement*)malloc(sizeof(struct return_statement));

    new_return->expr = i_expr;
    new->type = t_return;
    new->statement_data.u_return = new_return;
    new->next = NULL;
   
    return new;
}
struct statement* insert_if_statement(struct expression* i_expr, struct statement* i_if_body, struct statement* i_else_body){
    //printf("inser if\n");
    struct statement* new=(struct statement*)malloc(sizeof(struct statement));
    struct if_statement* new_if=(struct if_statement*)malloc(sizeof(struct if_statement));

    new_if->expr = i_expr;
    new_if->if_body = i_if_body;
    new_if->else_body = i_else_body;
    new->type = t_if;
    new->statement_data.u_if = new_if;
    new->next = NULL;
    //printf("after if %d\n", new->type);
    return new;
}

struct statement* insert_while_statement(struct expression* i_expr, struct statement* i_while_body){
    //printf("hello\n");
    struct statement* new=(struct statement*)malloc(sizeof(struct statement));
    struct while_statement* new_while=(struct while_statement*)malloc(sizeof(struct while_statement));

    new_while->expr = i_expr;
    new_while->while_body = i_while_body;
    new->type = t_while;
    new->statement_data.u_while = new_while;
    new->next = NULL;
    
    return new;
}

struct statement* insert_statlist(struct statement* i_statlist_body){
    //printf("inser statlist\n");
    if (i_statlist_body != NULL){
        struct statement* new=(struct statement*)malloc(sizeof(struct statement));
        struct statlist_statement* new_statlist=(struct statlist_statement*)malloc(sizeof(struct statlist_statement));

        new_statlist->stt = i_statlist_body;
        new->statement_data.u_statlist = new_statlist;
        new->type = t_statlist;
        new->next = NULL;
        return new;
    } else {
        return NULL;
    }
}

struct statement* insert_expr_statement(struct expression* i_expr){
    //printf("inser exprt\n");
    struct statement* new=(struct statement*)malloc(sizeof(struct statement));
    new->type = t_expression;
    new->statement_data.u_expr = i_expr;
    new->next = NULL;
    return new;
}

//new
struct expression* insert_expression_op1(int operation, struct expression* arg){
    struct expression* new_expr = (struct expression*) malloc(sizeof(struct expression));
    struct op1* new_op1 = (struct op1*) malloc(sizeof(struct op1));
    new_op1->type = operation;
    new_op1->exp = arg;
    new_expr->expr_t = t_op1;
    new_expr->expression_morphs.operation1 = new_op1; 
    return new_expr;
}


struct expression* insert_expression_op2(struct expression* arg1, int operation, struct expression* arg2){
    struct expression* new_expr = (struct expression*) malloc(sizeof(struct expression));
    struct op2* new_op2 = (struct op2*) malloc(sizeof(struct op2));
    new_op2->type = operation;
    new_op2->exp1 = arg1;
    new_op2->exp2 = arg2;
    new_expr->expr_t = t_op2;
    new_expr->expression_morphs.operation2 = new_op2; 
    return new_expr;
}

struct expression* insert_expression_call(struct info* id, struct expression* exp, struct call* exp_list){
    struct expression* new_expr = (struct expression*) malloc(sizeof(struct expression));
    struct call* new_id_call = (struct call*) malloc(sizeof(struct call));
    // Name
    new_id_call->ct = call_name;
    new_id_call->call_morphs.info = id;
    if (exp == NULL && exp_list == NULL){
        new_id_call->next_arg = NULL;
    } else {
        new_id_call->next_arg = (struct call*) malloc(sizeof(struct call));
        // Expression
        new_id_call->next_arg->ct = call_exp;
        new_id_call->next_arg->call_morphs.exp = exp;
        new_id_call->next_arg->next_arg = exp_list;
    }
    new_expr->expr_t = t_call;
    new_expr->expression_morphs.c = new_id_call;
    return new_expr;
}

struct expression* insert_expression_terminal(struct info* info, int type){
    struct expression* new_expr = (struct expression*) malloc(sizeof(struct expression));
    struct terminal* new_term = (struct terminal*) malloc(sizeof(struct terminal));
    new_term->type = type;
    new_term->info = info;//(char*) strdup(id);
    new_expr->expr_t = t_term;
    new_expr->expression_morphs.t = new_term;
    return new_expr;
}

struct call* insert_expression_kleen(struct call* head, struct expression* exp){
    struct call* aux;
    struct call* current;

    if (head == NULL){
        aux = (struct call*) malloc(sizeof(struct call));
        aux->ct = call_exp;
        aux->call_morphs.exp = exp;
        aux->next_arg = NULL;
        return aux;    
    } else {
        for (current = head; current->next_arg; current = current->next_arg ) {}
        current->next_arg = (struct call*) malloc(sizeof(struct call));
        current->next_arg->ct = call_exp;
        current->next_arg->call_morphs.exp = exp;
        current->next_arg->next_arg = NULL;
    }
    return head;
}