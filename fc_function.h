
#ifndef EventLang_fc_function_h
#define EventLang_fc_function_h

#include "fun_c.h"

fc_funct_tree* fc_funct_tree_value(fc_value *value);
fc_funct_tree* fc_funct_tree_ref(int var);
fc_funct_tree* fc_funct_tree_call(int function, fc_funct_tree *arguments[], size_t length);

fc_function* fc_funct_new(size_t args_length, fc_funct_tree *local_trees[], size_t length);
fc_function* fc_funct_new_primitive(fc_function_primitive c_fun);
void fc_funct_call(fc_function *funct, fc_value *parameters[], size_t length, fc_value *buffer);
void fc_funct_free(fc_function *funct);
#endif
