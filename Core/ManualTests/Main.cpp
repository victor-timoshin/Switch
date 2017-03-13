#include <Pcf/Interface.h>

using namespace System;

template<typename T, int32 rank = 1, typename TAllocator=Allocator<T>>
class Array2;

#include <Pcf/System/Collections/Generic/ICollection.h>

using namespace System;

template<typename T, int32 rank, typename allocator>
class Array2;

#include <Pcf/System/Array.h>

/// @brief Provides methods for creating, manipulating, searching, && sorting arrays, thereby serving as the base class for all arrays.
/// @par Examples
/// The following code example demonstrates different methods to create an array.
/// @include Array21.cpp
/// @par Examples
/// The following code example creates && initializes an Array2 && displays its properties && its elements.
/// @include Array22.cpp
template<typename T, int32 rank, typename TAllocator>
class Array2 : public Object, public Linq::Extension::Enumerable<Array2<T, rank, TAllocator>, T>, public Collections::Generic::IList<T> {
  using Item = T;

public:
  /// @brief Initializes a new instance of the Array2 class that is empty.
  /// @remarks The Array2 class is ! thread safe.
  /// @par Examples
  /// The following code example demonstrates different methods to create an array.
  /// @include Array2Constructor.cpp
  Array2() {
    int32 r = rank;
    if (r != 1)
      throw System::ArgumentOutOfRangeException(pcf_current_information);

    this->lowerBound.push_back(0);
    this->upperBound.push_back(-1);
  }

  /// @brief Initializes a new instance of the Array2 class with lengths for each rank specified.
  /// @param length the length for the first rank.
  /// @remarks The Array2 class is ! thread safe.
  /// @par Examples
  /// The following code example demonstrates different methods to create an array.
  /// @include Array2Constructor.cpp
  explicit Array2(int32 length) : length(length), array(length) {
    int32 r = rank;
    if (r != 1)
      throw System::ArgumentOutOfRangeException(pcf_current_information);

    this->lowerBound.push_back(0);
    this->upperBound.push_back(length-1);
  }

  /// @brief Initializes a new instance of the Array2 class with lengths for each rank specified.
  /// @param length1 the length for the first rank.
  /// @param length2 the length for the second rank.
  /// @remarks The Array2 class is ! thread safe.
  /// @par Examples
  /// The following code example demonstrates different methods to create an array.
  /// @include Array2Constructor.cpp
  Array2(int32 length1, int32 length2) : length(length2 * length1), array(length2 * length1) {
    int32 r = rank;
    if (r != 2)
      throw System::ArgumentOutOfRangeException(pcf_current_information);

    this->lowerBound.push_back(0);
    this->upperBound.push_back(length1-1);
    this->lowerBound.push_back(0);
    this->upperBound.push_back(length2-1);
  }

  /// @brief Initializes a new instance of the Array2 class with lengths for each rank specified.
  /// @param length1 the length for the first rank.
  /// @param length2 the length for the second rank.
  /// @param length3 the length for the third rank.
  /// @remarks The Array2 class is ! thread safe.
  /// @par Examples
  /// The following code example demonstrates different methods to create an array.
  /// @include Array2Constructor.cpp
  Array2(int32 length1, int32 length2, int32 length3) : length(length3 * length2 * length1), array(length3 * length2 * length1) {
    int32 r = rank;
    if (r != 3)
      throw System::ArgumentOutOfRangeException(pcf_current_information);

    this->lowerBound.push_back(0);
    this->upperBound.push_back(length1-1);
    this->lowerBound.push_back(0);
    this->upperBound.push_back(length2-1);
    this->lowerBound.push_back(0);
    this->upperBound.push_back(length3-1);
  }

  /// @brief Initializes a new instance of the Array2 && copy array[] T.
  /// @param array the Array2 to copy.
  /// @remarks The Array2 class is ! thread safe.
  /// @par Examples
  /// The following code example demonstrates different methods to create an array.
  /// @include Array2Constructor.cpp
  template<int32 len>
  explicit Array2(const T (&array)[len]) : length(len), array(len) {
    int32 r = rank;
    if (r != 1)
      throw System::ArgumentOutOfRangeException(pcf_current_information);
    int l = len;
    if (l < 0)
      throw System::ArgumentOutOfRangeException(pcf_current_information);

    this->lowerBound.push_back(0);
    this->upperBound.push_back(length-1);
    for (int32 index = 0; index < length; index++)
      this->array[index] = array[index];
  }

  /// @brief Initializes a new instance of the Array2 && copy array[] T with length specified.
  /// @param array the Array2 to copy.
  /// @param length Length of the array.
  /// @remarks The Array2 class is ! thread safe.
  /// @par Examples
  /// The following code example demonstrates different methods to create an array.
  /// @include Array2Constructor.cpp
  Array2(const T* array, int32 length) : length(length), array(length) {
    if (array == null)
      throw System::ArgumentNullException(pcf_current_information);
    int32 r = rank;
    if (r != 1)
      throw System::ArgumentOutOfRangeException(pcf_current_information);
    if (length < 0)
      throw System::ArgumentOutOfRangeException(pcf_current_information);

    this->lowerBound.push_back(0);
    this->upperBound.push_back(length-1);
    for (int32 index = 0; index < length; index++)
      this->array[index] = array[index];
  }

  /// @brief Initializes a new instance of the Array2 && copy array Array2 specified.
  /// @param array the Array2 to copy.
  /// @remarks The Array2 class is ! thread safe.
  /// @par Examples
  /// The following code example demonstrates different methods to create an array.
  /// @include Array2Constructor.cpp
  Array2(const Array2& array) : length(array.length), operationNumber(array.operationNumber), array(array.array), lowerBound(array.lowerBound), upperBound(array.upperBound) {}

