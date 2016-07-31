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
boolean PTW_Arduino_Assert::assertBoolean(boolean actual, boolean expected, char *msg) {
    boolean testPassed = printTestResultWithMsg(assertBoolean(actual, expected), msg);

    if (failVerbosity && !testPassed) {
        printVerboseFailMessageBoolean(actual,expected);
    }

    return testPassed;
}
boolean PTW_Arduino_Assert::assertBoolean(boolean actual, boolean expected, char *msg, int lineNumber) {
    boolean testPassed = printTestResultWithMsgAndLine(assertBoolean(actual, expected), msg, lineNumber);

    if (failVerbosity && !testPassed) {
        printVerboseFailMessageBoolean(actual,expected);
    }

    return testPassed;
}
// buffer
boolean PTW_Arduino_Assert::assertEqualBuffer(char *actual, char *expected, int length) {
    boolean pass = true;
    for (int i = 0; i < length; i++) {
        if (actual[i] != expected[i]) {
            pass = false;
        }
    }
    return pass;
}

boolean PTW_Arduino_Assert::assertEqualBuffer(char *actual, char *expected, int length, char *msg) {
    boolean testPassed = printTestResultWithMsg(assertEqualBuffer(actual, expected, length), msg);

    if (failVerbosity && !testPassed) {
        printVerboseFailMessageBuffer(actual, expected, length);
    }

    return testPassed;
}
boolean PTW_Arduino_Assert::assertEqualBuffer(char *actual, char *expected, int length, char *msg, int lineNumber) {
    boolean testPassed = printTestResultWithMsgAndLine(assertEqualBuffer(actual, expected, length), msg, lineNumber);

    if (failVerbosity && !testPassed) {
        printVerboseFailMessageBuffer(actual, expected, length);
    }

    return testPassed;
}
//  byte
boolean PTW_Arduino_Assert::assertEqualByte(byte actual, byte expected) {
    numberOfTests++;
    boolean passed = (actual == expected);
    if (passed) {
        numberOfTestsPassed++;
    } else {
        numberOfTestsFailed++;
    }
    return passed;
}
boolean PTW_Arduino_Assert::assertEqualByte(byte actual, byte expected, char *msg) {
    boolean testPassed = printTestResultWithMsg(assertEqualByte(actual, expected), msg);

    if (failVerbosity && !testPassed) {
        printVerboseFailMessageByte(actual,expected);
    }

    return testPassed;
}
boolean PTW_Arduino_Assert::assertEqualByte(byte actual, byte expected, char *msg, int lineNumber) {
    boolean testPassed = printTestResultWithMsgAndLine(assertEqualByte(actual, expected), msg, lineNumber);

    if (failVerbosity && !testPassed) {
        printVerboseFailMessageByte(actual,expected);
    }

    return testPassed;
}
//  char
boolean PTW_Arduino_Assert::assertEqualChar(char actual, char expected) {
    numberOfTests++;
    boolean passed = (actual == expected);
    if (passed) {
        numberOfTestsPassed++;
    } else {
        numberOfTestsFailed++;
    }
    return passed;
}
boolean PTW_Arduino_Assert::assertEqualChar(char actual, char expected, char *msg) {
    boolean testPassed = printTestResultWithMsg(assertEqualChar(actual, expected), msg);

    if (failVerbosity && !testPassed) {
        printVerboseFailMessageChar(actual,expected);
    }

    return testPassed;
}
boolean PTW_Arduino_Assert::assertEqualChar(char actual, char expected, char *msg, int lineNumber) {
    boolean testPassed = printTestResultWithMsgAndLine(assertEqualChar(actual, expected), msg, lineNumber);

    if (failVerbosity && !testPassed) {
        printVerboseFailMessageChar(actual,expected);
    }

    return testPassed;
}
//  int
boolean PTW_Arduino_Assert::assertEqualInt(int actual, int expected) {
    numberOfTests++;
    boolean passed = (actual == expected);
    if (passed) {
        numberOfTestsPassed++;
    } else {
        numberOfTestsFailed++;
    }
    return passed;
}
boolean PTW_Arduino_Assert::assertEqualInt(int actual, int expected, char *msg) {
    boolean testPassed = printTestResultWithMsg(assertEqualInt(actual, expected), msg);

    if (failVerbosity && !testPassed) {
        printVerboseFailMessageInt(actual,expected);
    }

    return testPassed;
}
boolean PTW_Arduino_Assert::assertEqualInt(int actual, int expected, char *msg, int lineNumber) {
    boolean testPassed = printTestResultWithMsgAndLine(assertEqualInt(actual, expected), msg, lineNumber);

    if (failVerbosity && !testPassed) {
        printVerboseFailMessageInt(actual,expected);
    }

    return testPassed;
}

