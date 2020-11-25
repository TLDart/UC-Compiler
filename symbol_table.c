#include "symbol_table.h"
struct scope* get_scope_by_id(struct scope* head, int id){
    while(head){
        if(head->id == id){
            return head;
        }
        head = head->next;
    }
    return NULL;
}
struct scope* get_scope_by_name(struct scope* head, char* name){
    while(head){
        if(strcmp(head->name, name) == 0){
            return head;
        }
        head = head->next;
    }
    return NULL;
}

struct scope* create_scope(struct scope* head, char* name){
        struct scope* new=(struct scope*)malloc(sizeof(struct scope));

        new->name = (char*)strdup(name);
        new->id = 0;
        new->symtab = NULL;
        new->next = NULL;
        if(head == NULL){
            return new;
        }

        else{
            while(head->next){
                head = head->next;
            }
            new->id = head->id + 1;
            head->next = new;
        }
        return new;
}

struct sym_element* get_token_by_name(struct sym_element* head, char* name){
    while(head){
        if(strcmp(head->name, name) == 0){
            return head;
        }
        head = head ->next;
    }
}

struct sym_element* insert_sym_element(struct sym_element* head,struct sym_element* new){
    if(head == NULL){
        return new;
    }
    if(new->name && strcmp(new->name, "return") == 0){ // Insert return first
        //printf("Is inside return\n");
        new->next = head;
    }
    else{
    //printf("Is inside else\n");
        if(new != NULL){
            //printf("%s\n", new->name);
        }
        struct sym_element* looper = head;
        while(looper->next){
            looper = looper-> next;
        }
        looper->next = new;
    }
    return head;
}

struct sym_element* create_sym_element(char* name, s_types type, struct sym_function* f, int parameter){
    struct sym_element* new=(struct sym_element*)malloc(sizeof(struct sym_element));
    if(name == NULL)
        new->name = NULL;
    else
        new->name = (char*)strdup(name);
    new->type = type;
    new->sym_f = f;
    new->parameter = parameter;
    new->next = NULL;

    return new;
}

struct sym_function* create_sym_f_param(struct function_declaration* f){
    struct sym_function* new=(struct sym_function*)malloc(sizeof(struct sym_function));

    new->return_value = f->type;
    new->params = NULL;
    struct parameter_list* p = f->param_list;
    struct sym_f_param* params_tp = new->params;
    while(p){
        struct sym_f_param* new2=(struct sym_f_param*)malloc(sizeof(struct sym_f_param));
        new2->param_type = p->p_dec->type;
        new2->next = NULL;
        if(params_tp == NULL){
            params_tp = new2;
            new->params = new2;
        }
        else{
            params_tp->next = new2;
            params_tp = params_tp->next;
        }
        p = p->next;
    }
    return new;

}



