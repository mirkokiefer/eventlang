
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
  
  fc_funct_tree root_exprs[3];
  fc_value mult;
  fc_value_new_function(fc_primitive_mult(), &mult);
  fc_funct_tree_value(&mult, &root_exprs[0]);
  
  fc_funct_tree a_ref;
  fc_funct_tree_ref(2, &a_ref);
  fc_funct_tree b_ref;
  fc_funct_tree_ref(3, &b_ref);
  
  fc_funct_tree myfun_exprs[2];
  fc_value c;
  fc_value_new_number(2, &c);
  fc_funct_tree_value(&c, &myfun_exprs[0]);
  
  fc_funct_tree c_ref;
  fc_funct_tree_ref(4, &c_ref);
  fc_funct_tree* mult_call_args[] = {&a_ref, &b_ref, &c_ref};
  fc_funct_tree_call(1, mult_call_args, 3, &myfun_exprs[1]);
  
  fc_function myfun_funct;
  fc_funct_tree* myfun_expr_p[] = {&myfun_exprs[0], &myfun_exprs[1]};
  fc_funct_new(2, myfun_expr_p, 2, &myfun_funct);
  fc_value myfun;
  fc_value_new_function(&myfun_funct, &myfun);
  
  fc_funct_tree_value(&myfun, &root_exprs[1]);
  
  fc_value three; fc_value four;
  fc_value_new_number(3, &three);
  fc_value_new_number(4, &four);
  
  fc_funct_tree three_tree; fc_funct_tree four_tree;
  fc_funct_tree_value(&three, &three_tree);
  fc_funct_tree_value(&four, &four_tree);
  fc_funct_tree *myfun_call_args[] = {&three_tree, &four_tree};
  
  fc_funct_tree_call(2, myfun_call_args, 2, &root_exprs[2]);
  
  fc_function root;
  fc_funct_tree *root_expr_p[] = {&root_exprs[0], &root_exprs[1], &root_exprs[2]};
  fc_funct_new(0, root_expr_p, 3, &root);
  
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