  /// @cond
  Array2(Array2&& array) : length(array.length), operationNumber(array.operationNumber), array(Move(array.array)), lowerBound(Move(array.lowerBound)), upperBound(Move(array.upperBound)) {
    array.length = 0;
    array.operationNumber = 0;
  }
  /// @endcond

  /// @brief Initializes a new instance of the Array2 && copy array Array2 specified.
  /// @param array the Array2 to copy.
  /// @remarks The Array2 class is ! thread safe.
  /// @par Examples
  /// The following code example demonstrates different methods to create an array.
  /// @include Array2Constructor.cpp
  explicit Array2(const Collections::Generic::IList<T>& list) : length(list.Count), array(list.Count) {
    int32 r = rank;
    if (r != 1)
      throw System::ArgumentOutOfRangeException(pcf_current_information);

    this->lowerBound.push_back(0);
    this->upperBound.push_back(this->length-1);
    for (int32 index = 0; index < list.Count; index++)
      this->array[index] = list[index];
  }

  /// @brief Initializes a new instance of the Array2 && copy array Array2 specified.
  /// @param array the Array2 to copy.
  /// @remarks The Array2 class is ! thread safe.
  /// @par Examples
  /// The following code example demonstrates different methods to create an array.
  /// @include Array2Constructor.cpp
  explicit Array2(const Collections::Generic::IEnumerable<T>& collection) {
    int32 r = rank;
    if (r != 1)
      throw System::ArgumentOutOfRangeException(pcf_current_information);

    System::Collections::Generic::Enumerator<T> enumerator = collection.GetEnumerator();
    while (enumerator.MoveNext())
      this->array.push_back(enumerator.Current);
    this->length = (int32)this->array.size();
    this->lowerBound.push_back(0);
    this->upperBound.push_back(this->length-1);
  }

  /// @cond
  Array2(InitializerList<T> il) : length((int32)il.size()), array(il) {
    this->lowerBound.push_back(0);
    this->upperBound.push_back((int32)il.size());
  }
  /// @endcond

  explicit Array2(const std::vector<T>& array) : length((int32)array.size()) {
    this->lowerBound.push_back(0);
    this->upperBound.push_back(length-1);
    for (T value : array)
      this->array.push_back(value);
  }

  /// @brief Get access to raw data of the Array2.
  /// @return A pointer to raw data of the array.
  Property<const T*, ReadOnly> Data{
    pcf_get{ return this->array.data(); }
  };

  /// @brief Gets a 32-bit integer that represents the total number of elements in all the dimensions of the Array2.
  /// @return int32 A 32-bit integer that represents the total number of elements in all the dimensions of the Array2; zero if there are no elements in the array.
  /// @par Examples
  /// The following code example demonstrates methods to get the length of an array.
  /// @include Array2GetLength.cpp
  Property<int32, ReadOnly> Length {
    pcf_get {return static_cast<int32>(this->array.size());}
  };

  /// @brief Gets a 64-bit integer that represents the total number of elements in all the dimensions of the Array2.
  /// @return int64 A 64-bit integer that represents the total number of elements in all the dimensions of the Array2; zero if there are no elements in the array.
  Property<int64, ReadOnly> LongLength {
    pcf_get {return static_cast<int64>(this->array.size());}
  };

  /// @brief Gets the rank (number of dimensions) of the Array2.
  /// @return int32 The rank (number of dimensions) of the Array2.
  /// @par Examples
  /// The following code example demonstrates methods to get the rank of an array.
  /// @include Array2GetLength.cpp
  Property<int32, ReadOnly> Rank {
    pcf_get {return rank;}
  };

  /// @brief Returns a read-only wrapper for the specified array.
  /// @param array The one-dimensional, zero-based array to wrap in a read-only ReadOnlyCollection<T> wrapper.
  /// @return A read-only ReadOnlyCollection<T> wrapper for the specified array.
  /// @remarks To prevent any modifications to the array, expose the array only through this wrapper.
  /// @remarks A collection that is read-only is simply a collection with a wrapper that prevents modifying the collection; therefore, if changes are made to the underlying collection, the read-only collection reflects those changes.
  /// @remarks This method is an O(n) operation.
  /// @par Examples
  /// The following example wraps an array in a read-only ReadOnlyCollection<T>.
  /// @include Array2AsReadOnly.cpp
  static System::Collections::ObjectModel::ReadOnlyCollection<T> AsReadOnly(const Array2& array) { return System::Collections::ObjectModel::ReadOnlyCollection<T>(array); }

  static int32 BinarySearch(const Array2& array, const T& item) {return BinarySearch(array, 0, array.Length, item, System::Collections::Generic::Comparer<T>::Default().Release());}

  static int32 BinarySearch(const Array2& array, const T& item, const SharedPointer<System::Collections::Generic::IComparer<T>>& comparer) {return BinarySearch(array, 0, array.Length, item, comparer);}

  static int32 BinarySearch(const Array2& array, int32 index, int32 count, const T& item, const SharedPointer<System::Collections::Generic::IComparer<T>>& comparer) {
    if (rank  != 1)
      throw RankException(pcf_current_information);
    if (index < 0 || count < 0)
      throw ArgumentOutOfRangeException(pcf_current_information);
    if (index + count > array->Length)
      throw ArgumentException(pcf_current_information);
    typename std::vector<T, TAllocator>::const_iterator first = array.array.begin();
    typename std::vector<T, TAllocator>::const_iterator last = array.array.begin();
    std::advance(first, index);
    std::advance(last, index+count);
    typename std::vector<T, TAllocator>::const_iterator position = std::lower_bound(first, last, item, Array2::Comparer(comparer.ToPointer()));

    if (position != array.array.end() && !comparer->Compare(item, *position))
      return static_cast<int32>(std::distance(array.array.begin(), position));

    return static_cast<int32>(~std::distance(array.array.begin(), position));
  }

