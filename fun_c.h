
#include "deps.h"
#include "fc_core.h"
#include "fc_list.h"
#include "fc_dict.h"
#include "fc_function.h"
#include "fc_primitives.h"
#include "fc_utils.h"

#ifndef FunC_fun_c_h
#define FunC_fun_c_h

#define HASH_LENGTH 41
#define FC_HASH_BYTE_LENGTH 20

// data types
typedef struct fc_dict_s* FCDict;
typedef struct fc_list_s* FCList;
typedef struct _fc_function* FCFunction;

typedef enum {
  fc_type_nil,
  fc_type_number,
  fc_type_list,
  fc_type_dict,
  fc_type_function
} fc_type;

// values
union fc_value_u {
  double number;
  FCList list;
  FCDict dict;
  FCFunction function;
};

typedef struct {
  fc_type type;
  union fc_value_u value;
} fc_value;

// functions
typedef union _fc_tree_or_param fc_tree_or_param;
typedef struct _fc_funct_tree fc_funct_tree;
typedef struct _fc_funct_params fc_funct_params;
typedef struct _fc_context fc_context;
typedef struct _fc_function fc_function;
typedef void(*fc_function_primitive)(fc_value *parameters[], fc_context *context, fc_value *buffer);

typedef enum {
  FC_NORMAL_FUNCTION,
  FC_PRIMITIVE_FUNCTION
} fc_funct_type;

typedef union {
  fc_function_primitive primitive_fun;
  fc_funct_params *normal_fun;
} fc_normal_or_primitive_funct;

struct _fc_function {
  fc_funct_type type;
  fc_normal_or_primitive_funct function;
};

struct _fc_funct_params {
  size_t args_length;
  fc_funct_tree *local_trees;
};

typedef enum {
  FC_TREE_CALL,
  FC_TREE_REF,
  FC_TREE_VALUE
} fc_tree_type;

typedef struct {
  int function;
  fc_funct_tree *args;
} fc_tree_call;

typedef union {
  int ref;
  fc_value *value;
  fc_tree_call call;
} fc_tree_node;

struct _fc_funct_tree {
  fc_tree_type type;
  fc_tree_node tree;
};


#endif
