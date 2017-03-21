﻿#include <Pcf/Is.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace TUnit;

namespace {
  class IsTest : public TestFixture {
  protected:
    void StringIsString() {
      string s = "Test";
      Assert::IsTrue(is<string>(s), pcf_current_information);
    }

    void StringIsObject() {
      string s = "Test";
      Assert::IsTrue(is<object>(s), pcf_current_information);
    }
    
    void StringIsIComparable() {
      string s = "Test";
      Assert::IsTrue(is<IComparable>(s), pcf_current_information);
    }
    
    void StringIsInt32() {
      string s = "Test";
      Assert::IsFalse(is<Int32>(s), pcf_current_information);
    }
    
    void ObjectFromStringIsString() {
      string s = "Test";
      object& o = s;
      Assert::IsTrue(is<string>(o), pcf_current_information);
    }
    
    void ObjectFromStringIsObject() {
      string s = "Test";
      object& o = s;
      Assert::IsTrue(is<object>(o), pcf_current_information);
    }
    
    void ObjectFormStringIsIComparable() {
      string s = "Test";
      object& o = s;
      Assert::IsTrue(is<IComparable>(o), pcf_current_information);
    }
    
    void ObjectFormStringIsInt32() {
      string s = "Test";
      object& o = s;
      Assert::IsFalse(is<Int32>(o), pcf_current_information);
    }
    
    void ConstStringIsString() {
      const string s = "Test";
      Assert::IsTrue(is<string>(s), pcf_current_information);
    }
    
    void ConstStringIsObject() {
      const string s = "Test";
      Assert::IsTrue(is<object>(s), pcf_current_information);
    }
    
    void ConstStringIsIComparable() {
      const string s = "Test";
      Assert::IsTrue(is<IComparable>(s), pcf_current_information);
    }
    
    void ConstStringIsInt32() {
      const string s = "Test";
      Assert::IsFalse(is<Int32>(s), pcf_current_information);
    }
    
    void ConstObjectFromStringIsString() {
      const string s = "Test";
      const object& o = s;
      Assert::IsTrue(is<string>(o), pcf_current_information);
    }
    
    void ConstObjectFromStringIsObject() {
      const string s = "Test";
      const object& o = s;
      Assert::IsTrue(is<object>(o), pcf_current_information);
    }
    
    void ConstObjectFormStringIsIComparable() {
      const string s = "Test";
      const object& o = s;
      Assert::IsTrue(is<IComparable>(o), pcf_current_information);
    }
    
    void ConstObjectFormStringIsInt32() {
      const string s = "Test";
      const object& o = s;
      Assert::IsFalse(is<Int32>(o), pcf_current_information);
    }
    
    void StringPtrIsString() {
      string s = "Test";
      Assert::IsTrue(is<string>(&s), pcf_current_information);
    }
    
    void StringPtrIsObject() {
      string s = "Test";
      Assert::IsTrue(is<object>(&s), pcf_current_information);
    }
    
    void StringPtrIsIComparable() {
      string s = "Test";
      Assert::IsTrue(is<IComparable>(&s), pcf_current_information);
    }
    
    void StringPtrIsInt32() {
      string s = "Test";
      Assert::IsFalse(is<Int32>(&s), pcf_current_information);
    }
    
    void ObjectPtrFromStringPtrIsString() {
      string s = "Test";
      object* o = &s;
      Assert::IsTrue(is<string>(o), pcf_current_information);
    }
    
    void ObjectPtrFromStringPtrIsObject() {
      string s = "Test";
      object* o = &s;
      Assert::IsTrue(is<object>(o), pcf_current_information);
    }
    
    void ObjectPtrFormStringPtrIsIComparable() {
      string s = "Test";
      object* o = &s;
      Assert::IsTrue(is<IComparable>(o), pcf_current_information);
    }
    
    void ObjectPtrFormStringPtrIsInt32() {
      string s = "Test";
      object* o = &s;
      Assert::IsFalse(is<Int32>(o), pcf_current_information);
    }
    
    void StringPtrNullIsString() {
      string* s = null;
      Assert::IsFalse(is<string>(s), pcf_current_information);
    }
    
