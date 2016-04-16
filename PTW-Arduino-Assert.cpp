/**
 * @abstract This library was created so I, AJ Keller, could do Test Driven
 *  Development (TDD) eaiser across the several different libraries I am working
 *  on and maintaing.
 * @author AJ Keller
 * @license MIT
 */

#include "PTW-Arduino-Assert.h"

/***************************************************/
/** PUBLIC METHODS *********************************/
/***************************************************/
// EQUAL
//  boolean
boolean PTW_Arduino_Assert::assertEqual(boolean a, boolean b) {
    return a == b;
}
boolean PTW_Arduino_Assert::assertEqual(boolean a, boolean b, char *msg) {
    return printMessage(assertEqual(a, b), msg);
}
//  byte
boolean PTW_Arduino_Assert::assertEqual(byte a, byte b) {
    return a == b;
}
boolean PTW_Arduino_Assert::assertEqual(byte a, byte b, char *msg) {
    return printMessage(assertEqual(a, b), msg);
}
//  char
boolean PTW_Arduino_Assert::assertEqual(char a, char b) {
    return a == b;
}
boolean PTW_Arduino_Assert::assertEqual(char a, char b, char *msg) {
    return printMessage(assertEqual(a, b), msg);
}
//  int
boolean PTW_Arduino_Assert::assertEqual(int a, int b) {
    return a == b;
}
boolean PTW_Arduino_Assert::assertEqual(int a, int b, char *msg) {
    return printMessage(assertEqual(a, b), msg);
}

// NOT EQUAL
//  boolean
boolean PTW_Arduino_Assert::assertNotEqual(boolean a, boolean b) {
    return !assertEqual(a,b);
}
boolean PTW_Arduino_Assert::assertNotEqual(boolean a, boolean b, char *msg) {
    return printMessage(assertNotEqual(a, b), msg);
}
//  byte
boolean PTW_Arduino_Assert::assertNotEqual(byte a, byte b) {
    return !assertEqual(a,b);
}
boolean assertNotEqual(byte a, byte b, char *msg) {
    return printMessage(assertNotEqual(a, b), msg);
}
//  char
boolean PTW_Arduino_Assert::assertNotEqual(char a, char b) {
    return !assertEqual(a,b);
}
boolean PTW_Arduino_Assert::assertNotEqual(char a, char b, char *msg) {
    return printMessage(assertNotEqual(a, b), msg);
}
//  int
boolean PTW_Arduino_Assert::assertNotEqual(int a, int b) {
    return !assertEqual(a,b);
}
boolean PTW_Arduino_Assert::assertNotEqual(int a, int b, char *msg) {
    return printMessage(assertNotEqual(a, b), msg);
}

// GREATER THAN
//  boolean
boolean PTW_Arduino_Assert::assertGreaterThan(boolean a, boolean b) {
    return a > b;
}
boolean PTW_Arduino_Assert::assertGreaterThan(boolean a, boolean b, char *msg) {
    return printMessage(assertGreaterThan(a, b), msg);
}
//  byte
boolean PTW_Arduino_Assert::assertGreaterThan(byte a, byte b) {
    return a > b;
}
boolean PTW_Arduino_Assert::assertGreaterThan(byte a, byte b, char *msg) {
    return printMessage(assertGreaterThan(a, b), msg);
}
//  char
boolean PTW_Arduino_Assert::assertGreaterThan(char a, char b) {
    return a > b;
}
boolean PTW_Arduino_Assert::assertGreaterThan(char a, char b, char *msg) {
    return printMessage(assertGreaterThan(a, b), msg);
}
//  int
boolean PTW_Arduino_Assert::assertGreaterThan(int a, int b) {
    return a > b;
}
boolean PTW_Arduino_Assert::assertGreaterThan(int a, int b, char *msg) {
    return printMessage(assertGreaterThan(a, b), msg);
}

// LESS THAN
//  boolean
boolean PTW_Arduino_Assert::assertLessThan(boolean a, boolean b) {
  return a < b;
}
boolean PTW_Arduino_Assert::assertLessThan(boolean a, boolean b, char *msg) {
  return a < b;
}
//  byte
boolean PTW_Arduino_Assert::assertLessThan(byte a, byte b) {
  return a < b;
}
boolean PTW_Arduino_Assert::assertLessThan(byte a, byte b, char *msg) {
  return a < b;
}
//  char
boolean PTW_Arduino_Assert::assertLessThan(char a, char b) {
  return a < b;
}
boolean PTW_Arduino_Assert::assertLessThan(char a, char b, char *msg) {
  return a < b;
}
//  int
boolean PTW_Arduino_Assert::assertLessThan(int a, int b) {
  return a < b;
}
boolean PTW_Arduino_Assert::assertLessThan(int a, int b, char *msg) {
  return a < b;
}

void PTW_Arduino_Assert::printTestStart(void) {
    Serial.println("Auto Test Start");
    Serial.println("PTW-Arduino-Assert v0.1.0");
}

void PTW_Arduino_Assert::printFunctionNameUnderTest(char *title) {
    Serial.print("#");
    Serial.println(msg);
}

void PTW_Arduino_Assert::printTestEnd(void) {
    Serial.println("Auto Test End")
}
/***************************************************/
/** PRIVATE METHODS ********************************/
/***************************************************/
boolean PTW_Arduino_Assert::printMessage(boolean testPassed, char *msg) {
    if (!testPassed) {
        Serial.print(" Failed - ");
        Serial.println(msg);
    } else {
        Serial.println(" Passed");
    }
    return testPassed;
}
