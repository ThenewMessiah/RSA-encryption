#include <iostream>
#include "rsa.h"

int getPrimeNum()
{
	int num = 0;
	return num;
}

bool checkRelativelyPrime(int num1, int num2)
{
	return true;
}

Key::Key()
{

}

Key::Key(int privateKey, int baseNum, int exp)
{
	_privateKey = privateKey;
	_publicBase = baseNum;
	_publicExp = exp;
}

Key::Key(const Key& copy_from)
{
	_privateKey = copy_from._privateKey;
	_publicBase = copy_from._publicBase;
	_publicExp = copy_from._publicExp;
}

Key::~Key()
{

}

int Key::getPrivateKey() const
{
	return _privateKey;
}

int Key::getPublicBase() const
{
	return _publicBase;
}

int Key::getPublicExp() const
{
	return _publicExp;
}