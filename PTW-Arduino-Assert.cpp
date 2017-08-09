/**
* @abstract This library was created so I, AJ Keller, could do Test Driven
*  Development (TDD) eaiser across the several different libraries I am working
*  on and maintaing.
* @author AJ Keller
* @license MIT
* @version 0.3.2
*/

#include "PTW-Arduino-Assert.h"
#include "HardwareSerial.h"

PTW_Arduino_Assert::PTW_Arduino_Assert() {
  numberOfTests = 0;
  numberOfTestsFailed = 0;
  numberOfTestsPassed = 0;
  serialType = SERIAL_HARDWARE;
  failVerbosity = false;
}
/***************************************************/
/** PUBLIC METHODS *********************************/
/***************************************************/

// FORCE
boolean PTW_Arduino_Assert::fail(void) {
  numberOfTests++;
  numberOfTestsFailed++;
  return false;
}
boolean PTW_Arduino_Assert::fail(const char *msg) {
  return printTestResultWithMsg(fail(), msg);;
}

boolean PTW_Arduino_Assert::fail(const char *msg, int lineNumber) {
  return printTestResultWithMsgAndLine(fail(), msg, lineNumber);
}


boolean PTW_Arduino_Assert::pass(void) {
  numberOfTests++;
  numberOfTestsPassed++;
  return true;
}

boolean PTW_Arduino_Assert::pass(const char *msg) {
  return printTestResultWithMsg(pass(), msg);;
}

boolean PTW_Arduino_Assert::pass(const char *msg, int lineNumber) {
  return printTestResultWithMsgAndLine(pass(), msg, lineNumber);
}


boolean PTW_Arduino_Assert::assertApproximately(float actual, float expected, float epsilon) {
  numberOfTests++;
  boolean passed = false;

  if (abs(actual - expected) < epsilon) {
    passed = true;
  }

  if (passed) {
    numberOfTestsPassed++;
  } else {
    numberOfTestsFailed++;
  }
  return passed;
}

boolean PTW_Arduino_Assert::assertApproximately(float actual, float expected, float epsilon, const char *msg) {
  boolean testPassed = printTestResultWithMsg(assertApproximately(actual, expected, epsilon), msg);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(actual, expected);
  }

  return testPassed;
}

boolean PTW_Arduino_Assert::assertApproximately(float actual, float expected, float epsilon, const char *msg, int lineNumber) {
  boolean testPassed = printTestResultWithMsgAndLine(assertApproximately(actual, expected, epsilon), msg, lineNumber);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(actual, expected);
  }

  return testPassed;
}

boolean PTW_Arduino_Assert::assertApproximately(double actual, double expected, double epsilon) {
  numberOfTests++;
  boolean passed = false;

  if (abs(actual - expected) < epsilon) {
    passed = true;
  }

  if (passed) {
    numberOfTestsPassed++;
  } else {
    numberOfTestsFailed++;
  }
  return passed;
}

boolean PTW_Arduino_Assert::assertApproximately(double actual, double expected, double epsilon, const char *msg) {
  boolean testPassed = printTestResultWithMsg(assertApproximately(actual, expected, epsilon), msg);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(actual, expected);
  }

  return testPassed;
}

boolean PTW_Arduino_Assert::assertApproximately(double actual, double expected, double epsilon, const char *msg, int lineNumber) {
  boolean testPassed = printTestResultWithMsgAndLine(assertApproximately(actual, expected, epsilon), msg, lineNumber);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(actual, expected);
  }

  return testPassed;
}

// EQUAL
//  boolean
boolean PTW_Arduino_Assert::assertBoolean(boolean actual, boolean expected) {
  numberOfTests++;
  boolean passed = (actual == expected);
  if (passed) {
    numberOfTestsPassed++;
  } else {
    numberOfTestsFailed++;
  }
  return passed;
}
boolean PTW_Arduino_Assert::assertBoolean(boolean actual, boolean expected, const char *msg) {
  boolean testPassed = printTestResultWithMsg(assertBoolean(actual, expected), msg);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(actual, expected);
  }

  return testPassed;
}
boolean PTW_Arduino_Assert::assertBoolean(boolean actual, boolean expected, const char *msg, int lineNumber) {
  boolean testPassed = printTestResultWithMsgAndLine(assertBoolean(actual, expected), msg, lineNumber);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(actual, expected);
  }

  return testPassed;
}
boolean PTW_Arduino_Assert::assertFalse(boolean isFalse) {
  numberOfTests++;
  boolean passed = (isFalse == false);
  if (passed) {
    numberOfTestsPassed++;
  } else {
    numberOfTestsFailed++;
  }
  return passed;
}
boolean PTW_Arduino_Assert::assertFalse(boolean isFalse, const char *msg) {
  boolean testPassed = printTestResultWithMsg(assertFalse(isFalse), msg);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(isFalse, (boolean)false);
  }

  return testPassed;
}
boolean PTW_Arduino_Assert::assertFalse(boolean isFalse, const char *msg, int lineNumber) {
  boolean testPassed = printTestResultWithMsgAndLine(assertFalse(isFalse), msg, lineNumber);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(isFalse, (boolean)false);
  }

  return testPassed;
}
boolean PTW_Arduino_Assert::assertTrue(boolean isTrue) {
  numberOfTests++;
  boolean passed = (isTrue == true);
  if (passed) {
    numberOfTestsPassed++;
  } else {
    numberOfTestsFailed++;
  }
  return passed;
}
boolean PTW_Arduino_Assert::assertTrue(boolean isTrue, const char *msg) {
  boolean testPassed = printTestResultWithMsg(assertTrue(isTrue), msg);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(isTrue, (boolean)true);
  }

  return testPassed;
}
boolean PTW_Arduino_Assert::assertTrue(boolean isTrue, const char *msg, int lineNumber) {
  boolean testPassed = printTestResultWithMsgAndLine(assertTrue(isTrue), msg, lineNumber);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(isTrue, (boolean)true);
  }

  return testPassed;
}
// STRING
boolean PTW_Arduino_Assert::assertEqual(String actual, String expected) {
  numberOfTests++;
  boolean passed = actual.equals(expected);
  if (passed) {
    numberOfTestsPassed++;
  } else {
    numberOfTestsFailed++;
  }
  return passed;
}

boolean PTW_Arduino_Assert::assertEqual(String actual, String expected, const char *msg) {
  boolean testPassed = printTestResultWithMsg(assertEqual(actual, expected), msg);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(actual, expected);
  }

  return testPassed;
}

