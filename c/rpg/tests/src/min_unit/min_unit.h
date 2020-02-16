/* Minimal Unit Testing framework 
 * http://www.jera.com/techinfo/jtns/jtn002.html
 */

/* file: minunit.h */

#include <stdio.h>

#define TEST_FAILED 1
#define TEST_PASSED 0

#define mu_assert(message, test) do { if (test) { return TEST_PASSED; } else { return message; } } while (0)
#define mu_run_test(test) do { char *message = test(); tests_run++; \
                            if (message) { printf("%d - %s\n\r", tests_run, message); tests_failed++; } else { printf("%d - %s\n\r",tests_run ,"Test passed"); tests_passed++;} } while (0)
extern int tests_run;
extern int tests_failed;
extern int tests_passed;