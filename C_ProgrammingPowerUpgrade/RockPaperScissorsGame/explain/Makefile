run: main.o game.o gameTimes.o gameMoney.o gameContinue.o
	gcc -o run main.o game.o gameTimes.o gameMoney.o gameContinue.o

main.o: main.c
	gcc -c main.c

game.o: game.c
	gcc -c game.c

gameTimes.o: gameTimes.c
	gcc -c gameTimes.c

gameMoney.o: gameMoney.c
	gcc -c gameMoney.c

gameContinue.o: gameContinue.c
	gcc -c gameContinue.c

clean:
	rm run *.o
