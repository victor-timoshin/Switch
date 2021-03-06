#include <Switch/Switch>

using namespace System;
using namespace System::Linq;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      int x[] = { 42, 24, 84, 21, 48, 12 };
      int y[] = { 5, 1, 71, 80 };

      auto query = Enumerable::AsEnumerable(x)->Concat(y)->Where([](int i) {return i != 21;})->OrderByDescending<int>([](int i) {return i;});

      Console::WriteLine("query = {{{0}}}", string::Join(", ", *query));
    }
  };
}

startup_(Examples::Program);

// This code example produces the following output:
//
// query = {84, 80, 71, 48, 42, 24, 12, 5, 1}

