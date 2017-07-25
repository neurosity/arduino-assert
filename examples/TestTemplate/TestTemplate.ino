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
  testAssertEqual();
  testAssertNotEqual();
  testApproximately();
  testBuffer();
  test.end();
}

void testAssertEqual() {
  test.describe("assertEqual");
  test.assertEqual((char)1+1, (char)2, "1 should equal 1",__LINE__);
  test.assertEqual((int)1+1, (int)2, "1 should equal 1",__LINE__);
  test.assertEqual((unsigned long long)1+1, (unsigned long long)2, "1 should equal 1",__LINE__);
  test.assertEqual((size_t)1+1, (size_t)2, "1 should equal 1",__LINE__);
  test.assertEqual((long)1+1, (long)2, "1 should equal 1",__LINE__);
}
void testAssertNotEqual() {
  test.describe("assertNotEqual");
  test.assertNotEqual((char)1+1, (char)1, "2 should not equal 1", __LINE__);
  test.assertNotEqual((int)1+1, (int)1, "2 should not equal 1", __LINE__);
  test.assertNotEqual((unsigned long long)1+1, (unsigned long long)1, "2 should not equal 1", __LINE__);
  test.assertNotEqual((size_t)1+1, (size_t)1, "2 should not equal 1", __LINE__);
  test.assertNotEqual((long)1+1, (long)1, "2 should not equal 1", __LINE__);
}

void testApproximately() {
  test.describe("assertApproximately");
  float expected_f = 8388607.012345;
  float actual_f = 8388607.012347;
  float epsilon_f = 0.000003;
  test.assertApproximately(actual_f, expected_f, epsilon_f, "float should be within 0.000003", __LINE__);
  epsilon_f = 0.000000;
  test.assertApproximately(actual_f, expected_f, epsilon_f, "this should fail :/", __LINE__);

  double expected_d = 8388607.012345;
  double actual_d = 8388607.012347;
  double epsilon_d = 0.000003;
  test.assertApproximately(actual_d, expected_d, epsilon_d, "double should be within 0.000003", __LINE__);
  epsilon_d = 0.000001;
  test.assertApproximately(actual_d, expected_d, epsilon_d, "this should fail :/", __LINE__);
}

void testBuffer() {
  test.describe("buffer");
  char bufferTaco[] = "taco";
  char bufferTest[] = "hey_taco";
  int bufferTacoLength = 4;
  test.assertNotEqualBuffer(bufferTaco,bufferTest, bufferTacoLength, "should not find taco buffer in first 4 bytes of test buffer");
  test.assertEqualBuffer(bufferTaco,bufferTest + 4, bufferTacoLength, "should find taco buffer in last 4 bytes of test buffer");
}
