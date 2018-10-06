shortestDistance.py

To use this program you will want to specifiy the method and the file when running the program.
There are three different methods. bruteforce, divideandcounquer and enhanceddnc.
The usage of the program looks like this

python shortestDistance.py <method> <filename>

Example:

python shortestDistance.py enhanceddnc input.txt

After running it will print onto the screen how long the process took. A file called "output.txt" will
also be generated after running. This file contains the length of the shortest distance and a list of all
pairs of points with that same length. The numbers will be floats.

An example input and output file is provided. Using the input file the results should exactly match the output file.

EXTRA PROGRAM
filegenerator.py

*********************************IMPORTANT NOTE*******************************************************
* This file does not create distinct points. So when using this file the shortest distance can be 0. *
******************************************************************************************************

This is a program to generate input files. It generates a list of points in the format given in the assignment pdf.
To run this program a lower bound, an upper bound and the number of points must be given. The usage of the program
looks like this

python filegenerator.py <lowerbound> <upperbound> <number of points>

Example:

python shortestDistance.py 0 100 10

After running a file will be made calle "input.txt" and will have a list of points. The points will be ints.


