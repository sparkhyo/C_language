run: main.o screenOut.o blManager.o cusInfoAccess.o dvdInfoAccess.o rentInfoAccess.o
	gcc -o run main.o screenOut.o blManager.o cusInfoAccess.o dvdInfoAccess.o rentInfoAccess.o

main.o: main.c
	gcc -c main.c

screenOut.o: screenOut.c
	gcc -c screenOut.c

blManager.o: blManager.c
	gcc -c blManager.c

cusInfoAccess.o: cusInfoAccess.c
	gcc -c cusInfoAccess.c

dvdInfoAccess.o: dvdInfoAccess.c
	gcc -c dvdInfoAccess.c

rentInfoAccess.o: rentInfoAccess.c
	gcc -c rentInfoAccess.c

clean:
	rm *.o run
