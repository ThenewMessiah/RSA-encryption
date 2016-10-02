all: RSA

RSA: main.o fileIO.o rsa.o
		g++ main.o fileIO.o rsa.o -o RSA -lboost_unit_test_framework

main.o: main.cpp fileIO.cpp rsa.cpp
		g++ -c main.cpp fileIO.cpp rsa.cpp -lboost_unit_test_framework

test: test.o fileIO.o rsa.o
	g++ test.o fileIO.o rsa.o -o test_RSA -lboost_unit_test_framework

test.o: test.cpp fileIO.cpp rsa.cpp
	g++ -c test.cpp fileIO.cpp rsa.cpp -lboost_unit_test_framework

clean:
	rm *.o RSA

