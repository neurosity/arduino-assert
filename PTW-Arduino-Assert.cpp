/**
 * @abstract This library was created so I, AJ Keller, could do Test Driven
 *  Development (TDD) eaiser across the several different libraries I am working
 *  on and maintaing.
 * @author AJ Keller
 * @license MIT
 */

#include "PTW-Arduino-Assert.h"

/**
* @description: The function the OpenBCI board will call in setup
* @author: AJ Keller (@pushtheworldllc)
*/
void OpenBCI_32bit_Class::begin(void) {
    // Bring the board up
    boardBegin() ? ledFlash(2) : ledFlash(1);
}

// EQUAL
//  boolean
boolean assertEqual(boolean a, boolean b) {
  return a == b;
}
//  char
boolean assertEqual(char a, char b) {
  return a == b;
}
//  int
boolean assertEqual(int a, int b) {
  return a == b;
}

// NOT EQUAL
//  boolean
boolean assertNotEqual(boolean a, boolean b) {
  return !assertEqual(a,b);
}
//  char
boolean assertNotEqual(char a, char b) {
  return !assertEqual(a,b);
}
//  int
boolean assertNotEqual(int a, int b) {
  return !assertEqual(a,b);
}

// GREATER THAN
//  boolean
boolean assertGreaterThan(boolean a, boolean b) {
  return a > b;
}
//  char
boolean assertGreaterThan(char a, char b) {
  return a > b;
}
//  int
boolean assertGreaterThan(int a, int b) {
  return a > b;
}

// LESS THAN
//  boolean
boolean assertLessThan(boolean a, boolean b) {
  return a < b;
}
//  char
boolean assertLessThan(char a, char b) {
  return a < b;
}
//  int
boolean assertLessThan(int a, int b) {
  return a < b;
}
