/**
 * @abstract This library was created so I, AJ Keller, could do Test Driven
 *  Development (TDD) eaiser across the several different libraries I am working
 *  on and maintaing.
 * @author AJ Keller
 * @license MIT
 */

#include "PTW-Arduino-Assert.h"

PTW_Arduino_Assert::PTW_Arduino_Assert() {
    numberOfTests = 0;
    numberOfTestsFailed = 0;
    numberOfTestsPassed = 0;
}
/***************************************************/
/** PUBLIC METHODS *********************************/
/***************************************************/
// EQUAL
//  boolean
boolean PTW_Arduino_Assert::assertEqual(boolean a, boolean b) {
    numberOfTests++;
    boolean passed = (a == b);
    if (passed) {
        numberOfTestsPassed++;
    } else {
        numberOfTestsFailed++;
    }
    return passed;
}
boolean PTW_Arduino_Assert::assertEqual(boolean a, boolean b, char *msg) {
    return printTestResultWithMsg(assertEqual(a, b), msg);
}
//  byte
boolean PTW_Arduino_Assert::assertEqual(byte a, byte b) {
    numberOfTests++;
    boolean passed = (a == b);
    if (passed) {
        numberOfTestsPassed++;
    } else {
        numberOfTestsFailed++;
    }
    return passed;
}
boolean PTW_Arduino_Assert::assertEqual(byte a, byte b, char *msg) {
    return printTestResultWithMsg(assertEqual(a, b), msg);
}
//  char
boolean PTW_Arduino_Assert::assertEqual(char a, char b) {
    numberOfTests++;
    boolean passed = (a == b);
    if (passed) {
        numberOfTestsPassed++;
    } else {
        numberOfTestsFailed++;
    }
    return passed;
}
boolean PTW_Arduino_Assert::assertEqual(char a, char b, char *msg) {
    return printTestResultWithMsg(assertEqual(a, b), msg);
}
//  int
boolean PTW_Arduino_Assert::assertEqual(int a, int b) {
    numberOfTests++;
    boolean passed = (a == b);
    if (passed) {
        numberOfTestsPassed++;
    } else {
        numberOfTestsFailed++;
    }
    return passed;
}
boolean PTW_Arduino_Assert::assertEqual(int a, int b, char *msg) {
    return printTestResultWithMsg(assertEqual(a, b), msg);
}

// NOT EQUAL
//  boolean
boolean PTW_Arduino_Assert::assertNotEqual(boolean a, boolean b) {
    return !assertEqual(a,b);
}
boolean PTW_Arduino_Assert::assertNotEqual(boolean a, boolean b, char *msg) {
    return printTestResultWithMsg(assertNotEqual(a, b), msg);
}
//  byte
boolean PTW_Arduino_Assert::assertNotEqual(byte a, byte b) {
    return !assertEqual(a,b);
}
boolean PTW_Arduino_Assert::assertNotEqual(byte a, byte b, char *msg) {
    return printTestResultWithMsg(assertNotEqual(a, b), msg);
}
//  char
boolean PTW_Arduino_Assert::assertNotEqual(char a, char b) {
    return !assertEqual(a,b);
}
boolean PTW_Arduino_Assert::assertNotEqual(char a, char b, char *msg) {
    return printTestResultWithMsg(assertNotEqual(a, b), msg);
}
//  int
boolean PTW_Arduino_Assert::assertNotEqual(int a, int b) {
    return !assertEqual(a,b);
}
boolean PTW_Arduino_Assert::assertNotEqual(int a, int b, char *msg) {
    return printTestResultWithMsg(assertNotEqual(a, b), msg);
}