  /// @brief Sets a range of elements in an array to the default value of each element type.
  /// @param array The array whose elements need to be cleared.
  /// @param index The starting index of the range of elements to clear.
  /// @param length The number of elements to clear.
  /// @exception IndexOutOfRangeException index is less than the lower bound of array.  -or- length is less than zero.  -or-  The sum of index and length is greater than the size of array.
  /// @remarks This method resets each element in an array to the element type's default value. It sets elements of reference types (including String elements) to null, and sets elements of value types to the default values shown in the following table.
  /// | Type                                          | Value                              |
  /// |-----------------------------------------------|------------------------------------|
  /// | bool                                          | false                              |
  /// | All integral and floating point numeric types | 0 (zero)                           |
  /// | DateTime                                      | DateTime::MinValue                 |
  /// | Other value types                             | Default value of the type's fields |
  /// @remarks The range of cleared elements wrap from row to row in a multi-dimensional array.
  /// @remarks This method only clears the values of the elements; it does not delete the elements themselves. An array has a fixed size; therefore, elements cannot be added or removed.
  /// @remarks This method is an O(n) operation, where n is length.
  static void Clear(Array2& array, int32 index, int32 length) {
    if (index < 0 || length < 0 || index + length > (int32)array.array.size())
      throw IndexOutOfRangeException(pcf_current_information);
    std::fill(array.array.begin()+index, array.array.begin()+index+length, T());
  }

  /// @brief Creates a one-dimensional Array2 of the specified Type and length, with zero-based indexing.
  /// @param length The size of the Array2 to create.
  /// @return A new one-dimensional Array2 of the specified Type with the specified length, using zero-based indexing.
  static Array2<T, 1, TAllocator> CreateInstance(int32 length) {return Array2<T, 1, TAllocator>(length);}

  /// @brief Creates a two-dimensional Array2 of the specified Type and dimension lengths, with zero-based indexing.
  /// @param length1 The size of the first dimension of the Array2 to create.
  /// @param length2 The size of the second dimension of the Array2 to create.
  /// @return A new two-dimensional Array2 of the specified Type with the specified length for each dimension, using zero-based indexing.
  static Array2<T, 2, TAllocator> CreateInstance(int32 length1, int32 length2) {return Array2<T, 2, TAllocator>(length1, length2);}

  /// @brief Creates a three-dimensional Array2 of the specified Type and dimension lengths, with zero-based indexing.
  /// @param length1 The size of the first dimension of the Array2 to create.
  /// @param length2 The size of the second dimension of the Array2 to create.
  /// @param length3 The size of the third dimension of the Array2 to create.
  /// @return A new three-dimensional Array2 of the specified Type with the specified length for each dimension, using zero-based indexing.
  static Array2<T, 3, TAllocator> CreateInstance(int32 length1, int32 length2, int32 length3) {return Array2<T, 3, TAllocator>(length1, length2, length3);}

  /// @brief Gets a 32-bit integer that represents the total number of elements in all the dimensions of the Array2.
  /// @param dimension A zero-based dimension of the Array2 whose length needs to be determined.
  /// @return int32 A 32-bit integer that represents the total number of elements in all the dimensions of the Array2; zero if there are no elements in the array.
  /// @exception ArgumentOutOfRangeException dimension is less than zero. -||- dimension is equal to || greater than rank.
  /// @par Examples
  /// The following code example demonstrates methods to get the length of an array.
  /// @include Array2GetLength.cpp
  int32 GetLength(int32 dimension) const { return this->GetUpperBound(dimension)+1; }

  /// @brief Returns an IEnumerator for the Array2.
  /// @return IEnumerator An IEnumerator for the Array2.
  /// @par Examples
  /// The following code example shows how to use GetEnumerator to list the elements of an array.
  /// @include Array2GetEnumerator.cpp
  Collections::Generic::Enumerator<T> GetEnumerator() const override {
    class Enumerator : public object, public Collections::Generic::IEnumerator<T> {
    public:
      explicit Enumerator(const Array2& array) : array(array), operationNumber(array.operationNumber), iterator(array.array.begin()) {}
      void Reset() override {this->beforeFirst = true; this->operationNumber = this->array.operationNumber; this->iterator = this->array.array.begin();}

      bool MoveNext() override {
        if (this->operationNumber != this->array.operationNumber) throw System::InvalidOperationException(pcf_current_information);
        if (this->iterator == this->array.array.end()) return false;
        if (this->beforeFirst) {
          this->beforeFirst = false;
          return this->iterator != this->array.array.end();
        }
        return ++this->iterator != this->array.array.end();
      }

    protected:
      const T& GetCurrent() const override {
        if (this->beforeFirst || this->iterator == this->array.array.end()) throw System::InvalidOperationException(pcf_current_information);
        return *this->iterator;
      }

      const Array2& array;
      bool beforeFirst = true;
      int64 operationNumber;
      typename std::vector<T, TAllocator>::const_iterator iterator;
    };

    return System::Collections::Generic::Enumerator<T>(new Enumerator(*this));
  }

