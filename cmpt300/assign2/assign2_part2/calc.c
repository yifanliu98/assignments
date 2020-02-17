/* calc.c - Multithreaded calculator */

#include "calc.h"

pthread_t adderThread;
pthread_t degrouperThread;
pthread_t multiplierThread;
pthread_t readerThread;
pthread_t sentinelThread;

char buffer[BUF_SIZE];
int num_ops;

pthread_mutex_t mutex;
// struct error_dectect {
// 	int adderUnaltered;
// 	int grouperUnaltered;
// 	int multiplierUnaltered;
// } detector;
sem_t sem;

void sem_w(sem_t* sem) {
	if (sem_wait(sem) != 0) printErrorAndExit("Fail to sem_wait");
}

void sem_p(sem_t* sem) {
	if (sem_post(sem) != 0) printErrorAndExit("Fail to sem_post");
}

/* Utiltity functions provided for your convenience */

/* int2string converts an integer into a string and writes it in the
   passed char array s, which should be of reasonable size (e.g., 20
   characters).  */
char *int2string(int i, char *s)
{
    sprintf(s, "%d", i);
    return s;
}

/* string2int just calls atoi() */
int string2int(const char *s)
{
    return atoi(s);
}

/* isNumeric just calls isdigit() */
int isNumeric(char c)
{
    return isdigit(c);
}

int length_int(int i) {
	char c[20];
	int2string(i, c);
	return strlen(c);
}

/* End utility functions */


void printErrorAndExit(char *msg)
{
    msg = msg ? msg : "An unspecified error occured!";
    fprintf(stderr, "%s\n", msg);
    exit(EXIT_FAILURE);
}

int timeToFinish()
{
    /* be careful: timeToFinish() also accesses buffer */
    return buffer[0] == '.';
}

/* Looks for an addition symbol "+" surrounded by two numbers, e.g. "5+6"
   and, if found, adds the two numbers and replaces the addition subexpression 
   with the result ("(5+6)*8" becomes "(11)*8")--remember, you don't have
   to worry about associativity! */
void *adder(void *arg)
{
    int bufferlen;
    int value1, value2;
    int startOffset, remainderOffset;
    int i;
	char back[BUF_SIZE];
	char val1[20];
	char val2[20];

    while (1) {
    	
	if(pthread_mutex_lock(&mutex) != 0) printErrorAndExit("Fail to Lock!");
		
	if (timeToFinish()) {
		pthread_mutex_unlock(&mutex); 
  		return NULL;
	}

	/* storing this prevents having to recalculate it in the loop */
	bufferlen = strlen(buffer);

	for (i=0; i<bufferlen; i++) {
		if (buffer[i] == '+') {
			if (isNumeric(buffer[i-1]) && isNumeric(buffer[i+1])) {
				memset(val1, '\0', strlen(val1));
				memset(val2, '\0', strlen(val2));
				memset(back, '\0', strlen(back));

				for (startOffset = i-2; startOffset>=0; startOffset--) if (!isNumeric(buffer[startOffset])) break;
				startOffset++; // the beginning of value 1
				for (int j = 0; j < i - startOffset; j++) val2[j] = buffer[startOffset+j];
				for (remainderOffset = i+2; remainderOffset < bufferlen; remainderOffset++) if (!isNumeric(buffer[remainderOffset])) break;
				remainderOffset--; // the end of value 2
				for (int j = 0; j < remainderOffset - i; j++) val1[j] = buffer[i+j+1];
				strcat(back, buffer + remainderOffset + 1);

				value1 = string2int(val1);
				value2 = string2int(val2);
				int result = value1 + value2;
				char sum[20];
				int2string(result, sum);
				memset(buffer+startOffset, '\0', bufferlen - startOffset);
				strcat(buffer, sum);
				strcat(buffer, back);

				bufferlen = strlen(buffer);
				num_ops++;
				break;
			}
		} if (buffer[i] == ';') break;
		
	} 
	if(pthread_mutex_unlock(&mutex)!=0) printErrorAndExit("Fail to Unlock");
	sem_w(&sem);
	sem_p(&sem);

	sched_yield();
	usleep(50000);
    } // end while
}

