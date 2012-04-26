
#ifndef FunC_fc_dict_h
#define FunC_fc_dict_h

#include "fun_c.h"

FCDict FCDictUpdate(FCDict dict, fc_value *keyValues[]);
fc_value FCDictValue(FCDict dict, fc_value *key);

#endif
