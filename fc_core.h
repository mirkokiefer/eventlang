
#ifndef FunC_fc_core_h
#define FunC_fc_core_h

#include "fun_c.h"

typedef struct fc_object* fc_object_s;
typedef struct fc_type* fc_type_s;
typedef struct fc_context* fc_context_s;

// object functions
typedef void(*child_cb_f)(void *cookie, char *key, fc_object_s objects[], size_t length);

// see objects as tables like in Lua - have a meta-table defining polymorphic functions
fc_object_s object_create(void *data, fc_type_s type);
fc_object_s object_create_from_hash(char hash[HASH_LENGTH], fc_context_s context);
void* object_data(fc_object_s object, fc_type_s type);
void object_walk_children(fc_object_s object, child_cb_f cb);
void object_store(fc_object_s object, fc_context_s context);
void object_proxify(fc_object_s object, fc_context_s context);

// type functions
typedef void(*dealloc_f)(fc_object_s object);
typedef void(*walk_children_f)(fc_object_s object, void *cookie, child_cb_f cb);
typedef void(*store_children_f)(fc_object_s object, char *key, fc_object_s objects[], size_t length);
typedef void(*compare_f)(fc_object_s object1, fc_object_s object2, fc_type_s object2_type);

struct fc_type_init {
  char *name;
  dealloc_f dealloc_fun;
  walk_children_f walk_children_fun;
  store_children_f store_children_fun;
  compare_f compare_fun;
};

fc_type_s type_create(struct fc_type_init *parameters);

#endif