boolean PTW_Arduino_Assert::assertEqual(String actual, String expected, const char *msg, int line) {
  boolean testPassed = printTestResultWithMsgAndLine(assertEqual(actual, expected), msg, line);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(actual, expected);
  }

  return testPassed;
}
// char buffer
boolean PTW_Arduino_Assert::assertEqualBuffer(char *actual, char *expected, int length) {
  numberOfTests++;
  boolean passed = true;
  for (int i = 0; i < length; i++) {
    if (actual[i] != expected[i]) {
      passed = false;
    }
  }
  if (passed) {
    numberOfTestsPassed++;
  } else {
    numberOfTestsFailed++;
  }
  return passed;
}
boolean PTW_Arduino_Assert::assertEqualBuffer(char *actual, char *expected, int length, const char *msg) {
  boolean testPassed = printTestResultWithMsg(assertEqualBuffer(actual, expected, length), msg);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessageBuffer(actual, expected, length);
  }

  return testPassed;
}
boolean PTW_Arduino_Assert::assertEqualBuffer(char *actual, char *expected, int length, const char *msg, int lineNumber) {
  boolean testPassed = printTestResultWithMsgAndLine(assertEqualBuffer(actual, expected, length), msg, lineNumber);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessageBuffer(actual, expected, length);
  }

  return testPassed;
}
// uint8_t buffer
boolean PTW_Arduino_Assert::assertEqualBuffer(uint8_t *actual, uint8_t *expected, int length) {
  boolean passed = true;
  numberOfTests++;
  for (int i = 0; i < length; i++) {
    if (actual[i] != expected[i]) {
      passed = false;
    }
  }
  if (passed) {
    numberOfTestsPassed++;
  } else {
    numberOfTestsFailed++;
  }
  return passed;
}
boolean PTW_Arduino_Assert::assertEqualBuffer(uint8_t *actual, uint8_t *expected, int length, const char *msg) {
  boolean testPassed = printTestResultWithMsg(assertEqualBuffer(actual, expected, length), msg);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessageBuffer(actual, expected, length);
  }

  return testPassed;
}
boolean PTW_Arduino_Assert::assertEqualBuffer(uint8_t *actual, uint8_t *expected, int length, const char *msg, int lineNumber) {
  boolean testPassed = printTestResultWithMsgAndLine(assertEqualBuffer(actual, expected, length), msg, lineNumber);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessageBuffer(actual, expected, length);
  }

  return testPassed;
}
//  byte
boolean PTW_Arduino_Assert::assertEqualHex(byte actual, byte expected) {
  numberOfTests++;
  boolean passed = (actual == expected);
  if (passed) {
    numberOfTestsPassed++;
  } else {
    numberOfTestsFailed++;
  }
  return passed;
}
boolean PTW_Arduino_Assert::assertEqualHex(byte actual, byte expected, const char *msg) {
  boolean testPassed = printTestResultWithMsg(assertEqualHex(actual, expected), msg);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessageHex(actual, expected);
  }

  return testPassed;
}
boolean PTW_Arduino_Assert::assertEqualHex(byte actual, byte expected, const char *msg, int lineNumber) {
  boolean testPassed = printTestResultWithMsgAndLine(assertEqualHex(actual, expected), msg, lineNumber);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessageHex(actual, expected);
  }

  return testPassed;
}
//  char
boolean PTW_Arduino_Assert::assertEqual(char actual, char expected) {
  numberOfTests++;
  boolean passed = (actual == expected);
  if (passed) {
    numberOfTestsPassed++;
  } else {
    numberOfTestsFailed++;
  }
  return passed;
}
boolean PTW_Arduino_Assert::assertEqual(char actual, char expected, const char *msg) {
  boolean testPassed = printTestResultWithMsg(assertEqual(actual, expected), msg);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(actual, expected);
  }

  return testPassed;
}
boolean PTW_Arduino_Assert::assertEqual(char actual, char expected, const char *msg, int lineNumber) {
  boolean testPassed = printTestResultWithMsgAndLine(assertEqual(actual, expected), msg, lineNumber);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(actual, expected);
  }

  return testPassed;
}
//  int
boolean PTW_Arduino_Assert::assertEqual(int actual, int expected) {
  numberOfTests++;
  boolean passed = (actual == expected);
  if (passed) {
    numberOfTestsPassed++;
  } else {
    numberOfTestsFailed++;
  }
  return passed;
}
boolean PTW_Arduino_Assert::assertEqual(int actual, int expected, const char *msg) {
  boolean testPassed = printTestResultWithMsg(assertEqual(actual, expected), msg);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(actual, expected);
  }

  return testPassed;
}
boolean PTW_Arduino_Assert::assertEqual(int actual, int expected, const char *msg, int lineNumber) {
  boolean testPassed = printTestResultWithMsgAndLine(assertEqual(actual, expected), msg, lineNumber);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(actual, expected);
  }

  return testPassed;
}
//  long
boolean PTW_Arduino_Assert::assertEqual(long actual, long expected) {
  numberOfTests++;
  boolean passed = (actual == expected);
  if (passed) {
    numberOfTestsPassed++;
  } else {
    numberOfTestsFailed++;
  }
  return passed;
}
boolean PTW_Arduino_Assert::assertEqual(long actual, long expected, const char *msg) {
  boolean testPassed = printTestResultWithMsg(assertEqual(actual, expected), msg);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(actual, expected);
  }

  return testPassed;
}
boolean PTW_Arduino_Assert::assertEqual(long actual, long expected, const char *msg, int lineNumber) {
  boolean testPassed = printTestResultWithMsgAndLine(assertEqual(actual, expected), msg, lineNumber);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(actual, expected);
  }

  return testPassed;
}
// size_t
boolean PTW_Arduino_Assert::assertEqual(size_t actual, size_t expected) {
  numberOfTests++;
  boolean passed = (actual == expected);
  if (passed) {
    numberOfTestsPassed++;
  } else {
    numberOfTestsFailed++;
  }
  return passed;
}
boolean PTW_Arduino_Assert::assertEqual(size_t actual, size_t expected, const char *msg) {
  boolean testPassed = printTestResultWithMsg(assertEqual(actual, expected), msg);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(actual, expected);
  }

  return testPassed;
}
boolean PTW_Arduino_Assert::assertEqual(size_t actual, size_t expected, const char *msg, int lineNumber) {
  boolean testPassed = printTestResultWithMsgAndLine(assertEqual(actual, expected), msg, lineNumber);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(actual, expected);
  }

  return testPassed;
}
//  unsigned long
boolean PTW_Arduino_Assert::assertEqual(unsigned long actual, unsigned long expected) {
  numberOfTests++;
  boolean passed = (actual == expected);
  if (passed) {
    numberOfTestsPassed++;
  } else {
    numberOfTestsFailed++;
  }
  return passed;
}
boolean PTW_Arduino_Assert::assertEqual(unsigned long actual, unsigned long expected, const char *msg) {
  boolean testPassed = printTestResultWithMsg(assertEqual(actual, expected), msg);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(actual, expected);
  }

  return testPassed;
}
boolean PTW_Arduino_Assert::assertEqual(unsigned long actual, unsigned long expected, const char *msg, int lineNumber) {
  boolean testPassed = printTestResultWithMsgAndLine(assertEqual(actual, expected), msg, lineNumber);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(actual, expected);
  }

  return testPassed;
}
//  long long
boolean PTW_Arduino_Assert::assertEqual(long long actual, long long expected) {
  numberOfTests++;
  boolean passed = (actual == expected);
  if (passed) {
    numberOfTestsPassed++;
  } else {
    numberOfTestsFailed++;
  }
  return passed;
}
boolean PTW_Arduino_Assert::assertEqual(long long actual, long long expected, const char *msg) {
  boolean testPassed = printTestResultWithMsg(assertEqual(actual, expected), msg);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(actual, expected);
  }

  return testPassed;
}
boolean PTW_Arduino_Assert::assertEqual(long long actual, long long expected, const char *msg, int lineNumber) {
  boolean testPassed = printTestResultWithMsgAndLine(assertEqual(actual, expected), msg, lineNumber);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(actual, expected);
  }

  return testPassed;
}
//  unsigned long long
boolean PTW_Arduino_Assert::assertEqual(unsigned long long actual, unsigned long long expected) {
  numberOfTests++;
  boolean passed = (actual == expected);
  if (passed) {
    numberOfTestsPassed++;
  } else {
    numberOfTestsFailed++;
  }
  return passed;
}
boolean PTW_Arduino_Assert::assertEqual(unsigned long long actual, unsigned long long expected, const char *msg) {
  boolean testPassed = printTestResultWithMsg(assertEqual(actual, expected), msg);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(actual, expected);
  }

  return testPassed;
}
boolean PTW_Arduino_Assert::assertEqual(unsigned long long actual, unsigned long long expected, const char *msg, int lineNumber) {
  boolean testPassed = printTestResultWithMsgAndLine(assertEqual(actual, expected), msg, lineNumber);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(actual, expected);
  }

  return testPassed;
}

