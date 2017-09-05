#include "rational.h"
#include<list>
template<typename T> class polynom {
private:
  T* coefficients;
  unsigned int deg;
public:
  polynom(const T* arr,unsigned int degr);
  polynom(const polynom<T>& poly);
  polynom(const T value);
  polynom();
  ~polynom();
  const unsigned int getDegree() const;
  polynom<T> operator+(polynom<T>& rechts) const;
  polynom<T> operator-(const polynom<T>& rechts) const;
  polynom<T> operator*(polynom<T>& rechts) const;
  polynom<T> operator*(T& rechts) const;
  polynom<T> operator/(T& rechts) const;
  void set(const T* arr,unsigned int degr);
  void operator+=(polynom<T>& rechts);
  void operator-=(polynom<T>& rechts);
  void operator*=(polynom<T>& rechts);
  bool operator==(polynom<T>& rechts) const;
  polynom<T>& operator=(const polynom<T>& rechts);
  bool operator!=(polynom<T>& rechts);
  polynom<T>& operator=(const T& rechts);
  polynom<T> operator<<(unsigned int num) const;
  polynom<T> operator>>(unsigned int num) const;
  polynom< T > division(polynom< T > divisor, polynom< T >* remainder) const;
  polynom< T > derivative() const;
  polynom< T > integral() const;
  T evaluate(T position) const;
  T integrate(T a,T b) const;
  T* getCoefficients();
};

template class polynom<rational<int> >;