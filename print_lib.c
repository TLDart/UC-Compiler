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
            print_dec(head->data_program.u_dec, depth +1);
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
}

void print_dec(struct declaration* f_dec, int depth){
    print_indentation(depth);
    printf("Declaration\n");
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

void print_statement(struct statement* stt, int depth){
    ;
}
void print_declaration(struct declaration* dec, int depth){
    print_indentation(depth);
    printf("Declaration\n");
    ;
}