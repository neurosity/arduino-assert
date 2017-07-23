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
    // FLOATS
    boolean assertApproximately(float, float, float);
    boolean assertApproximately(float, float, float, char *);
    boolean assertApproximately(double, double, double);
    boolean assertApproximately(double, double, double, char *);
    // EQUAL
    boolean assertBoolean(boolean, boolean);
    boolean assertBoolean(boolean, boolean, char *);
    boolean assertBoolean(boolean, boolean, char *, int);
    boolean assertEqual(unsigned long long, unsigned long long);
    boolean assertEqual(unsigned long long, unsigned long long, char *);
    boolean assertEqualBuffer(char *, char *, int);
    boolean assertEqualBuffer(char *, char *, int, char *);
    boolean assertEqualBuffer(char *, char *, int, char *, int);
    boolean assertEqualString(String, String);
    boolean assertEqualString(String, String, char *);
    boolean assertEqualByte(byte, byte);
    boolean assertEqualByte(byte, byte, char *);
    boolean assertEqualByte(byte, byte, char *, int);
    boolean assertEqualChar(char, char);
    boolean assertEqualChar(char, char, char *);
    boolean assertEqualChar(char, char, char *, int);
    boolean assertEqualInt(int, int);
    boolean assertEqualInt(int, int, char *);
    boolean assertEqualInt(int, int, char *, int);
    // NOT EQUAL
    boolean assertNotEqualBuffer(char *, char *, int);
    boolean assertNotEqualBuffer(char *, char *, int, char *);
    boolean assertNotEqualBuffer(char *, char *, int, char *, int);
    boolean assertNotEqualByte(byte, byte);
    boolean assertNotEqualByte(byte, byte, char *);
    boolean assertNotEqualByte(byte, byte, char *, int);
    boolean assertNotEqualChar(char, char);
    boolean assertNotEqualChar(char, char, char *);
    boolean assertNotEqualChar(char, char, char *, int);
    boolean assertNotEqualInt(int, int);
    boolean assertNotEqualInt(int, int, char *);
    boolean assertNotEqualInt(int, int, char *, int);
    // GREATER THAN
    boolean assertGreaterThanByte(byte, byte);
    boolean assertGreaterThanByte(byte, byte, char *);
    boolean assertGreaterThanByte(byte, byte, char *, int);
    boolean assertGreaterThanChar(char, char);
    boolean assertGreaterThanChar(char, char, char *);
    boolean assertGreaterThanChar(char, char, char *, int);
    boolean assertGreaterThanInt(int, int);
    boolean assertGreaterThanInt(int, int, char *);
    boolean assertGreaterThanInt(int, int, char *, int);
    // LESS THAN
    boolean assertLessThanByte(byte, byte);
    boolean assertLessThanByte(byte, byte, char *);
    boolean assertLessThanByte(byte, byte, char *, int);
    boolean assertLessThanChar(char, char);
    boolean assertLessThanChar(char, char, char *);
    boolean assertLessThanChar(char, char, char *, int);
    boolean assertLessThanInt(int, int);
    boolean assertLessThanInt(int, int, char *);
    boolean assertLessThanInt(int, int, char *, int);
    // Between
    boolean assertBetweenInt(int, int, int);
    boolean assertBetweenInt(int, int, int, char *);
    boolean assertBetweenInt(int, int, int, char *, int);
    boolean assertBetweenInclusiveInt(int, int, int);
    boolean assertBetweenInclusiveInt(int, int, int, char *);
    boolean assertBetweenInclusiveInt(int, int, int, char *, int);

    void begin(void);
    void end(void);
    void describe(char *title);
    void detail(char *);
    void it(char *);

    // void setSerial(USBSerial &serial);
    void setSerial(HardwareSerial &serial);
    // void setSerial(SoftwareSerial *serial);

    byte failVerbosity;

private:
    HardwareSerial *_hardwareSerial;

    void printLLNumber(unsigned long long, uint8_t);
    boolean printTestResultWithMsg(boolean, char *);
    boolean printTestResultWithMsgAndLine(boolean, char *, int);
    void printVerboseFailMessage(boolean, boolean);
    void printVerboseFailMessage(char, char);
    void printVerboseFailMessage(double, double);
    void printVerboseFailMessage(float, float);
    void printVerboseFailMessage(int, int);
    void printVerboseFailMessage(String, String);
    void printVerboseFailMessage(unsigned long long, unsigned long long);
    void printVerboseFailMessageHex(uint8_t, uint8_t);
    void printVerboseFailMessageBuffer(char *, char *, int);
    void printVerboseFailMessageIntBetween(int, int, int);
    void printVerboseFailMessageIntBetweenInclusive(int, int, int);

    byte serialType;
    int numberOfTests;
    int numberOfTestsFailed;
    int numberOfTestsPassed;
};

// This let's us call into the class from within the library if necessary
extern PTW_Arduino_Assert test;

#endif
