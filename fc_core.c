

#include "fc_core.h"

fc_value FCValueNewNumber(double number) {
  fc_value value = {
    .value = {.number = number},
    .type = fc_type_number
  };
  return value;
}

fc_value FCValueNewDict(FCDict dict) {
  fc_value value = {
    .value = {.dict = dict},
    .type = fc_type_dict
  };
  return value;
}

fc_value FCValueNewList(FCList list) {
  fc_value value = {
    .value = {.list = list},
    .type = fc_type_list
  };
  return value;
}

fc_type FCValueType(fc_value value) {
  return value.type;
}

double FCValueNumber(fc_value value) {
  return value.value.number;
}

FCList FCValueList(fc_value value) {
  return value.value.list;
}

FCDict FCValueDict(fc_value value) {
  return value.value.dict;
}

union _fc_tree_or_param {
  fc_funct_tree *function;
  int parameter;
};

struct _fc_funct_tree {
  FCFunction function;
  fc_tree_or_param *parameters;
};

struct _fc_funct_params {
  FCFunction parent;
  int *args;
  int *local_vars;
  fc_tree_or_param *local_trees;
};

