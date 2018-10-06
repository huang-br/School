CC=gcc
FLAGS=-Wall -Werror -std=gnu99 -O2 -g

all: bubble_sort_test shell_sort_test quick_sort_test merge_sort_test full_test

vector.o: vector.h vector.c
	$(CC) $(FLAGS) -c -o vector.o -D TYPE=double vector.c

bubble_sort.o: vector.h bubble_sort.h bubble_sort.c
	$(CC) $(FLAGS) -c -o bubble_sort.o -D TYPE=double bubble_sort.c

shell_sort.o: vector.h shell_sort.h shell_sort.c
	$(CC) $(FLAGS) -c -o shell_sort.o -D TYPE=double shell_sort.c

quick_sort.o: vector.h quick_sort.h quick_sort.c
	$(CC) $(FLAGS) -c -o quick_sort.o -D TYPE=double quick_sort.c

merge_sort.o: vector.h merge_sort.h merge_sort.c
	$(CC) $(FLAGS) -c -o merge_sort.o -D TYPE=double merge_sort.c

bubble_sort_test: vector.o merge_sort.o bubble_sort.o sort_test.h sort_test.c
	$(CC) $(FLAGS) -o bubble_sort_test -D TYPE=double -D SORT_FN=bubble_sort sort_test.c bubble_sort.o vector.o merge_sort.o

shell_sort_test: vector.o merge_sort.o shell_sort.o sort_test.h sort_test.c
	$(CC) $(FLAGS) -o shell_sort_test -D TYPE=double -D SORT_FN=shell_sort sort_test.c shell_sort.o vector.o merge_sort.o

quick_sort_test: vector.o merge_sort.o quick_sort.o sort_test.h sort_test.c
	$(CC) $(FLAGS) -o quick_sort_test -D TYPE=double -D SORT_FN=quick_sort sort_test.c quick_sort.o vector.o merge_sort.o

merge_sort_test: vector.o merge_sort.o sort_test.h sort_test.c
	$(CC) $(FLAGS) -o merge_sort_test -D TYPE=double -D SORT_FN=merge_sort sort_test.c vector.o merge_sort.o

full_test: vector.o bubble_sort.o shell_sort.o quick_sort.o merge_sort.o full_test.h full_test.c
	$(CC) $(FLAGS) -lm -o full_test -D TYPE=double full_test.c vector.o bubble_sort.o shell_sort.o quick_sort.o merge_sort.o

clean:
	rm -f bubble_sort_test shell_sort_test quick_sort_test merge_sort_test full_test
	rm -f *.o
