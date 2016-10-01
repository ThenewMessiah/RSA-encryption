#ifndef RSA_H
#define SIERPINSKI_H

int getPrimeNum();
bool checkRelativelyPrime(int num1, int num2);

class Key
{
public:
	Key();									// default constructor
	Key(int privateKey, int baseNum, int exp);				// Custom Key constructor
	Key(const Key& copy_from);				// copy constructor
	~Key();									// destructor

	int getPrivateKey() const;
	int getPublicBase() const;
	int getPublicExp() const;

private:
	int _privateKey;
	int _publicBase;
	int _publicExp;
};

#endif