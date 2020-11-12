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

