defualt: prog

dynArray.o: dynArray.c dynAray.h
	gcc -Wall -ansi -c dynArray.c

prog: dynArray.o
	gcc -Wall -ansi -o prog dynArray.o stackapp.c

clean:
	rm dynArray.o

cleanall:
	rm prog
