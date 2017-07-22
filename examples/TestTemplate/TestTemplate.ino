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
  test.assertEqual(1+1, 2, "1 should equal 1",__LINE__);
}
void testAdd_T2() {
  test.assertNotEqual(1+1, 1, "2 should not equal 1", __LINE__);
}

void testBuffer() {
    char bufferTaco[] = "taco";
    char bufferTest[] = "hey_taco";

    int bufferTacoLength = 4;

    test.assertNotEqualBuffer(bufferTaco,bufferTest, bufferTacoLength, "should not find taco buffer in first 4 bytes of test buffer");

    test.assertEqualBuffer(bufferTaco,bufferTest + 4, bufferTacoLength, "should find taco buffer in last 4 bytes of test buffer");
}
