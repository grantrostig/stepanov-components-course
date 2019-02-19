#ifndef SINGLETON_H
#define SINGLETON_H

template <typename T> 
// T is Semiregualr or Regular or TotallyOrdered
struct singleton
{
  typedef T value_type;
  T value;
  
  // Conversions from T and to T:
  explicit singleton(const T& x) : value(x) {}
  explicit operator T() const { return value; }
  
  // grostig: According to Stepanov the following block is anti-pattern, 
  // but he includes it, to show what others do.
  // Converts between types held by singleton.  ie. int to double.
  // Write conversions from T to singleton<T> and singleton<T> to T.
//  template <typename U>
//  singleton(const singleton<U>& x) : value(x.value) {}
  
  // Semiregular:
  singleton(const singleton& x) : value(x.value) {} // could be implicitly declared
  singleton() {}                                    // could be implicitly declared sometimes
  ~singleton() {}                                   // could be implicitly declared 
  singleton& operator=(const singleton& x) {        // could be implicitly declared 
    value = x.value;
    return *this;
  }
  // Regular
  friend
  bool operator==(const singleton& x, const singleton& y) {
    return x.value == y.value;
  }
  friend
  bool operator!=(const singleton& x, const singleton& y) {
     return !(x == y);
  }
  // TotallyOrdered
  friend
  bool operator<(const singleton& x, const singleton& y) { 
    return x.value < y.value;
  }
  friend
  bool operator>(const singleton& x, const singleton& y) {
    return y < x;
  }
  friend
  bool operator<=(const singleton& x, const singleton& y) {
    return !(y < x);
  }
  friend
  bool operator>=(const singleton& x, const singleton& y) {
    return !(x < y);
  } 

  // Arithmetic
  friend
  T operator+(const singleton& x, const singleton& y) {
    return x.value + y.value;
  }


};

#endif