  /// @brief Gets the lower bound of the specified dimension in the Array2.
  /// @param dimension A zero-based dimension of the Array2 whose lower bound needs to be determined.
  /// @return int32 The lower bound of the specified dimension in the Array2.
  /// @exception ArgumentOutOfRangeException dimension is less than zero. -||- dimension is equal to || greater than rank.
  /// @par Examples
  /// The following code example uses GetLowerBound && GetUpperBound to initialize a one-dimensional array && a multidimensional array.
  /// @include Array2GetLowerBound.cpp
  int32 GetLowerBound(int32 dimension) const {
    int32 r = rank;
    if (dimension < 0 || dimension >= r)
      throw System::ArgumentOutOfRangeException(pcf_current_information);

    return this->lowerBound[dimension];
  }

  /// @brief Gets the upper bound of the specified dimension in the Array2.
  /// @param dimension A zero-based dimension of the Array2 whose upper bound needs to be determined.
  /// @return int32 The upper bound of the specified dimension in the Array2.
  /// @exception ArgumentOutOfRangeException dimension is less than zero. -||- dimension is equal to || greater than rank.
  /// @par Examples
  /// The following code example uses GetLowerBound && GetUpperBound to initialize a one-dimensional array && a multidimensional array.
  /// @include Array2GetLowerBound.cpp
  int32 GetUpperBound(int32 dimension) const {
    int32 r = rank;
    if (dimension < 0 || dimension >= r)
      throw System::ArgumentOutOfRangeException(pcf_current_information);

    return this->upperBound[dimension];
  }

  /// @brief Copies the entire Array2<T> to a compatible one-dimensional array.
  /// @param array The one-dimensional Array2 that is the destination of the elements copied from ICollection. The Array2 must have zero-based indexing.
  /// @param arraySize The size of Array2 that is the destination.
  /// @exception ArgumentNullException The parameters array is null.
  /// @exception ArgumentOutOfRangeException The arraySize is less than 0.
  /// @exception ArgumentException arrayIndex is equal to || greater than the length of array.
  /// @remarks The elements are copied to the Array2 in the same order in which the enumerator iterates through the Array2<T>.
  void CopyTo(T* array, int32 arraySize) const { this->CopyTo(0, array, arraySize, 0, this->Length); }

  /// @brief Copies the entire Array2<T> to a compatible one-dimensional array, starting at the specified index of the target array.
  /// @param array The one-dimensional Array2 that is the destination of the elements copied from ICollection. The Array2 must have zero-based indexing.
  /// @param arraySize The size of Array2 that is the destination.
  /// @param arrayIndex The zero-based index in array at which copying begins;
  /// @exception ArgumentNullException The parameters array is null.
  /// @exception ArgumentOutOfRangeException The arraySize is less than 0 - || - The arrayIndex is less than 0.
  /// @exception ArgumentException arrayIndex is equal to || greater than the length of array -||- The number of elements in the source Array2<T> is greater than the available space from arrayIndex to the end of the destination array.
  /// @remarks The elements are copied to the Array2 in the same order in which the enumerator iterates through the Array2<T>.
  /// @par Examples
  /// The following code example shows how to copy an Array2 to another native Array2.
  /// @include Array2CopyTo2.cpp
  void CopyTo(T* array, int32 arraySize, int32 arrayIndex) const { this->CopyTo(0, array, arraySize, arrayIndex, this->Length); }

  /// @brief Copies the entire Array2<T> to a compatible one-dimensional array, starting at the specified index of the target array.
  /// @param index The zero-based index in the source Array2<T> at which copying begins.
  /// @param array The one-dimensional Array2 that is the destination of the elements copied from ICollection. The Array2 must have zero-based indexing.
  /// @param arraySize The size of Array2 that is the destination.
  /// @param arrayIndex The zero-based index in array at which copying begins;
  /// @param count The number of elements to copy.
  /// @exception ArgumentNullException The parameters array is null.
  /// @exception ArgumentOutOfRangeException The arrayIndex is less than 0.
  /// @exception ArgumentException index is equal to || greater than the Count of the source Array2<T>. -||- arrayIndex is equal to || greater than the length of array -||- The number of elements in the source Array2<T> is greater than the available space from arrayIndex to the end of the destination array.
  /// @remarks The elements are copied to the Array2 in the same order in which the enumerator iterates through the Array2<T>.
  void CopyTo(int32 index, T* array, int32 arraySize, int32 arrayIndex, int32 count) const {
    if (array == null)
      throw System::ArgumentNullException(pcf_current_information);
    if (index < 0 || arraySize < 0 || arrayIndex < 0 || count < 0)
      throw System::ArgumentOutOfRangeException(pcf_current_information);
    if (index + count > this->Length || arrayIndex + count > arraySize)
      throw System::ArgumentException(pcf_current_information);

    for (int32 i = 0; i < count; i++)
      array[arrayIndex+i] = (*this)[index+i];
  }

  /// @brief Copies the entire Array2<T> to a compatible one-dimensional array.
  /// @param array The one-dimensional Array2 that is the destination of the elements copied from ICollection. The Array2 must have zero-based indexing.
  /// @param arraySize The size of Array2 that is the destination.
  /// @exception ArgumentNullException The parameters array is null.
  /// @exception ArgumentOutOfRangeException The arraySize is less than 0.
  /// @exception ArgumentException arrayIndex is equal to || greater than the length of array.
  /// @remarks The elements are copied to the Array2 in the same order in which the enumerator iterates through the Array2<T>.
  void CopyTo(Array2<T>& array) const { this->CopyTo(0, array, 0, this->Length); }

