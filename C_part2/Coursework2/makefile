
all: Square
Square: main.o set_functions.o root.o integral.o Interface.o
	gcc -o Square main.o set_functions.o root.o integral.o Interface.o
main.o: main.c header.h
	gcc -c -o main.o main.c
set_functions.o: set_functions.c
	gcc -c -o set_functions.o set_functions.c
root.o: root.c
	gcc -c -o root.o root.c
integral.o: integral.c
	gcc -c -o integral.o integral.c
Interface.o: Interface.c
	gcc -c -o Interface.o Interface.c
clean:
	del *.o Square.exe