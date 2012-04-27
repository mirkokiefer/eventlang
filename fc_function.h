
#ifndef EventLang_fc_function_h
#define EventLang_fc_function_h

#include "fun_c.h"

void fc_funct_tree_value(fc_value *value, fc_funct_tree *buffer);
void fc_funct_tree_ref(int var, fc_funct_tree *buffer);
void fc_funct_tree_call(int function, fc_funct_tree *arguments[], size_t length, fc_funct_tree *buffer);

void fc_funct_new(size_t args_length, fc_funct_tree *local_trees[], size_t length, fc_function *buffer);
void fc_funct_new_primitive(fc_function_primitive c_fun, fc_function *buffer);
void fc_function_invoke(fc_function *funct, fc_value *parameters[], size_t length, fc_context *context, fc_value *buffer);

#endif