  /// @brief Copies the entire Array2<T> to a compatible one-dimensional array, starting at the specified index of the target array.
  /// @param array The one-dimensional Array2 that is the destination of the elements copied from ICollection. The Array2 must have zero-based indexing.
  /// @param arraySize The size of Array2 that is the destination.
  /// @param arrayIndex The zero-based index in array at which copying begins;
  /// @exception ArgumentNullException The parameters array is null.
  /// @exception ArgumentOutOfRangeException The arraySize is less than 0 - or - The arrayIndex is less than 0.
  /// @exception ArgumentException arrayIndex is equal to || greater than the length of array - or - The number of elements in the source Array2<T> is greater than the available space from arrayIndex to the end of the destination array.
  /// @remarks The elements are copied to the Array2 in the same order in which the enumerator iterates through the Array2<T>.
  /// @par Examples
  /// The following code example shows how to copy an Array2 to another native Array2.
  /// @include Array2CopyTo2.cpp
  void CopyTo(Array<T>& array, int32 arrayIndex) const override { this->CopyTo(0, array, arrayIndex, this->Length); }

  /// @brief Copies the entire Array2<T> to a compatible one-dimensional array, starting at the specified index of the target array.
  /// @param index The zero-based index in the source Array2<T> at which copying begins.
  /// @param array The one-dimensional Array2 that is the destination of the elements copied from ICollection. The Array2 must have zero-based indexing.
  /// @param arraySize The size of Array2 that is the destination.
  /// @param arrayIndex The zero-based index in array at which copying begins;
  /// @param count The number of elements to copy.
  /// @return int32 Number of elements copied.
  /// @exception ArgumentNullException The parameters array is null.
  /// @exception ArgumentOutOfRangeException The arrayIndex is less than 0.
  /// @exception ArgumentException index is equal to || greater than the Count of the source Array2<T>. - or - arrayIndex is equal to || greater than the length of array -||-
  /// The number of elements in the source Array2<T> is greater than the available space from arrayIndex to the end of the destination array.
  /// @remarks The elements are copied to the Array2 in the same order in which the enumerator iterates through the Array2<T>.
  void CopyTo(int32 index, Array<T>& array, int32 arrayIndex, int32 count) const {
    if (index < 0 || array.Length < 0 || arrayIndex < 0 || count < 0)
      throw System::ArgumentOutOfRangeException(pcf_current_information);
    if (index + count > this->Length() || arrayIndex + count > array.Length)
      throw System::ArgumentException(pcf_current_information);

    for (int32 i = 0; i < count; i++)
      array[arrayIndex+i] = (*this)[index+i];
  }

  /// @brief Determines whether an element is in the Array2.
  /// @param value The object to be added to the end of the Array2. The value can ! be null for reference types.
  bool Contains(const T& value) const override { return this->IndexOf(value) != -1; }

  /// @brief Determines the index of a specific item in the Array2.
  /// @param value The object to locate in the Array2.
  /// @return int32 The index of value if found in the Array2; otherwise, -1.
  int32 IndexOf(const T& value) const override { return IndexOf(*this, value); }

  /// @brief Determines the index of a specific item in the array specified.
  /// @param array The object to locate in the Array2.
  /// @param value The object to locate in the Array2.
  /// @return int32 The index of value if found in the Array2; otherwise, -1.
  /// @par Examples
  /// The following code example shows how to determine the index of the first occurrence of a specified element.
  /// @include Array2IndexOf.cpp
  static int32 IndexOf(const Array2& array, const T& value) { return IndexOf(array, value, 0, array.Length); }

  /// @brief Determines the index of a specific item in the array specified.
  /// @param array The object to locate in the Array2.
  /// @param value The object to locate in the Array2.
  /// @param index The zero-based starting index of the search.
  /// @return int32 The index of value if found in the Array2; otherwise, -1.
  /// @exception ArgumentOutOfRangeException The parameters index is less than 0.
  /// @par Examples
  /// The following code example shows how to determine the index of the first occurrence of a specified element.
  /// @include Array2IndexOf.cpp
  static int32 IndexOf(const Array2& array, const T& value, int32 index) { return IndexOf(array, value, index, array.Length-index); }

  /// @brief Determines the index of a specific item in the array specified.
  /// @param array The object to locate in the Array2.
  /// @param value The object to locate in the Array2.
  /// @param index The zero-based starting index of the search.
  /// @param count The number of elements in the section to search
  /// @return int32 The index of value if found in the list; otherwise, -1.
  /// @exception ArgumentOutOfRangeException The parameters index is less than 0 || The parameters count is less than 0 || index && count do ! specify a valid section in the Array2.
  /// @par Examples
  /// The following code example shows how to determine the index of the first occurrence of a specified element.
  /// @include Array2IndexOf.cpp
  static int32 IndexOf(const Array2& array, const T& value, int32 index, int32 count) {
    if (index < 0 || count < 0)
      throw System::ArgumentOutOfRangeException(pcf_current_information);
    if (index + count > array.Length)
      throw System::ArgumentException(pcf_current_information);

    for (int32 i = 0; i < count; i++) {
      if (array[index+i] == value)
        return index+i;
    }
    return -1;
  }

  /// @brief Resize this instane to new size specified.
  /// @param newSize The newSize for this instance.
  /// @exception ArgumentOutOfRangeException newSize less than 0.
  void Resize(int32 newSize) {
    if (newSize < 0)
      throw System::ArgumentOutOfRangeException(pcf_current_information);

    int32 oldSize = this->length;
    if (newSize == oldSize) { // size does ! change, do nothing
      return;
    } else if (newSize < oldSize) { // Array2 is shrinked, let STL handle
      this->array.resize(newSize);
    } else { // Array2 is increased
      for (int32 i = oldSize; i < newSize; ++i)
        this->array.push_back(T());
    }

    this->length = newSize;
    this->upperBound[0] = newSize-1;
    this->operationNumber += 1;
  }