// NOT EQUAL
//  buffer
boolean PTW_Arduino_Assert::assertNotEqualBuffer(char *actual, char *expected, int length) {
  return !assertEqualBuffer(actual, expected,length);
}

boolean PTW_Arduino_Assert::assertNotEqualBuffer(char *actual, char *expected, int length, const char *msg) {
  boolean testPassed = printTestResultWithMsg(assertNotEqualBuffer(actual, expected, length), msg);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessageBuffer(actual, expected, length);
  }

  return testPassed;
}
boolean PTW_Arduino_Assert::assertNotEqualBuffer(char *actual, char *expected, int length, const char *msg, int lineNumber) {
  boolean testPassed = printTestResultWithMsgAndLine(assertNotEqualBuffer(actual, expected, length), msg, lineNumber);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessageBuffer(actual, expected, length);
  }

  return testPassed;
}
//  byte
boolean PTW_Arduino_Assert::assertNotEqualHex(byte actual, byte expected) {
  return !assertEqual(actual, expected);
}
boolean PTW_Arduino_Assert::assertNotEqualHex(byte actual, byte expected, const char *msg) {
  boolean testPassed = printTestResultWithMsg(assertNotEqualHex(actual, expected), msg);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessageHex(actual, expected);
  }

  return testPassed;
}
boolean PTW_Arduino_Assert::assertNotEqualHex(byte actual, byte expected, const char *msg, int lineNumber) {
  boolean testPassed = printTestResultWithMsgAndLine(assertNotEqualHex(actual, expected), msg, lineNumber);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessageHex(actual, expected);
  }

  return testPassed;
}
//  char
boolean PTW_Arduino_Assert::assertNotEqual(char actual, char expected) {
  numberOfTests++;
  boolean passed = (actual != expected);
  if (passed) {
    numberOfTestsPassed++;
  } else {
    numberOfTestsFailed++;
  }
  return passed;
}
boolean PTW_Arduino_Assert::assertNotEqual(char actual, char expected, const char *msg) {
  boolean testPassed = printTestResultWithMsg(assertNotEqual(actual, expected), msg);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(actual, expected);
  }

  return testPassed;
}
boolean PTW_Arduino_Assert::assertNotEqual(char actual, char expected, const char *msg, int lineNumber) {
  boolean testPassed = printTestResultWithMsgAndLine(assertNotEqual(actual, expected), msg, lineNumber);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(actual, expected);
  }

  return testPassed;
}
//  int
boolean PTW_Arduino_Assert::assertNotEqual(int actual, int expected) {
  numberOfTests++;
  boolean passed = (actual != expected);
  if (passed) {
    numberOfTestsPassed++;
  } else {
    numberOfTestsFailed++;
  }
  return passed;
}
boolean PTW_Arduino_Assert::assertNotEqual(int actual, int expected, const char *msg) {
  boolean testPassed = printTestResultWithMsg(assertNotEqual(actual, expected), msg);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(actual, expected);
  }

  return testPassed;
}
boolean PTW_Arduino_Assert::assertNotEqual(int actual, int expected, const char *msg, int lineNumber) {
  boolean testPassed = printTestResultWithMsgAndLine(assertNotEqual(actual, expected), msg, lineNumber);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(actual, expected);
  }

  return testPassed;
}
//  long
boolean PTW_Arduino_Assert::assertNotEqual(long actual, long expected) {
  numberOfTests++;
  boolean passed = (actual != expected);
  if (passed) {
    numberOfTestsPassed++;
  } else {
    numberOfTestsFailed++;
  }
  return passed;
}
boolean PTW_Arduino_Assert::assertNotEqual(long actual, long expected, const char *msg) {
  boolean testPassed = printTestResultWithMsg(assertNotEqual(actual, expected), msg);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(actual, expected);
  }

  return testPassed;
}
boolean PTW_Arduino_Assert::assertNotEqual(long actual, long expected, const char *msg, int lineNumber) {
  boolean testPassed = printTestResultWithMsgAndLine(assertNotEqual(actual, expected), msg, lineNumber);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(actual, expected);
  }

  return testPassed;
}
//  long long
boolean PTW_Arduino_Assert::assertNotEqual(long long actual, long long expected) {
  numberOfTests++;
  boolean passed = (actual != expected);
  if (passed) {
    numberOfTestsPassed++;
  } else {
    numberOfTestsFailed++;
  }
  return passed;
}
boolean PTW_Arduino_Assert::assertNotEqual(long long actual, long long expected, const char *msg) {
  boolean testPassed = printTestResultWithMsg(assertNotEqual(actual, expected), msg);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(actual, expected);
  }

  return testPassed;
}
boolean PTW_Arduino_Assert::assertNotEqual(long long actual, long long expected, const char *msg, int lineNumber) {
  boolean testPassed = printTestResultWithMsgAndLine(assertNotEqual(actual, expected), msg, lineNumber);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(actual, expected);
  }

  return testPassed;
}
//  size_t
boolean PTW_Arduino_Assert::assertNotEqual(size_t actual, size_t expected) {
  numberOfTests++;
  boolean passed = (actual != expected);
  if (passed) {
    numberOfTestsPassed++;
  } else {
    numberOfTestsFailed++;
  }
  return passed;
}
boolean PTW_Arduino_Assert::assertNotEqual(size_t actual, size_t expected, const char *msg) {
  boolean testPassed = printTestResultWithMsg(assertNotEqual(actual, expected), msg);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(actual, expected);
  }

  return testPassed;
}
boolean PTW_Arduino_Assert::assertNotEqual(size_t actual, size_t expected, const char *msg, int lineNumber) {
  boolean testPassed = printTestResultWithMsgAndLine(assertNotEqual(actual, expected), msg, lineNumber);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(actual, expected);
  }

  return testPassed;
}
//  unsigned long
boolean PTW_Arduino_Assert::assertNotEqual(unsigned long actual, unsigned long expected) {
  numberOfTests++;
  boolean passed = (actual != expected);
  if (passed) {
    numberOfTestsPassed++;
  } else {
    numberOfTestsFailed++;
  }
  return passed;
}
boolean PTW_Arduino_Assert::assertNotEqual(unsigned long actual, unsigned long expected, const char *msg) {
  boolean testPassed = printTestResultWithMsg(assertNotEqual(actual, expected), msg);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(actual, expected);
  }

  return testPassed;
}
boolean PTW_Arduino_Assert::assertNotEqual(unsigned long actual, unsigned long expected, const char *msg, int lineNumber) {
  boolean testPassed = printTestResultWithMsgAndLine(assertNotEqual(actual, expected), msg, lineNumber);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(actual, expected);
  }

  return testPassed;
}
//  unsigned long long
boolean PTW_Arduino_Assert::assertNotEqual(unsigned long long actual, unsigned long long expected) {
  numberOfTests++;
  boolean passed = (actual != expected);
  if (passed) {
    numberOfTestsPassed++;
  } else {
    numberOfTestsFailed++;
  }
  return passed;
}
boolean PTW_Arduino_Assert::assertNotEqual(unsigned long long actual, unsigned long long expected, const char *msg) {
  boolean testPassed = printTestResultWithMsg(assertNotEqual(actual, expected), msg);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(actual, expected);
  }

  return testPassed;
}
boolean PTW_Arduino_Assert::assertNotEqual(unsigned long long actual, unsigned long long expected, const char *msg, int lineNumber) {
  boolean testPassed = printTestResultWithMsgAndLine(assertNotEqual(actual, expected), msg, lineNumber);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(actual, expected);
  }

  return testPassed;
}

