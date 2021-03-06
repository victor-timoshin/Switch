/// @file
/// @brief Contains Switch::System::Windows::Forms::VisualStyles::VisualStyleState enum.
#pragma once

#include <Switch/System/Enum.hpp>

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Switch::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Switch::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
      namespace Forms {
        /// @brief The Switch::System::Windows::Forms::VisualStyles namespace contains classes for rendering controls and other Windows user interface (UI) elements with visual styles in operating systems that support them.
        namespace VisualStyles {
          /// @brief Specifies how visual styles are applied to the current application.
          /// @par Library
          /// Switch.System.Windows.Forms
          /// @remarks This enumeration is used by the Application::VisualStyleState property to specify whether visual styles are applied to client or nonclient areas of application windows.
          enum class VisualStyleState {
            /// @brief Visual styles are not applied to the application.
            NoneEnabled = 0,
            /// @brief Visual styles are applied only to the nonclient area.
            NonClientAreaEnabled = 1,
            /// @brief Visual styles are applied only to the client area.
            ClientAreaEnabled = 2,
            /// @brief Visual styles are applied to client and nonclient areas.
            ClientAndNonClientAreasEnabled = 3,
          };
        }
      }
    }
  }
}

/// @cond
template<>
struct EnumRegister<System::Windows::Forms::VisualStyles::VisualStyleState> {
public:
  void operator()(System::Collections::Generic::IDictionary<System::Windows::Forms::VisualStyles::VisualStyleState, string>& values, bool& flags) {
    values[System::Windows::Forms::VisualStyles::VisualStyleState::NoneEnabled] = "NoneEnabled";
    values[System::Windows::Forms::VisualStyles::VisualStyleState::NonClientAreaEnabled] = "NonClientAreaEnabled";
    values[System::Windows::Forms::VisualStyles::VisualStyleState::ClientAreaEnabled] = "ClientAreaEnabled";
    values[System::Windows::Forms::VisualStyles::VisualStyleState::ClientAndNonClientAreasEnabled] = "ClientAndNonClientAreasEnabled";
    flags = false;
  }
};
/// @endcond

using namespace Switch;
