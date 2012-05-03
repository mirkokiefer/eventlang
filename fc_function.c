
#include "fc_function.h"

typedef union _fc_tree_or_param fc_tree_or_param;
typedef struct _fc_funct_params fc_funct_params;

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

void fc_context_new(fc_context *parent, fc_value *values[], size_t length, fc_context *buffer);
