/**
 * @abstract This library was created so I, AJ Keller, could do Test Driven
 *  Development (TDD) eaiser across the several different libraries I am working
 *  on and maintaing.
 * @author AJ Keller
 * @license MIT
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
boolean PTW_Arduino_Assert::assertEqualBoolean(boolean actual, boolean expected) {
    numberOfTests++;
    boolean passed = (actual == expected);
    if (passed) {
        numberOfTestsPassed++;
    } else {
        numberOfTestsFailed++;
    }
    return passed;
}
boolean PTW_Arduino_Assert::assertEqualBoolean(boolean actual, boolean expected, char *msg) {
    boolean testPassed = printTestResultWithMsg(assertEqualBoolean(actual, expected), msg);

    if (failVerbosity) {
        printVerboseFailMessageBoolean(actual,expected);
    }

    return testPassed;
}
//  byte
// boolean PTW_Arduino_Assert::assertEqual(byte actual, byte expected) {
//     numberOfTests++;
//     boolean passed = (actual == expected);
//     if (passed) {
//         numberOfTestsPassed++;
//     } else {
//         numberOfTestsFailed++;
//     }
//     return passed;
// }
// boolean PTW_Arduino_Assert::assertEqual(byte actual, byte expected, char *msg) {
//     return printTestResultWithMsg(assertEqual(actual, expected), msg);
// }
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
    boolean testPassed = printTestResultWithMsg(assertEqualChar(actual, expected), msg)

    if (failVerbosity) {
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
    boolean testPassed = printTestResultWithMsg(assertEqualInt(actual, expected), msg)

    if (failVerbosity) {
        printVerboseFailMessageInt(actual,expected);
    }

    return testPassed;
}

// NOT EQUAL
//  boolean
boolean PTW_Arduino_Assert::assertNotEqualBoolean(boolean actual, boolean expected) {
    return !assertEqualBoolean(actual,expected);
}
boolean PTW_Arduino_Assert::assertNotEqualBoolean(boolean actual, boolean expected, char *msg) {
    boolean testPassed = printTestResultWithMsg(assertNotEqualBoolean(actual, expected), msg);

    if (failVerbosity) {
        printVerboseFailMessageBoolean(actual,expected);
    }

    return testPassed;
}
//  byte
// boolean PTW_Arduino_Assert::assertNotEqual(byte actual, byte expected) {
//     return !assertEqual(actual,expected);
// }
// boolean PTW_Arduino_Assert::assertNotEqual(byte actual, byte expected, char *msg) {
//     return printTestResultWithMsg(assertNotEqual(actual, expected), msg);
// }
//  char
boolean PTW_Arduino_Assert::assertNotEqualChar(char actual, char expected) {
    return !assertEqualChar(actual,expected);
}
boolean PTW_Arduino_Assert::assertNotEqualChar(char actual, char expected, char *msg) {
    boolean testPassed = printTestResultWithMsg(assertNotEqualChar(actual, expected), msg)

    if (failVerbosity) {
        printVerboseFailMessageChar(actual,expected);
    }

    return testPassed;
}
//  int
boolean PTW_Arduino_Assert::assertNotEqualInt(int actual, int expected) {
    return !assertEqualInt(actual,expected);
}
boolean PTW_Arduino_Assert::assertNotEqualInt(int actual, int expected, char *msg) {
    boolean testPassed = printTestResultWithMsg(assertNotEqualInt(actual, expected), msg)

    if (failVerbosity) {
        printVerboseFailMessageInt(actual,expected);
    }

    return testPassed;
}

// GREATER THAN
//  boolean
boolean PTW_Arduino_Assert::assertGreaterThanBoolean(boolean actual, boolean expected) {
    numberOfTests++;
    boolean passed = (actual > expected);
    if (passed) {
        numberOfTestsPassed++;
    } else {
        numberOfTestsFailed++;
    }
    return passed;
}
boolean PTW_Arduino_Assert::assertGreaterThanBoolean(boolean actual, boolean expected, char *msg) {
    boolean testPassed = printTestResultWithMsg(assertGreaterThanBoolean(actual, expected), msg)

    if (failVerbosity) {
        printVerboseFailMessageBoolean(actual,expected);
    }

    return testPassed;
}
//  byte
// boolean PTW_Arduino_Assert::assertGreaterThan(byte actual, byte expected) {
//     numberOfTests++;
//     boolean passed = (actual > expected);
//     if (passed) {
//         numberOfTestsPassed++;
//     } else {
//         numberOfTestsFailed++;
//     }
//     return passed;
// }
// boolean PTW_Arduino_Assert::assertGreaterThan(byte actual, byte expected, char *msg) {
//     return printTestResultWithMsg(assertGreaterThan(actual, expected), msg);
// }
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
boolean PTW_Arduino_Assert::assertGreaterThan(char actual, char expected, char *msg) {
    boolean testPassed = printTestResultWithMsg(assertGreaterThan(actual, expected), msg)

    if (failVerbosity) {
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
    boolean testPassed = printTestResultWithMsg(assertGreaterThanInt(actual, expected), msg)

    if (failVerbosity) {
        printVerboseFailMessageInt(actual,expected);
    }

    return testPassed;
}

// LESS THAN
//  boolean
boolean PTW_Arduino_Assert::assertLessThanBoolean(boolean actual, boolean expected) {
    numberOfTests++;
    boolean passed = (actual < expected);
    if (passed) {
        numberOfTestsPassed++;
    } else {
        numberOfTestsFailed++;
    }
    return passed;
}
boolean PTW_Arduino_Assert::assertLessThanBoolean(boolean actual, boolean expected, char *msg) {
    boolean testPassed = printTestResultWithMsg(assertLessThanBoolean(actual, expected), msg)

    if (failVerbosity) {
        printVerboseFailMessageBoolean(actual,expected);
    }

    return testPassed;
}
//  byte
// boolean PTW_Arduino_Assert::assertLessThan(byte actual, byte expected) {
//     numberOfTests++;
//     boolean passed = (actual < expected);
//     if (passed) {
//         numberOfTestsPassed++;
//     } else {
//         numberOfTestsFailed++;
//     }
//     return passed;
// }
// boolean PTW_Arduino_Assert::assertLessThan(byte actual, byte expected, char *msg) {
//     return printTestResultWithMsg(assertLessThan(actual, expected), msg);
// }
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
    boolean testPassed = printTestResultWithMsg(assertLessThanChar(actual, expected), msg)

    if (failVerbosity) {
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
    boolean testPassed = printTestResultWithMsg(assertLessThanInt(actual, expected), msg)

    if (failVerbosity) {
        printVerboseFailMessageInt(actual,expected);
    }

    return testPassed;
}

void PTW_Arduino_Assert::begin(void) {
    if (_hardwareSerial) {
        _hardwareSerial->println("-------------------------------");
        _hardwareSerial->println("-- PTW-Arduino-Assert v0.1.0 --");
        _hardwareSerial->println("-------------------------------");
        _hardwareSerial->println("------- AUTO TEST BEGIN -------");
        _hardwareSerial->println("-------------------------------");
    }
    // if (_softwareSerial) {
    //     _softwareSerial.println("-------------------------------");
    //     _softwareSerial.println("-- PTW-Arduino-Assert v0.1.0 --");
    //     _softwareSerial.println("-------------------------------");
    //     _softwareSerial.println("------- AUTO TEST BEGIN -------");
    //     _softwareSerial.println("-------------------------------");
    // }
    // if (_usbSerial) {
    //     _usbSerial->println("-------------------------------");
    //     _usbSerial->println("-- PTW-Arduino-Assert v0.1.0 --");
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
        _hardwareSerial->print(" #");
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
            _hardwareSerial->.print("      Expected - true");
            _hardwareSerial->.print("      Actual   - false");
        } else {
            _hardwareSerial->.print("      Expected - false");
            _hardwareSerial->.print("      Actual   - true");
        }
    }
}

void PTW_Arduino_Assert::printVerboseFailMessageChar(char actual, char expected) {
    if (_hardwareSerial) {
        _hardwareSerial->.print("      Expected - "); _hardwareSerial->println(expected);
        _hardwareSerial->.print("      Actual   - "); _hardwareSerial->println(actual);
    }
}

void PTW_Arduino_Assert::printVerboseFailMessageInt(int actual, int expected) {
    if (_hardwareSerial) {
        _hardwareSerial->.print("      Expected - "); _hardwareSerial->println(expected);
        _hardwareSerial->.print("      Actual   - "); _hardwareSerial->println(actual);
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
