CC=gcc
FLAGS=-Wall -Werror -std=gnu99 -O2 -g

all: objects tests

objects: hash_functions.o unit_test.o

tests: hash_fn_test.exe

%.o: %.c *.h
	$(CC) $(FLAGS) -c -o $@ $<

%.exe: %.c %.h unit_test.o hash_functions.o
	$(CC) $(FLAGS) -o $@ $^

clean:
	rm -f *.o
	rm -f *.exe
