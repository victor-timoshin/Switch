#include "../../../../../Includes/Pcf/System/Windows/Forms/Application.h"
#include "../../../../../Includes/Pcf/System/Windows/Forms/Button.h"
#include "../../../../__OS/FormsApi.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

void Button::CreateHandle() {
  this->handle = __OS::FormsApi::Button::Create(*this);
  this->Control::CreateHandle();
  __OS::FormsApi::Button::SetIsDefault(*this);
}

void Button::SetIsDefault(bool isDefault) {
  if (this->isDefault != isDefault) {
    this->isDefault = isDefault;
    if (this->IsHandleCreated)
      __OS::FormsApi::Button::SetIsDefault(*this);
  }
}
