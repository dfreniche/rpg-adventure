#include <stdio.h>
#include "min_unit/min_unit.h"

static char * test_foo() {
    int foo = 7;
    
    mu_assert("error, foo != 7\n", foo==7);
}

static char * test_bar() {
    int bar = 4;

    mu_assert("error, bar != 5\n", bar==5);
}

void all_tests() {
    mu_run_test(test_foo);
    mu_run_test(test_bar);
}

// include test runner
#include "min_unit/min_unit_main.h"