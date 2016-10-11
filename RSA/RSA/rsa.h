#ifndef RSA_H
#define SIERPINSKI_H

int getRandomNumber(int min, int max);
int getPrimeNum(int numOfDigits);
int gcd(int m, int n);
bool checkRelativelyPrime(int num1, int num2);
int modValue(int base, int exp, int mod);
int modularInverse(int a, int b);

class Key
{
public:
	Key();
	Key(int privateKey, int baseNum, int factor1, int factor2, int exp);
	Key(const Key& copy_from);
	~Key();

	int getPrivateKey() const;
	int getPublicBase() const;
	int getFactor1() const;
	int getFactor2() const;
	int getPublicExp() const;


private:
	int _privateKey;
	int _publicBase;
	int _factor1;
	int _factor2;
	int _publicExp;
};

#endif