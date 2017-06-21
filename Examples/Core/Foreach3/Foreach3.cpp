#include <Pcf/Pcf>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      string str = string::Join(Environment::NewLine, {"Red", "Blue", "Green", "Yellow", "Gray"});
      
      for (char32 item : str) {
        Console::Write(item);
      }
    }
  };
}

pcf_startup (Examples::Program)

// This code produces the following output:
//
// Red
// Blue
// Green
// Yellow
// Gray