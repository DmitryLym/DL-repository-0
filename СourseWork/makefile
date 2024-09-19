
all: report
report: main.o temp_function.o
	gcc -o report main.o temp_function.o
main.o: main.c temp_function.h
	gcc -c -o main.o main.c
temp_function.o: temp_function.c
	gcc -c -o temp_function.o temp_function.c
clean:
	del *.o report.exe
