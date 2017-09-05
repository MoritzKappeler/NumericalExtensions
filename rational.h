#include <utility>
#include <stdio.h>
template<typename T> class rational {
private:
  T _numerator, _denominator;
  static T ggT(const T a,const T b);
public:  
  rational(const T numerator,const T denominator);
  rational(const T numerator);
  rational();
  rational(const rational<T>& fract);
  rational<T> operator+(const rational<T>& right);
  rational<T> operator-(const rational<T>& right);
  rational<T> operator*(const rational<T>& right);
  rational<T> operator/(const rational<T>& right);
  void operator+=(const rational<T>& right);
  void operator-=(const rational<T>& right);
  void operator*=(const rational<T>& right);
  void operator/=(const rational<T>& right);
  bool operator>(const rational<T>& right);
  bool operator<(const rational<T>& right);
  bool operator==(const rational<T>& right);
  bool operator!=(const rational<T>& right);
  rational<T>& operator=(const rational<T>& right);
  rational<T> Inverse();
  rational<T> operator+(const T& right);
  rational<T> operator*(const T& right);
  rational<T> operator/(const T& right);
  rational<T> operator-(const T& right);
  void operator+=(const T& right);
  void operator-=(const T& right);
  void operator*=(const T& right);
  void operator/=(const T& right);
  T denominator();
  T numerator();
  
};
  
/*template<class T> class rational {
private:
  T _numerator, _denominator;
  T ggT(T a,T b);
public:  
  rational(T numerator,T denominator);
  //rational<T> operator+(rational<T>& right);
  //rational operator-(rational& right);
  //rational operator*(rational& right);
  //rational operator/(rational& right);
  //rational Inverse();
  T denominator();
  T numerator();

};

class T {
  rational<T> operator+(rational<T>& right);
  rational<T> operator*(rational<T>& right);
};
*/
