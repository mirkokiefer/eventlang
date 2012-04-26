
#ifndef FunC_fc_core_h
#define FunC_fc_core_h

#include "fun_c.h"

fc_value FCValueNewNumber(double number);
fc_value FCValueNewDict(FCDict dict);
fc_value FCValueNewList(FCList list);
fc_value FCValueNewFunction(FCFunction function);
fc_type FCValueType(fc_value value);
double FCValueNumber(fc_value value);
FCList FCValueList(fc_value value);
FCDict FCValueDict(fc_value value);
FCFunction FCValueFunction(fc_value value);

typedef union _fc_tree_or_param fc_tree_or_param;
typedef struct _fc_funct_tree fc_funct_tree;
typedef struct _fc_funct_params fc_funct_params;

fc_tree_or_param fc_tree_or_param_new(fc_funct_tree tree, int parameter);
fc_funct_tree fc_funct_tree_new(FCFunction function, fc_tree_or_param *parameters);
FCFunction FCFunctionNew(FCFunction parent, int *args, int *local_vars, fc_tree_or_param local_trees);
fc_value FCFunctionInvoke(FCFunction funct, fc_value parameters[]);

#endif

