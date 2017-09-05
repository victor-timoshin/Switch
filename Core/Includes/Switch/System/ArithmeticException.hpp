/// @file
/// @brief Contains Switch::System::ArithmeticException exception.
#pragma once

#include "SystemException.hpp"

/// @brief The Switch library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The exception that is thrown for errors in an arithmetic, casting, or conversion operation.
    class _public ArithmeticException : public SystemException {
    public:
      /// @brief Create a new instance of class ArithmeticException
      /// @remarks Message is set with the default message associate to the error.
      ArithmeticException() : SystemException() {}
      
      /// @brief Create a new instance of class ArithmeticException
      /// @param value The Excetion to copy.
      /// @remarks Message is set with the default message associate to the error.
      ArithmeticException(const ArithmeticException& value) : SystemException(value) {}
      
      /// @brief Create a new instance of class ArithmeticException
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #_current_information.
      /// @remarks Message is set with the default message associate to the error.
      ArithmeticException(const CurrentInformation& information) : SystemException(information) {}
      
      /// @brief Create a new instance of class ArithmeticException
      /// @param message Message string associate to the error.
      ArithmeticException(const System::String& message) : SystemException(message) {}
      
      /// @brief Create a new instance of class ArithmeticException
      /// @param message Message string associate to the error.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #_current_information.
      ArithmeticException(const System::String& message, const CurrentInformation& information) : SystemException(message, information) {}
      
      /// @brief Create a new instance of class ArithmeticException
      /// @param message Message string associate to the error.
      /// @param innerException The exception that is the cause of the current exception, or a null reference if no inner exception is specified.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #_current_information.
      ArithmeticException(const System::String& message, const System::Exception& innerException, const CurrentInformation& information) : SystemException(message, innerException, information) {}
      
    private:
      System::String GetDefaultMessage() const override {return "Overflow or underflow in the arithmetic operation."; }
    };
  }
}

using namespace Switch;