// GREATER THAN
//  byte
boolean PTW_Arduino_Assert::assertGreaterThanHex(byte actual, byte expected) {
  numberOfTests++;
  boolean passed = (actual > expected);
  if (passed) {
    numberOfTestsPassed++;
  } else {
    numberOfTestsFailed++;
  }
  return passed;
}
boolean PTW_Arduino_Assert::assertGreaterThanHex(byte actual, byte expected, const char *msg) {
  boolean testPassed = printTestResultWithMsg(assertGreaterThanHex(actual, expected), msg);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessageHex(actual, expected);
  }

  return testPassed;
}
boolean PTW_Arduino_Assert::assertGreaterThanHex(byte actual, byte expected, const char *msg, int lineNumber) {
  boolean testPassed = printTestResultWithMsgAndLine(assertGreaterThanHex(actual, expected), msg, lineNumber);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessageHex(actual, expected);
  }

  return testPassed;
}
//  char
boolean PTW_Arduino_Assert::assertGreaterThan(char actual, char expected) {
  numberOfTests++;
  boolean passed = (actual > expected);
  if (passed) {
    numberOfTestsPassed++;
  } else {
    numberOfTestsFailed++;
  }
  return passed;
}
boolean PTW_Arduino_Assert::assertGreaterThan(char actual, char expected, const char *msg) {
  boolean testPassed = printTestResultWithMsg(assertGreaterThan(actual, expected), msg);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(actual, expected);
  }

  return testPassed;
}
boolean PTW_Arduino_Assert::assertGreaterThan(char actual, char expected, const char *msg, int lineNumber) {
  boolean testPassed = printTestResultWithMsgAndLine(assertGreaterThan(actual, expected), msg, lineNumber);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(actual, expected);
  }

  return testPassed;
}
//  int
boolean PTW_Arduino_Assert::assertGreaterThan(int actual, int expected) {
  numberOfTests++;
  boolean passed = (actual > expected);
  if (passed) {
    numberOfTestsPassed++;
  } else {
    numberOfTestsFailed++;
  }
  return passed;
}
boolean PTW_Arduino_Assert::assertGreaterThan(int actual, int expected, const char *msg) {
  boolean testPassed = printTestResultWithMsg(assertGreaterThan(actual, expected), msg);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(actual, expected);
  }

  return testPassed;
}
boolean PTW_Arduino_Assert::assertGreaterThan(int actual, int expected, const char *msg, int lineNumber) {
  boolean testPassed = printTestResultWithMsgAndLine(assertGreaterThan(actual, expected), msg, lineNumber);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(actual, expected);
  }

  return testPassed;
}
//  long
boolean PTW_Arduino_Assert::assertGreaterThan(long actual, long expected) {
  numberOfTests++;
  boolean passed = (actual > expected);
  if (passed) {
    numberOfTestsPassed++;
  } else {
    numberOfTestsFailed++;
  }
  return passed;
}
boolean PTW_Arduino_Assert::assertGreaterThan(long actual, long expected, const char *msg) {
  boolean testPassed = printTestResultWithMsg(assertGreaterThan(actual, expected), msg);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(actual, expected);
  }

  return testPassed;
}
boolean PTW_Arduino_Assert::assertGreaterThan(long actual, long expected, const char *msg, int lineNumber) {
  boolean testPassed = printTestResultWithMsgAndLine(assertGreaterThan(actual, expected), msg, lineNumber);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(actual, expected);
  }

  return testPassed;
}
//  long long
boolean PTW_Arduino_Assert::assertGreaterThan(long long actual, long long expected) {
  numberOfTests++;
  boolean passed = (actual > expected);
  if (passed) {
    numberOfTestsPassed++;
  } else {
    numberOfTestsFailed++;
  }
  return passed;
}
boolean PTW_Arduino_Assert::assertGreaterThan(long long actual, long long expected, const char *msg) {
  boolean testPassed = printTestResultWithMsg(assertGreaterThan(actual, expected), msg);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(actual, expected);
  }

  return testPassed;
}
boolean PTW_Arduino_Assert::assertGreaterThan(long long actual, long long expected, const char *msg, int lineNumber) {
  boolean testPassed = printTestResultWithMsgAndLine(assertGreaterThan(actual, expected), msg, lineNumber);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(actual, expected);
  }

  return testPassed;
}
//  size_t
boolean PTW_Arduino_Assert::assertGreaterThan(size_t actual, size_t expected) {
  numberOfTests++;
  boolean passed = (actual > expected);
  if (passed) {
    numberOfTestsPassed++;
  } else {
    numberOfTestsFailed++;
  }
  return passed;
}
boolean PTW_Arduino_Assert::assertGreaterThan(size_t actual, size_t expected, const char *msg) {
  boolean testPassed = printTestResultWithMsg(assertGreaterThan(actual, expected), msg);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(actual, expected);
  }

  return testPassed;
}
boolean PTW_Arduino_Assert::assertGreaterThan(size_t actual, size_t expected, const char *msg, int lineNumber) {
  boolean testPassed = printTestResultWithMsgAndLine(assertGreaterThan(actual, expected), msg, lineNumber);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(actual, expected);
  }

  return testPassed;
}
//  unsigned long
boolean PTW_Arduino_Assert::assertGreaterThan(unsigned long actual, unsigned long expected) {
  numberOfTests++;
  boolean passed = (actual > expected);
  if (passed) {
    numberOfTestsPassed++;
  } else {
    numberOfTestsFailed++;
  }
  return passed;
}
boolean PTW_Arduino_Assert::assertGreaterThan(unsigned long actual, unsigned long expected, const char *msg) {
  boolean testPassed = printTestResultWithMsg(assertGreaterThan(actual, expected), msg);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(actual, expected);
  }

  return testPassed;
}
boolean PTW_Arduino_Assert::assertGreaterThan(unsigned long actual, unsigned long expected, const char *msg, int lineNumber) {
  boolean testPassed = printTestResultWithMsgAndLine(assertGreaterThan(actual, expected), msg, lineNumber);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(actual, expected);
  }

  return testPassed;
}
//  unsigned long long
boolean PTW_Arduino_Assert::assertGreaterThan(unsigned long long actual, unsigned long long expected) {
  numberOfTests++;
  boolean passed = (actual > expected);
  if (passed) {
    numberOfTestsPassed++;
  } else {
    numberOfTestsFailed++;
  }
  return passed;
}
boolean PTW_Arduino_Assert::assertGreaterThan(unsigned long long actual, unsigned long long expected, const char *msg) {
  boolean testPassed = printTestResultWithMsg(assertGreaterThan(actual, expected), msg);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(actual, expected);
  }

  return testPassed;
}
boolean PTW_Arduino_Assert::assertGreaterThan(unsigned long long actual, unsigned long long expected, const char *msg, int lineNumber) {
  boolean testPassed = printTestResultWithMsgAndLine(assertGreaterThan(actual, expected), msg, lineNumber);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(actual, expected);
  }

  return testPassed;
}
// LESS THAN
//  byte
boolean PTW_Arduino_Assert::assertLessThanHex(byte actual, byte expected) {
  numberOfTests++;
  boolean passed = (actual < expected);
  if (passed) {
    numberOfTestsPassed++;
  } else {
    numberOfTestsFailed++;
  }
  return passed;
}
boolean PTW_Arduino_Assert::assertLessThanHex(byte actual, byte expected, const char *msg) {
  boolean testPassed = printTestResultWithMsg(assertLessThanHex(actual, expected), msg);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessageHex(actual, expected);
  }

  return testPassed;
}
boolean PTW_Arduino_Assert::assertLessThanHex(byte actual, byte expected, const char *msg, int lineNumber) {
  boolean testPassed = printTestResultWithMsgAndLine(assertLessThanHex(actual, expected), msg, lineNumber);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessageHex(actual, expected);
  }

  return testPassed;
}
//  char
boolean PTW_Arduino_Assert::assertLessThan(char actual, char expected) {
  numberOfTests++;
  boolean passed = (actual < expected);
  if (passed) {
    numberOfTestsPassed++;
  } else {
    numberOfTestsFailed++;
  }
  return passed;
}
boolean PTW_Arduino_Assert::assertLessThan(char actual, char expected, const char *msg) {
  boolean testPassed = printTestResultWithMsg(assertLessThan(actual, expected), msg);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(actual, expected);
  }

  return testPassed;
}
boolean PTW_Arduino_Assert::assertLessThan(char actual, char expected, const char *msg, int lineNumber) {
  boolean testPassed = printTestResultWithMsgAndLine(assertLessThan(actual, expected), msg, lineNumber);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(actual, expected);
  }

  return testPassed;
}
//  int
boolean PTW_Arduino_Assert::assertLessThan(int actual, int expected) {
  numberOfTests++;
  boolean passed = (actual < expected);
  if (passed) {
    numberOfTestsPassed++;
  } else {
    numberOfTestsFailed++;
  }
  return passed;
}
boolean PTW_Arduino_Assert::assertLessThan(int actual, int expected, const char *msg) {
  boolean testPassed = printTestResultWithMsg(assertLessThan(actual, expected), msg);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(actual, expected);
  }

  return testPassed;
}
boolean PTW_Arduino_Assert::assertLessThan(int actual, int expected, const char *msg, int lineNumber) {
  boolean testPassed = printTestResultWithMsgAndLine(assertLessThan(actual, expected), msg, lineNumber);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(actual, expected);
  }

  return testPassed;
}
//  long
boolean PTW_Arduino_Assert::assertLessThan(long actual, long expected) {
  numberOfTests++;
  boolean passed = (actual < expected);
  if (passed) {
    numberOfTestsPassed++;
  } else {
    numberOfTestsFailed++;
  }
  return passed;
}
boolean PTW_Arduino_Assert::assertLessThan(long actual, long expected, const char *msg) {
  boolean testPassed = printTestResultWithMsg(assertLessThan(actual, expected), msg);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(actual, expected);
  }

  return testPassed;
}
boolean PTW_Arduino_Assert::assertLessThan(long actual, long expected, const char *msg, int lineNumber) {
  boolean testPassed = printTestResultWithMsgAndLine(assertLessThan(actual, expected), msg, lineNumber);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(actual, expected);
  }

  return testPassed;
}
//  long long
boolean PTW_Arduino_Assert::assertLessThan(long long actual, long long expected) {
  numberOfTests++;
  boolean passed = (actual < expected);
  if (passed) {
    numberOfTestsPassed++;
  } else {
    numberOfTestsFailed++;
  }
  return passed;
}
boolean PTW_Arduino_Assert::assertLessThan(long long actual, long long expected, const char *msg) {
  boolean testPassed = printTestResultWithMsg(assertLessThan(actual, expected), msg);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(actual, expected);
  }

  return testPassed;
}
boolean PTW_Arduino_Assert::assertLessThan(long long actual, long long expected, const char *msg, int lineNumber) {
  boolean testPassed = printTestResultWithMsgAndLine(assertLessThan(actual, expected), msg, lineNumber);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(actual, expected);
  }

  return testPassed;
}
//  size_t
boolean PTW_Arduino_Assert::assertLessThan(size_t actual, size_t expected) {
  numberOfTests++;
  boolean passed = (actual < expected);
  if (passed) {
    numberOfTestsPassed++;
  } else {
    numberOfTestsFailed++;
  }
  return passed;
}
boolean PTW_Arduino_Assert::assertLessThan(size_t actual, size_t expected, const char *msg) {
  boolean testPassed = printTestResultWithMsg(assertLessThan(actual, expected), msg);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(actual, expected);
  }

  return testPassed;
}
boolean PTW_Arduino_Assert::assertLessThan(size_t actual, size_t expected, const char *msg, int lineNumber) {
  boolean testPassed = printTestResultWithMsgAndLine(assertLessThan(actual, expected), msg, lineNumber);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(actual, expected);
  }

  return testPassed;
}
boolean PTW_Arduino_Assert::assertLessThan(unsigned long actual, unsigned long expected) {
  numberOfTests++;
  boolean passed = (actual < expected);
  if (passed) {
    numberOfTestsPassed++;
  } else {
    numberOfTestsFailed++;
  }
  return passed;
}
boolean PTW_Arduino_Assert::assertLessThan(unsigned long actual, unsigned long expected, const char *msg) {
  boolean testPassed = printTestResultWithMsg(assertLessThan(actual, expected), msg);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(actual, expected);
  }

  return testPassed;
}
boolean PTW_Arduino_Assert::assertLessThan(unsigned long actual, unsigned long expected, const char *msg, int lineNumber) {
  boolean testPassed = printTestResultWithMsgAndLine(assertLessThan(actual, expected), msg, lineNumber);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(actual, expected);
  }

  return testPassed;
}
boolean PTW_Arduino_Assert::assertLessThan(unsigned long long actual, unsigned long long expected) {
  numberOfTests++;
  boolean passed = (actual < expected);
  if (passed) {
    numberOfTestsPassed++;
  } else {
    numberOfTestsFailed++;
  }
  return passed;
}
boolean PTW_Arduino_Assert::assertLessThan(unsigned long long actual, unsigned long long expected, const char *msg) {
  boolean testPassed = printTestResultWithMsg(assertLessThan(actual, expected), msg);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(actual, expected);
  }

  return testPassed;
}
boolean PTW_Arduino_Assert::assertLessThan(unsigned long long actual, unsigned long long expected, const char *msg, int lineNumber) {
  boolean testPassed = printTestResultWithMsgAndLine(assertLessThan(actual, expected), msg, lineNumber);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessage(actual, expected);
  }

  return testPassed;
}

