// Bridge pattern -- Structural example

#include <Pcf/Pcf>

using namespace System;

namespace DesignPatterns {
  namespace Structural {
    // The 'Implementor' abstract class
    class Implementor pcf_abstract {
    public:
      virtual void Operation() const = 0;
    };
    
    // The 'Abstraction' class
    class Abstraction : public object {
    public:
      // Property
      Property<refptr<DesignPatterns::Structural::Implementor>, WriteOnly> Implementor {
        pcf_set {this->implementor = value;}
      };
      
      virtual void Operation() const {
        this->implementor->Operation();
      }

    protected:
      refptr<DesignPatterns::Structural::Implementor> implementor;
    };
    
    // The 'RefinedAbstraction' class
    class RefinedAbstraction : public Abstraction {
    public:
      void Operation() const override {
        this->implementor->Operation();
      }
    };
    
    // The 'ConcreteImplementorA' class
    class ConcreteImplementorA : public Implementor {
    public:
      void Operation() const override {
        Console::WriteLine("ConcreteImplementorA Operation");
      }
    };
    
    // The 'ConcreteImplementorB' class
    class ConcreteImplementorB : public Implementor {
    public:
      void Operation() const override {
        Console::WriteLine("ConcreteImplementorB Operation");
      }
    };
    
    // MainApp startup class for Structural
    // Bridge Design Pattern.
    class MainApp {
    public:
      // Entry point into console application.
      static void Main() {
        refptr<Abstraction> ab = pcf_new<RefinedAbstraction>();
        
        // Set implementation and call
        ab->Implementor = pcf_new<ConcreteImplementorA>();
        ab->Operation();
        
        // Change implemention and call
        ab->Implementor = pcf_new<ConcreteImplementorB>();
        ab->Operation();
      }
    };
  }
}

// Specify the Main entry point to System
pcf_startup (DesignPatterns::Structural::MainApp)

// This code produces the following output:
//
// ConcreteImplementorA Operation
// ConcreteImplementorB Operation