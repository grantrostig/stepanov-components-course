#ifndef INSTRUMENTED_H
#define INSTRUMENTED_H
#include <cstddef>

struct instrumented_base
{
  enum operations {
    n, copy, assignment, destructor, default_constructor, equality, comparison, construction
  };
  static const size_t number_ops = 8;
  static double operation_counts[number_ops];
  static const char* counter_names[number_ops];
  static void initialize(size_t);
};

template <typename T> 
// T is Semiregualr or Regular or TotallyOrdered
struct instrumented :  instrumented_base
{
  typedef T value_type;
  T value;
  // Conversions from T and to T:
  explicit instrumented(const T& x) : value(x) { ++operation_counts[construction]; }

  // Semiregular:
  instrumented(const instrumented& x) : value(x.value) {
    ++operation_counts[copy];
  } 
  instrumented() { ++operation_counts[default_constructor]; }  // default constructor
  ~instrumented() { ++operation_counts[destructor]; }  // calls destructors of automatic storage class variables implicitly.  such as vector, but not a pointer.
  instrumented& operator=(const instrumented& x) {  
    ++operation_counts[assignment];
    value = x.value;
    return *this;
  }
  // Regular
  friend
  bool operator==(const instrumented& x, const instrumented& y) {
    ++operation_counts[equality];
    return x.value == y.value;
  }
  friend
  bool operator!=(const instrumented& x, const instrumented& y) {
     return !(x == y);
  }
  // TotallyOrdered
  friend
  bool operator<(const instrumented& x, const instrumented& y) { 
    ++operation_counts[comparison];
    return x.value < y.value;
  }
  friend
  bool operator>(const instrumented& x, const instrumented& y) {
    return y < x;
  }
  friend
  bool operator<=(const instrumented& x, const instrumented& y) {
    return !(y < x);
  }
  friend
  bool operator>=(const instrumented& x, const instrumented& y) {
    return !(x < y);
  } 
};

#endif