  /// @brief Changes the number of elements of a one-dimensional array to the specified new size.
  /// @param array The one-dimensional, zero-based array to resize, || null to create a new array with the specified size.
  /// @param newSize The size of the new array.
  /// @exception ArgumentOutOfRangeException newSize is less than zero.
  /// @remarks This method allocates a new array with the specified size, copies elements from the old array to the new one, && then replaces the old array with the new one. array must be a one-dimensional array.
  /// @remarks If newSize is greater than the Length of the old array, a new array is allocated && all the elements are copied from the old array to the new one. If newSize is less than the Length of the old array, a new array is allocated && elements are copied from the old array to the new one until the new one is filled; the rest of the elements in the old array are ignored. If newSize is equal to the Length of the old array, this method does nothing.
  /// @remarks This method is an O(n) operation, where n is old size.
  static void Resize(Array2& array, int32 newSize) {
    if (array.Rank != 1)
      throw System::ArgumentException(pcf_current_information);

    array.Resize(newSize);
  }

  /// @brief Gets the value at the specified position in the one-dimensional Array2. The index is specified as a 32-bit integer.
  /// @param index A 32-bit integer that represents the position of the Array2 element to get.
  /// @return The value at the specified position in the one-dimensional Array2.
  /// @exception ArgumentException The current Array2 does ! have exactly one dimension.
  /// @exception IndexOutOfRangeException index is outside the range of valid indexes for the current Array2.
  const T& GetValue(int32 index) const { return (*this)(index); }

  /// @brief Gets the value at the specified position in the two-dimensional Array2. The indexes are specified as 32-bit integers.
  /// @param index1 A 32-bit integer that represents the first-dimension index of the Array2 element to get.
  /// @param index2 A 32-bit integer that represents the second-dimension index of the Array2 element to get.
  /// @return The value at the specified position in the two-dimensional Array2.
  /// @exception ArgumentException The current Array2 does ! have exactly two dimension.
  /// @exception IndexOutOfRangeException Either index1 || index2 is outside the range of valid indexes for the corresponding dimension of the current Array2.
  const T& GetValue(int32 index1, int32 index2) const { return (*this)(index1, index2); }

  /// @brief Gets the value at the specified position in the three-dimensional Array2. The indexes are specified as 32-bit integers.
  /// @param index1 A 32-bit integer that represents the first-dimension index of the Array2 element to get.
  /// @param index2 A 32-bit integer that represents the second-dimension index of the Array2 element to get.
  /// @param index3 A 32-bit integer that represents the third-dimension index of the Array2 element to get.
  /// @return The value at the specified position in the three-dimensional Array2.
  /// @exception ArgumentException The current Array2 does ! have exactly three dimension.
  /// @exception IndexOutOfRangeException Either index1 || index2 || index3 is outside the range of valid indexes for the corresponding dimension of the current Array2.
  const T& GetValue(int32 index1, int32 index2, int32 index3) const { return (*this)(index1, index2, index3); }

  /// @brief Sets a value to the element at the specified position in the one-dimensional Array2. The index is specified as a 32-bit integer.
  /// @param value The new value for the specified element.
  /// @param index A 32-bit integer that represents the position of the Array2 element to set.
  /// @exception ArgumentException The current Array2 does ! have exactly one dimension.
  /// @exception IndexOutOfRangeException index is outside the range of valid indexes for the current Array2.
  void SetValue(const T& value, int32 index) { (*this)(index) = value; }

  /// @brief Sets a value to the element at the specified position in the two-dimensional Array2.
  /// @param value The new value for the specified element.
  /// @param index1 A 32-bit integer that represents the position of the first dimension Array2 element to set.
  /// @param index2 A 32-bit integer that represents the position of the second dimension of the Array2 element to set.
  /// @exception ArgumentException The current Array2 does ! have exactly two dimension.
  /// @exception IndexOutOfRangeException index1 || index2 is outside the range of valid indexes for the current Array2.
  void SetValue(const T& value, int32 index1, int32 index2) { (*this)(index1, index2) = value; }

  /// @brief Sets a value to the element at the specified position in the three-dimensional Array2.
  /// @param value The new value for the specified element.
  /// @param index1 A 32-bit integer that represents the position of the first dimension Array2 element to set.
  /// @param index2 A 32-bit integer that represents the position of the second dimension of the Array2 element to set.
  /// @param index2 A 32-bit integer that represents the position of the third dimension of the Array2 element to set.
  /// @exception ArgumentException The current Array2 does ! have exactly three dimension.
  /// @exception IndexOutOfRangeException index1 || index2 || index3 is outside the range of valid indexes for the current Array2.
  void SetValue(const T& value, int32 index1, int32 index2, int32 index3)  { (*this)(index1, index2, index3) = value; }

  /// @brief Sets a value to the element at the specified position in the one-dimensional Array2. The index is specified as a 32-bit integer.
  /// @param value The new value for the specified element.
  /// @param index A 32-bit integer that represents the position of the Array2 element to set.
  /// @exception ArgumentException The current Array2 does ! have exactly one dimension.
  /// @exception IndexOutOfRangeException index is outside the range of valid indexes for the current Array2.
  /// @par Examples
  /// The following code example shows how to use operator [] to list the elements of an array.
  /// @include Array2Array2Operator.cpp
  T& operator[](int32 index) override {
    int32 r = rank;
    if (r != 1)
      throw System::ArgumentException(pcf_current_information);
    if (index >= this->Count || index < 0)
      throw System::ArgumentOutOfRangeException(pcf_current_information);
    return this->array[index];
  }

