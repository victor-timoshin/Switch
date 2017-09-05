/// @file
/// @brief Contains Switch::System::ComponentModel::ISite interface.
#pragma once

#include <Switch/Interface.hpp>

#include "IComponent.hpp"

namespace Switch {
  namespace System {
    namespace ComponentModel {
      class IComponenent;
      /// @interface ISite
      /// @brief Provides functionality required by sites.
      class _public ISite _interface {
      public:
        /// @brief A valid value for this property (that is, the value is not null) indicates that the component has been added to a container.
        virtual const IComponenent& GetComponent() const = 0;
      };
    }
  }
}