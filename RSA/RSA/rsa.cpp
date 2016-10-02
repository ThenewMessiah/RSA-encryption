#include <iostream>
#include <math.h>
#include <cstring>
#include <cstdlib>
#include "exception.h"
#include "rsa.h"

using namespace std;

// Program to implement Sieve of Eratosthenes
int getPrimeNum(int numOfDigits)
{
	if(numOfDigits < 1)
		throw Exception("Number of Digits is too small!");
	if(numOfDigits > 4)
		throw Exception("Number of Digits is too large!");

	int primeNum = 0, primeCount = 0, range = int(pow(10.0, double(numOfDigits))) + 1;
	int arr[range];
	memset(arr, 0, range * sizeof(int));
	int primeArr[range];
	memset(primeArr, 0, range * sizeof(int));

	for (int i = 2; i < range; i++)
	{
		for (int j = i * i; j < range; j+=i)
		{
			arr[j - 1] = 1;
		}
	}
	for (int i = 1; i < range; i++)
	{
		if (arr[i - 1] == 0) {
			primeArr[primeCount] = i;
			primeCount++;
		}
	}
	do
	{
		// get random index from 1 - number of primes in range
		int randIndex = rand() % (primeCount - 1);
		primeNum = primeArr[randIndex];
	}while (primeNum < range/10 || primeNum > range);
	// keep getting a new number until primeNum is the correct number of digits
	return primeNum;
}

int gcd(int m, int n)
{
	int r;

	// Check for valid input
	if((m == 0) || (n == 0))
		throw Exception("Cannot determine GCD: At least 1 number is set to 0!");
	else if((m < 0) || (n < 0))
		throw Exception("Cannot determine GCD: At least 1 number is negative!");

	do
	{
		r = m % n;
		if(r == 0)
			break;
		m = n;
		n = r;
	}
	while(true);

	return n;
}

bool checkRelativelyPrime(int num1, int num2)
{
	if(gcd(num1, num2) == 1) return true;
	else return false;
}

int modularInverse(int num, int mod)
{
	if(!checkRelativelyPrime(num, mod))
		throw Exception("Modular Inverse does not exist (not co-prime)!");
	int mod0 = mod, t, q;
	int x0 = 0, x1 = 1;
	if (mod == 1) return 1;
	while (num > 1) {
		q = num / mod;
		t = mod, mod = num % mod, num = t;
		t = x0, x0 = x1 - q * x0, x1 = t;
	}
	if (x1 < 0) x1 += mod0;
	return x1;
}

Key::Key()
{
	// factor1 == p
	_factor1 = getPrimeNum(3);
	// factor2 == q
	_factor2 = getPrimeNum(2);
	// base = (p * q)
	_publicBase = _factor1 * _factor2;
	// e = number relatively prime to (p-1)(q-1)
	_publicExp = getPrimeNum(2);
	// privateKey = exp ^ -1 mod (p-1)(q-1)
	_privateKey = modularInverse(_publicExp, (_factor1 - 1) * (_factor2 - 1));
}

Key::Key(int privateKey, int baseNum, int factor1, int factor2, int exp)
{
	if(factor1 * factor2 != baseNum)
		throw Exception("Cannot construct Key: Factors 1 and/or 2 are not factors of Base number!");
	_privateKey = privateKey;
	_publicBase = baseNum;
	_factor1 = factor1;
	_factor2 = factor2;
	_publicExp = exp;
}

Key::Key(const Key& copy_from)
{
	_privateKey = copy_from._privateKey;
	_publicBase = copy_from._publicBase;
	_factor1 = copy_from._factor1;
	_factor2 = copy_from._factor2;
	_publicExp = copy_from._publicExp;
}

Key::~Key() { }

int Key::getPrivateKey() const {return _privateKey;}

int Key::getPublicBase() const {return _publicBase;}

int Key::getFactor1() const {return _factor1;}

int Key::getFactor2() const {return _factor2;}

int Key::getPublicExp() const {return _publicExp;}