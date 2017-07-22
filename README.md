# PTW-Arduino-Assert
A super lightweight library for Test Driven Development

Written with love by [Push The World!](http://www.pushtheworldllc.com)

We use this in the firmware for OpenBCI.

## Example
```Arduino
#include <PTW-Arduino-Assert.h>

void setup() {
  // Start hardware Serial for debug
  Serial.begin(115200);

  // Set serial for library
  test.setSerial(Serial);

}

void loop() {
  if (Serial.available()) {
    Serial.read();
    go();
  }
}

void go() {
  test.begin();
  testAdd();
  testBuffer();
  test.end();
}

void testAdd() {
  test.describe("Add");
  testAdd_T1();
  testAdd_T2();
}

void testAdd_T1() {
  test.assertEqualInt(1+1, 2, "1 should equal 1");
}
void testAdd_T2() {
  test.assertNotEqualInt(1+1, 1, "2 should not equal 1");
}

void testBuffer() {
    char bufferTaco[] = "taco";
    char bufferTest[] = "hey_taco";

    int bufferTacoLength = 4;

    test.assertNotEqualBuffer(bufferTaco,bufferTest, bufferTacoLength, "should not find taco buffer in first 4 bytes of test buffer");

    test.assertEqualBuffer(bufferTaco,bufferTest + 4, bufferTacoLength, "should find taco buffer in last 4 bytes of test buffer");
}

```

# Reference Guide

### assertBoolean(actual, expected)

Assert that `actual` and `expected` are the same.

**_actual_** - {boolean}

The output of the function under test.

**_expected_** - {boolean}

The expected output value of the function under test.

**_Returns_** - {boolean}

`true` if they are equal, `false` if not.

### assertBoolean(actual, expected, message)

Assert that `actual` and `expected` are the same.

**_actual_** - {boolean}

The output of the function under test.

**_expected_** - {boolean}

The expected output value of the function under test.

**_message_** - {char *}

A "should" message to print out with the test whether it passes or fails.

**_Returns_** - {boolean}

`true` if they are equal, `false` if not.

### assertBoolean(actual, expected, message, lineNumber);

Assert that `actual` and `expected` are the same.

**_actual_** - {boolean}

The output of the function under test.

**_expected_** - {boolean}

The expected output value of the function under test.

**_message_** - {char *}

A "should" message to print out with the test whether it passes or fails.

**_lineNumber_** - {int}

The line number of this assert call. Extremely helpful for those first couple runs though a large test file. Simply use Arduino's `__LINE__` reserved word which the preprocessor will insert the line number on! Clutch!

**_Returns_** - {boolean}

`true` if they are equal, `false` if not.

### assertEqualBuffer(actual, expected, length)

Assert that `actual` and `expected` are the same on a char by char basis.

**_actual_** - {char *}

The output of the function under test.

**_expected_** - {char *}

The expected output value of the function under test.

**_Returns_** - {boolean}

`true` if they are equal, `false` if not.

boolean assertEqualBuffer(char *, char *, int, char *);
boolean assertEqualBuffer(char *, char *, int, char *, int);
boolean assertEqualByte(byte, byte);
boolean assertEqualByte(byte, byte, char *);
boolean assertEqualByte(byte, byte, char *, int);
boolean assertEqualChar(char, char);
boolean assertEqualChar(char, char, char *);
boolean assertEqualChar(char, char, char *, int);
boolean assertEqualInt(int, int);
boolean assertEqualInt(int, int, char *);
boolean assertEqualInt(int, int, char *, int);

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

boolean assertGreaterThanByte(byte, byte);
boolean assertGreaterThanByte(byte, byte, char *);
boolean assertGreaterThanByte(byte, byte, char *, int);
boolean assertGreaterThanChar(char, char);
boolean assertGreaterThanChar(char, char, char *);
boolean assertGreaterThanChar(char, char, char *, int);
boolean assertGreaterThanInt(int, int);
boolean assertGreaterThanInt(int, int, char *);
boolean assertGreaterThanInt(int, int, char *, int);

boolean assertLessThanByte(byte, byte);
boolean assertLessThanByte(byte, byte, char *);
boolean assertLessThanByte(byte, byte, char *, int);
boolean assertLessThanChar(char, char);
boolean assertLessThanChar(char, char, char *);
boolean assertLessThanChar(char, char, char *, int);
boolean assertLessThanInt(int, int);
boolean assertLessThanInt(int, int, char *);
boolean assertLessThanInt(int, int, char *, int);

boolean assertBetweenInt(int, int, int);
boolean assertBetweenInt(int, int, int, char *);
boolean assertBetweenInt(int, int, int, char *, int);
boolean assertBetweenInclusiveInt(int, int, int);
boolean assertBetweenInclusiveInt(int, int, int, char *);
boolean assertBetweenInclusiveInt(int, int, int, char *, int);