/* Looks for a multiplication symbol "*" surrounded by two numbers, e.g.
   "5*6" and, if found, multiplies the two numbers and replaces the
   mulitplication subexpression with the result ("1+(5*6)+8" becomes
   "1+(30)+8"). */
void *multiplier(void *arg)
{
    int bufferlen;
    int value1, value2;
    int startOffset, remainderOffset;
    int i;
	char back[BUF_SIZE];
	char val1[20];
	char val2[20];

    while (1) {
    	
	if(pthread_mutex_lock(&mutex) != 0) printErrorAndExit("Fail to Lock!");
		
	if (timeToFinish()) {
		pthread_mutex_unlock(&mutex); 
  		return NULL;
	}

	/* storing this prevents having to recalculate it in the loop */
	bufferlen = strlen(buffer);

	for (i=0; i<bufferlen; i++) {
		if (buffer[i] == '*') {
			if (isNumeric(buffer[i-1]) && isNumeric(buffer[i+1])) {
				memset(val1, '\0', strlen(val1));
				memset(val2, '\0', strlen(val2));
				memset(back, '\0', strlen(back));

				for (startOffset = i-2; startOffset>=0; startOffset--) if (!isNumeric(buffer[startOffset])) break;
				startOffset++; // the beginning of value 1
				for (int j = 0; j < i - startOffset; j++) val2[j] = buffer[startOffset+j];
				for (remainderOffset = i+2; remainderOffset < bufferlen; remainderOffset++) if (!isNumeric(buffer[remainderOffset])) break;
				remainderOffset--; // the end of value 2
				for (int j = 0; j < remainderOffset - i; j++) val1[j] = buffer[i+j+1];
				strcat(back, buffer + remainderOffset + 1);

				value1 = string2int(val1);
				value2 = string2int(val2);
				int result = value1 * value2;
				char product[20];
				int2string(result, product);
				memset(buffer+startOffset, '\0', bufferlen - startOffset);
				strcat(buffer, product);
				strcat(buffer, back);

				bufferlen = strlen(buffer);
				num_ops++;
				break;
			}
		} if (buffer[i] == ';') break;
	} 
	if(pthread_mutex_unlock(&mutex)!=0) printErrorAndExit("Fail to Unlock");
	sem_w(&sem);
	sem_p(&sem);

	sched_yield();
	usleep(50000);
    } // end while
}


/* Looks for a number immediately surrounded by parentheses [e.g.
   "(56)"] in the buffer and, if found, removes the parentheses leaving
   only the surrounded number. */
void *degrouper(void *arg)
{
	char back[BUF_SIZE];
	char number[BUF_SIZE];

    int bufferlen;
    int i, end;
    while (1) {

	if (pthread_mutex_lock(&mutex) != 0) printErrorAndExit("Fail to lock!");
	if (timeToFinish()) {
		pthread_mutex_unlock(&mutex);
	    return NULL;
	}

	/* storing this prevents having to recalculate it in the loop */
	bufferlen = strlen(buffer);
	for (i = 0; i < bufferlen; i++) {
		if (buffer[i] == '(') {
			if (isNumeric(buffer[i+1])) {
				for (end = i+2; end < bufferlen; end++) if (!isNumeric(buffer[end])) break;
				if (buffer[end] == ')') {
					memset(back, '\0', strlen(back));
					memset(number, '\0', strlen(number));

					strcat(back, buffer+end+1);
					memset(buffer+end, '\0', bufferlen-end);
					strcat(number, buffer+i+1);
					memset(buffer+i, '\0', bufferlen-i);
					strcat(buffer, number);
					strcat(buffer, back);

					num_ops++;
					break;
				}
			}
		} if (buffer[i] == ';') break;
	} 
	if(pthread_mutex_unlock(&mutex) != 0) printErrorAndExit("Fail to Unlock");
	sem_w(&sem);
	sem_p(&sem);

	sched_yield();
	usleep(50000);
	
    }
}


