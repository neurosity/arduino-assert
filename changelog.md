# v1.0.0

Now on the Arduino library manager.

### New functions

* Add `assertEqualString`

# v0.3.2

### Bug Fixes
* NotEqual functions not adding to totals correctly

# v0.3.0

### New Features

* Add `it` function for better sub test. Use this to describe what you are testing with a thoughtful sentence. These statements should form your function descriptions i.e. what `it` (the function) should do
* Add ability to print line numbers of auto test.
* Add `assertNotEqualBuffer`

### Breaking Changes
* Renamed `assertEqualBoolean` to `assertBoolean`
* Removed `assertLessThanBoolean`, `assertGreaterThanBoolean`, and `assertNotEqualBoolean` because these don't make sense to have with booleans. Just use `assertBoolean`.
