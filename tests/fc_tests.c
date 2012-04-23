
#include "minuit.h"
#include "fc_tests.h"

int tests_run = 0;

static char* test_http_interface() {
  //mu_assert("test http server", strcmp(test, "/test")==0);
  return 0;
}

static char* all_tests() {
  //mu_run_test(test_tree);
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
