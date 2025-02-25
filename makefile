all: date.o address.o student.o main.o
	g++ address.o main.o date.o student.o -o all
address.o: address.h address.cpp
	g++ -c address.cpp
main.o: main.cpp address.cpp date.cpp
	g++ -c main.cpp
date.o: date.h date.cpp
	g++ -c date.cpp
student.o: student.h student.cpp date.h address.h
	g++ -c student.cpp
clean:
	rm -f *.o
	rm all
run: all
	./all
	