// GREATER THAN
//  boolean
boolean PTW_Arduino_Assert::assertGreaterThan(boolean a, boolean b) {
    numberOfTests++;
    boolean passed = (a > b);
    if (passed) {
        numberOfTestsPassed++;
    } else {
        numberOfTestsFailed++;
    }
    return passed;
}
boolean PTW_Arduino_Assert::assertGreaterThan(boolean a, boolean b, char *msg) {
    return printTestResultWithMsg(assertGreaterThan(a, b), msg);
}
//  byte
boolean PTW_Arduino_Assert::assertGreaterThan(byte a, byte b) {
    numberOfTests++;
    boolean passed = (a > b);
    if (passed) {
        numberOfTestsPassed++;
    } else {
        numberOfTestsFailed++;
    }
    return passed;
}
boolean PTW_Arduino_Assert::assertGreaterThan(byte a, byte b, char *msg) {
    return printTestResultWithMsg(assertGreaterThan(a, b), msg);
}
//  char
boolean PTW_Arduino_Assert::assertGreaterThan(char a, char b) {
    numberOfTests++;
    boolean passed = (a > b);
    if (passed) {
        numberOfTestsPassed++;
    } else {
        numberOfTestsFailed++;
    }
    return passed;
}
boolean PTW_Arduino_Assert::assertGreaterThan(char a, char b, char *msg) {
    return printTestResultWithMsg(assertGreaterThan(a, b), msg);
}
//  int
boolean PTW_Arduino_Assert::assertGreaterThan(int a, int b) {
    numberOfTests++;
    boolean passed = (a > b);
    if (passed) {
        numberOfTestsPassed++;
    } else {
        numberOfTestsFailed++;
    }
    return passed;
}
boolean PTW_Arduino_Assert::assertGreaterThan(int a, int b, char *msg) {
    return printTestResultWithMsg(assertGreaterThan(a, b), msg);
}

// LESS THAN
//  boolean
boolean PTW_Arduino_Assert::assertLessThan(boolean a, boolean b) {
    numberOfTests++;
    boolean passed = (a < b);
    if (passed) {
        numberOfTestsPassed++;
    } else {
        numberOfTestsFailed++;
    }
    return passed;
}
boolean PTW_Arduino_Assert::assertLessThan(boolean a, boolean b, char *msg) {
    return printTestResultWithMsg(assertLessThan(a, b), msg);
}
//  byte
boolean PTW_Arduino_Assert::assertLessThan(byte a, byte b) {
    numberOfTests++;
    boolean passed = (a < b);
    if (passed) {
        numberOfTestsPassed++;
    } else {
        numberOfTestsFailed++;
    }
    return passed;
}
boolean PTW_Arduino_Assert::assertLessThan(byte a, byte b, char *msg) {
    return printTestResultWithMsg(assertLessThan(a, b), msg);
}
//  char
boolean PTW_Arduino_Assert::assertLessThan(char a, char b) {
    numberOfTests++;
    boolean passed = (a < b);
    if (passed) {
        numberOfTestsPassed++;
    } else {
        numberOfTestsFailed++;
    }
    return passed;
}
boolean PTW_Arduino_Assert::assertLessThan(char a, char b, char *msg) {
    return printTestResultWithMsg(assertLessThan(a, b), msg);
}
//  int
boolean PTW_Arduino_Assert::assertLessThan(int a, int b) {
    numberOfTests++;
    boolean passed = (a < b);
    if (passed) {
        numberOfTestsPassed++;
    } else {
        numberOfTestsFailed++;
    }
    return passed;
}
boolean PTW_Arduino_Assert::assertLessThan(int a, int b, char *msg) {
    return printTestResultWithMsg(assertLessThan(a, b), msg);
}

void PTW_Arduino_Assert::printFunctionNameUnderTest(char *title) {
    if (_serial) {
        _serial.print(" #");
        _serial.println(msg);
    }
}

void PTW_Arduino_Assert::begin(void) {
    if (_serial) {
        _serial.println("-------------------------------");
        _serial.println("-- PTW-Arduino-Assert v0.1.0 --");
        _serial.println("-------------------------------");
        _serial.println("------- Auto Test Start -------");
        _serial.println("-------------------------------");
    }
}

void PTW_Arduino_Assert::end(void) {
    if (_serial) {
        _serial.println("-------------------------------");
        _serial.println("-------- Auto Test End --------");
        _serial.println("-------------------------------");
    }
}

/***************************************************/
/** PRIVATE METHODS ********************************/
/***************************************************/

boolean PTW_Arduino_Assert::printTestResultWithMsg(boolean testPassed, char *msg) {
    if (!testPassed) {
        _serial.print("   Failed - ");
    } else {
        _serial.print("   Passed - ");
    }
    _serial.println(msg);
    return testPassed;
}

void PTW_Arduino_Assert::setHarwareSerial(HardwareSerial *serial) {
    _serial = serial;
}

PTW_Arduino_Assert test;
