paint.out: main.o canvas.o playgame.o commands.o
	gcc -g -Wall -Werror -o paint.out main.o canvas.o playgame.o commands.o

main.o: main.c canvas.h playgame.h
	gcc -g -Wall -Werror -c main.c

canvas.o: canvas.c canvas.h
	gcc -g -Wall -Werror -c canvas.c

playgame.o: playgame.c playgame.h canvas.h commands.h
	gcc -g -Wall -Werror -c playgame.c

commands.o: commands.c commands.h playgame.h canvas.h
	gcc -g -Wall -Werror -c commands.c

clean:
	rm -f *.o*.out

run: paint.out
	./paint.out