/* sentinel waits for a number followed by a ; (e.g. "453;") to appear
   at the beginning of the buffer, indicating that the current
   expression has been fully reduced by the other threads and can now be
   output.  It then "dequeues" that expression (and trailing ;) so work can
   proceed on the next (if available). */
void *sentinel(void *arg)
{
    char numberBuffer[20];
    int bufferlen;
    int i;

    while (1) {

	if(pthread_mutex_lock(&mutex) != 0) printErrorAndExit("Fail to Lock!");
		
	if (timeToFinish()) {
		pthread_mutex_unlock(&mutex); 
  		return NULL;
	}

	/* storing this prevents having to recalculate it in the loop */
	bufferlen = strlen(buffer);

	for (i = 0; i < bufferlen; i++) {
	    if (buffer[i] == ';') {
		if (i == 0) {
		    printErrorAndExit("Sentinel found empty expression!");
		} else {
		    /* null terminate the string */
		    numberBuffer[i] = '\0';
		     // print out the number we've found 
		    fprintf(stdout, "%s\n", numberBuffer);
		    /* shift the remainder of the string to the left */
		    strcpy(buffer, &buffer[i + 1]);
		    break;
		}
	    } else if (!isNumeric(buffer[i])) {
		break;
	    } else {
		numberBuffer[i] = buffer[i];
	    }
	} 
	if(pthread_mutex_unlock(&mutex)!=0) printErrorAndExit("Fail to Unlock");
	sem_w(&sem);
	sem_p(&sem);

	sched_yield();
	usleep(50000);
    }
}

/* reader reads in lines of input from stdin and writes them to the
   buffer */
void *reader(void *arg)
{
    while (1) {
	char tBuffer[100];
	int currentlen;
	int newlen;
	int free;

	fgets(tBuffer, sizeof(tBuffer), stdin);

	/* Sychronization bugs in remainder of function need to be fixed */

	newlen = strlen(tBuffer);
	currentlen = strlen(buffer);

	/* if tBuffer comes back with a newline from fgets, remove it */
	if (tBuffer[newlen - 1] == '\n') {
	    /* shift null terminator left */
	    tBuffer[newlen - 1] = tBuffer[newlen];
	    newlen--;
	}

	/* -1 for null terminator, -1 for ; separator */
	free = sizeof(buffer) - currentlen - 2;

	while (free < newlen) {
		// spinwaiting
	}

	/* we can add another expression now */
	pthread_mutex_lock(&mutex);
	strcat(buffer, tBuffer);
	strcat(buffer, ";");
	pthread_mutex_unlock(&mutex);
	sched_yield();

	/* Stop when user enters '.' */
	if (tBuffer[0] == '.') {
	    return NULL;
	}

    }
}

/* Where it all begins */
int smp3_main(int argc, char **argv)
{
    void *arg = 0;		/* dummy value */

	if(pthread_mutex_init(&mutex, NULL)!=0) printErrorAndExit("Failed trying to initialize lock");

    /* let's create our threads */
    if (pthread_create(&multiplierThread, NULL, multiplier, arg)
		|| pthread_create(&adderThread, NULL, adder, arg)
		|| pthread_create(&degrouperThread, NULL, degrouper, arg)
		|| pthread_create(&sentinelThread, NULL, sentinel, arg)
		|| pthread_create(&readerThread, NULL, reader, arg)) {
		printErrorAndExit("Failed trying to create threads");
    }

    /* you need to join one of these threads... but which one? */
    void * status;
    pthread_detach(multiplierThread);
    pthread_detach(adderThread);
    pthread_detach(degrouperThread);
    pthread_join(sentinelThread,&status);
    pthread_detach(readerThread);

    /* everything is finished, print out the number of operations performed */
    fprintf(stdout, "Performed a total of %d operations\n", num_ops);
    pthread_mutex_destroy(&mutex);
    return EXIT_SUCCESS;
}
