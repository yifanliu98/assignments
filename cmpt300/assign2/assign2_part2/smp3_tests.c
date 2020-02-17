/*************** YOU SHOULD NOT MODIFY ANYTHING IN THIS FILE ***************/
#define _GNU_SOURCE
#include <stdio.h>
#undef _GNU_SOURCE
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "testrunner.h"
#include "calc.h"

#define quit_if(cond) do {if (cond) exit(EXIT_FAILURE);} while(0)

pid_t rv;

/* Prepare input, reroute file descriptors, and run the program. */
void run_test(const char *input, int argc, char **argv)
{
    /* Prepare input */
    FILE *in = fopen("smp3.in", "w");
    fprintf(in, input);
    fclose(in);

    /* Reroute standard file descriptors */
    freopen("smp3.in", "r", stdin);
    freopen("smp3.out", "w", stdout);
    freopen("smp3.err", "w", stderr);
    quit_if(smp3_main(argc, argv) != EXIT_SUCCESS);
    fclose(stdout);
    fclose(stderr);
}


/* Test basic addition */
int test_add(int argc, char **argv)
{
    char *args[] = { "./calc", NULL };
    FILE *out;
    int i;
    run_test("2+2\n.\n", 1, args);
    out = fopen("smp3.out", "r");
    fscanf(out, "%d\n", &i);
    fclose(out);
    quit_if(i != 4);
    return EXIT_SUCCESS;
}

/* Test basic multiplication */
int test_multiply(int argc, char **argv)
{
    char *args[] = { "./calc", NULL };
    FILE *out;
    int i;
    run_test("2*2\n.\n", 1, args);
    out = fopen("smp3.out", "r");
    fscanf(out, "%d\n", &i);
    fclose(out);
    quit_if(i != 4);
    return EXIT_SUCCESS;
}

/* Test basic grouping */
int test_grouping(int argc, char **argv)
{
    char *args[] = { "./calc", NULL };
    FILE *out;
    int i;
    run_test("(4)\n.\n", 1, args);
    out = fopen("smp3.out", "r");
    fscanf(out, "%d\n", &i);
    fclose(out);
    quit_if(i != 4);
    return EXIT_SUCCESS;
}

/* Test nested grouping */
int test_nested_grouping(int argc, char **argv)
{
    char *args[] = { "./calc", NULL };
    FILE *out;
    int i;
    run_test("(((4)))\n.\n", 1, args);
    out = fopen("smp3.out", "r");
    fscanf(out, "%d\n", &i);
    fclose(out);
    quit_if(i != 4);
    return EXIT_SUCCESS;
}

/* Test all operators together */
int test_all_operators(int argc, char **argv)
{
    char *args[] = { "./calc", NULL };
    FILE *out;
    int i;
    run_test("1+(2*3)+(4+5)\n.\n", 1, args);
    out = fopen("smp3.out", "r");
    fscanf(out, "%d\n", &i);
    fclose(out);
    quit_if(i != 16);
    return EXIT_SUCCESS;
}

/* Test multiple expression inputs */
int test_multiple_lines(int argc, char **argv)
{
    char *args[] = { "./calc", NULL };
    FILE *out;
    int i, j, k;
    run_test("(1+2)*3\n((3+2)*1)\n(2+(2*2)+(2*(2+2)))\n.\n", 1, args);
    out = fopen("smp3.out", "r");
    fscanf(out, "%d\n%d\n%d\n", &i, &j, &k);
    fclose(out);
    quit_if(i != 9 || j != 5 || k != 14);
    return EXIT_SUCCESS;
}

/* Test the num_ops counter */
int test_num_ops(int argc, char **argv)
{
    char *args[] = { "./calc", NULL };
    run_test("(1+2)*3\n((3+2)*1)\n(2+(2*2)+(2*(2+2)))\n.\n", 1, args);
    quit_if(num_ops != 16);
    return EXIT_SUCCESS;
}

/* Test presence of sched_yield() */
int test_sched_yield(int argc, char **argv)
{
    FILE *out;
    int i;
    system("grep sched_yield calc.c | wc -l > smp3.out");
    out = fopen("smp3.out", "r");
    fscanf(out, "%d", &i);
    fclose(out);
    quit_if(i < 5);
    return EXIT_SUCCESS;
}

void killproc()
{
	kill(rv, SIGKILL);
}

/* Test detecting no progress on invalid input */
int test_no_progress(int argc, char **argv)
{
    char *args[] = { "./calc", NULL };
    char line[30];
    FILE *out;
    rv = fork();
    if (rv == 0) {
	run_test("1++2\n", 1, args);
    } else {
    	atexit(killproc);
	waitpid(rv, NULL, 0);
	out = fopen("smp3.out", "r");
	fgets(line, 30, out);
	fclose(out);
	quit_if(strcmp(line, "No progress can be made\n"));
    }
    return EXIT_SUCCESS;
}

/* Test presence of sem_wait()/sem_post() */
int test_semaphore(int argc, char **argv)
{
    FILE *out;
    int i, j;
    system("grep sem_wait calc.c | wc -l > smp3.out");
    system("grep sem_post calc.c | wc -l >> smp3.out");
    out = fopen("smp3.out", "r");
    fscanf(out, "%d\n%d", &i, &j);
    fclose(out);
    quit_if(i < 4 || j < 4);
    return EXIT_SUCCESS;
}


/*
 * Main entry point for SMP3 test harness
 */
int run_smp3_tests(int argc, char **argv)
{
    /* Tests can be invoked by matching their name or their suite name 
       or 'all' */
    testentry_t tests[] = {
	{"add", "suite1", test_add},
	{"multiply", "suite1", test_multiply},
	{"grouping", "suite1", test_grouping},
	{"nested_grouping", "suite1", test_nested_grouping},
	{"all_operators", "suite1", test_all_operators},
	{"multiple_lines", "suite1", test_multiple_lines},
	{"num_ops", "suite1", test_num_ops},
	{"sched_yield", "suite1", test_sched_yield},
	{"no_progress", "suite1", test_no_progress},
	{"semaphore", "suite1", test_semaphore}
    };
    int result = run_testrunner(argc, argv, tests,
				sizeof(tests) / sizeof(testentry_t));
    unlink("smp3.in");
    unlink("smp3.out");
    unlink("smp3.err");
    return result;
}

/* The real main function.  */
int main(int argc, char **argv)
{
    if (argc > 1 && !strcmp(argv[1], "-test")) {
	return run_smp3_tests(argc - 1, argv + 1);
    } else {
	return smp3_main(argc, argv);
    }
}
