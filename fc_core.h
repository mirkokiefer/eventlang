
#ifndef FunC_fc_core_h
#define FunC_fc_core_h

#include "fun_c.h"

void fc_value_new_number(double number, fc_value *buffer);
void fc_value_new_dict(FCDict dict, fc_value *buffer);
void fc_value_new_list(FCList list, fc_value *buffer);
void fc_value_new_function(fc_function *function, fc_value *buffer);
void fc_value_new_lazy(FCFunction function, fc_value *arguments[], fc_context *context, fc_value *buffer);
fc_type fc_value_type(fc_value *value);
double fc_value_number(fc_value *value);
FCList fc_value_list(fc_value *value);
FCDict fc_value_dict(fc_value *value);
FCFunction fc_value_function(fc_value *value);


#endif

