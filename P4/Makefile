CC = g++

all: ComplexNumber.o  main.o
	$(CC) -o Main $?

ComplexNumber.o: ComplexNumber.cpp
	$(CC) -c $?

main.o: main.cpp
	$(CC) -c $?

clean:
	rm -f *.o Main
