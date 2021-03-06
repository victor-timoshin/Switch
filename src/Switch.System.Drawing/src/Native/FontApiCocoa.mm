#if defined(__APPLE__)
#import <Cocoa/Cocoa.h>
#import <Foundation/Foundation.h>
#include "Api.hpp"
#include "../../include/Switch/System/Drawing/Font.hpp"
#include "../../include/Switch/System/Drawing/FontFamily.hpp"
#include "../../include/Switch/System/Drawing/FontStyle.hpp"
#include "../../include/Switch/System/Drawing/GraphicsUnit.hpp"

using namespace System;
using namespace System::Drawing;

intptr Native::FontApi::Create(const System::Drawing::FontFamily& family, float emSize, System::Drawing::FontStyle style, byte gdiCharSet, bool gdiVerticalFont) {
  NSFont* hfont = [NSFont fontWithName:[NSString stringWithUTF8String:family.Name().c_str()] size:GetHeight(emSize, IntPtr::Zero)];
  if ((style & System::Drawing::FontStyle::Bold) == System::Drawing::FontStyle::Bold) hfont = [[NSFontManager sharedFontManager] convertFont:hfont toHaveTrait:NSFontBoldTrait];
  if ((style & System::Drawing::FontStyle::Italic) == System::Drawing::FontStyle::Italic) hfont = [[NSFontManager sharedFontManager] convertFont:hfont toHaveTrait:NSFontItalicTrait];
  return (intptr)hfont;
}

void Native::FontApi::Destroy(intptr hfont) {
  [(NSFont*)hfont release];
}

void Native::FontApi::GetInformation(intptr hfont, string& name, float& size, System::Drawing::FontStyle& style) {
  NSFont* font = (NSFont*)hfont;
  name = [[font fontName] UTF8String];
  size = [font pointSize] / 4 * 3;
  style = FontStyle::Regular;
}

float Native::FontApi::GetHeight(float emSize, intptr hdc) {
  return emSize / 3 * 4;
}

float Native::FontApi::GetSize(float height, intptr hdc) {
  return height / 4 * 3;
}

#endif
