CC=gcc
FLAGS=-Wall -Werror -Wconversion -std=gnu99 -O2 -g

all: objects tests

objects: tree.o iterator.o set.o

tests: unit_tests/unit_test.o unit_tests/tree_test_basic.exe unit_tests/tree_test_indexing.exe unit_tests/tree_test_avl.exe unit_tests/traversal_test.exe unit_tests/set_ops_test.exe

%.o: %.c *.h
	$(CC) $(FLAGS) -c -o $@ -D TYPE=float $<

unit_tests/%.o: unit_tests/%.c unit_tests/%.h
	$(CC) $(FLAGS) -c -o $@ -D TYPE=float $<

unit_tests/%.exe: unit_tests/%.c unit_tests/%.h unit_tests/unit_test.o tree.o iterator.o set.o
	$(CC) $(FLAGS) -o $@ -D TYPE=float $^

clean:
	rm -f *.o
	rm -f unit_tests/*.o
	rm -f unit_tests/*.exe
