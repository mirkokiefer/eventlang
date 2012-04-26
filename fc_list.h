
#ifndef FunC_fc_list_h
#define FunC_fc_list_h

#include "fun_c.h"

typedef FCList(*map_list_f)(FCList head);

FCList FCListAdd(FCList list, fc_value *value);
fc_value FCListHead(FCList list);
FCList FCListNext(FCList list);
FCList FCListMap(FCList list, map_list_f fun);

#endif
