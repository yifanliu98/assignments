/*************** YOU SHOULD NOT MODIFY ANYTHING IN THIS FILE ***************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sched.h>
#include <ctype.h>
#include <pthread.h>
#include <semaphore.h>

#define LENGTH(a) ( sizeof(a) / sizeof(*(a)) )

#define BUF_SIZE 500

extern char buffer[BUF_SIZE];
extern int num_ops;

void *adder(void *arg);
void *multiplier(void *arg);
void *degrouper(void *arg);
void *sentinel(void *arg);
void *reader(void *arg);

int smp3_main(int argc, char **argv);
