#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      // Define Boolean true and false values.
      Array<bool> values = {true, false};

      // Display the value and its corresponding byte array.
      Console::WriteLine("{0,10}{1,16}\n", "Boolean", "Bytes");
      for (bool value : values) {
        Array<byte> bytes = BitConverter::GetBytes(value);
        Console::WriteLine("{0,10}{1,16}", value, BitConverter::ToString(bytes));
      }
    }
  };
}

startup_(Examples::Program);

// This code produces the following output:
//
//       bool           Bytes
//
//       True              01
//      False              00
