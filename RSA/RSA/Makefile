CC=g++

all: RSA

RSA: main.o fileIO.o rsa.o
		$(CC) main.o fileIO.o rsa.o -o RSA -lboost_unit_test_framework

main.o: main.cpp fileIO.cpp rsa.cpp
		$(CC) -c main.cpp fileIO.cpp rsa.cpp -lboost_unit_test_framework

test: test.o fileIO.o rsa.o
	$(CC) test.o fileIO.o rsa.o -o test_RSA -lboost_unit_test_framework

test.o: test.cpp fileIO.cpp rsa.cpp
	$(CC) -c test.cpp fileIO.cpp rsa.cpp -lboost_unit_test_framework

clean:
	rm *.o RSA test_RSA

