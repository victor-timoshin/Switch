/// @file
/// @brief Contains Pcf::System::Windows::Forms::Button class.
#pragma once

#include <Pcf/System/Environment.h>
#include "Control.h"
#include "ProgressBarStyle.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The Pcf::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Pcf::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Pcf::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Pcf::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple Mac Os X and Linux like Ubuntu operating system.
      namespace Forms {
        /// @brief Represents a standard Windows label.
        /// @remarks Label controls are typically used to provide descriptive text for a control. For example, you can use a Label to add descriptive text for a TextBox control to inform the user about the type of data expected in the control. Label controls can also be used to add descriptive text to a Form to provide the user with helpful information. For example, you can add a Label to the top of a Form that provides instructions to the user on how to input data in the controls on the form. Label controls can be also used to display run time information on the status of an application. For example, you can add a Label control to a form to display the status of each file as a list of files is processed.
        /// @remarks A Label participates in the tab order of a form, but does not receive focus (the next control in the tab order receives focus). For example, if the UseMnemonic property is set to true, and a mnemonic character�the first character after an ampersand (&)�is specified in the Text property of the control, when a user presses ALT+ the mnemonic key, focus moves to the next control in the tab order. This feature provides keyboard navigation for a form. In addition to displaying text, the Label control can also display an image using the Image property, or a combination of the ImageIndex and ImageList properties.
        /// @note A Label can be made transparent by setting its BackColor property to Color.Transparent. When you use a transparent label, use only the current device coordinate system to draw on the container, or the Label background might paint improperly.
        class pcf_public ProgressBar : public Control {
        public:
          ProgressBar() : Control("", 0, 0, 100, System::Environment::OSVersion().Platform == System::PlatformID::MacOSX ? 20 : 23) {
            this->SetStyle(ControlStyles::UserPaint, false);
            this->TabStop = false;
          }

          Property<int32> Maximum{
            pcf_get{ return this->maximum; },
            pcf_set{ this->SetMaximum(value); },
          };

          Property<int32> Minimum{
            pcf_get{ return this->minimum; },
            pcf_set{ this->SetMinimum(value); },
          };

          Property<ProgressBarStyle> Style{
            pcf_get{ return this->style; },
            pcf_set{ this->SetProgressStyle(value); },
          };

          Property<int32> Value{
            pcf_get{ return this->value; },
            pcf_set{ this->SetValue(value); },
          };

        protected:
          void CreateHandle() override;
          System::Drawing::Size GetDefaultSize() const override { return System::Drawing::Size(100, System::Environment::OSVersion().Platform == System::PlatformID::MacOSX ? 20 : 23); }
          void SetMaximum(int32 maximum);
          void SetMinimum(int32 minimum);
          void SetProgressStyle(ProgressBarStyle style);
          void SetValue(int32 value);

          /// @cond
          int32 maximum = 100;
          int32 minimum = 0;
          ProgressBarStyle style = ProgressBarStyle::Blocks;
          int32 value = 0;
          /// @endcond
        };
      }
    }
  }
}