// Between
boolean PTW_Arduino_Assert::assertBetween(int actual, int lower, int upper) {
  numberOfTests++;
  boolean passed = (actual > lower) && (actual < upper);
  if (passed) {
    numberOfTestsPassed++;
  } else {
    numberOfTestsFailed++;
  }
  return passed;
}
boolean PTW_Arduino_Assert::assertBetween(int actual, int lower, int upper, const char *msg) {
  boolean testPassed = printTestResultWithMsg(assertBetween(actual, lower, upper), msg);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessageIntBetween(actual,lower,upper);
  }

  return testPassed;
}
boolean PTW_Arduino_Assert::assertBetween(int actual, int lower, int upper, const char *msg, int lineNumber) {
  boolean testPassed = printTestResultWithMsgAndLine(assertBetween(actual, lower, upper), msg, lineNumber);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessageIntBetween(actual,lower,upper);
  }

  return testPassed;
}
boolean PTW_Arduino_Assert::assertBetweenInclusive(int actual, int lower, int upper) {
  numberOfTests++;
  boolean passed = (actual >= lower) && (actual <= upper);
  if (passed) {
    numberOfTestsPassed++;
  } else {
    numberOfTestsFailed++;
  }
  return passed;
}
boolean PTW_Arduino_Assert::assertBetweenInclusive(int actual, int lower, int upper, const char *msg) {
  boolean testPassed = printTestResultWithMsg(assertBetween(actual, lower, upper), msg);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessageIntBetweenInclusive(actual,lower,upper);
  }

  return testPassed;
}
boolean PTW_Arduino_Assert::assertBetweenInclusive(int actual, int lower, int upper, const char *msg, int lineNumber) {
  boolean testPassed = printTestResultWithMsgAndLine(assertBetween(actual, lower, upper), msg, lineNumber);

  if (failVerbosity && !testPassed) {
    printVerboseFailMessageIntBetweenInclusive(actual,lower,upper);
  }

  return testPassed;
}
void PTW_Arduino_Assert::begin(void) {
  if (_hardwareSerial) {
    _hardwareSerial->println("-------------------------------");
    _hardwareSerial->println("-- PTW-Arduino-Assert v1.1.1 --");
    _hardwareSerial->println("-------------------------------");
    _hardwareSerial->println("------- AUTO TEST BEGIN -------");
    _hardwareSerial->println("-------------------------------");
  }
  numberOfTests = 0;
  numberOfTestsFailed = 0;
  numberOfTestsPassed = 0;
}

