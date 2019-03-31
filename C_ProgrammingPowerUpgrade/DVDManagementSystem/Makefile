run: main.o screenOut.o cusInfoAccess.o cusManager.o dvdInfoAccess.o dvdManager.o
	gcc -o run main.o screenOut.o cusInfoAccess.o cusManager.o dvdInfoAccess.o dvdManager.o

main.o: main.c
	gcc -c main.c

screenOut.o: screenOut.c
	gcc -c screenOut.c

cusInfoAccess.o: cusInfoAccess.c
	gcc -c cusInfoAccess.c

cusManager.o: cusManager.c
	gcc -c cusManager.c

dvdInfoAccess.o: dvdInfoAccess.c
	gcc -c dvdInfoAccess.c

dvdManager.o: dvdManager.c
	gcc -c dvdManager.c

clean:
	rm *.o run