    void StringPtrNullIsObject() {
      string* s = null;
      Assert::IsFalse(is<object>(s), pcf_current_information);
    }
    
    void StringPtrNullIsIComparable() {
      string* s = null;
      Assert::IsFalse(is<IComparable>(s), pcf_current_information);
    }
    
    void StringPtrNullIsInt32() {
      string* s = null;
      Assert::IsFalse(is<Int32>(s), pcf_current_information);
    }
    
    void ObjectPtrFromStringPtrNullIsString() {
      string* s = null;
      object* o = s;
      Assert::IsFalse(is<string>(o), pcf_current_information);
    }
    
    void ObjectPtrFromStringPtrNullIsObject() {
      string* s = null;
      object* o = s;
      Assert::IsFalse(is<object>(o), pcf_current_information);
    }
    
    void ObjectPtrFormStringPtrNullIsIComparable() {
      string* s = null;
      object* o = s;
      Assert::IsFalse(is<IComparable>(o), pcf_current_information);
    }
    
    void ObjectPtrFormStringPtrNullIsInt32() {
      string* s = null;
      object* o = s;
      Assert::IsFalse(is<Int32>(o), pcf_current_information);
    }
    
    void ConstStringPtrIsString() {
      string s = "Test";
      const string* cs = &s;
      Assert::IsTrue(is<string>(cs), pcf_current_information);
    }
    
    void ConstStringPtrIsObject() {
      string s = "Test";
      const string* cs = &s;
      Assert::IsTrue(is<object>(cs), pcf_current_information);
    }
    
    void ConstStringPtrIsIComparable() {
      string s = "Test";
      const string* cs = &s;
      Assert::IsTrue(is<IComparable>(cs), pcf_current_information);
    }
    
    void ConstStringPtrIsInt32() {
      string s = "Test";
      const string* cs = &s;
      Assert::IsFalse(is<Int32>(cs), pcf_current_information);
    }
    
    void ConstObjectPtrFromStringPtrIsString() {
      string s = "Test";
      const object* o = &s;
      Assert::IsTrue(is<string>(o), pcf_current_information);
    }
    
    void ConstObjectPtrFromStringPtrIsObject() {
      string s = "Test";
      const object* o = &s;
      Assert::IsTrue(is<object>(o), pcf_current_information);
    }
    
    void ConstObjectPtrFormStringPtrIsIComparable() {
      string s = "Test";
      const object* o = &s;
      Assert::IsTrue(is<IComparable>(o), pcf_current_information);
    }
    
    void ConstObjectPtrFormStringPtrIsInt32() {
      string s = "Test";
      const object* o = &s;
      Assert::IsFalse(is<Int32>(o), pcf_current_information);
    }
    
    void ConstStringPtrNullIsString() {
      const string* s = null;
      Assert::IsFalse(is<string>(s), pcf_current_information);
    }
    
    void ConstStringPtrNullIsObject() {
      const string* s = null;
      Assert::IsFalse(is<object>(s), pcf_current_information);
    }
    
    void ConstStringPtrNullIsIComparable() {
      const string* s = null;
      Assert::IsFalse(is<IComparable>(s), pcf_current_information);
    }
    
    void ConstStringPtrNullIsInt32() {
      const string* s = null;
      Assert::IsFalse(is<Int32>(s), pcf_current_information);
    }
    
    void ConstObjectPtrFromStringPtrNullIsString() {
      const string* s = null;
      const object* o = s;
      Assert::IsFalse(is<string>(o), pcf_current_information);
    }
    
    void ConstObjectPtrFromStringPtrNullIsObject() {
      const string* s = null;
      const object* o = s;
      Assert::IsFalse(is<object>(o), pcf_current_information);
    }
    
    void ConstObjectPtrFormStringPtrNullIsIComparable() {
      const string* s = null;
      const object* o = s;
      Assert::IsFalse(is<IComparable>(o), pcf_current_information);
    }
    
    void ConstObjectPtrFormStringPtrNullIsInt32() {
      const string* s = null;
      const object* o = s;
      Assert::IsFalse(is<Int32>(o), pcf_current_information);
    }
    
    void SpStringIsString() {
      SharedPointer<string> s = SharedPointer<String>::Create("Test");
      Assert::IsTrue(is<string>(s), pcf_current_information);
    }
    
