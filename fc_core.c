

#include "fc_core.h"

void fc_value_new_number(double number, fc_value *buffer) {
  buffer->type = fc_type_number;
  buffer->value.number = number;
}

void fc_value_new_dict(FCDict dict, fc_value *buffer) {
  buffer->type = fc_type_dict;
  buffer->value.dict = dict;
}

void fc_value_new_list(FCList list, fc_value *buffer) {
  buffer->type = fc_type_list;
  buffer->value.list = list;
}

void fc_value_new_function(FCFunction function, fc_value *buffer) {
  buffer->type = fc_type_function;
  buffer->value.function = function;
}

fc_type fc_value_type(fc_value *value) {
  return value->type;
}

double fc_value_number(fc_value *value) {
  return value->value.number;
}

FCList fc_value_list(fc_value *value) {
  return value->value.list;
}

FCDict fc_value_dict(fc_value *value) {
  return value->value.dict;
}

FCFunction fc_value_function(fc_value *value) {
  return value->value.function;
}
