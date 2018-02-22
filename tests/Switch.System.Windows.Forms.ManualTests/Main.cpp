#include <Switch/System/Diagnostics/ConsoleTraceListener.hpp>
#include <Switch/System/Diagnostics/Debug.hpp>
#include <Switch/System/Windows/Forms/Application.hpp>
#include <Switch/System/Windows/Forms/Form.hpp>
#include <Switch/System/Windows/Forms/Screen.hpp>
#include <Switch/Startup.hpp>

using namespace System;
using namespace System::Windows::Forms;

namespace ManualTests {
  class Program {
  public:
    static void Main() {
      System::Diagnostics::Debug::Listeners().Add(System::Diagnostics::ConsoleTraceListener());
      for (Screen screen : Screen::AllScreens()) {
        System::Diagnostics::Debug::WriteLine(string::Format("DeviceName = {0}", screen.DeviceName));
        System::Diagnostics::Debug::WriteLine(string::Format("  Bounds = {0}", screen.Bounds));
        System::Diagnostics::Debug::WriteLine(string::Format("  WorkingArea = {0}", screen.WorkingArea));
        System::Diagnostics::Debug::WriteLine(string::Format("  Primary = {0}", screen.Primary));
        System::Diagnostics::Debug::WriteLine(string::Format("  BitsPerPixel = {0}", screen.BitsPerPixel));
      }

      Button button;
      button.Text = "Create";
      button.Location = System::Drawing::Point(10, 10);

      Form mainForm;
      mainForm.Text = "ManualTests";
      mainForm.Controls().Add(button);

      System::Collections::Generic::List < $<Form >> forms;
      int number = 1;
      button.Click += delegate_(const object & sender, const EventArgs & e) {
        $<Form> form = new_<Form>();
        form->Text = string::Format("Form {0}", number++);
        form->Visible = true;
        forms.Add(form);
      };

      mainForm.ShowDialog();
    }
  };
}

startup_(ManualTests::Program);
