
#include "fc_function.h"

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
  FCFunction parent;
  int *args;
  int *local_vars;
  fc_funct_tree *local_trees;
};

typedef enum {
  FC_TREE_NODE,
  FC_TREE_LEAF
} fc_tree_type;

typedef struct {
  FCFunction function;
  fc_funct_tree *parameters;
} fc_tree_node;

typedef union {
  int leaf;
  fc_funct_tree *node;
} fc_node_or_leaf;

struct _fc_funct_tree {
  fc_tree_type type;
  fc_node_or_leaf tree;
};