    void SpStringIsObject() {
      SharedPointer<string> s = SharedPointer<String>::Create("Test");
      Assert::IsTrue(is<object>(s)), pcf_current_information;
    }
    
    void SpStringIsIComparable() {
      SharedPointer<string> s = SharedPointer<String>::Create("Test");
      Assert::IsTrue(is<IComparable>(s), pcf_current_information);
    }
    
    void SpStringIsInt32() {
      SharedPointer<string> s = new String("Test");
      Assert::IsFalse(is<Int32>(s), pcf_current_information);
    }
    
    void SpObjectFromSpStringIsString() {
      SharedPointer<object> o = SharedPointer<object>::Create<string>("Test");
      Assert::IsTrue(is<string>(o), pcf_current_information);
    }
    
    void SpObjectFromSpStringIsObject() {
      SharedPointer<object> o = SharedPointer<object>::Create<string>("Test");
      Assert::IsTrue(is<object>(o), pcf_current_information);
    }
    
    void SpObjectFormSpStringIsIComparable() {
      SharedPointer<object> o = SharedPointer<object>::Create<string>("Test");
      Assert::IsTrue(is<IComparable>(o), pcf_current_information);
    }
    
    void SpObjectFormSpStringIsInt32() {
      SharedPointer<object> o = SharedPointer<object>::Create<string>("Test");
      Assert::IsFalse(is<Int32>(o), pcf_current_information);
    }
    
    void SpStringNullIsString() {
      SharedPointer<string> s = SharedPointer<string>::Null();
      Assert::IsFalse(is<string>(s), pcf_current_information);
    }
    
    void SpStringNullIsObject() {
      SharedPointer<string> s = SharedPointer<string>::Null();
      Assert::IsFalse(is<object>(s), pcf_current_information);
    }
    
    void SpStringNullIsIComparable() {
      SharedPointer<string> s = SharedPointer<string>::Null();
      Assert::IsFalse(is<IComparable>(s), pcf_current_information);
    }
    
    void SpStringNullIsInt32() {
      SharedPointer<string> s = SharedPointer<string>::Null();
      Assert::IsFalse(is<Int32>(s), pcf_current_information);
    }
    
    void SpObjectFromSpStringNullIsString() {
      SharedPointer<object> o = as<object>(SharedPointer<string>::Null());
      Assert::IsFalse(is<string>(o), pcf_current_information);
    }
    
    void SpObjectFromSpStringNullIsObject() {
      SharedPointer<object> o = as<object>(SharedPointer<string>::Null());
      Assert::IsFalse(is<object>(o), pcf_current_information);
    }
    
    void SpObjectFormSpStringNullIsIComparable() {
      SharedPointer<object> o = as<object>(SharedPointer<string>::Null());
      Assert::IsFalse(is<IComparable>(o), pcf_current_information);
    }
    
    void SpObjectFormSpStringNullIsInt32() {
      SharedPointer<object> o = as<object>(SharedPointer<string>::Null());
      Assert::IsFalse(is<Int32>(o), pcf_current_information);
    }
    
    void ConstSpStringIsString() {
      const SharedPointer<string> s = SharedPointer<String>::Create("Test");
      Assert::IsTrue(is<string>(s), pcf_current_information);
    }
    
    void ConstSpStringIsObject() {
      const SharedPointer<string> s = SharedPointer<String>::Create("Test");
      Assert::IsTrue(is<object>(s), pcf_current_information);
    }
    
    void ConstSpStringIsIComparable() {
      const SharedPointer<string> s = SharedPointer<String>::Create("Test");
      Assert::IsTrue(is<IComparable>(s), pcf_current_information);
    }
    
    void ConstSpStringIsInt32() {
      const SharedPointer<string> s = SharedPointer<String>::Create("Test");
      Assert::IsFalse(is<Int32>(s), pcf_current_information);
    }
    
    void ConstSpObjectFromConstSpStringIsString() {
      const SharedPointer<object> o = SharedPointer<object>::Create<string>("Test");
      Assert::IsTrue(is<string>(o), pcf_current_information);
    }
    
