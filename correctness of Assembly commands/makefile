mycomp: mycomp.o complex.o
	gcc -g -ansi mycomp.o complex.o -o mycomp -lm

mycomp.o: mycomp.c mycomp.h complex.h
	gcc -c -Wall -ansi -pedantic mycomp.c -o mycomp.o

complex.o: complex.c complex.h
	gcc -c -Wall -ansi -pedantic complex.c -o complex.o -lm

clean:
	rm -f mycomp.o
