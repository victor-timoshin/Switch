#include <Switch/Switch>

using namespace System;
using namespace System::Collections;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      // Create a new hash table.
      //
      Hashtable openWith;

      // Add some elements to the hash table. There are no
      // duplicate keys, but some of the values are duplicates.
      openWith.Add("txt", "notepad.exe");
      openWith.Add("bmp", "paint.exe");
      openWith.Add("dib", "paint.exe");
      openWith.Add("rtf", "wordpad.exe");

      // The Add method throws an exception if the new key is
      // already in the hash table.
      try {
        openWith.Add("txt", "winword.exe");
      } catch (...) {
        Console::WriteLine("An element with Key = \"txt\" already exists.");
      }

      // The Item property is the default property, so you
      // can omit its name when accessing elements.
      Console::WriteLine("For key = \"rtf\", value = {0}.", openWith["rtf"]);

      // The default Item property can be used to change the value
      // associated with a key.
      openWith["rtf"] = "winword.exe";
      Console::WriteLine("For key = \"rtf\", value = {0}.", openWith["rtf"]);

      // If a key does not exist, setting the default Item property
      // for that key adds a new key/value pair.
      openWith["doc"] = "winword.exe";

      // ContainsKey can be used to test keys before inserting
      // them.
      if (!openWith.ContainsKey("ht")) {
        openWith.Add("ht", "hypertrm.exe");
        Console::WriteLine("Value added for key = \"ht\": {0}", openWith["ht"]);
      }

      // When you use foreach to enumerate hash table elements,
      // the elements are retrieved as KeyValuePair objects.
      Console::WriteLine();
      for (DictionaryEntry de : openWith)
        Console::WriteLine("Key = {0}, Value = {1}", de.Key, de.Value);

      // To get the values alone, use the Values property.
      Hashtable::ValueCollection valueColl = openWith.Values;

      // The elements of the ValueCollection are strongly typed
      // with the type that was specified for hash table values.
      Console::WriteLine();
      for (string s : valueColl)
        Console::WriteLine("Value = {0}", s);

      // To get the keys alone, use the Keys property.
      Hashtable::KeyCollection keyColl = openWith.Keys;

      // The elements of the KeyCollection are strongly typed
      // with the type that was specified for hash table keys.
      Console::WriteLine();
      for (string s : keyColl)
        Console::WriteLine("Key = {0}", s);

      // Use the Remove method to remove a key/value pair.
      Console::WriteLine("\nRemove(\"doc\")");
      openWith.Remove("doc");

      if (!openWith.ContainsKey("doc"))
        Console::WriteLine("Key \"doc\" is not found.");
    }
  };
}

startup_(Examples::Program);

// This code example can produces the following output:
//
// An element with Key = "txt" already exists.
// For key = "rtf", value = wordpad.exe.
// For key = "rtf", value = winword.exe.
// Value added for key = "ht": hypertrm.exe
//
// Key = ht, Value = hypertrm.exe
// Key = txt, Value = notepad.exe
// Key = doc, Value = winword.exe
// Key = dib, Value = paint.exe
// Key = rtf, Value = winword.exe
// Key = bmp, Value = paint.exe
//
// Value = hypertrm.exe
// Value = notepad.exe
// Value = winword.exe
// Value = paint.exe
// Value = winword.exe
// Value = paint.exe
//
// Key = ht
// Key = txt
// Key = doc
// Key = dib
// Key = rtf
// Key = bmp
//
// Remove("doc")
// Key "doc" is not found.
