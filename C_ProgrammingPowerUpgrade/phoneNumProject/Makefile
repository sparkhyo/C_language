run: main.o phoneFunc.o screenOut.o
	gcc -o run main.o phoneFunc.o screenOut.o
main.o: main.c
	gcc -c main.c
phoneFunc.o: phoneFunc.c
	gcc -c phoneFunc.c
screenOut.o: screenOut.c
	gcc -c screenOut.c
clean:
	rm *.o run
