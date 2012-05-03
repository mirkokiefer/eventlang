
#include "minuit.h"
#include "fc_tests.h"

int tests_run = 0;

static char* test_functions() {
  /*
  () ->
    mult = primitive:mult
    myfun = (a, b) ->
      c = 2
      mult(c, a, b)
    myfun(3,4)
  */
  
  fc_value mult_val;
  fc_value_new_function(fc_primitive_mult(), &mult_val);
  
  fc_value myfun_val;
  {
    fc_value c;
    fc_value_new_number(2, &c);
    fc_funct_tree *mult_call_args[] = {fc_funct_tree_ref(2), fc_funct_tree_ref(3), fc_funct_tree_ref(4)};
    fc_funct_tree* myfun_exprs[] = {fc_funct_tree_value(&c), fc_funct_tree_call(1, mult_call_args, 3)};
    fc_function *myfun = fc_funct_new(2, myfun_exprs, 2);
    fc_value_new_function(myfun, &myfun_val);
  }
      
  fc_value three; fc_value four;
  fc_value_new_number(3, &three);
  fc_value_new_number(4, &four);  
  fc_funct_tree *myfun_call_args[] = {fc_funct_tree_value(&three), fc_funct_tree_value(&four)};
    
  fc_funct_tree *root_exprs[] = {fc_funct_tree_value(&mult_val), fc_funct_tree_value(&myfun_val), fc_funct_tree_call(2, myfun_call_args, 2)};
  fc_function *root = fc_funct_new(0, root_exprs, 3);
  
  fc_value result;
  fc_funct_call(root, NULL, 0, &result);
  //mu_assert("test http server", strcmp(test, "/test")==0);
  return 0;
}

static char* all_tests() {
  mu_run_test(test_functions);
  return 0;
}

bool run_tests() {
  char *result = all_tests();
  if (result != 0) {
    printf("%s\n", result);
  }
  else {
    printf("ALL TESTS PASSED\n");
  }
  printf("Tests run: %d\n", tests_run);
  
  return result == 0;
}