void PTW_Arduino_Assert::describe(char *title) {
  if (_hardwareSerial) {
    _hardwareSerial->print("\n #");
    _hardwareSerial->println(title);
  }
  // if (_softwareSerial) {
  //     _softwareSerial.print(" #");
  //     _softwareSerial.println(msg);
  // }
  // if (_usbSerial) {
  //     _usbSerial->print(" #");
  //     _usbSerial->println(title);
  // }
}

void PTW_Arduino_Assert::detail(char *msg) {
  if (_hardwareSerial) {
    _hardwareSerial->print("\n ->");
    _hardwareSerial->println(msg);
  }
  // if (_softwareSerial) {
  //     _softwareSerial.print(" #");
  //     _softwareSerial.println(msg);
  // }
  // if (_usbSerial) {
  //     _usbSerial->print(" #");
  //     _usbSerial->println(title);
  // }
}

void PTW_Arduino_Assert::it(char *msg) {
  if (_hardwareSerial) {
    _hardwareSerial->print("\n  it ");
    _hardwareSerial->println(msg);
  }
  // if (_softwareSerial) {
  //     _softwareSerial.print(" #");
  //     _softwareSerial.println(msg);
  // }
  // if (_usbSerial) {
  //     _usbSerial->print(" #");
  //     _usbSerial->println(title);
  // }
}

