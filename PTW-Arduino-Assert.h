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
    boolean assertApproximately(float, float, float, const char *);
    boolean assertApproximately(double, double, double);
    boolean assertApproximately(double, double, double, const char *);
    // BOOLEAN
    boolean assertBoolean(boolean, boolean);
    boolean assertBoolean(boolean, boolean, const char *);
    boolean assertBoolean(boolean, boolean, const char *, int);
    boolean assertFalse(boolean);
    boolean assertFalse(boolean, const char *);
    boolean assertFalse(boolean, const char *, int);
    boolean assertTrue(boolean);
    boolean assertTrue(boolean, const char *);
    boolean assertTrue(boolean, const char *, int);
    // EQUAL
    boolean assertEqualBuffer(char *, char *, int);
    boolean assertEqualBuffer(char *, char *, int, const char *);
    boolean assertEqualBuffer(char *, char *, int, const char *, int);
    boolean assertEqualHex(byte, byte);
    boolean assertEqualHex(byte, byte, const char *);
    boolean assertEqualHex(byte, byte, const char *, int);
    boolean assertEqual(char, char);
    boolean assertEqual(char, char, const char *);
    boolean assertEqual(char, char, const char *, int);
    boolean assertEqual(int, int);
    boolean assertEqual(int, int, const char *);
    boolean assertEqual(int, int, const char *, int);
    boolean assertEqual(String, String);
    boolean assertEqual(String, String, const char *);
    boolean assertEqual(String, String, const char *, int);
    boolean assertEqual(long long, long long);
    boolean assertEqual(long long, long long, const char *);
    boolean assertEqual(long long, long long, const char *, int);
    boolean assertEqual(unsigned long long, unsigned long long);
    boolean assertEqual(unsigned long long, unsigned long long, const char *);
    boolean assertEqual(unsigned long long, unsigned long long, const char *, int);
    // NOT EQUAL
    boolean assertNotEqualBuffer(char *, char *, int);
    boolean assertNotEqualBuffer(char *, char *, int, const char *);
    boolean assertNotEqualBuffer(char *, char *, int, const char *, int);
    boolean assertNotEqualHex(byte, byte);
    boolean assertNotEqualHex(byte, byte, const char *);
    boolean assertNotEqualHex(byte, byte, const char *, int);
    boolean assertNotEqual(char, char);
    boolean assertNotEqual(char, char, const char *);
    boolean assertNotEqual(char, char, const char *, int);
    boolean assertNotEqual(int, int);
    boolean assertNotEqual(int, int, const char *);
    boolean assertNotEqual(int, int, const char *, int);
    boolean assertNotEqual(long long, long long);
    boolean assertNotEqual(long long, long long, const char *);
    boolean assertNotEqual(long long, long long, const char *, int);
    boolean assertNotEqual(unsigned long long, unsigned long long);
    boolean assertNotEqual(unsigned long long, unsigned long long, const char *);
    boolean assertNotEqual(unsigned long long, unsigned long long, const char *, int);
    // GREATER THAN
    boolean assertGreaterThanHex(uint8_t, uint8_t);
    boolean assertGreaterThanHex(uint8_t, uint8_t, const char *);
    boolean assertGreaterThanHex(uint8_t, uint8_t, const char *, int);
    boolean assertGreaterThan(char, char);
    boolean assertGreaterThan(char, char, const char *);
    boolean assertGreaterThan(char, char, const char *, int);
    boolean assertGreaterThan(int, int);
    boolean assertGreaterThan(int, int, const char *);
    boolean assertGreaterThan(int, int, const char *, int);
    boolean assertGreaterThan(long long, long long);
    boolean assertGreaterThan(long long, long long, const char *);
    boolean assertGreaterThan(long long, long long, const char *, int);
    boolean assertGreaterThan(unsigned long long, unsigned long long);
    boolean assertGreaterThan(unsigned long long, unsigned long long, const char *);
    boolean assertGreaterThan(unsigned long long, unsigned long long, const char *, int);
    // LESS THAN
    boolean assertLessThanHex(uint8_t, uint8_t);
    boolean assertLessThanHex(uint8_t, uint8_t, const char *);
    boolean assertLessThanHex(uint8_t, uint8_t, const char *, int);
    boolean assertLessThan(char, char);
    boolean assertLessThan(char, char, const char *);
    boolean assertLessThan(char, char, const char *, int);
    boolean assertLessThan(int, int);
    boolean assertLessThan(int, int, const char *);
    boolean assertLessThan(int, int, const char *, int);
    boolean assertLessThan(long long, long long);
    boolean assertLessThan(long long, long long, const char *);
    boolean assertLessThan(long long, long long, const char *, int);
    boolean assertLessThan(unsigned long long, unsigned long long);
    boolean assertLessThan(unsigned long long, unsigned long long, const char *);
    boolean assertLessThan(unsigned long long, unsigned long long, const char *, int);
    // Between
    boolean assertBetween(int, int, int);
    boolean assertBetween(int, int, int, const char *);
    boolean assertBetween(int, int, int, const char *, int);
    boolean assertBetweenInclusive(int, int, int);
    boolean assertBetweenInclusive(int, int, int, const char *);
    boolean assertBetweenInclusive(int, int, int, const char *, int);

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
    boolean printTestResultWithMsg(boolean, const char *);
    boolean printTestResultWithMsgAndLine(boolean, const char *, int);
    void printVerboseFailMessage(boolean, boolean);
    void printVerboseFailMessage(char, char);
    void printVerboseFailMessage(double, double);
    void printVerboseFailMessage(float, float);
    void printVerboseFailMessage(int, int);
    void printVerboseFailMessage(String, String);
    void printVerboseFailMessage(long long, long long);
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
