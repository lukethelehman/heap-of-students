all: date.o address.o student.o main.o
	g++ date.o address.o student.o main.o -o all
date.o: date.h date.cpp
	g++ -c date.cpp
address.o: address.h address.cpp
	g++ -c address.cpp
student.o: student.h student.cpp date.h address.h
	g++ -c student.cpp
main.o: main.cpp address.cpp date.cpp
	g++ -c main.cpp
clean:
	rm -f *.o
	rm all
run: all
	./all
	


