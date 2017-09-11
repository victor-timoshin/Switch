/// @file
/// @brief Contains Switch::System::Threading::SynchronizationLockException exception.
#pragma once

#include "../SystemException.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Threading namespace provides classes and interfaces that enable multithreaded programming.
    /// SystemException addition to classes for synchronizing thread activities and access to data ( Mutex, Monitor, Interlocked, AutoResetEvent, and so on), this namespace includes a ThreadPool class that allows you to use a pool of system-supplied threads, and a Timer class that executes callback methods on thread pool threads.
    namespace Threading {
      /// @brief The exception that is thrown when a method requires the caller to own the lock on a given Monitor, and the method is invoked by a caller that does not own that lock.
      class _export SynchronizationLockException : public SystemException {
      public:
        /// @brief Create a new instance of class SynchronizationLockException
        /// @remarks Message is set with the default message associate to the error.
        SynchronizationLockException() : SystemException() {}
        
        /// @brief Create a new instance of class SynchronizationLockException
        /// @param value The Excetion to copy.
        /// @remarks Message is set with the default message associate to the error.
        SynchronizationLockException(const SynchronizationLockException& value) : SystemException(value) {}
        
        /// @brief Create a new instance of class SynchronizationLockException
        /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #_caller.
        /// @remarks Message is set with the default message associate to the error.
        SynchronizationLockException(const Caller& information) : SystemException(information) {}
        
        /// @brief Create a new instance of class SynchronizationLockException
        /// @param message Message string associate to the error.
        SynchronizationLockException(const System::String& message) : SystemException(message) {}
        
        /// @brief Create a new instance of class SynchronizationLockException
        /// @param message Message string associate to the error.
        /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #_caller.
        SynchronizationLockException(const System::String& message, const Caller& information) : SystemException(message, information) {}
        
        /// @brief Create a new instance of class SynchronizationLockException
        /// @param message Message string associate to the error.
        /// @param innerException The exception that is the cause of the current exception, or a null reference if no inner exception is specified.
        /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #_caller.
        SynchronizationLockException(const System::String& message, const System::Exception& innerException, const Caller& information) : SystemException(message, innerException, information) {}
        
      private:
        System::String GetDefaultMessage() const override {return "Object synchronization method was called from an unsynchronized block of code."; }
      };
    }
  }
}

using namespace Switch;
