
#include "rational.h"
#include <stdexcept>

template<typename T>
T rational<T>::ggT(T a,T b) {
  if(a==0)
    return b;
  else
    return ggT(b%a,a);
}

template<typename T> 
rational<T>::rational(T numerator,T denominator) {
  T a,b;
  if(denominator <0) {
    numerator*=-1;
    denominator*=-1;
  }
  if(numerator!=0) {
    if(denominator==0) throw std::invalid_argument( "divide by zero error" );
    a=numerator;
    b=denominator;
    if(a<0) a*=-1;
    
    if(a>b) std::swap(a,b);
    T gT=ggT(a,b);
    _numerator=numerator/gT;
    _denominator=denominator/gT;
  } else {
    _numerator=0;
    _denominator=1;
  }
  
}
template<typename T> rational<T>::rational(T numerator) {
  _numerator=numerator;
  _denominator=1;
}
template<typename T> rational<T>::rational() {
  _numerator=0;
  _denominator=1;
}
template<typename T> rational<T>::rational(const rational<T>& fract): _numerator(fract._numerator),_denominator(fract._denominator) {
  
}

template<typename T>  T rational<T>::numerator() {
    return _numerator;
  }
template<typename T>  T rational<T>::denominator() {
    return _denominator;
  }
template<typename T> rational<T> rational<T>::operator+(const rational<T>& right) {
  return rational<T>(_numerator*right._denominator+right._numerator*_denominator ,_denominator*right._denominator);
}
template<typename T> rational<T> rational<T>::operator-(const rational<T>& right) {
  return rational<T>(_numerator*right._denominator-right._numerator*_denominator ,_denominator*right._denominator);
}
template<typename T> rational<T> rational<T>::operator*(const rational<T>& right) {
  return rational<T>(_numerator*right._numerator,_denominator*right._denominator);
} 
template<typename T> rational<T> rational<T>::operator/(const rational<T>& right) {
  return rational<T>(_numerator*right._denominator,_denominator*right._numerator);
}

template<typename T> void rational<T>::operator+=(const rational<T>& right) {
  rational<T> res=*this+right;
  _numerator=res._numerator;
  _denominator=res._denominator;
}
template<typename T> void rational<T>::operator-=(const rational<T>& right) {
  rational<T> res=*this-right;
  _numerator=res._numerator;
  _denominator=res._denominator;
}
template<typename T> void rational<T>::operator*=(const rational<T>& right) {
  rational<T> res=*this*right;
  _numerator=res._numerator;
  _denominator=res._denominator;
}
template<typename T> void rational<T>::operator/=(const rational<T>& right) {
  rational<T> res=*this/right;
  _numerator=res._numerator;
  _denominator=res._denominator;
}
template<typename T> void rational<T>::operator+=(const T& right) {
  rational<T> res=*this+right;
  _numerator=res._numerator;
  _denominator=res._denominator;
}
template<typename T> void rational<T>::operator-=(const T& right) {
  rational<T> res=*this-right;
  _numerator=res._numerator;
  _denominator=res._denominator;
}
template<typename T> void rational<T>::operator*=(const T& right) {
  rational<T> res=*this*right;
  _numerator=res._numerator;
  _denominator=res._denominator;
}
template<typename T> void rational<T>::operator/=(const T& right) {
  rational<T> res=*this/right;
  _numerator=res._numerator;
  _denominator=res._denominator;
}
template<typename T> rational<T> rational<T>::Inverse() {
  return rational<T>(_denominator,_numerator);
}
template<typename T> rational< T >& rational<T>::operator=(const rational< T >& right)
{
  _numerator=right._numerator;
  _denominator=right._denominator;
  return *this;
}

template<typename T> bool rational<T>::operator==(const rational<T>& right) {
  return _numerator==right._numerator && _denominator==right._denominator;
}
template<typename T> bool rational<T>::operator!=(const rational<T>& right) {
  return !(*this==right);
}
template<typename T> bool rational<T>::operator>(const rational<T>& right) {
  rational<T> diff=*this-right;
  return diff._numerator>0;
}
template<typename T> bool rational<T>::operator<(const rational<T>& right) {
  rational<T> diff=*this-right;
  return diff._numerator<0;
}
template<typename T> rational<T> rational<T>::operator+(const T& right) {
 return rational<T>(_denominator*right+_numerator,_denominator);
}
template<typename T> rational<T> rational<T>::operator-(const T& right) {
 return rational<T>(_denominator*right-_numerator,_denominator);
}
template<typename T> rational<T> rational<T>::operator*(const T& right) {
  return rational<T>(_numerator*right,_denominator);
}
template<typename T> rational<T> rational<T>::operator/(const T& right) {
  return rational<T>(_numerator,_denominator*right);
}

template class rational<int>;