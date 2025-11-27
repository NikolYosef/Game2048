CC = gcc
OBJS = main.o game.o board.o steps.o 
EXEC = game
DEBUG = -g
CFLAGS = -std=c99 -Wall -Werror $(DEBUG)


$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $@
	
board.o: board.c board.h game.h
game.o: game.c game.h steps.h board.h
main.o: main.c game.h
steps.o: steps.c steps.h game.h

clean: 	
	rm -f $(OBJS) $(EXEC)
