CC=gcc
FLAGS=-Wall -Werror -std=gnu99 -O2 -g

all: array_paren_checker linked_paren_checker test_array_stack test_linked_stack test_array_deque test_linked_deque

paren_checker.o: paren_checker.c paren_checker.h
	$(CC) $(FLAGS) -c -o paren_checker.o -D TYPE=char paren_checker.c

check_next_paren.o: check_next_paren.c check_next_paren.h
	$(CC) $(FLAGS) -c -o check_next_paren.o -D TYPE=char check_next_paren.c

array_char_stack.o: array_stack.c stack.h
	$(CC) $(FLAGS) -c -o array_char_stack.o -D TYPE=char array_stack.c

linked_char_stack.o: linked_stack.c stack.h
	$(CC) $(FLAGS) -c -o linked_char_stack.o -D TYPE=char linked_stack.c

array_int_deque.o: array_deque.c deque.h
	$(CC) $(FLAGS) -c -o array_int_deque.o -D TYPE=int array_deque.c

linked_int_deque.o: linked_deque.c deque.h
	$(CC) $(FLAGS) -c -o linked_int_deque.o -D TYPE=int linked_deque.c

test_stack.o: test_stack.c test_stack.h
	$(CC) $(FLAGS) -c -o test_stack.o test_stack.c

test_deque.o: test_deque.c test_deque.h
	$(CC) $(FLAGS) -c -o test_deque.o test_deque.c

unit_test.o: unit_test.c unit_test.h
	$(CC) $(FLAGS) -c -o unit_test.o unit_test.c

array_paren_checker: array_char_stack.o check_next_paren.o paren_checker.o
	$(CC) $(FLAGS) -o array_paren_checker -D TYPE=char array_char_stack.o check_next_paren.o paren_checker.o

linked_paren_checker: linked_char_stack.o check_next_paren.o paren_checker.o
	$(CC) $(FLAGS) -o linked_paren_checker -D TYPE=char linked_char_stack.o check_next_paren.o paren_checker.o

test_array_stack: array_char_stack.o test_stack.o unit_test.o
	$(CC) $(FLAGS) -o test_array_stack -D TYPE=char array_char_stack.o unit_test.o test_stack.o

test_linked_stack: linked_char_stack.o test_stack.o unit_test.o
	$(CC) $(FLAGS) -o test_linked_stack -D TYPE=char linked_char_stack.o unit_test.o test_stack.o

test_array_deque: array_int_deque.o test_deque.o unit_test.o
	$(CC) $(FLAGS) -o test_array_deque -D TYPE=int array_int_deque.o unit_test.o test_deque.o

test_linked_deque: linked_int_deque.o test_deque.o unit_test.o
	$(CC) $(FLAGS) -o test_linked_deque -D TYPE=int linked_int_deque.o unit_test.o test_deque.o

clean:
	rm -f  array_paren_checker test_array_stack linked_paren_checker test_linked_stack test_array_deque test_linked_deque
	rm -f *.o
