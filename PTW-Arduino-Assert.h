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
    boolean assertEqualBoolean(boolean, boolean);
    boolean assertEqualBoolean(boolean, boolean, char *);
    boolean assertEqualByte(byte, byte);
    boolean assertEqualByte(byte, byte, char *);
    boolean assertEqualChar(char, char);
    boolean assertEqualChar(char, char, char *);
    boolean assertEqualInt(int, int);
    boolean assertEqualInt(int, int, char *);
    // NOT EQUAL
    boolean assertNotEqualBoolean(boolean, boolean);
    boolean assertNotEqualBoolean(boolean, boolean, char *);
    boolean assertNotEqualByte(byte, byte);
    boolean assertNotEqualByte(byte, byte, char *);
    boolean assertNotEqualChar(char, char);
    boolean assertNotEqualChar(char, char, char *);
    boolean assertNotEqualInt(int, int);
    boolean assertNotEqualInt(int, int, char *);
    // GREATER THAN
    boolean assertGreaterThanBoolean(boolean, boolean);
    boolean assertGreaterThanBoolean(boolean, boolean, char *);
    boolean assertGreaterThanByte(byte, byte);
    boolean assertGreaterThanByte(byte, byte, char *);
    boolean assertGreaterThanChar(char, char);
    boolean assertGreaterThanChar(char, char, char *);
    boolean assertGreaterThanInt(int, int);
    boolean assertGreaterThanInt(int, int, char *);
    // LESS THAN
    boolean assertLessThanBoolean(boolean, boolean);
    boolean assertLessThanBoolean(boolean, boolean, char *);
    boolean assertLessThanByte(byte, byte);
    boolean assertLessThanByte(byte, byte, char *);
    boolean assertLessThanChar(char, char);
    boolean assertLessThanChar(char, char, char *);
    boolean assertLessThanInt(int, int);
    boolean assertLessThanInt(int, int, char *);

    boolean assertBufferEqual(char *, char *, int);
    boolean assertBufferEqual(char *, char *, int, char *);

    void begin(void);
    void end(void);
    void describe(char *title);
    void detail(char *);

    void printVerboseFailMessageBoolean(boolean, boolean);
    void printVerboseFailMessageBuffer(char *, char *, int length);
    void printVerboseFailMessageByte(byte, byte);
    void printVerboseFailMessageChar(char, char);
    void printVerboseFailMessageInt(int, int);

    // void setSerial(USBSerial &serial);
    void setSerial(HardwareSerial &serial);
    // void setSerial(SoftwareSerial *serial);

    byte failVerbosity;

private:
    HardwareSerial *_hardwareSerial;
    // SoftwareSerial *_softwareSerial;

    // USBSerial *_usbSerial;
    byte serialType;
    boolean printTestResultWithMsg(boolean, char *msg);
    int numberOfTests;
    int numberOfTestsFailed;
    int numberOfTestsPassed;
};

// This let's us call into the class from within the library if necessary
extern PTW_Arduino_Assert test;

#endif