void PTW_Arduino_Assert::end(void) {
  if (_hardwareSerial) {
    _hardwareSerial->println("-------------------------------");
    _hardwareSerial->print("  Total Tests: ");
    _hardwareSerial->println(numberOfTests);
    _hardwareSerial->print("  Tests Passed: ");
    _hardwareSerial->println(numberOfTestsPassed);
    _hardwareSerial->print("  Tests Failed: ");
    _hardwareSerial->println(numberOfTestsFailed);
    _hardwareSerial->println("-------------------------------");
    _hardwareSerial->println("-------- AUTO TEST END --------");
    _hardwareSerial->println("-------------------------------");
  }
  // if (_softwareSerial) {
  //     _softwareSerial.println("-------------------------------");
  //     _softwareSerial.print("  Total Tests: ");
  //     _softwareSerial.println(numberOfTests);
  //     _softwareSerial.print("  Tests Passed: ");
  //     _softwareSerial.println(numberOfTestsPassed);
  //     _softwareSerial.print("  Tests Failed: ");
  //     _softwareSerial.println(numberOfTestsFailed);
  //     _softwareSerial.println("-------------------------------");
  //     _softwareSerial.println("-------- AUTO TEST END --------");
  //     _softwareSerial.println("-------------------------------");
  // }
  // if (_usbSerial) {
  //     _usbSerial->println("-------------------------------");
  //     _usbSerial->print("  Total Tests: ");
  //     _usbSerial->println(numberOfTests);
  //     _usbSerial->print("  Tests Passed: ");
  //     _usbSerial->println(numberOfTestsPassed);
  //     _usbSerial->print("  Tests Failed: ");
  //     _usbSerial->println(numberOfTestsFailed);
  //     _usbSerial->println("-------------------------------");
  //     _usbSerial->println("-------- AUTO TEST END --------");
  //     _usbSerial->println("-------------------------------");
  // }
}

/***************************************************/
/** PRIVATE METHODS ********************************/
/***************************************************/

void PTW_Arduino_Assert::printVerboseFailMessage(boolean actual, boolean expected) {
  if (_hardwareSerial) {
    if (expected) {
      _hardwareSerial->println("      Expected:  true");
      _hardwareSerial->println("      Actual:    false");
    } else {
      _hardwareSerial->println("      Expected:  false");
      _hardwareSerial->println("      Actual:    true");
    }
  }
}

void PTW_Arduino_Assert::printVerboseFailMessageHex(uint8_t actual, uint8_t expected) {
  if (_hardwareSerial) {
    _hardwareSerial->print("      Expected:  0x");
    if (expected < 0x10) _hardwareSerial->print("0"); // prevents only a nibble being printed
    _hardwareSerial->println(expected,HEX);
    _hardwareSerial->print("      Actual:    0x");
    if (actual < 0x10) _hardwareSerial->print("0"); // prevents only a nibble being printed
    _hardwareSerial->println(actual,HEX);
  }
}

void PTW_Arduino_Assert::printVerboseFailMessage(char actual, char expected) {
  if (_hardwareSerial) {
    _hardwareSerial->print("      Expected:  "); _hardwareSerial->println(expected);
    _hardwareSerial->print("      Actual:    "); _hardwareSerial->println(actual);
  }
}

void PTW_Arduino_Assert::printVerboseFailMessage(float actual, float expected) {
  if (_hardwareSerial) {
    _hardwareSerial->printf("      Expected:  %0.8f\n", expected);
    _hardwareSerial->printf("      Actual:    %0.8f\n", actual);
  }
}

void PTW_Arduino_Assert::printVerboseFailMessage(double actual, double expected) {
  if (_hardwareSerial) {
    _hardwareSerial->printf("      Expected:  %0.8f\n", expected);
    _hardwareSerial->printf("      Actual:    %0.8f\n", actual);
  }
}

void PTW_Arduino_Assert::printVerboseFailMessage(int actual, int expected) {
  if (_hardwareSerial) {
    _hardwareSerial->print("      Expected:  "); _hardwareSerial->println(expected);
    _hardwareSerial->print("      Actual:    "); _hardwareSerial->println(actual);
  }
}

