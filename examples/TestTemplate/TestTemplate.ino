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
  test.end();
}

void testAdd() {
  test.describe("Add");
  testAdd_T1();
  testAdd_T2();
}

void testAdd_T1() {
  test.assertEqual(1+1, 2, "1 should equal 1");
}
void testAdd_T2() {
  test.assertNotEqual(1+1, 1, "2 should not equal 1");
}
