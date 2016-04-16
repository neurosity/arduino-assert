/**
 * @abstract This library was created so I, AJ Keller, could do Test Driven
 *  Development (TDD) eaiser across the several different libraries I am working
 *  on and maintaing.
 * @author AJ Keller
 * @license MIT
 */

#ifndef _____PTW_Arduino_Assert__
#define _____PTW_Arduino_Assert__

#include <Arduino.h>

class PTW_Arduino_Assert {

public:
    PTW_Arduino_Assert();
    // EQUAL
    boolean assertEqual(boolean a, boolean b);
    boolean assertEqual(boolean a, boolean b, char *msg);
    boolean assertEqual(byte a, byte b);
    boolean assertEqual(byte a, byte b, char *msg);
    boolean assertEqual(char a, char b);
    boolean assertEqual(char a, char b, char *msg);
    boolean assertEqual(int a, int b);
    boolean assertEqual(int a, int b, char *msg);
    // NOT EQUAL
    boolean assertNotEqual(boolean a, boolean b);
    boolean assertNotEqual(boolean a, boolean b, char *msg);
    boolean assertNotEqual(byte a, byte b);
    boolean assertNotEqual(byte a, byte b, char *msg);
    boolean assertNotEqual(char a, char b);
    boolean assertNotEqual(char a, char b, char *msg);
    boolean assertNotEqual(int a, int b);
    boolean assertNotEqual(int a, int b, char *msg);
    // GREATER THAN
    boolean assertGreaterThan(boolean a, boolean b);
    boolean assertGreaterThan(boolean a, boolean b, char *msg);
    boolean assertGreaterThan(byte a, byte b);
    boolean assertGreaterThan(byte a, byte b, char *msg);
    boolean assertGreaterThan(char a, char b);
    boolean assertGreaterThan(char a, char b, char *msg);
    boolean assertGreaterThan(int a, int b);
    boolean assertGreaterThan(int a, int b, char *msg);
    // LESS THAN
    boolean assertLessThan(boolean a, boolean b);
    boolean assertLessThan(boolean a, boolean b, char *msg);
    boolean assertLessThan(byte a, byte b);
    boolean assertLessThan(byte a, byte b, char *msg);
    boolean assertLessThan(char a, char b);
    boolean assertLessThan(char a, char b, char *msg);
    boolean assertLessThan(int a, int b);
    boolean assertLessThan(int a, int b, char *msg);

    void begin(void);
    void end(void);
    void function(char *title);

    void setHarwareSerial(HardwareSerial *serial);

private:
    HardwareSerial _serial;
    boolean printTestResultWithMsg(boolean testPassed, char *msg);
    int numberOfTests;
    int numberOfTestsFailed;
    int numberOfTestsPassed;
};

// This let's us call into the class from within the library if necessary
extern PTW_Arduino_Assert test;

#endif
