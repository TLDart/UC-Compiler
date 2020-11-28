#ifndef STRUCTURES_H
#define STRUCTURES_H

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

// Nao mexer senão fica tudo lixado!!!!!
typedef enum {t_typespec_char,t_typespec_int,t_typespec_void,t_typespec_short,t_typespec_double, typespec_null} typespec_type;

struct info{
    char* id;
    int lines;
    int cols;
};

struct function_definition{
    typespec_type type;
    struct info* info;
    struct parameter_list* param_list; 
    struct function_body* f_body;
};

struct function_declaration{
    typespec_type type;
    struct info* info; 
    struct parameter_list* param_list; 
};

struct parameter_list{
    struct parameter_declaration* p_dec;
    struct parameter_list* next;
};

struct parameter_declaration{
    typespec_type type;
    struct info* info;
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
struct declaration{
    typespec_type type;
    struct declarator* decl;
    struct declaration* next;
};
struct declarator{
    struct info* info;
    struct expression* expr;
};
typedef enum{t_if, t_return, t_while, t_statlist, t_expression} stt_type;
struct statement{
    stt_type type;
    union{
        struct if_statement* u_if;
        struct return_statement* u_return;
        struct while_statement* u_while;
        struct statlist_statement* u_statlist;
        struct expression* u_expr;
    } statement_data;
    struct statement* next;
};

struct if_statement{
    struct expression* expr;
    struct statement* if_body;
    struct statement* else_body;
};
struct return_statement{
    struct expression* expr;
};

struct while_statement{
    struct expression* expr;
    struct statement* while_body;
};
struct statlist_statement{
    struct statement* stt;
};

typedef enum{t_op1, t_op2, t_term, t_call } expression_type;
struct expression{
    expression_type expr_t;
    union {
        struct op1* operation1;
        struct op2* operation2;
        struct call* c;
        struct terminal* t;  
    } expression_morphs;
};

typedef enum {t_char, t_charlit, t_id, t_int, t_short, t_intlit, t_double, t_reallit,t_void} t_type;

struct terminal{
    t_type type;
    struct info* info;
};

typedef enum{t_not, t_minus, t_plus} op1_type;
struct op1{
    op1_type type;
    struct expression* exp;
};

typedef enum{
    t_or, t_and, t_eq, t_ne, t_lt, t_gt,
    t_ge, t_add, t_sub, t_mul, t_div, t_mod, t_store, 
    t_comma, t_bitwiseand, t_bitwisexor,t_bitwiseor,t_le
} op2_type;

struct op2{
    op2_type type;
    struct expression* exp1;
    struct expression* exp2;
};

typedef enum {call_name, call_exp} call_type;
struct call {
    call_type ct;
    union{
        struct info* info;
        struct expression* exp;
    } call_morphs;
    struct call* next_arg;
};

#endif