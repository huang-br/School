CC=gcc
FLAGS=-Wall -Werror -std=gnu99 -O2 -g

all: objects tests

objects: p_queue.o

tests: unit_tests/unit_test.o unit_tests/shell_sort.o unit_tests/basic_test.exe unit_tests/sort_test.exe unit_tests/large_test.exe

%.o: %.c *.h
	$(CC) $(FLAGS) -c -o $@ -D TYPE=float $<

unit_tests/%.o: unit_tests/%.c unit_tests/%.h
	$(CC) $(FLAGS) -c -o $@ -D TYPE=float $<

unit_tests/%.exe: unit_tests/%.c unit_tests/%.h unit_tests/unit_test.o unit_tests/shell_sort.o p_queue.o
	$(CC) $(FLAGS) -o $@ -D TYPE=float $^

clean:
	rm -f *.o
	rm -f unit_tests/*.o
	rm -f unit_tests/*.exe
