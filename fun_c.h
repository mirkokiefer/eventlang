
#include "deps.h"
#include "fc_core.h"
#include "fc_list.h"
#include "fc_dict.h"

#ifndef FunC_fun_c_h
#define FunC_fun_c_h

#define HASH_LENGTH 41
#define FC_HASH_BYTE_LENGTH 20

typedef struct fc_dict_s* FCDict;
typedef struct fc_list_s* FCList;
typedef struct fc_function* FCFunction;

typedef enum {
  fc_type_nil,
  fc_type_number,
  fc_type_list,
  fc_type_dict,
  fc_type_function
} fc_type;

union fc_value_u {
  double number;
  FCList list;
  FCDict dict;
  FCFunction function;
};

typedef struct {
  union fc_value_u value;
  fc_type type;
} fc_value;

#endif
