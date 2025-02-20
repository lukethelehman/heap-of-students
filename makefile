all: date.o address.o main.o
	g++ address.o main.o date.o -o all
address.o: address.h address.cpp
	g++ -c address.cpp
main.o: main.cpp address.cpp date.cpp
	g++ -c main.cpp
date.o: date.h date.cpp
	g++ -c date.cpp
clean:
	rm -f *.o
	rm all
run: all
	./all
	


