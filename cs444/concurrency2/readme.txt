To compile this program simply type "make" to create the executable file.
To delete the program type "make clean" this will delete the executable file.

The makefile will create a program named a.out

to run this type ./a.out

The table updates every 5 seconds, so it may not catch very quick changes. This can be changed by changing the sleep time on the printing function.

The program can also clear the screen with every table update to not have the screen be cluttered by updates. This is off by defualt. To turn this on
simply uncomment out the clear line in the printing function.

The table sometimes breaks and doesn't print the name of the last person. 
The first semaphore is kind of broken. It initializes to a very high value and I don't really know how to fix it.
