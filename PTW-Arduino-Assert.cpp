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
// boolean PTW_Arduino_Assert::assertEqual(byte a, byte b) {
//     numberOfTests++;
//     boolean passed = (a == b);
//     if (passed) {
//         numberOfTestsPassed++;
//     } else {
//         numberOfTestsFailed++;
//     }
//     return passed;
// }
// boolean PTW_Arduino_Assert::assertEqual(byte a, byte b, char *msg) {
//     return printTestResultWithMsg(assertEqual(a, b), msg);
// }
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
// boolean PTW_Arduino_Assert::assertNotEqual(byte a, byte b) {
//     return !assertEqual(a,b);
// }
// boolean PTW_Arduino_Assert::assertNotEqual(byte a, byte b, char *msg) {
//     return printTestResultWithMsg(assertNotEqual(a, b), msg);
// }
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
// boolean PTW_Arduino_Assert::assertGreaterThan(byte a, byte b) {
//     numberOfTests++;
//     boolean passed = (a > b);
//     if (passed) {
//         numberOfTestsPassed++;
//     } else {
//         numberOfTestsFailed++;
//     }
//     return passed;
// }
// boolean PTW_Arduino_Assert::assertGreaterThan(byte a, byte b, char *msg) {
//     return printTestResultWithMsg(assertGreaterThan(a, b), msg);
// }
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
// boolean PTW_Arduino_Assert::assertLessThan(byte a, byte b) {
//     numberOfTests++;
//     boolean passed = (a < b);
//     if (passed) {
//         numberOfTestsPassed++;
//     } else {
//         numberOfTestsFailed++;
//     }
//     return passed;
// }
// boolean PTW_Arduino_Assert::assertLessThan(byte a, byte b, char *msg) {
//     return printTestResultWithMsg(assertLessThan(a, b), msg);
// }
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
    if (_usbSerial) {
        _usbSerial->println("-------------------------------");
        _usbSerial->println("-- PTW-Arduino-Assert v0.1.0 --");
        _usbSerial->println("-------------------------------");
        _usbSerial->println("------- AUTO TEST BEGIN -------");
        _usbSerial->println("-------------------------------");
    }
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
    if (_usbSerial) {
        _usbSerial->print(" #");
        _usbSerial->println(title);
    }
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
    if (_usbSerial) {
        _usbSerial->println("-------------------------------");
        _usbSerial->print("  Total Tests: ");
        _usbSerial->println(numberOfTests);
        _usbSerial->print("  Tests Passed: ");
        _usbSerial->println(numberOfTestsPassed);
        _usbSerial->print("  Tests Failed: ");
        _usbSerial->println(numberOfTestsFailed);
        _usbSerial->println("-------------------------------");
        _usbSerial->println("-------- AUTO TEST END --------");
        _usbSerial->println("-------------------------------");
    }
}

/***************************************************/
/** PRIVATE METHODS ********************************/
/***************************************************/

boolean PTW_Arduino_Assert::printTestResultWithMsg(boolean testPassed, char *msg) {
    if (_hardwareSerial) {
        if (!testPassed) {
            _hardwareSerial->print("   Failed - ");
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
    if (_usbSerial) {
        if (!testPassed) {
            _usbSerial->print("   Failed - ");
        } else {
            _usbSerial->print("   Passed - ");
        }
        _usbSerial->println(msg);
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

void PTW_Arduino_Assert::setSerial(USBSerial &serial) {
    _usbSerial = &serial;
}

PTW_Arduino_Assert test;
