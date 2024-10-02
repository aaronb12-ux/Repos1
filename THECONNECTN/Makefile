connectn.out: main.o gameboard.o playgame.o winconditions.o inputval.o
	gcc -g -Wall -Werror -o connectn.out main.o gameboard.o playgame.o winconditions.c inputval.o

main.o: main.c gameboard.h playgame.h
	gcc -g -Wall -Werror -c main.c

gameboard.o: gameboard.c gameboard.h
	gcc -g -Wall -Werror -c gameboard.c

playgame.o: playgame.c gameboard.h playgame.h winconditions.h inputval.h
	gcc -g -Wall -Werror -c playgame.c

winconditions.o: winconditions.c winconditions.h gameboard.h
	gcc -g -Wall -Werror -c winconditions.c

inputval.o: inputval.c inputval.h playgame.h
	gcc -g -Wall -Werror -c inputval.c

clean:
	rm -f  *.o*.out

run: connectn.out
	./connectn.out 9 9 3


