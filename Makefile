all: exec
verif.o: verif.c verif.h
	gcc -c verif.c -o verif.o

maketeam.o: maketeam.c maketeam.h verif.h
	gcc -c maketeam.c -o maketeam.o

combat.o: combat.c combat.h verif.h maketeam.h
	gcc -c combat.c -o combat.o

jeu_interface.o: jeu_interface.c verif.h 
	gcc -c jeu_interface.c -o jeu_interface.o

main.o: main.c maketeam.h combat.c combat.h verif.h
	gcc -c main.c -o main.o

exec: main.o maketeam.o jeu_interface.o combat.o verifs.o
	gcc main.o maketeam.o jeu_interface.o combat.o verifs.o -o exec

clean:
	rm exec
	rm *.o