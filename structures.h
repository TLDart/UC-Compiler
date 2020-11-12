#ifndef STRUCTURES_H
#define STRUCTURES_H

typedef enum {t_char, t_charlit, t_id, t_int, t_short, t_intlit, t_double, t_reallit,t_void} t_type;

struct terminal{
    t_type type;
    char* id;
};

typedef enum{t_or, t_and, t_eq, t_ne, t_lt, t_gt, t_ge, t_add, t_sub, t_mul, t_div, t_mod, t_store, t_comma, t_bitwiseand, t_bitwisexor,t_bitwiseor} op2_type;

struct op2{
    op2_type type;
    struct terminal *t1;
    struct terminal *t2;
};
typedef enum{t_not, t_minus, t_plus} op1_type;
struct op1{
    op1_type type;
    struct terminal *t1;
};

typedef enum{t_f_def, t_f_dec, t_dec} p_type;
struct program{
    p_type type;
    union{
        struct function_definition* u_f_def;
        struct function_declaration* u_f_dec;
        struct declaration* u_dec;
    } data_program;
    struct program* next;
};

struct function_definition{
        char* typespec;
        char* id;
        //struct parameter_list* param_list; 
};

#endif