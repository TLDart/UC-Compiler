#include "structures.h"
#include "functions.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


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
        head = new;

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
    else

    printf("asdasd\n");
    return new;
}

struct program* insert_program_func_dec_rem(struct program* head, struct function_declaration* i_f_dec){

    struct program* new=(struct program*)malloc(sizeof(struct program));
    new->type = t_f_dec;
    new->data_program.u_f_dec = i_f_dec;
    new->next = NULL;

    if(head == NULL)
        head = new;

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
        head = new;

    else{
        struct program* looper = head;
        while(looper->next != NULL) looper = looper->next;
        looper->next = new;
    }
    return head;
}

struct function_definition* insert_function_definition(int i_typespec, char* i_id, struct parameter_list* i_param_list, struct function_body* i_f_body){
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

    new->id = (char*)strdup(i_id);
    new->param_list = i_param_list;
    new->f_body = i_f_body;
}

struct function_declaration* insert_function_declaration(int i_typespec, char* i_id, struct parameter_list* i_param_list){
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

    new->id = (char*)strdup(i_id);
    new->param_list = i_param_list;
}

struct parameter_declaration* insert_param_dec(int i_typespec, char* i_id){
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
        new->id = NULL;
    }
    else
        new->id = (char*)strdup(i_id);

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
        head = new;

    else{
        struct parameter_list* looper = head;
        while(looper->next != NULL) looper = looper->next;
        looper->next = new;
    }
    return head;
}

struct function_body* insert_f_body_statement(struct statement* stt){
 struct function_body* new=(struct function_body*)malloc(sizeof(struct function_body));

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