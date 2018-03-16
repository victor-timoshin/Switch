/// @file
/// @brief Contains Switch::System::ComponentModel::Component class.
#pragma once

#include <Switch/System/Object.hpp>
#include <Switch/System/Drawing/Size.hpp>
#include "../../SystemWindowsFormsExport.hpp"
#include "IComponent.hpp"

namespace Switch {
  namespace System {
    /// @brief The Switch::System::ComponentModel namespace provides classes that are used to implement the run-time and design-time behavior of components and controls. This namespace includes the base classes and interfaces for implementing attributes and type converters, binding to data sources, and licensing components.
    namespace ComponentModel {
      /// @brief Provides the base implementation for the IComponent interface and enables object sharing between applications.
      /// @par Library
      /// Switch.System.Windows.Forms
      class system_windows_forms_export_ Component : public object, public IComponent {
      public:
        /// @brief Initializes a new instance of the Component class.
        Component() {}
        Component(const Component& component) = default;

        /// @brief Determines if events can be raised on the control.
        /// @return true if the control is hosted as an ActiveX control whose events are not frozen; otherwise, false.
        /// @remarks If this control is being hosted as an ActiveX control, this property will return false if the ActiveX control has its events frozen.
        virtual bool CanRaiseEvent() const {return true;}

        virtual void Close() {}
      };
    }
  }
}
