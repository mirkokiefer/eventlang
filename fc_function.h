
#ifndef EventLang_fc_function_h
#define EventLang_fc_function_h

#include "fun_c.h"

fc_funct_tree fc_funct_tree_leaf(int param);
fc_funct_tree fc_funct_tree_node(FCFunction function, fc_funct_tree *arguments);
void fc_funct_tree_free(fc_funct_tree tree);

FCFunction FCFunctionNew(int args[], int local_vars[], fc_funct_tree *local_trees);
FCFunction FCFunctionNewPrimitive(fc_function_primitive c_fun);
void FCFunctionInvoke(FCFunction funct, fc_value *parameters[], fc_context *context, fc_value *buffer);

void fc_context_new(fc_context *parent, int vars[], fc_value *values[], fc_context *buffer);

#endif
