// Don't rename into .c
// min_unit_main.h: implementation of a quite simple test runner

int tests_run = 0;
int tests_failed = 0;
int tests_passed = 0;

int main(int argc, char **argv) {
    printf("Running all tests: start\n\r");
     all_tests();
     if (tests_failed != 0) {
         printf("Test failed: %d\n\r", tests_failed);
     }
     else {
         printf("ALL TESTS PASSED\n\r");
     }
     printf("Tests run: %d\n\r", tests_run);
 
    while(1);
 }