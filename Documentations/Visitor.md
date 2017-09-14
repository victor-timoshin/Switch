![Switch Header](Images/SwitchNativeC++port.png)

| [Home](Home.md) | [Gallery](Gallery.md) | [Examples](Examples.md) | [Download](Download.md) | [Documentation](Documentation.md) | [Project](https://sourceforge.net/projects/switchpro) | [Source](https://github.com/gammasoft71/switch) | [License](License.md) | [Contact](Contact.md) | [GAMMA Soft](https://gammasoft71.wixsite.com/gammasoft) |
|-----------------|-----------------------|-------------------------|-------------------------|-----------------------------------|-------------------------------------------------------|-------------------------------------------------|-----------------------|-----------------------|---------------------------------------------------------|

# Definition

Represent an operation to be performed on the elements of an object structure. Visitor lets you define a new operation without changing the classes of the elements on which it operates.

# UML class diagram

![AbstractFactory](Images/DesignPatterns/visitor.gif)

# Sample code

This structural code demonstrates the Visitor pattern in which an object traverses an object structure and performs the same operation on each node in this structure. Different visitor objects define different operations.

```c++
// Visitor pattern -- Behavorail example
 
#include <Switch/Switch>
 
using namespace System;
using namespace System::Collections::Generic;
 
namespace DesignPatterns {
  namespace Behavioral {
    class Visitor;
    
    // The 'Element' abstract class
    class Element _abstract {
    public:
      virtual void Accept(refptr<Visitor> visitor) = 0;
    };
    
    // A 'ConcreteElement' class
    class ConcreteElementA : public Element {
    public:
      void Accept(refptr<Visitor> visitor) override;
      
      void OperationA() {
      }
    };
    
    // A 'ConcreteElement' class
    class ConcreteElementB : public Element {
    public:
      void Accept(refptr<Visitor> visitor) override;
      
      void OperationB() {
      }
    };
    
    // The 'Visitor' abstract class
    class Visitor _abstract {
    public:
      virtual void VisitConcreteElementA(const ConcreteElementA& concreteElementA) = 0;
      virtual void VisitConcreteElementB(const ConcreteElementB& concreteElementB) = 0;
    };
 
    inline void ConcreteElementA::Accept(refptr<Visitor> visitor) {
      visitor->VisitConcreteElementA(*this);
    }
 
    inline void ConcreteElementB::Accept(refptr<Visitor> visitor) {
      visitor->VisitConcreteElementB(*this);
    }
    
    // A 'ConcreteVisitor' class
    class ConcreteVisitor1 : public Visitor {
    public:
      void VisitConcreteElementA(const ConcreteElementA& concreteElementA) override {
        Console::WriteLine("{0} visited by {1}", concreteElementA.GetType().Name, this->GetType().Name);
      }
      
      void VisitConcreteElementB(const ConcreteElementB& concreteElementB) override {
        Console::WriteLine("{0} visited by {1}", concreteElementB.GetType().Name, this->GetType().Name);
      }
    };
    
    // A 'ConcreteVisitor' class
    class ConcreteVisitor2 : public Visitor {
    public:
      void VisitConcreteElementA(const ConcreteElementA& concreteElementA) override {
        Console::WriteLine("{0} visited by {1}", concreteElementA.GetType().Name, this->GetType().Name);
      }
      
      void VisitConcreteElementB(const ConcreteElementB& concreteElementB) override {
        Console::WriteLine("{0} visited by {1}", concreteElementB.GetType().Name, this->GetType().Name);
      }
    };
    
    // The 'ObjectStructure' class
    class ObjectStructure : public object {
    public:
      void Attach(refptr<Element> element) {
        this->elements.Add(element);
      }
      
      void Detach(refptr<Element> element) {
        this->elements.Remove(element);
      }
      
      void Accept(refptr<Visitor> visitor) {
        for (refptr<Element> element : this->elements) {
          element->Accept(visitor);
        }
      }
    private:
      List<refptr<Element>> elements;
    };
 
    // MainApp startup class for Behavioral
    // Visitor Design Pattern.
    class MainApp {
    public:
      static void Main() {
        // Setup structure
        ObjectStructure o;
        o.Attach(ref_new<ConcreteElementA>());
        o.Attach(ref_new<ConcreteElementB>());
        
        // Create visitor objects
        refptr<ConcreteVisitor1> v1 = ref_new<ConcreteVisitor1>();
        refptr<ConcreteVisitor2> v2 = ref_new<ConcreteVisitor2>();
        
        // Structure accepting visitors
        o.Accept(v1);
        o.Accept(v2);
      }
    };
  }
}
 
// Specify the Main entry point to System
_startup (DesignPatterns::Behavioral::MainApp)
```

# Output

```
ConcreteElementA visited by ConcreteVisitor1
ConcreteElementB visited by ConcreteVisitor1
ConcreteElementA visited by ConcreteVisitor2
ConcreteElementB visited by ConcreteVisitor2
```

# See also
​
Other Resources

* [Framework Design Guidelines](FrameworkDesignGuidelines.md)
* [Common Design Patterns](CommonDesignPatterns.md)

______________________________________________________________________________________________

© 2010 - 2017 by GAMMA Soft.