    void ConstSpObjectFromConstSpStringIsObject() {
      const SharedPointer<object> o = SharedPointer<object>::Create<string>("Test");
      Assert::IsTrue(is<object>(o), pcf_current_information);
    }
    
    void ConstSpObjectFormConstSpStringIsIComparable() {
      const SharedPointer<object> o = SharedPointer<object>::Create<string>("Test");
      Assert::IsTrue(is<IComparable>(o), pcf_current_information);
    }
    
    void ConstSpObjectFormConstSpStringIsInt32() {
      const SharedPointer<object> o = SharedPointer<object>::Create<string>("Test");
      Assert::IsFalse(is<Int32>(o), pcf_current_information);
    }
    
    void ConstSpStringNullIsString() {
      const SharedPointer<string> s = SharedPointer<string>::Null();
      Assert::IsFalse(is<string>(s), pcf_current_information);
    }
    
    void ConstSpStringNullIsObject() {
      const SharedPointer<string> s = SharedPointer<string>::Null();
      Assert::IsFalse(is<object>(s), pcf_current_information);
    }
    
    void ConstSpStringNullIsIComparable() {
      const SharedPointer<string> s = SharedPointer<string>::Null();
      Assert::IsFalse(is<IComparable>(s), pcf_current_information);
    }
    
    void ConstSpStringNullIsInt32() {
      const SharedPointer<string> s = SharedPointer<string>::Null();
      Assert::IsFalse(is<Int32>(s), pcf_current_information);
    }
    
    void ConstSpObjectFromConstSpStringNullIsString() {
      const SharedPointer<object> o = as<object>(SharedPointer<string>::Null());
      Assert::IsFalse(is<string>(o), pcf_current_information);
    }
    
    void ConstSpObjectFromConstSpStringNullIsObject() {
      const SharedPointer<object> o = as<object>(SharedPointer<string>::Null());
      Assert::IsFalse(is<object>(o), pcf_current_information);
    }
    
    void ConstSpObjectFormConstSpStringNullIsIComparable() {
      const SharedPointer<object> o = as<object>(SharedPointer<string>::Null());
      Assert::IsFalse(is<IComparable>(o), pcf_current_information);
    }
    
    void ConstSpObjectFormConstSpStringNullIsInt32() {
      const SharedPointer<object> o = as<object>(SharedPointer<string>::Null());
      Assert::IsFalse(is<Int32>(o), pcf_current_information);
    }
    
    void UpStringIsString() {
      UniquePointer<string> s = UniquePointer<String>::Create("Test");
      Assert::IsTrue(is<string>(s), pcf_current_information);
    }
    
    void UpStringIsObject() {
      UniquePointer<string> s = UniquePointer<String>::Create("Test");
      Assert::IsTrue(is<object>(s), pcf_current_information);
    }
    
    void UpStringIsIComparable() {
      UniquePointer<string> s = UniquePointer<String>::Create("Test");
      Assert::IsTrue(is<IComparable>(s), pcf_current_information);
    }
    
    void UpStringIsInt32() {
      UniquePointer<string> s = UniquePointer<String>::Create("Test");
      Assert::IsFalse(is<Int32>(s), pcf_current_information);
    }
    
    void UpObjectFromUpStringIsString() {
      UniquePointer<object> o = UniquePointer<object>::Create<string>("Test");
      Assert::IsTrue(is<string>(o), pcf_current_information);
    }
    
    void UpObjectFromUpStringIsObject() {
      UniquePointer<object> o = UniquePointer<object>::Create<string>("Test");
      Assert::IsTrue(is<object>(o), pcf_current_information);
    }
    
    void UpObjectFormUpStringIsIComparable() {
      UniquePointer<object> o = UniquePointer<object>::Create<string>("Test");
      Assert::IsTrue(is<IComparable>(o), pcf_current_information);
    }
    
    void UpObjectFormUpStringIsInt32() {
      UniquePointer<object> o = UniquePointer<object>::Create<string>("Test");
      Assert::IsFalse(is<Int32>(o), pcf_current_information);
    }
    
    void UpStringNullIsString() {
      UniquePointer<string> s = UniquePointer<string>::Null();
      Assert::IsFalse(is<string>(s), pcf_current_information);
    }
    