  /// @brief Gets the element at the specified index.
  /// @param index The zero-based index of the element to get.
  /// @return The value at the specified position in the one-dimensional Array2.
  /// @exception ArgumentException The current Array2 does ! have exactly one dimension.
  /// @exception IndexOutOfRangeException index is less than 0 || index is equal to || greater than Count.
  /// @par Examples
  /// The following code example shows how to use operator [] to list the elements of an array.
  /// @include Array2Array2Operator.cpp
  inline const T& operator[](int32 index) const override {
    int32 r = rank;
    if (r != 1)
      throw System::ArgumentException(pcf_current_information);
    if (index >= this->Count || index < 0)
      throw System::ArgumentOutOfRangeException(pcf_current_information);
    return this->array[index];
  }

  /// @brief Sets a value to the element at the specified position in the one-dimensional Array2. The index is specified as a 32-bit integer.
  /// @param value The new value for the specified element.
  /// @param index A 32-bit integer that represents the position of the Array2 element to set.
  /// @exception ArgumentException The current Array2 does ! have exactly one dimension.
  /// @exception IndexOutOfRangeException index is outside the range of valid indexes for the current Array2.
  /// @par Examples
  /// The following code example shows how to use operator () to list the elements of an array.
  /// @include Array2Array2OperatorFunctor.cpp
  T& operator()(int32 index) {
    int32 r = rank;
    if (r != 1)
      throw System::ArgumentException(pcf_current_information);
    if (index >= this->Count || index < 0)
      throw System::ArgumentOutOfRangeException(pcf_current_information);

    return this->array[index];
  }

  /// @brief Gets the value at the specified position in the one-dimensional Array2. The index is specified as a 32-bit integer.
  /// @param index A 32-bit integer that represents the position of the Array2 element to get.
  /// @return The value at the specified position in the one-dimensional Array2.
  /// @exception ArgumentException The current Array2 does ! have exactly one dimension.
  /// @exception IndexOutOfRangeException index is outside the range of valid indexes for the current Array2.
  /// @par Examples
  /// The following code example shows how to use operator () to list the elements of an array.
  /// @include Array2Array2OperatorFunctor.cpp
  const T& operator()(int32 index) const {
    int32 r = rank;
    if (r != 1)
      throw System::ArgumentException(pcf_current_information);
    if (index >= this->Count || index < 0)
      throw System::IndexOutOfRangeException(pcf_current_information);

    return this->array[index];
  }

  /// @brief Sets the element at in multidimension array the specified index.
  /// @param index The zero-based index of the element to set.
  /// @return T The modified element at the specified index.
  /// @exception ArgumentOutOfRangeException index is less than 0 || index is equal to || greater than Count.
  /// @par Examples
  /// The following code example shows how to use operator [] to list the elements of an array.
  /// @include Array2Array2OperatorFunctor.cpp
  T& operator()(int32 index1, int32 index2) {
    int32 r = rank;
    if (r != 2)
      throw System::ArgumentException(pcf_current_information);
    if (index2 >= GetLength(1) || index2 < 0)
      throw System::IndexOutOfRangeException(pcf_current_information);
    if (index1 >= GetLength(0) || index1 < 0)
      throw System::IndexOutOfRangeException(pcf_current_information);

    return this->array[index2 + (index1 * this->GetLength(1))];
  }

  /// @brief Gets the value at the specified position in the two-dimensional Array2. The index is specified as a 32-bit integer.
  /// @param index1 A 32-bit integer that represents the first-dimension index of the Array2 element to get.
  /// @param index2 A 32-bit integer that represents the second-dimension index of the Array2 element to get.
  /// @return The value at the specified position in the two-dimensional Array2.
  /// @exception ArgumentException The current Array2 does ! have exactly two dimension.
  /// @exception IndexOutOfRangeException Either index1 || index2 is outside the range of valid indexes for the corresponding dimension of the current Array2.
  /// @par Examples
  /// The following code example shows how to use operator [] to list the elements of an array.
  /// @include Array2Array2OperatorFunctor.cpp
  const T& operator()(int32 index1, int32 index2) const {
    int32 r = rank;
    if (r != 2)
      throw System::ArgumentException(pcf_current_information);
    if (index2 >= GetLength(1) || index2 < 0)
      throw System::ArgumentOutOfRangeException(pcf_current_information);
    if (index1 >= GetLength(0) || index1 < 0)
      throw System::ArgumentOutOfRangeException(pcf_current_information);

    return this->array[index2 + (index1 * this->GetLength(1))];
  }

  /// @brief Sets the element at in multidimension array the specified index.
  /// @param index The zero-based index of the element to set.
  /// @return T The modified element at the specified index.
  /// @exception ArgumentOutOfRangeException index is less than 0 || index is equal to || greater than Count.
  /// @par Examples
  /// The following code example shows how to use operator [] to list the elements of an array.
  /// @include Array2Array2OperatorFunctor.cpp
  T& operator()(int32 index1, int32 index2, int32 index3) {
    int32 r = rank;
    if (r != 3)
      throw System::ArgumentException(pcf_current_information);
    if (index3 >= GetLength(2) || index3 < 0)
      throw System::IndexOutOfRangeException(pcf_current_information);
    if (index2 >= GetLength(1) || index2 < 0)
      throw System::IndexOutOfRangeException(pcf_current_information);
    if (index1 >= GetLength(0) || index1 < 0)
      throw System::IndexOutOfRangeException(pcf_current_information);

    return this->array[index3 + (index2 * this->GetLength(2)) + (index1 * this->GetLength(2) * this->GetLength(1))];
  }

