/**
 * @abstract This library was created so I, AJ Keller, could do Test Driven
 *  Development (TDD) eaiser across the several different libraries I am working
 *  on and maintaing.
 * @author AJ Keller
 * @license MIT
 */

#ifndef _____PTW_Arduino_Assert__
#define _____PTW_Arduino_Assert__

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif


#define SERIAL_HARDWARE 0
#define SERIAL_SOFTWARE 1
#define SERIAL_USB 2

#define VERBOSE_NONE 0
#define VERBOSE_MAX 1

class PTW_Arduino_Assert {

public:
    PTW_Arduino_Assert();
    // EQUAL
    boolean assertEqualBoolean(boolean actual, boolean expected);
    boolean assertEqualBoolean(boolean actual, boolean expected, char *msg);
    // boolean assertEqual(byte actual, byte expected);
    // boolean assertEqual(byte actual, byte expected, char *msg);
    boolean assertEqualChar(char actual, char expected);
    boolean assertEqualChar(char actual, char expected, char *msg);
    boolean assertEqualInt(int actual, int expected);
    boolean assertEqualInt(int actual, int expected, char *msg);
    // NOT EQUAL
    boolean assertNotEqualBoolean(boolean actual, boolean expected);
    boolean assertNotEqualBoolean(boolean actual, boolean expected, char *msg);
    // boolean assertNotEqual(byte actual, byte expected);
    // boolean assertNotEqual(byte actual, byte expected, char *msg);
    boolean assertNotEqualChar(char actual, char expected);
    boolean assertNotEqualChar(char actual, char expected, char *msg);
    boolean assertNotEqualInt(int actual, int expected);
    boolean assertNotEqualInt(int actual, int expected, char *msg);
    // GREATER THAN
    boolean assertGreaterThanBoolean(boolean actual, boolean expected);
    boolean assertGreaterThanBoolean(boolean actual, boolean expected, char *msg);
    // boolean assertGreaterThan(byte actual, byte expected);
    // boolean assertGreaterThan(byte actual, byte expected, char *msg);
    boolean assertGreaterThanChar(char actual, char expected);
    boolean assertGreaterThanChar(char actual, char expected, char *msg);
    boolean assertGreaterThanInt(int actual, int expected);
    boolean assertGreaterThanInt(int actual, int expected, char *msg);
    // LESS THAN
    boolean assertLessThanBoolean(boolean actual, boolean expected);
    boolean assertLessThanBoolean(boolean actual, boolean expected, char *msg);
    // boolean assertLessThan(byte actual, byte expected);
    // boolean assertLessThan(byte actual, byte expected, char *msg);
    boolean assertLessThanChar(char actual, char expected);
    boolean assertLessThanChar(char actual, char expected, char *msg);
    boolean assertLessThanInt(int actual, int expected);
    boolean assertLessThanInt(int actual, int expected, char *msg);

    void begin(void);
    void end(void);
    void describe(char *title);

    void printVerboseFailMessageBoolean(boolean actual, boolean expected);
    void printVerboseFailMessageChar(char actual, char expected);
    void printVerboseFailMessageInt(int actual, int expected);

    // void setSerial(USBSerial &serial);
    void setSerial(HardwareSerial &serial);
    // void setSerial(SoftwareSerial *serial);

    byte failVerbosity;

private:
    HardwareSerial *_hardwareSerial;
    // SoftwareSerial *_softwareSerial;

    // USBSerial *_usbSerial;
    byte serialType;
    boolean printTestResultWithMsg(boolean testPassed, char *msg);
    int numberOfTests;
    int numberOfTestsFailed;
    int numberOfTestsPassed;
};

// This let's us call into the class from within the library if necessary
extern PTW_Arduino_Assert test;

#endif
