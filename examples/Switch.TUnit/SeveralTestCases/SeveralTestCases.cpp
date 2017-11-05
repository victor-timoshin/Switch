#include <Switch/Switch>

using namespace TUnit;
using namespace System;

namespace UnitTests {
  class _TestFixture(TeastCase1) {
    void _Test(TestOne) {
      Assert::IsTrue(true, _caller);
    }
    
    void _Test(TestTwo) {
      Assert::IsFalse(false, _caller);
    }
    
    void _Test(TestThree) {
      Assert::IsEmpty("", _caller);
    }
  };

  class _TestFixture(TeastCase2) {
    void _Test(TestOne) {
      Assert::IsTrue(true, _caller);
    }
    
    void _Test(TestTwo) {
      Assert::IsFalse(false, _caller);
    }
    
    void _Test(TestThree) {
      Assert::IsEmpty("", _caller);
    }
    
    void _Test(TestFour) {
      Assert::IsEmpty({}, _caller);
    }
  };

  class _TestFixture(TeastCase3) {
    void _Test(TestOne) {
      Assert::IsNull(null, _caller);
    }
    
    void _Test(TestTwo) {
      _<string> str;
      Assert::IsNull(str, _caller);
    }
  };

  // Used _Test to add unit test to execute at the unit test suit.
  _AddTestFixture(TeastCase1);
  _AddTest(TeastCase1, TestOne);
  _AddTest(TeastCase1, TestTwo);
  _AddTest(TeastCase1, TestThree);
  _AddTestFixture(TeastCase2);
  _AddTest(TeastCase2, TestOne);
  _AddTest(TeastCase2, TestTwo);
  _AddTest(TeastCase2, TestThree);
  _AddTest(TeastCase2, TestFour);
  _AddTestFixture(TeastCase3);
  _AddTest(TeastCase3, TestOne);
  _AddTest(TeastCase3, TestTwo);
}

// This code produces the following output:
//
// Start 9 tests from 3 test cases
//   Start 3 tests from TeastCase1
//     PASSED TeastCase1.TestOne (0 ms)
//     PASSED TeastCase1.TestTwo (0 ms)
//     PASSED TeastCase1.TestThree (0 ms)
//   End 3 tests from TeastCase1 (3 ms total)
//
//   Start 4 tests from TeastCase2
//     PASSED TeastCase2.TestOne (0 ms)
//     PASSED TeastCase2.TestTwo (0 ms)
//     PASSED TeastCase2.TestThree (0 ms)
//     PASSED TeastCase2.TestFour (0 ms)
//   End 4 tests from TeastCase2 (0 ms total)
//
//   Start 2 tests from TeastCase3
//     PASSED TeastCase3.TestOne (0 ms)
//     PASSED TeastCase3.TestTwo (0 ms)
//   End 2 tests from TeastCase3 (1 ms total)
//
//   Summary :
//     PASSED 9 tests.
// End 9 tests from 3 test cases ran. (5 ms total)