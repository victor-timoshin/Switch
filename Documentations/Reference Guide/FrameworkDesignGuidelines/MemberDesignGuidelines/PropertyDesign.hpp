/// @page PropertyDesignPage Property Design
/// Although properties are technically very similar to methods, they are quite different in terms of their usage scenarios. They should be seen as smart fields. They have the calling syntax of fields, and the flexibility of methods.
///
/// <b>√ DO</b> create get-only properties if the caller should not be able to change the value of the property.
///
/// Keep in mind that if the type of the property is a mutable reference type, the property value can be changed even if the property is get-only.
///
/// <b>X DO NOT</b> provide set-only properties or properties with the setter having broader accessibility than the getter.
///
/// For example, do not use properties with a public setter and a protected getter.
///
/// If the property getter cannot be provided, implement the functionality as a method instead. Consider starting the method name with Set and follow with what you would have named the property. For example, AppDomain has a method called SetCachePath instead of having a set-only property called CachePath.
///
/// <b>√ DO</b> provide sensible default values for all properties, ensuring that the defaults do not result in a security hole or terribly inefficient code.
///
/// <b>√ DO</b> allow properties to be set in any order even if this results in a temporary invalid state of the object.
///
/// It is common for two or more properties to be interrelated to a point where some values of one property might be invalid given the values of other properties on the same object. In such cases, exceptions resulting from the invalid state should be postponed until the interrelated properties are actually used together by the object.
///
/// <b>√ DO</b> preserve the previous value if a property setter throws an exception.
///
/// X AVOID throwing exceptions from property getters.
///
/// Property getters should be simple operations and should not have any preconditions. If a getter can throw an exception, it should probably be redesigned to be a method. Notice that this rule does not apply to indexers, where we do expect exceptions as a result of validating the arguments.
///
/// @section SeeSection See also
/// Other Resources
/// * @ref CorelibSection
/// * @ref FrameworkDesignGuidelinesPage
/// * @ref TypeDesignGuidelinesPage