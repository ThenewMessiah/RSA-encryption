CC=g++

all: RSA

RSA: main.o fileIO.o rsa.o
		$(CC) main.o fileIO.o rsa.o -o RSA -lboost_unit_test_framework

main.o: main.cpp fileIO.cpp rsa.cpp
		$(CC) -c main.cpp fileIO.cpp rsa.cpp

test: test.o fileIO.o rsa.o
	$(CC) test.o fileIO.o rsa.o -o testSuites -lboost_unit_test_framework

test.o: test.cpp fileIO.cpp rsa.cpp
	$(CC) -c test.cpp fileIO.cpp rsa.cpp

clean:
	rm *.o RSA testSuites