// NOT EQUAL
//  buffer
boolean PTW_Arduino_Assert::assertNotEqualBuffer(char *actual, char *expected, int length) {
    return !assertEqualBuffer(actual,expected,length);
}

boolean PTW_Arduino_Assert::assertNotEqualBuffer(char *actual, char *expected, int length, char *msg) {
    boolean testPassed = printTestResultWithMsg(assertNotEqualBuffer(actual, expected, length), msg);

    if (failVerbosity && !testPassed) {
        printVerboseFailMessageBuffer(actual,expected, length);
    }

    return testPassed;
}
boolean PTW_Arduino_Assert::assertNotEqualBuffer(char *actual, char *expected, int length, char *msg, int lineNumber) {
    boolean testPassed = printTestResultWithMsgAndLine(assertNotEqualBuffer(actual, expected, length), msg, lineNumber);

    if (failVerbosity && !testPassed) {
        printVerboseFailMessageBuffer(actual,expected, length);
    }

    return testPassed;
}
//  byte
boolean PTW_Arduino_Assert::assertNotEqualByte(byte actual, byte expected) {
    return !assertEqualChar(actual,expected);
}
boolean PTW_Arduino_Assert::assertNotEqualByte(byte actual, byte expected, char *msg) {
    boolean testPassed = printTestResultWithMsg(assertNotEqualByte(actual, expected), msg);

    if (failVerbosity && !testPassed) {
        printVerboseFailMessageByte(actual,expected);
    }

    return testPassed;
}
boolean PTW_Arduino_Assert::assertNotEqualByte(byte actual, byte expected, char *msg, int lineNumber) {
    boolean testPassed = printTestResultWithMsgAndLine(assertNotEqualByte(actual, expected), msg, lineNumber);

    if (failVerbosity && !testPassed) {
        printVerboseFailMessageByte(actual,expected);
    }

    return testPassed;
}
//  char
boolean PTW_Arduino_Assert::assertNotEqualChar(char actual, char expected) {
    numberOfTests++;
    boolean passed = (actual != expected);
    if (passed) {
        numberOfTestsPassed++;
    } else {
        numberOfTestsFailed++;
    }
    return passed;
}
boolean PTW_Arduino_Assert::assertNotEqualChar(char actual, char expected, char *msg) {
    boolean testPassed = printTestResultWithMsg(assertNotEqualChar(actual, expected), msg);

    if (failVerbosity && !testPassed) {
        printVerboseFailMessageChar(actual,expected);
    }

    return testPassed;
}
boolean PTW_Arduino_Assert::assertNotEqualChar(char actual, char expected, char *msg, int lineNumber) {
    boolean testPassed = printTestResultWithMsgAndLine(assertNotEqualChar(actual, expected), msg, lineNumber);

    if (failVerbosity && !testPassed) {
        printVerboseFailMessageChar(actual,expected);
    }

    return testPassed;
}
//  int
boolean PTW_Arduino_Assert::assertNotEqualInt(int actual, int expected) {
    return !assertEqualInt(actual,expected);
}
boolean PTW_Arduino_Assert::assertNotEqualInt(int actual, int expected, char *msg) {
    boolean testPassed = printTestResultWithMsg(assertNotEqualInt(actual, expected), msg);

    if (failVerbosity && !testPassed) {
        printVerboseFailMessageInt(actual,expected);
    }

    return testPassed;
}
boolean PTW_Arduino_Assert::assertNotEqualInt(int actual, int expected, char *msg, int lineNumber) {
    boolean testPassed = printTestResultWithMsgAndLine(assertNotEqualInt(actual, expected), msg, lineNumber);

    if (failVerbosity && !testPassed) {
        printVerboseFailMessageInt(actual,expected);
    }

    return testPassed;
}

