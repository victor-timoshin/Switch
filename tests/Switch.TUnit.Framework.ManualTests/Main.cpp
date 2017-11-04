#include <Switch/Switch.TUnit.Framework>

using namespace TUnit::Framework;
using namespace System;

namespace UnitTets {
  class Test1 : public TestFixture {
    OneTimeSetUpAttribute __OneTimeInitAttribute {"OneTimeInit", *this, &Test1::OneTimeInit};
    void OneTimeInit() {
    }
    
    OneTimeTearDownAttribute __OneTimeCleanupAttribute {"OneTimeCleanup", *this, &Test1::OneTimeCleanup};
    void OneTimeCleanup() {
    }
    
    SetUpAttribute __InitAttribute {"Init", *this, &Test1::Init};
    void Init() {
    }
    
    TearDownAttribute __CleanupAttribute {"Cleanup", *this, &Test1::Cleanup};
    void Cleanup() {
    }
    
    TestAttribute __TestCase1Attribute {"TestCase1", *this, &Test1::TestCase1};
    void TestCase1() {
    }
    
    TestAttribute __TestCase2Attribute {"TestCase2", *this, &Test1::TestCase2};
    void TestCase2() {
    }
    
    TestAttribute __TestCase3Attribute {"TestCase3", *this, &Test1::TestCase3, TestState::Ignored};
    void TestCase3() {
    }
  };
  
  TestFixtureAttribute<Test1> __Test1Attribute {"Test1"};
  
  class _test_fixture(Test2) {
    void _one_time_set_up(OneTimeInit) {
    }

    void _one_time_tear_down(OneTimeCleanup) {
    }
    
    void _set_up(Init) {
    }
    
    void _tear_down(Cleanup) {
    }
    
    void _test(TestCase1) {
    }
    
    void _test(TestCase2) {
    }
    
    void _ignore_test(TestCase3) {
    }
  };
  
  _add_test_fixture(Test2)

  class _test_class(Test3) {
    void _test_class_initialize(OneTimeInit) {
    }
    
    void _test_class_cleanup(OneTimeCleanup) {
    }
    
    void _test_initialize(Init) {
    }
    
    void _test_cleanup(Cleanup) {
    }
    
    void _test_method(TestCase1) {
    }
    
    void _test_method(TestCase2) {
    }
    
    void _ignore_test_method(TestCase3) {
    }
  };
  
  _add_test_fixture(Test3)
  
  class _test_class(Test4) {
    void _test_class_initialize(OneTimeInit) {
    }
    
    void _test_class_cleanup(OneTimeCleanup) {
    }

    void _test_method(TestCase1) {
    }
  };
  
  class Test5 : public Test4 {
    void _test_class_initialize(OneTimeInit) {
    }
    
    void _test_class_cleanup(OneTimeCleanup) {
    }

    void _test_method(TestCase2) {
    }
  };

  _add_test_fixture(Test5)

  class MainTest {
  public:
    static void Main(const Array<string>& args) {
      TUnit::Framework::UnitTest(args).Run();
    }
  };
}

_startup(UnitTets::MainTest)

