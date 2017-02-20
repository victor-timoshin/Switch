#include <limits>
#include "../../../Includes/Pcf/System/Int16.h"
#include "../../../Includes/Pcf/System/Convert.h"
#include "../../../Includes/Pcf/System/DivideByZeroException.h"
#include "../../../Includes/Pcf/System/NumericalFormat.h"
#include "../../../Includes/Pcf/System/NumericalParsing.h"

using namespace System;

Property<int16, ReadOnly> Int16::MaxValue {
  [] {return std::numeric_limits<int16>::max();}
};

Property<int16, ReadOnly> Int16::MinValue {
  [] {return std::numeric_limits<int16>::min();}
};

int16 Int16::Parse(const string& value) {
  return Parse(value,10);
}

int16 Int16::Parse(const string& str, const int32 base) {
  int64 value = NumericalParsing::ParseSigned(str, base, 16);
  return Convert::ToInt16(value);
}

bool Int16::TryParse(const string& value, int16& retValue) {
  return TryParse(value, 10, retValue);
}

bool Int16::TryParse(const string& value, Int16& retValue) {
  return TryParse(value, 10, retValue.value);
}

bool Int16::TryParse(const string& str, int32 base, int16& value) {
  try {
    value = Parse(str,base);
  } catch(const Exception&) {
    return false;
  }
  return true;
}

bool Int16::TryParse(const string& value, int32 base, Int16& retValue) {
  return TryParse(value, base, retValue.value);
}

int32 Int16::GetHashCode() const noexcept
{
  return this->value;
}

string Int16::ToString() const noexcept {
  return ToString("g", Reference<IFormatProvider>::Null());
}

string Int16::ToString(const string& format) const {
  return ToString(format, Reference<IFormatProvider>::Null());
}

string Int16::ToString(const string& format, const IFormatProvider&) const {
  int64 arg = Convert::ToInt64(this->value);
  int32 precision;
  char32 type = NumericalFormat::GetFormatType(format, precision);
  switch(type) {
    case 0:   return NumericalFormat::Format_Custom(arg,format);
    case 'b': return NumericalFormat::Format_B(arg, precision, 16);
    case 'd': return NumericalFormat::Format_D(arg, precision);
    case 'f': 
      if (format.Length() == 1) precision = 2;
      return NumericalFormat::Format_F(arg, precision);
    case 'g':
    case 'G': {
      if (precision == 0) precision = 5;
      return NumericalFormat::Format_G(arg, precision, type == 'G');
    }

    case 'n': 
      if (format.Length() == 1) precision = 2;
      return NumericalFormat::Format_N(arg, precision);
    case 'p': 
      if (format.Length() == 1) precision = 2;
      return NumericalFormat::Format_P(arg, precision);
    case 'x': return NumericalFormat::Format_X(arg, precision, false, 4);
    case 'X': return NumericalFormat::Format_X(arg, precision, true,  4);
  }
  return format;
}

int32 Int16::CompareTo(const Int16& value) const {
  return this->value - value.value;
}

int32 Int16::CompareTo(const IComparable& obj) const {
  if (!is<Int16>(obj))
    return 1;
 return CompareTo(static_cast<const Int16&>(obj));
}

TypeCode Int16::GetTypeCode() const {
  return TypeCode::Int16;
}

bool Int16::ToBoolean(const IFormatProvider&) const {
  return this->value != 0;
}

byte Int16::ToByte(const IFormatProvider&) const {
  if (this->value < Byte::MinValue)
    throw OverflowException(pcf_current_information);

  if (this->value > Byte::MaxValue)
    throw OverflowException(pcf_current_information);

  return (sbyte)value;
}

char32 Int16::ToChar(const IFormatProvider&) const {
  if (this->value < 0)
    throw OverflowException(pcf_current_information);
  
  return this->value;
}

DateTime Int16::ToDateTime(const IFormatProvider&) const {
  return DateTime((int64)this->value);
}

double Int16::ToDouble(const IFormatProvider&) const {
  return (double)this->value;
}

int16 Int16::ToInt16(const IFormatProvider&) const {
  return this->value;
}

int32 Int16::ToInt32(const IFormatProvider&) const {
  return (int32)this->value;
}

int64 Int16::ToInt64(const IFormatProvider&) const {
  return (int64)this->value;
}

uint16 Int16::ToUInt16(const IFormatProvider&) const {
  if (this->value < UInt16::MinValue)
    throw OverflowException(pcf_current_information);
  
  return (uint16)this->value;
}

uint32 Int16::ToUInt32(const IFormatProvider&) const {
  if (this->value < 0)
    throw OverflowException(pcf_current_information);
    
  return (uint32)this->value;
}

uint64 Int16::ToUInt64(const IFormatProvider&) const {
  if (this->value < 0)
    throw OverflowException(pcf_current_information);
    
  return (uint64)this->value;
}

sbyte Int16::ToSByte(const IFormatProvider&) const {
  if (this->value < SByte::MinValue)
    throw OverflowException(pcf_current_information);
  
  if (this->value > SByte::MaxValue)
    throw OverflowException(pcf_current_information);
  
  return (sbyte)this->value;
}

float Int16::ToSingle(const IFormatProvider&) const {
  return (float)this->value;
}

string Int16::ToString(const IFormatProvider&) const {
  return ToString();
}

Int16::operator int16() const {
  return this->value;
}

Int16& Int16::operator =(const Int16& value) {
  this->value = value.value;
  return *this;
}

Int16& Int16::operator +=(const Int16& value) {
  this->value += value.value;
  return *this;
}

Int16& Int16::operator -=(const Int16& value) {
  this->value -= value.value;
  return *this;
}

Int16& Int16::operator *=(const Int16& value) {
  this->value *= value.value;
  return *this;
}

Int16& Int16::operator /=(const Int16& value) {
  if (value == 0)
    throw DivideByZeroException(pcf_current_information);
  
  this->value /= value.value;
  return *this;
}

Int16& Int16::operator %=(const Int16& value) {
  if (value == 0)
    throw DivideByZeroException(pcf_current_information);
  
  this->value %= value;
  return *this;
}

Int16& Int16::operator &=(const Int16& value) {
   this->value &= value.value;
   return *this;
}

Int16& Int16::operator |=(const Int16& value) {
   this->value |= value.value;
   return *this;
}

Int16& Int16::operator ^=(const Int16& value) {
   this->value ^= value.value;
   return *this;
}

Int16& Int16::operator <<=(const Int16& value) {
   this->value <<= value.value;
   return *this;
}

Int16& Int16::operator >>=(const Int16& value) {
   this->value >>= value.value;
   return *this;
}

Int16& Int16::operator ++() {
  ++this->value;
  return *this;
}

const Int16 Int16::operator ++(int) {
  return this->value++;
}

Int16& Int16::operator --() {
  --this->value;
  return *this;
}

const Int16 Int16::operator --(int) {
  return this->value--;
}