// GREATER THAN
//  byte
boolean PTW_Arduino_Assert::assertGreaterThanByte(byte actual, byte expected) {
    numberOfTests++;
    boolean passed = (actual > expected);
    if (passed) {
        numberOfTestsPassed++;
    } else {
        numberOfTestsFailed++;
    }
    return passed;
}
boolean PTW_Arduino_Assert::assertGreaterThanByte(byte actual, byte expected, char *msg) {
    boolean testPassed = printTestResultWithMsg(assertGreaterThanByte(actual, expected), msg);

    if (failVerbosity && !testPassed) {
        printVerboseFailMessageByte(actual,expected);
    }

    return testPassed;
}
boolean PTW_Arduino_Assert::assertGreaterThanByte(byte actual, byte expected, char *msg, int lineNumber) {
    boolean testPassed = printTestResultWithMsgAndLine(assertGreaterThanByte(actual, expected), msg, lineNumber);

    if (failVerbosity && !testPassed) {
        printVerboseFailMessageByte(actual,expected);
    }

    return testPassed;
}
//  char
boolean PTW_Arduino_Assert::assertGreaterThanChar(char actual, char expected) {
    numberOfTests++;
    boolean passed = (actual > expected);
    if (passed) {
        numberOfTestsPassed++;
    } else {
        numberOfTestsFailed++;
    }
    return passed;
}
boolean PTW_Arduino_Assert::assertGreaterThanChar(char actual, char expected, char *msg) {
    boolean testPassed = printTestResultWithMsg(assertGreaterThanChar(actual, expected), msg);

    if (failVerbosity && !testPassed) {
        printVerboseFailMessageChar(actual,expected);
    }

    return testPassed;
}
boolean PTW_Arduino_Assert::assertGreaterThanChar(char actual, char expected, char *msg, int lineNumber) {
    boolean testPassed = printTestResultWithMsgAndLine(assertGreaterThanChar(actual, expected), msg, lineNumber);

    if (failVerbosity && !testPassed) {
        printVerboseFailMessageChar(actual,expected);
    }

    return testPassed;
}
//  int
boolean PTW_Arduino_Assert::assertGreaterThanInt(int actual, int expected) {
    numberOfTests++;
    boolean passed = (actual > expected);
    if (passed) {
        numberOfTestsPassed++;
    } else {
        numberOfTestsFailed++;
    }
    return passed;
}
boolean PTW_Arduino_Assert::assertGreaterThanInt(int actual, int expected, char *msg) {
    boolean testPassed = printTestResultWithMsg(assertGreaterThanInt(actual, expected), msg);

    if (failVerbosity && !testPassed) {
        printVerboseFailMessageInt(actual,expected);
    }

    return testPassed;
}
boolean PTW_Arduino_Assert::assertGreaterThanInt(int actual, int expected, char *msg, int lineNumber) {
    boolean testPassed = printTestResultWithMsgAndLine(assertGreaterThanInt(actual, expected), msg, lineNumber);

    if (failVerbosity && !testPassed) {
        printVerboseFailMessageInt(actual,expected);
    }

    return testPassed;
}
// LESS THAN
//  byte
boolean PTW_Arduino_Assert::assertLessThanByte(byte actual, byte expected) {
    numberOfTests++;
    boolean passed = (actual < expected);
    if (passed) {
        numberOfTestsPassed++;
    } else {
        numberOfTestsFailed++;
    }
    return passed;
}
boolean PTW_Arduino_Assert::assertLessThanByte(byte actual, byte expected, char *msg) {
    boolean testPassed = printTestResultWithMsg(assertLessThanByte(actual, expected), msg);

    if (failVerbosity && !testPassed) {
        printVerboseFailMessageByte(actual,expected);
    }

    return testPassed;
}
boolean PTW_Arduino_Assert::assertLessThanByte(byte actual, byte expected, char *msg, int lineNumber) {
    boolean testPassed = printTestResultWithMsgAndLine(assertLessThanByte(actual, expected), msg, lineNumber);

    if (failVerbosity && !testPassed) {
        printVerboseFailMessageByte(actual,expected);
    }

    return testPassed;
}
//  char
boolean PTW_Arduino_Assert::assertLessThanChar(char actual, char expected) {
    numberOfTests++;
    boolean passed = (actual < expected);
    if (passed) {
        numberOfTestsPassed++;
    } else {
        numberOfTestsFailed++;
    }
    return passed;
}
boolean PTW_Arduino_Assert::assertLessThanChar(char actual, char expected, char *msg) {
    boolean testPassed = printTestResultWithMsg(assertLessThanChar(actual, expected), msg);

    if (failVerbosity && !testPassed) {
        printVerboseFailMessageChar(actual,expected);
    }

    return testPassed;
}
boolean PTW_Arduino_Assert::assertLessThanChar(char actual, char expected, char *msg, int lineNumber) {
    boolean testPassed = printTestResultWithMsgAndLine(assertLessThanChar(actual, expected), msg, lineNumber);

    if (failVerbosity && !testPassed) {
        printVerboseFailMessageChar(actual,expected);
    }

    return testPassed;
}
//  int
boolean PTW_Arduino_Assert::assertLessThanInt(int actual, int expected) {
    numberOfTests++;
    boolean passed = (actual < expected);
    if (passed) {
        numberOfTestsPassed++;
    } else {
        numberOfTestsFailed++;
    }
    return passed;
}
boolean PTW_Arduino_Assert::assertLessThanInt(int actual, int expected, char *msg) {
    boolean testPassed = printTestResultWithMsg(assertLessThanInt(actual, expected), msg);

    if (failVerbosity && !testPassed) {
        printVerboseFailMessageInt(actual,expected);
    }

    return testPassed;
}
boolean PTW_Arduino_Assert::assertLessThanInt(int actual, int expected, char *msg, int lineNumber) {
    boolean testPassed = printTestResultWithMsgAndLine(assertLessThanInt(actual, expected), msg, lineNumber);

    if (failVerbosity && !testPassed) {
        printVerboseFailMessageInt(actual,expected);
    }

    return testPassed;
}