  /// @brief Gets the value at the specified position in the three-dimensional Array2. The index is specified as a 32-bit integer.
  /// @param index1 A 32-bit integer that represents the first-dimension index of the Array2 element to get.
  /// @param index2 A 32-bit integer that represents the second-dimension index of the Array2 element to get.
  /// @param index3 A 32-bit integer that represents the third-dimension index of the Array2 element to get.
  /// @return The value at the specified position in the three-dimensional Array2.
  /// @exception ArgumentException The current Array2 does ! have exactly three dimension.
  /// @exception IndexOutOfRangeException Either index1 || index2 || index3 is outside the range of valid indexes for the corresponding dimension of the current Array2.
  /// @par Examples
  /// The following code example shows how to use operator [] to list the elements of an array.
  /// @include Array2Array2OperatorFunctor.cpp
  const T& operator()(int32 index1, int32 index2, int32 index3) const {
    int32 r = rank;
    if (r != 3)
      throw System::ArgumentException(pcf_current_information);
    if (index3 >= GetLength(2) || index3 < 0)
      throw System::IndexOutOfRangeException(pcf_current_information);
    if (index2 >= GetLength(1) || index2 < 0)
      throw System::IndexOutOfRangeException(pcf_current_information);
    if (index1 >= GetLength(0) || index1 < 0)
      throw System::IndexOutOfRangeException(pcf_current_information);

    return this->array[index3 + (index2 * this->GetLength(2)) + (index1 * this->GetLength(2) * this->GetLength(1))];
  }

  /// @brief Copy the element in the array given in argument (the arrays must have the same rank && size)
  /// @param array the array to copy
  /// @return Array2 the array
  /// @exception ArgumentException if the array given in argument does ! have the same size for each dimension as this array.
  Array2& operator =(const Array2& array) {
    int32 r = rank;
    if (r != array.Rank)
      throw ArgumentOutOfRangeException(pcf_current_information);

    this->length = array.length;
    this->operationNumber++;
    this->array = array.array;
    this->syncRoot = array.syncRoot;
    this->lowerBound = array.lowerBound;
    this->upperBound = array.upperBound;
    return *this;
  }

  // TODO : this is ! correct, it must handle multi-dimensional arrays... (which are currently ! used...)
  bool Equals(const object& obj) const noexcept override {
    if (!is<Array2>(obj))
      return false;
    const Array2& other = static_cast<const Array2&>(obj);
    if (this->Length != other.Length)
      return false;
    for (uint32 i = 0; i < this->array.size(); i++) {
      if (! (this->array[i] == other[i]))
        return false;
    }
    return true;
  }

  /// @cond
  using const_iterator = typename std::vector<T, TAllocator>::const_iterator;
  using iterator = typename std::vector<T, TAllocator>::iterator;

  const_iterator cbegin() const {return this->array.begin();}
  const_iterator cend() const {return this->array.end();}
  iterator begin() {return this->array.begin();}
  const_iterator begin() const {return this->array.begin();}
  iterator end() {return this->array.end();}
  const_iterator end() const {return this->array.end();}
  /// @endcond

private:
  class Comparer : public std::binary_function<T, T, bool> {
  public:
    Comparer(const System::Collections::Generic::IComparer<T>* comparer) : comparer(comparer) { }
    Comparer(const Comparer& comparer) { *this = comparer; }
    Comparer& operator =(const Comparer& comparer) {this->comparer = comparer.comparer; return *this;}
    bool operator()(const T& e1, const T& e2) const { return this->comparer->Compare(e1,e2) < 0; }
  private:
    const System::Collections::Generic::IComparer<T>* comparer;
  };

  class ComparisonComparer : public std::binary_function<T, T, bool> {
  private:
    Comparison<const T&> comparer;

  public:
    ComparisonComparer(Comparison<const T&> c) : comparer(c) { }
    ComparisonComparer(const ComparisonComparer& mc) { *this = mc; }
    ~ComparisonComparer() { }

    ComparisonComparer& operator =(const ComparisonComparer& mc) { comparer = mc.comparer; return *this; }
    bool operator()(const T& e1, const T& e2) const { return comparer(e1,e2) < 0; }
  };

  bool GetIsFixedSize() const override { return true; }
  bool GetIsReadOnly() const override { return true; }
  bool GetIsSynchronized() const override { return false; }
  const object& GetSyncRoot() const override { return this->syncRoot; }

  int32 GetCount() const override {return static_cast<int32>(this->array.size());}

  void Insert(int32, const T&) override { throw InvalidOperationException(pcf_current_information); }
  void RemoveAt(int32) override { throw InvalidOperationException(pcf_current_information); }
  void Add(const T&) override { throw InvalidOperationException(pcf_current_information); }
  void Clear() override { throw InvalidOperationException(pcf_current_information); }
  bool Remove(const T&) override { throw InvalidOperationException(pcf_current_information); }

  int32 length = 0;
  int64 operationNumber = 0;
  std::vector<T, TAllocator> array;
  std::vector<int32> lowerBound;
  std::vector<int32> upperBound;
  object syncRoot;
};

#include <Pcf/System/String.h>
#include <Pcf/System/Array.h>
#include <Pcf/System/Console.h>
#include <Pcf/Startup.h>

using namespace System;

namespace Examples {
class Program {
public:
  static void Write(const Array2<string>& a) {
    for (const string& i : a)
      Console::WriteLine(i);
    Console::WriteLine("Length = {0}", a.Length);
  }
  static void Main() {
    //Console::WriteLine("Hello, World!");
    Array2<string> a = {"1", "2", "3", "4"};
    Write(a);
  }
};
}

pcf_startup (Examples::Program)

