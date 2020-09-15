all: add-nbo

add-nbo: add-nbo.o
	g++ -g -o add-nbo add-nbo.o

add-nbo.o: add-nbo.cpp