// Between
boolean PTW_Arduino_Assert::assertBetweenInt(int actual, int lower, int upper) {
    numberOfTests++;
    boolean passed = (actual > lower) && (actual < upper);
    if (passed) {
        numberOfTestsPassed++;
    } else {
        numberOfTestsFailed++;
    }
    return passed;
}
boolean PTW_Arduino_Assert::assertBetweenInt(int actual, int lower, int upper, char *msg) {
    boolean testPassed = printTestResultWithMsg(assertBetweenInt(actual, lower, upper), msg);

    if (failVerbosity && !testPassed) {
        printVerboseFailMessageIntBetween(actual,lower,upper);
    }

    return testPassed;
}
boolean PTW_Arduino_Assert::assertBetweenInt(int actual, int lower, int upper, char *msg, int lineNumber) {
    boolean testPassed = printTestResultWithMsgAndLine(assertBetweenInt(actual, lower, upper), msg, lineNumber);

    if (failVerbosity && !testPassed) {
        printVerboseFailMessageIntBetween(actual,lower,upper);
    }

    return testPassed;
}
boolean PTW_Arduino_Assert::assertBetweenInclusiveInt(int actual, int lower, int upper) {
    numberOfTests++;
    boolean passed = (actual >= lower) && (actual <= upper);
    if (passed) {
        numberOfTestsPassed++;
    } else {
        numberOfTestsFailed++;
    }
    return passed;
}
boolean PTW_Arduino_Assert::assertBetweenInclusiveInt(int actual, int lower, int upper, char *msg) {
    boolean testPassed = printTestResultWithMsg(assertBetweenInt(actual, lower, upper), msg);

    if (failVerbosity && !testPassed) {
        printVerboseFailMessageIntBetweenInclusive(actual,lower,upper);
    }

    return testPassed;
}
boolean PTW_Arduino_Assert::assertBetweenInclusiveInt(int actual, int lower, int upper, char *msg, int lineNumber) {
    boolean testPassed = printTestResultWithMsgAndLine(assertBetweenInt(actual, lower, upper), msg, lineNumber);

    if (failVerbosity && !testPassed) {
        printVerboseFailMessageIntBetweenInclusive(actual,lower,upper);
    }

    return testPassed;
}
void PTW_Arduino_Assert::begin(void) {
    if (_hardwareSerial) {
        _hardwareSerial->println("-------------------------------");
        _hardwareSerial->println("-- PTW-Arduino-Assert v0.3.2 --");
        _hardwareSerial->println("-------------------------------");
        _hardwareSerial->println("------- AUTO TEST BEGIN -------");
        _hardwareSerial->println("-------------------------------");
    }
    // if (_softwareSerial) {
    //     _softwareSerial.println("-------------------------------");
    //     _softwareSerial.println("-- PTW-Arduino-Assert v0.3.2 --");
    //     _softwareSerial.println("-------------------------------");
    //     _softwareSerial.println("------- AUTO TEST BEGIN -------");
    //     _softwareSerial.println("-------------------------------");
    // }
    // if (_usbSerial) {
    //     _usbSerial->println("-------------------------------");
    //     _usbSerial->println("-- PTW-Arduino-Assert v0.3.2 --");
    //     _usbSerial->println("-------------------------------");
    //     _usbSerial->println("------- AUTO TEST BEGIN -------");
    //     _usbSerial->println("-------------------------------");
    // }
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

void PTW_Arduino_Assert::printVerboseFailMessageBoolean(boolean actual, boolean expected) {
    if (_hardwareSerial) {
        if (expected) {
            _hardwareSerial->println("      Expected - true");
            _hardwareSerial->println("      Actual   - false");
        } else {
            _hardwareSerial->println("      Expected - false");
            _hardwareSerial->println("      Actual   - true");
        }
    }
}

void PTW_Arduino_Assert::printVerboseFailMessageByte(byte actual, byte expected) {
    if (_hardwareSerial) {
        _hardwareSerial->print("      Expected - 0x");
        if (expected < 0x10) _hardwareSerial->print("0"); // prevents only a nibble being printed
        _hardwareSerial->println(expected,HEX);
        _hardwareSerial->print("      Actual   - 0x");
        if (actual < 0x10) _hardwareSerial->print("0"); // prevents only a nibble being printed
        _hardwareSerial->println(actual,HEX);
    }
}

void PTW_Arduino_Assert::printVerboseFailMessageChar(char actual, char expected) {
    if (_hardwareSerial) {
        _hardwareSerial->print("      Expected - "); _hardwareSerial->println(expected);
        _hardwareSerial->print("      Actual   - "); _hardwareSerial->println(actual);
    }
}

void PTW_Arduino_Assert::printVerboseFailMessageInt(int actual, int expected) {
    if (_hardwareSerial) {
        _hardwareSerial->print("      Expected - "); _hardwareSerial->println(expected);
        _hardwareSerial->print("      Actual   - "); _hardwareSerial->println(actual);
    }
}

void PTW_Arduino_Assert::printVerboseFailMessageIntBetween(int actual, int lower, int upper) {
    if (_hardwareSerial) {
        _hardwareSerial->print("      Expected - Greater than "); _hardwareSerial->print(lower); _hardwareSerial->print(" and less than "); _hardwareSerial->println(upper);
        _hardwareSerial->print("      Actual   - "); _hardwareSerial->println(actual);
    }
}

void PTW_Arduino_Assert::printVerboseFailMessageIntBetweenInclusive(int actual, int lower, int upper) {
    if (_hardwareSerial) {
        _hardwareSerial->print("      Expected - Greater than or equal to "); _hardwareSerial->print(lower); _hardwareSerial->print(" and less than or equal to "); _hardwareSerial->println(upper);
        _hardwareSerial->print("      Actual   - "); _hardwareSerial->println(actual);
    }
}

void PTW_Arduino_Assert::printVerboseFailMessageBuffer(char *actual, char *expected, int length) {
    for (int i = 0; i < length; i++) {
        if (_hardwareSerial) {
            _hardwareSerial->print("     Index: "); _hardwareSerial->println(i);
            _hardwareSerial->print("      Expected - "); _hardwareSerial->println(expected[i]);
            _hardwareSerial->print("      Actual   - "); _hardwareSerial->println(actual[i]);
        }
    }
}


boolean PTW_Arduino_Assert::printTestResultWithMsg(boolean testPassed, char *msg) {
    if (_hardwareSerial) {
        if (!testPassed) {
            _hardwareSerial->print(" ** Failed - ");
        } else {
            _hardwareSerial->print("   Passed - ");
        }
        _hardwareSerial->println(msg);
    }
    // if (_softwareSerial) {
    //     if (!testPassed) {
    //         _softwareSerial.print("   Failed - ");
    //     } else {
    //         _softwareSerial.print("   Passed - ");
    //     }
    //     _softwareSerial.println(msg);
    // }
    // if (_usbSerial) {
    //     if (!testPassed) {
    //         _usbSerial->print(" ** Failed - ");
    //     } else {
    //         _usbSerial->print("   Passed - ");
    //     }
    //     _usbSerial->println(msg);
    // }
    return testPassed;
}


boolean PTW_Arduino_Assert::printTestResultWithMsgAndLine(boolean testPassed, char *msg, int lineNumber) {
    if (_hardwareSerial) {
        if (!testPassed) {
            // ** Failed - should...
            _hardwareSerial->print(" ** Failed - ");
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
