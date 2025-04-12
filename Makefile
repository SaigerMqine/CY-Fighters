all: exec
verif.o: verif.c verif.h
	gcc -c verif.c -o verif.o
main.o: main.c maketeam.h
	gcc -c main.c -o main.o
exec: main.o maketeam.o
	gcc main.o maketeam.o -o exec

clean:
	rm exec
	rm *.o