    void UpStringNullIsObject() {
      UniquePointer<string> s = UniquePointer<string>::Null();
      Assert::IsFalse(is<object>(s), pcf_current_information);
    }
    
    void UpStringNullIsIComparable() {
      UniquePointer<string> s = UniquePointer<string>::Null();
      Assert::IsFalse(is<IComparable>(s), pcf_current_information);
    }
    
    void UpStringNullIsInt32() {
      UniquePointer<string> s = UniquePointer<string>::Null();
      Assert::IsFalse(is<Int32>(s), pcf_current_information);
    }
    
    void UpObjectFromUpStringNullIsString() {
      UniquePointer<string> s = UniquePointer<string>::Null();
      UniquePointer<object> o = as<object>(s);
      Assert::IsFalse(is<string>(o), pcf_current_information);
    }
    
    void UpObjectFromUpStringNullIsObject() {
      UniquePointer<string> s = UniquePointer<string>::Null();
      UniquePointer<object> o = as<object>(s);
      Assert::IsFalse(is<object>(o), pcf_current_information);
    }
    
    void UpObjectFormUpStringNullIsIComparable() {
      UniquePointer<string> s = UniquePointer<string>::Null();
      UniquePointer<object> o = as<object>(s);
      Assert::IsFalse(is<IComparable>(o), pcf_current_information);
    }
    
    void UpObjectFormUpStringNullIsInt32() {
      UniquePointer<string> s = UniquePointer<string>::Null();
      UniquePointer<object> o = as<object>(s);
      Assert::IsFalse(is<Int32>(o), pcf_current_information);
    }
    
    void RefStringIsString() {
      string str = "Test";
      Reference<string> s = str;
      Assert::IsTrue(is<string>(s), pcf_current_information);
    }
    
    void RefStringIsObject() {
      string str = "Test";
      Reference<string> s = str;
      Assert::IsTrue(is<object>(s), pcf_current_information);
    }
    
    void RefStringIsIComparable() {
      string str = "Test";
      Reference<string> s = str;
      Assert::IsTrue(is<IComparable>(s), pcf_current_information);
    }
    
    void RefStringIsInt32() {
      string str = "Test";
      Reference<string> s = str;
      Assert::IsFalse(is<Int32>(s), pcf_current_information);
    }
    
    void RefObjectFromRefStringIsString() {
      string str = "Test";
      Reference<object> o = str;
      Assert::IsTrue(is<string>(o), pcf_current_information);
    }
    
    void RefObjectFromRefStringIsObject() {
      string str = "Test";
      Reference<object> o = str;
      Assert::IsTrue(is<object>(o), pcf_current_information);
    }
    
    void RefObjectFormRefStringIsIComparable() {
      string str = "Test";
      Reference<object> o = str;
      Assert::IsTrue(is<IComparable>(o), pcf_current_information);
    }
    
    void RefObjectFormRefStringIsInt32() {
      string str = "Test";
      Reference<object> o = str;
      Assert::IsFalse(is<Int32>(o), pcf_current_information);
    }
    
    void RefStringNullIsString() {
      Reference<string> s = Reference<string>::Null();
      Assert::IsFalse(is<string>(s), pcf_current_information);
    }
    
    void RefStringNullIsObject() {
      Reference<string> s = Reference<string>::Null();
      Assert::IsFalse(is<object>(s), pcf_current_information);
    }
    
    void RefStringNullIsIComparable() {
      Reference<string> s = Reference<string>::Null();
      Assert::IsFalse(is<IComparable>(s), pcf_current_information);
    }
    
    void RefStringNullIsInt32() {
      Reference<string> s = Reference<string>::Null();
      Assert::IsFalse(is<Int32>(s), pcf_current_information);
    }
    
    void RefObjectFromRefStringNullIsString() {
      Reference<object> o = as<object>(Reference<string>::Null());
      Assert::IsFalse(is<string>(o), pcf_current_information);
    }
    
    void RefObjectFromRefStringNullIsObject() {
      Reference<object> o = as<object>(Reference<string>::Null());
      Assert::IsFalse(is<object>(o), pcf_current_information);
    }
    
    void RefObjectFormRefStringNullIsIComparable() {
      Reference<object> o = as<object>(Reference<string>::Null());
      Assert::IsFalse(is<IComparable>(o), pcf_current_information);
    }
    
