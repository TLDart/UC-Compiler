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

typedef enum {t_typespec_char,t_typespec_int,t_typespec_void,t_typespec_short,t_typespec_double} typespec_type;

struct function_definition{
        typespec_type type;
        char* id;
        struct parameter_list* param_list; 
        struct function_body* f_body;
};

struct function_declaration{
        typespec_type type;
        char* id;
        struct parameter_list* param_list; 
};

struct parameter_list{
    struct parameter_declaration* p_dec;
    struct parameter_list* next;
};

struct parameter_declaration{
    typespec_type type;
    char* id;
};

typedef enum {t_statement, t_declaration} f_body_type;

struct function_body{
    f_body_type type;
    union{
        struct statement* u_stt;
        struct declaration* u_dec;
    }data_body;
    struct function_body* next;
};

struct statement{
        ;
};

struct declaration{
    ;
};

#endif