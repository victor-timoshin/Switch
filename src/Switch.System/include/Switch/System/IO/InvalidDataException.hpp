/// @file
/// @brief Contains Switch::System::IO::InvalidDataException exception.
#pragma once

#include <Switch/System/IO/IOException.hpp>
#include "../../SystemExport.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::IO namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
    namespace IO {
      /// @brief The exception that is thrown when a data stream is in an invalid format.
      class system_export_ InvalidDataException : public IOException {
      public:
        /// @brief Create a new instance of class InvalidDataException
        /// @remarks Message is set with the default message associate to the error.
        InvalidDataException() : IOException() {}

        /// @brief Create a new instance of class InvalidDataException
        /// @param value The Excetion to copy.
        /// @remarks Message is set with the default message associate to the error.
        InvalidDataException(const InvalidDataException& value) : IOException(value) {}

        /// @brief Create a new instance of class InvalidDataException
        /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
        /// @remarks Message is set with the default message associate to the error.
        InvalidDataException(const System::Runtime::CompilerServices::Caller& information) : IOException(information) {}

        /// @brief Create a new instance of class InvalidDataException
        /// @param message Message string associate to the error.
        InvalidDataException(const System::String& message) : IOException(message) {}

        /// @brief Create a new instance of class InvalidDataException
        /// @param message Message string associate to the error.
        /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
        InvalidDataException(const System::String& message, const System::Runtime::CompilerServices::Caller& information) : IOException(message, information) {}

        /// @brief Create a new instance of class InvalidDataException
        /// @param message Message string associate to the error.
        /// @param innerException The exception that is the cause of the current exception, or a null reference if no inner exception is specified.
        /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
        InvalidDataException(const System::String& message, const System::Exception& innerException, const System::Runtime::CompilerServices::Caller& information) : IOException(message, innerException, information) {}

      private:
        System::String GetDefaultMessage() const override {return "Found invalid data while decoding."; }
      };
    }
  }
}

using namespace Switch;