    void RefObjectFormRefStringNullIsInt32() {
      Reference<object> o = as<object>(Reference<string>::Null());
      Assert::IsFalse(is<Int32>(o), pcf_current_information);
    }
    
    void ConstRefStringIsString() {
      const string str = "Test";
      const Reference<string> s = str;
      Assert::IsTrue(is<string>(s), pcf_current_information);
    }
    
    void ConstRefStringIsObject() {
      const string str = "Test";
      const Reference<string> s = str;
      Assert::IsTrue(is<object>(s), pcf_current_information);
    }
    
    void ConstRefStringIsIComparable() {
      const string str = "Test";
      const Reference<string> s = str;
      Assert::IsTrue(is<IComparable>(s), pcf_current_information);
    }
    
    void ConstRefStringIsInt32() {
      const string str = "Test";
      const Reference<string> s = str;
      Assert::IsFalse(is<Int32>(s), pcf_current_information);
    }
    
    void ConstRefObjectFromConstRefStringIsString() {
      const string str = "Test";
      const Reference<object> o = str;
      Assert::IsTrue(is<string>(o), pcf_current_information);
    }
    
    void ConstRefObjectFromConstRefStringIsObject() {
      const string str = "Test";
      const Reference<object> o = str;
      Assert::IsTrue(is<object>(o), pcf_current_information);
    }
    
    void ConstRefObjectFormConstRefStringIsIComparable() {
      const string str = "Test";
      const Reference<object> o = str;
      Assert::IsTrue(is<IComparable>(o), pcf_current_information);
    }
    
    void ConstRefObjectFormConstRefStringIsInt32() {
      const string str = "Test";
      const Reference<object> o = str;
      Assert::IsFalse(is<Int32>(o), pcf_current_information);
    }
    
    void ConstRefStringNullIsString() {
      const Reference<string> s = Reference<string>::Null();
      Assert::IsFalse(is<string>(s), pcf_current_information);
    }
    
    void ConstRefStringNullIsObject() {
      const Reference<string> s = Reference<string>::Null();
      Assert::IsFalse(is<object>(s), pcf_current_information);
    }
    
    void ConstRefStringNullIsIComparable() {
      const Reference<string> s = Reference<string>::Null();
      Assert::IsFalse(is<IComparable>(s), pcf_current_information);
    }
    
    void ConstRefStringNullIsInt32() {
      const Reference<string> s = Reference<string>::Null();
      Assert::IsFalse(is<Int32>(s), pcf_current_information);
    }
    
    void ConstRefObjectFromConstRefStringNullIsString() {
      const Reference<object> o = as<object>(Reference<string>::Null());
      Assert::IsFalse(is<string>(o), pcf_current_information);
    }
    
    void ConstRefObjectFromConstRefStringNullIsObject() {
      const Reference<object> o = as<object>(Reference<string>::Null());
      Assert::IsFalse(is<object>(o), pcf_current_information);
    }
    
    void ConstRefObjectFormConstRefStringNullIsIComparable() {
      const Reference<object> o = as<object>(Reference<string>::Null());
      Assert::IsFalse(is<IComparable>(o), pcf_current_information);
    }
    
    void ConstRefObjectFormConstRefStringNullIsInt32() {
      const Reference<object> o = as<object>(Reference<string>::Null());
      Assert::IsFalse(is<Int32>(o), pcf_current_information);
    }
  };
  
