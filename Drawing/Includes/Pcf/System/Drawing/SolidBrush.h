/// @file
/// @brief Contains Pcf::System::Drawing::SolidBrush class.
#pragma once

#include "Brush.h"
#include "Color.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the System::Drawing::Drawing2D, System::Drawing::Imaging, and System::Drawing::Text namespaces.
    namespace Drawing {
      class pcf_public SolidBrush : public Brush {
      public:
        explicit SolidBrush(const System::Drawing::Color& color);
        SolidBrush(const SolidBrush& brush) : SolidBrush(brush.color) {}
        SolidBrush& operator=(const SolidBrush& brush);

        Property<System::Drawing::Color, ReadOnly> Color {
          pcf_get {return this->color;}
        };

        UniquePointer<object> Clone() const override {
          return as<object>(UniquePointer<SolidBrush>::Create(this->color));
        };

      private:
        System::Drawing::Color color;
      };
    }
  }
}
