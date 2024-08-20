
all: CityTemp
CityTemp: main.o temp_api.o
	gcc -o CityTemp main.o temp_api.o
main.o: main.c temp_api.h
	gcc -c -o main.o main.c
temp_api.o: temp_api.c
	gcc -c -o temp_api.o temp_api.c
clean:
	del *.o CityTemp.exe
