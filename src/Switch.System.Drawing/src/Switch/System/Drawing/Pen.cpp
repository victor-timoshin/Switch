#include "../../../../include/Switch/System/Drawing/Pen.hpp"
#include "../../../Native/DrawingApi.hpp"

using namespace System;
using namespace System::Drawing;

void Pen::Create() {
  this->Destroy();
  this->pen = Native::DrawingApi::Pen::CreatePen(this->dashStyle, this->width, as<SolidBrush>(this->brush)().Color);
}

void Pen::Destroy() {
  if (this->pen != IntPtr::Zero)
    Native::DrawingApi::Pen::DeletePen(this->pen);
  this->pen = IntPtr::Zero;
}