void PTW_Arduino_Assert::printVerboseFailMessage(long actual, long expected) {
  if (_hardwareSerial) {
    _hardwareSerial->print("      Expected:  "); _hardwareSerial->println(expected);
    _hardwareSerial->print("      Actual:    "); _hardwareSerial->println(actual);
  }
}

void PTW_Arduino_Assert::printVerboseFailMessage(long long actual, long long expected) {
  if (_hardwareSerial) {
    _hardwareSerial->printf("      Expected:  ");
    if (expected < 0) _hardwareSerial->print("-");
    printLLNumber(expected, DEC); _hardwareSerial->println();
    _hardwareSerial->printf("      Actual:    ");
    if (expected < 0) _hardwareSerial->print("-");
    printLLNumber(actual, DEC); _hardwareSerial->println();
  }
}

void PTW_Arduino_Assert::printVerboseFailMessage(size_t actual, size_t expected) {
  if (_hardwareSerial) {
    _hardwareSerial->print("      Expected:  "); _hardwareSerial->println(expected);
    _hardwareSerial->print("      Actual:    "); _hardwareSerial->println(actual);
  }
}

void PTW_Arduino_Assert::printVerboseFailMessage(unsigned long actual, unsigned long expected) {
  if (_hardwareSerial) {
    _hardwareSerial->print("      Expected:  "); _hardwareSerial->println(expected);
    _hardwareSerial->print("      Actual:    "); _hardwareSerial->println(actual);
  }
}

void PTW_Arduino_Assert::printVerboseFailMessage(unsigned long long actual, unsigned long long expected) {
  if (_hardwareSerial) {
    _hardwareSerial->printf("      Expected:  "); printLLNumber(expected, DEC); _hardwareSerial->println();
    _hardwareSerial->printf("      Actual:    "); printLLNumber(actual, DEC); _hardwareSerial->println();
  }
}

void PTW_Arduino_Assert::printVerboseFailMessageIntBetween(int actual, int lower, int upper) {
  if (_hardwareSerial) {
    _hardwareSerial->print("      Expected:  Greater than "); _hardwareSerial->print(lower); _hardwareSerial->print(" and less than "); _hardwareSerial->println(upper);
    _hardwareSerial->print("      Actual:    "); _hardwareSerial->println(actual);
  }
}

void PTW_Arduino_Assert::printVerboseFailMessageIntBetweenInclusive(int actual, int lower, int upper) {
  if (_hardwareSerial) {
    _hardwareSerial->print("      Expected:  Greater than or equal to "); _hardwareSerial->print(lower); _hardwareSerial->print(" and less than or equal to "); _hardwareSerial->println(upper);
    _hardwareSerial->print("      Actual:    "); _hardwareSerial->println(actual);
  }
}

void PTW_Arduino_Assert::printVerboseFailMessageBuffer(char *actual, char *expected, int length) {
  for (int i = 0; i < length; i++) {
    if (_hardwareSerial) {
      _hardwareSerial->print("     Index: "); _hardwareSerial->println(i);
      _hardwareSerial->print("      Expected:  "); _hardwareSerial->println(expected[i]);
      _hardwareSerial->print("      Actual:    "); _hardwareSerial->println(actual[i]);
    }
  }
}

void PTW_Arduino_Assert::printVerboseFailMessageBuffer(uint8_t *actual, uint8_t *expected, int length) {
  for (int i = 0; i < length; i++) {
    if (_hardwareSerial) {
      if (actual[i]==expected[i]) {
        _hardwareSerial->print("     Index: "); _hardwareSerial->print(i);
        _hardwareSerial->print(" -  "); perfectPrintByteHex(actual[i]); Serial.println();
      } else {
        _hardwareSerial->print("     Index: "); _hardwareSerial->println(i);
        _hardwareSerial->print("      Expected:  "); perfectPrintByteHex(expected[i]); Serial.println();
        _hardwareSerial->print("      Actual:    "); perfectPrintByteHex(actual[i]); Serial.println();
      }
    }
  }
}

void PTW_Arduino_Assert::printVerboseFailMessage(String actual, String expected) {
  if (_hardwareSerial) {
    _hardwareSerial->print("      Expected:  "); _hardwareSerial->println(expected);
    _hardwareSerial->print("      Actual:    "); _hardwareSerial->println(actual);
  }
}

boolean PTW_Arduino_Assert::printTestResultWithMsg(boolean testPassed, const char *msg) {
  if (_hardwareSerial) {
    if (!testPassed) {
      _hardwareSerial->print("  Failed: ");
    } else {
      _hardwareSerial->print("   Passed - ");
    }
    _hardwareSerial->println(msg);
  }
  return testPassed;
}


boolean PTW_Arduino_Assert::printTestResultWithMsgAndLine(boolean testPassed, const char *msg, int lineNumber) {
  if (_hardwareSerial) {
    if (!testPassed) {
      // ** Failed - should...
      _hardwareSerial->print("  Failed: ");
      _hardwareSerial->println(msg);
      // (line: 380)
      _hardwareSerial->print("    line: ");
      _hardwareSerial->println(lineNumber);
    } else {
      _hardwareSerial->print("   Passed - ");
      _hardwareSerial->println(msg);
    }
  }
  return testPassed;
}

void PTW_Arduino_Assert::printLLNumber(unsigned long long n, uint8_t base) {
  unsigned char buf[16 * sizeof(long)]; // Assumes 8-bit chars.
  unsigned long long i = 0;

  if (n == 0) {
    Serial.print('0');
    return;
  }

  while (n > 0) {
    buf[i++] = n % base;
    n /= base;
  }

  for (; i > 0; i--)
    Serial.print((char) (buf[i - 1] < 10 ?
      '0' + buf[i - 1] :
      'A' + buf[i - 1] - 10));
}

void PTW_Arduino_Assert::perfectPrintByteHex(uint8_t b) {
  if (b <= 0x0F) {
    _hardwareSerial->print("0");
    _hardwareSerial->print(b, HEX);
  } else {
    _hardwareSerial->print(b, HEX);
  }
}

void PTW_Arduino_Assert::setSerial(HardwareSerial &serial) {
  _hardwareSerial = &serial;
}

// void PTW_Arduino_Assert::setSerial(SoftwareSerial *serial) {
//     serialType = SERIAL_SOFTWARE;
//     _softwareSerial = serial;
// }

// void PTW_Arduino_Assert::setSerial(USBSerial &serial) {
//     _usbSerial = &serial;
// }

PTW_Arduino_Assert test;
