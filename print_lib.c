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

void print_f_def(struct function_definition* f_dec, int depth){
    print_indentation(depth);
    printf("FuncDefinition\n");
}
void print_f_dec(struct function_declaration* f_dec, int depth){
    print_indentation(depth);
    printf("FuncDeclaration\n");
}
void print_dec(struct declaration* f_dec, int depth){
    print_indentation(depth);
    printf("Declaration\n");
}