
all: RSA

RSA: main.o fileIO.o rsa.o
		$(CXX) main.o fileIO.o rsa.o -o RSA -lboost_unit_test_framework

main.o: main.cpp fileIO.cpp rsa.cpp
		$(CXX) -c main.cpp fileIO.cpp rsa.cpp -std=c++11

test: test.o fileIO.o rsa.o
	$(CXX) test.o fileIO.o rsa.o -o testSuites -lboost_unit_test_framework

test.o: test.cpp fileIO.cpp rsa.cpp
	$(CXX) -c test.cpp fileIO.cpp rsa.cpp -std=c++11

clean:
	rm *.o RSA testSuites