  pcf_test(IsTest, StringIsString)
  pcf_test(IsTest, StringIsObject)
  pcf_test(IsTest, StringIsIComparable)
  pcf_test(IsTest, StringIsInt32)
  pcf_test(IsTest, ObjectFromStringIsString)
  pcf_test(IsTest, ObjectFromStringIsObject)
  pcf_test(IsTest, ObjectFormStringIsIComparable)
  pcf_test(IsTest, ObjectFormStringIsInt32)
  pcf_test(IsTest, ConstStringIsString)
  pcf_test(IsTest, ConstStringIsObject)
  pcf_test(IsTest, ConstStringIsIComparable)
  pcf_test(IsTest, ConstStringIsInt32)
  pcf_test(IsTest, ConstObjectFromStringIsString)
  pcf_test(IsTest, ConstObjectFromStringIsObject)
  pcf_test(IsTest, ConstObjectFormStringIsIComparable)
  pcf_test(IsTest, ConstObjectFormStringIsInt32)
  pcf_test(IsTest, StringPtrIsString)
  pcf_test(IsTest, StringPtrIsObject)
  pcf_test(IsTest, StringPtrIsIComparable)
  pcf_test(IsTest, StringPtrIsInt32)
  pcf_test(IsTest, ObjectPtrFromStringPtrIsString)
  pcf_test(IsTest, ObjectPtrFromStringPtrIsObject)
  pcf_test(IsTest, ObjectPtrFormStringPtrIsIComparable)
  pcf_test(IsTest, ObjectPtrFormStringPtrIsInt32)
  pcf_test(IsTest, StringPtrNullIsString)
  pcf_test(IsTest, StringPtrNullIsObject)
  pcf_test(IsTest, StringPtrNullIsIComparable)
  pcf_test(IsTest, StringPtrNullIsInt32)
  pcf_test(IsTest, ObjectPtrFromStringPtrNullIsString)
  pcf_test(IsTest, ObjectPtrFromStringPtrNullIsObject)
  pcf_test(IsTest, ObjectPtrFormStringPtrNullIsIComparable)
  pcf_test(IsTest, ObjectPtrFormStringPtrNullIsInt32)
  pcf_test(IsTest, ConstStringPtrIsString)
  pcf_test(IsTest, ConstStringPtrIsObject)
  pcf_test(IsTest, ConstStringPtrIsIComparable)
  pcf_test(IsTest, ConstStringPtrIsInt32)
  pcf_test(IsTest, ConstObjectPtrFromStringPtrIsString)
  pcf_test(IsTest, ConstObjectPtrFromStringPtrIsObject)
  pcf_test(IsTest, ConstObjectPtrFormStringPtrIsIComparable)
  pcf_test(IsTest, ConstObjectPtrFormStringPtrIsInt32)
  pcf_test(IsTest, ConstStringPtrNullIsString)
  pcf_test(IsTest, ConstStringPtrNullIsObject)
  pcf_test(IsTest, ConstStringPtrNullIsIComparable)
  pcf_test(IsTest, ConstStringPtrNullIsInt32)
  pcf_test(IsTest, ConstObjectPtrFromStringPtrNullIsString)
  pcf_test(IsTest, ConstObjectPtrFromStringPtrNullIsObject)
  pcf_test(IsTest, ConstObjectPtrFormStringPtrNullIsIComparable)
  pcf_test(IsTest, ConstObjectPtrFormStringPtrNullIsInt32)
  pcf_test(IsTest, SpStringIsString)
  pcf_test(IsTest, SpStringIsObject)
  pcf_test(IsTest, SpStringIsIComparable)
  pcf_test(IsTest, SpStringIsInt32)
  pcf_test(IsTest, SpObjectFromSpStringIsString)
  pcf_test(IsTest, SpObjectFromSpStringIsObject)
  pcf_test(IsTest, SpObjectFormSpStringIsIComparable)
  pcf_test(IsTest, SpObjectFormSpStringIsInt32)
  pcf_test(IsTest, SpStringNullIsString)
  pcf_test(IsTest, SpStringNullIsObject)
  pcf_test(IsTest, SpStringNullIsIComparable)
  pcf_test(IsTest, SpStringNullIsInt32)
  pcf_test(IsTest, SpObjectFromSpStringNullIsString)
  pcf_test(IsTest, SpObjectFromSpStringNullIsObject)
  pcf_test(IsTest, SpObjectFormSpStringNullIsIComparable)
  pcf_test(IsTest, SpObjectFormSpStringNullIsInt32)
  pcf_test(IsTest, ConstSpStringIsString)
  pcf_test(IsTest, ConstSpStringIsObject)
  pcf_test(IsTest, ConstSpStringIsIComparable)
  pcf_test(IsTest, ConstSpStringIsInt32)
  pcf_test(IsTest, ConstSpObjectFromConstSpStringIsString)
  pcf_test(IsTest, ConstSpObjectFromConstSpStringIsObject)
  pcf_test(IsTest, ConstSpObjectFormConstSpStringIsIComparable)
  pcf_test(IsTest, ConstSpObjectFormConstSpStringIsInt32)
  pcf_test(IsTest, ConstSpStringNullIsString)
  pcf_test(IsTest, ConstSpStringNullIsObject)
  pcf_test(IsTest, ConstSpStringNullIsIComparable)
  pcf_test(IsTest, ConstSpStringNullIsInt32)
  pcf_test(IsTest, ConstSpObjectFromConstSpStringNullIsString)
  pcf_test(IsTest, ConstSpObjectFromConstSpStringNullIsObject)
  pcf_test(IsTest, ConstSpObjectFormConstSpStringNullIsIComparable)
  pcf_test(IsTest, ConstSpObjectFormConstSpStringNullIsInt32)
  pcf_test(IsTest, UpStringIsString)
  pcf_test(IsTest, UpStringIsObject)
  pcf_test(IsTest, UpStringIsIComparable)
  pcf_test(IsTest, UpStringIsInt32)
  pcf_test(IsTest, UpObjectFromUpStringIsString)
  pcf_test(IsTest, UpObjectFromUpStringIsObject)
  pcf_test(IsTest, UpObjectFormUpStringIsIComparable)
  pcf_test(IsTest, UpObjectFormUpStringIsInt32)
  pcf_test(IsTest, UpStringNullIsString)
  pcf_test(IsTest, UpStringNullIsObject)
  pcf_test(IsTest, UpStringNullIsIComparable)
  pcf_test(IsTest, UpStringNullIsInt32)
  pcf_test(IsTest, UpObjectFromUpStringNullIsString)
  pcf_test(IsTest, UpObjectFromUpStringNullIsObject)
  pcf_test(IsTest, UpObjectFormUpStringNullIsIComparable)
  pcf_test(IsTest, UpObjectFormUpStringNullIsInt32)
  pcf_test(IsTest, RefStringIsString)
  pcf_test(IsTest, RefStringIsObject)
  pcf_test(IsTest, RefStringIsIComparable)
  pcf_test(IsTest, RefStringIsInt32)
  pcf_test(IsTest, RefObjectFromRefStringIsString)
  pcf_test(IsTest, RefObjectFromRefStringIsObject)
  pcf_test(IsTest, RefObjectFormRefStringIsIComparable)
  pcf_test(IsTest, RefObjectFormRefStringIsInt32)
  pcf_test(IsTest, RefStringNullIsString)
  pcf_test(IsTest, RefStringNullIsObject)
  pcf_test(IsTest, RefStringNullIsIComparable)
  pcf_test(IsTest, RefStringNullIsInt32)
  pcf_test(IsTest, RefObjectFromRefStringNullIsString)
  pcf_test(IsTest, RefObjectFromRefStringNullIsObject)
  pcf_test(IsTest, RefObjectFormRefStringNullIsIComparable)
  pcf_test(IsTest, RefObjectFormRefStringNullIsInt32)
  pcf_test(IsTest, ConstRefStringIsString)
  pcf_test(IsTest, ConstRefStringIsObject)
  pcf_test(IsTest, ConstRefStringIsIComparable)
  pcf_test(IsTest, ConstRefStringIsInt32)
  pcf_test(IsTest, ConstRefObjectFromConstRefStringIsString)
  pcf_test(IsTest, ConstRefObjectFromConstRefStringIsObject)
  pcf_test(IsTest, ConstRefObjectFormConstRefStringIsIComparable)
  pcf_test(IsTest, ConstRefObjectFormConstRefStringIsInt32)
  pcf_test(IsTest, ConstRefStringNullIsString)
  pcf_test(IsTest, ConstRefStringNullIsObject)
  pcf_test(IsTest, ConstRefStringNullIsIComparable)
  pcf_test(IsTest, ConstRefStringNullIsInt32)
  pcf_test(IsTest, ConstRefObjectFromConstRefStringNullIsString)
  pcf_test(IsTest, ConstRefObjectFromConstRefStringNullIsObject)
  pcf_test(IsTest, ConstRefObjectFormConstRefStringNullIsIComparable)
  pcf_test(IsTest, ConstRefObjectFormConstRefStringNullIsInt32)
}
