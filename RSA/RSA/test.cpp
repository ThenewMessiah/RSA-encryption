#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

#include "exception.h"
#include "fileIO.h"
#include "rsa.h"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(RSA_Test_Suite)

BOOST_AUTO_TEST_CASE(Exceptions)
{
  string message = "Test Exception";
  Exception e(message);
  BOOST_REQUIRE(e.message() == message);
}

BOOST_AUTO_TEST_CASE(ModularMath)
{
  int testNum;
  BOOST_TEST_MESSAGE("Initial test number value:" << testNum);

  BOOST_CHECK_THROW(getRandomNumber(0, 10), Exception);
  BOOST_CHECK_THROW(getRandomNumber(10, 0), Exception);
  BOOST_CHECK_THROW(getRandomNumber(50, 50), Exception);
  BOOST_CHECK_THROW(getRandomNumber(0, 0), Exception);
  BOOST_CHECK_NO_THROW(getRandomNumber(20, 30));
  BOOST_CHECK_NO_THROW(getRandomNumber(30, 20));

  testNum = getRandomNumber(1, 10);
  BOOST_CHECK_EQUAL(testNum >= 1 && testNum <= 10, true);
  testNum = getRandomNumber(1, 3);
  BOOST_CHECK_EQUAL(testNum >= 1 && testNum <= 3, true);
  testNum = getRandomNumber(1, 2);
  BOOST_CHECK_EQUAL(testNum >= 1 && testNum <= 2, true);
  testNum = getRandomNumber(450, 500);
  BOOST_CHECK_EQUAL(testNum >= 450 && testNum <= 500, true);
  testNum = getRandomNumber(10, 800);
  BOOST_CHECK_EQUAL(testNum >= 10 && testNum <= 800, true);

  BOOST_CHECK_THROW(getPrimeNum(0), Exception);
  BOOST_CHECK_THROW(getPrimeNum(5), Exception);
  BOOST_CHECK_NO_THROW(getPrimeNum(1));
  BOOST_CHECK_NO_THROW(getPrimeNum(4));

  testNum = getPrimeNum(1);
  BOOST_CHECK_EQUAL(testNum > 1 && testNum < 10, true);
  testNum = getPrimeNum(2);
  BOOST_CHECK_EQUAL(testNum > 10 && testNum < 100, true);
  testNum = getPrimeNum(3);
  BOOST_CHECK_EQUAL(testNum > 100 && testNum < 1000, true);
  testNum = getPrimeNum(4);
  BOOST_CHECK_EQUAL(testNum > 1000 && testNum < 10000, true);

  BOOST_CHECK_EQUAL(gcd(45, 60), 15);
  BOOST_CHECK_EQUAL(gcd(47, 13), 1);
  BOOST_CHECK_THROW(gcd(0, 600), Exception);
  BOOST_CHECK_THROW(gcd(300, 0), Exception);
  BOOST_CHECK_THROW(gcd(-21, 80), Exception);
  BOOST_CHECK_THROW(gcd(90, -31), Exception);

  BOOST_CHECK_EQUAL(checkRelativelyPrime(17, 19), true);
  BOOST_CHECK_EQUAL(checkRelativelyPrime(4, 8), false);
  BOOST_CHECK_EQUAL(checkRelativelyPrime(8, 4), false);
  BOOST_CHECK_EQUAL(checkRelativelyPrime(getPrimeNum(2), getPrimeNum(3)), true);

  BOOST_CHECK_EQUAL(modularInverse(42, 2017), 1969);
  BOOST_CHECK_EQUAL(modularInverse(29, 5200), 2869);
  BOOST_CHECK_THROW(modularInverse(4, 8), Exception);

}

BOOST_AUTO_TEST_CASE(RSA_Key)
{
  Key testKeyDefault;
  Key testKeyCustomGood(2869, 5353, 101, 53, 29);
  BOOST_CHECK_THROW(Key testKeyCustomBadFactors(1111, 2500, 750, 55, 13), Exception);

  BOOST_CHECK_EQUAL(testKeyDefault.getPublicBase(), testKeyDefault.getFactor1() * testKeyDefault.getFactor2());
}

BOOST_AUTO_TEST_SUITE_END()
