CC = gcc
CCOPTS = -Wall -c -g -ggdb
LINKOPTS = -Wall -g -ggdb -pthread

all: calc

calc: calc.o smp3_tests.o testrunner.o
	$(CC) $(LINKOPTS) -o $@ $^

calc.o: calc.c calc.h
	$(CC) $(CCOPTS) -o $@ $<

smp3_tests.o: smp3_tests.c calc.h
	$(CC) $(CCOPTS) -o $@ $<

testrunner.o: testrunner.c testrunner.h
	$(CC) $(CCOPTS) -o $@ $<

test: calc
	./calc -test -f10 all
	killall calc

clean:
	rm -rf *.o calc calc.exe *~
	
pretty: 
	indent *.c *.h -kr
