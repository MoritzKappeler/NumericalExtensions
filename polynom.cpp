#include "polynom.h"
#include "stdlib.h"
template<typename T> polynom<T>::polynom(const T* arr,unsigned int deg):deg(deg),coefficients(new T[deg+1]) {
  std::copy(arr,arr+deg+1,coefficients);
}
template<typename T> polynom<T>::polynom(const polynom<T>& poly): deg(poly.deg),coefficients(new T[poly.deg+1]) {
  std::copy(poly.coefficients,poly.coefficients+deg+1,coefficients);
}
template<typename T> polynom<T>::polynom(const T value): deg(0),coefficients(new T[1]) {
  coefficients[0]=value;
  //std::copy(&value,&value+1, coefficients);
}
template<typename T> polynom<T>::polynom(): deg(0),coefficients(new T[1]) {
  coefficients[0]=T(0);
}
template<typename T> polynom<T>::~polynom() {
  delete[] coefficients;
}
template<typename T> polynom<T> polynom<T>::operator+(polynom<T>& rechts) const {
  unsigned int d1=getDegree();
  unsigned int d2=rechts.getDegree();
  int degree=std::max<int>(d1,d2);
  T arr[degree+1];
  for(unsigned int i=0;i< degree+1;i++) {
    arr[i]=T(0);
    if(i<=d1) arr[i]=coefficients[i];
    if(i<=d2) arr[i]+=rechts.coefficients[i];
  }
  return polynom<T>(arr,degree);
}
template<typename T> polynom<T> polynom<T>::operator-(const polynom<T>& rechts) const {
  unsigned int d1=getDegree();
  unsigned int d2=rechts.getDegree();
  unsigned int degree=std::max<unsigned int>(d1,d2);
  T arr[degree+1];
  for(unsigned int i=0;i< degree+1;i++) {
    arr[i]=T(0);
    if(i<=d1) arr[i]=coefficients[i];
    if(i<=d2) arr[i]-=rechts.coefficients[i];
  }
  for(int i=degree;i>=0;i--) {
    if(arr[i]!=T(0)) return polynom<T>(arr,i);
  }
  return polynom<T>(0);
}
template<typename T> polynom<T> polynom<T>::operator*(polynom<T>& rechts) const {
  unsigned int d1=getDegree();
  unsigned int d2=rechts.getDegree();
  unsigned int degree=d1+d2;
  T arr[degree+1];
  
  for(unsigned int i=0;i<degree+1;i++) {
    arr[i]=T(0);
    for(unsigned int j=0;j<=i;j++) {
      if(j<=d1 && (i-j)<=d2) {
	arr[i]+=coefficients[j]*rechts.coefficients[i-j];
      }
    }
  }
  return polynom<T>(arr,degree);
}
template<typename T> polynom<T> polynom<T>::operator*(T& rechts)  const {
  unsigned int d1=getDegree();
  polynom<T> poly(*this);
  for(unsigned int i=0;i<d1+1;i++) {
    poly.coefficients[i]*=rechts;
  }
  return poly;
}
template<typename T> polynom<T> polynom<T>::operator/(T& rechts)  const {
  unsigned int d1=getDegree();
  polynom<T> poly(*this);
  for(unsigned int i=0;i<d1+1;i++) {
    poly.coefficients[i]/=rechts;
  }
  return poly;
}
template<typename T> T polynom<T>::evaluate(const T pos) const {
  T potenz(1);
  T res(0);
  for(unsigned int i=0;i<deg+1;i++) {
    res+=coefficients[i]*potenz;
    potenz*=pos;
  }
  return res;
}
template<typename T> T polynom<T>::integrate(const T a, const T b)  const
{
  polynom<T> res=this->integral();
  //T potenz1(a);
  //T potenz2(b);
  //T res(0);
  //for(unsigned int i=0;i<deg+1;i++) {
  //  res+=coefficients[i]*(potenz2-potenz1)/(i+1);
  //  potenz1*=a;
  //  potenz2*=b;
  //}
  return res.evaluate(b)-res.evaluate(a);
}
template<typename T> polynom<T> polynom<T>::derivative() const {
   if(deg>0) {
      T arr[deg];
      for(int i=0;i< deg;i++) {
	arr[i]=coefficients[i+1]*(i+1);
      }
      return polynom<T>(arr,deg-1);
   } else {
     return polynom<T>(0);
   }
}
template<typename T> polynom<T> polynom<T>::integral() const {
   T arr[deg+2];
   arr[0]=0;
   for(int i=0;i< deg+1;i++) {
     arr[i+1]=coefficients[i]/(i+1);
   }
   return polynom<T>(arr,deg+1);
}
template<typename T> polynom<T>& polynom<T>::operator=(const polynom<T>& rechts)
{
  delete[] coefficients;
  deg=rechts.deg;
  coefficients=new T[deg+1];
  std::copy(rechts.coefficients,rechts.coefficients+rechts.deg+1,coefficients);
  return *this;
}


template<typename T>  polynom<T>& polynom<T>::operator=(const T& rechts)
{
  delete[] coefficients;
  deg=0;
  coefficients=new T[1];
  coefficients[0]=rechts;
  return *this;
}

template<typename T> void polynom<T>::set(const T* arr, unsigned int degr)
{
  delete[] coefficients;
  deg=degr;
  coefficients=new T[deg+1];
  std::copy(arr,arr+degr+1,coefficients);
}
template<typename T> polynom< T > polynom<T>::division(polynom< T > divisor, polynom< T >* remainder) const
{
  remainder=new polynom<T>(*this);
  
  //remainder.deg=deg;
  //remainder->coefficients=new T[deg];
  //for(int i=0;i< deg;i++) {
  //  remainder->coefficients[i]=coefficients[i];
  //}
  unsigned int max=remainder->deg-divisor.deg;
  T arr[max+1];
  T factor;
  for(int i=remainder->deg;i>=divisor.deg;i--) {
    factor= remainder->coefficients[i]/divisor.coefficients[divisor.deg];
    arr[i-divisor.deg]=factor;
    for(int j=divisor.deg;j>=0;j--) {
      remainder->coefficients[i-divisor.deg+j]-=factor*divisor.coefficients[j];
    }
  }
  return polynom< T >(arr,max);
  
}
template<typename T> T* polynom<T>::getCoefficients() {
  return coefficients;
}
template<typename T> const unsigned int polynom<T>::getDegree() const {
  return deg;
}

template<typename T> void polynom<T>::operator*=(polynom<T>& rechts) {
  polynom<T> res=*this*rechts;
  deg=res.deg;
  delete[] coefficients;
  coefficients=new T[deg+1];
  std::copy(res.coefficients,res.coefficients+deg+1,coefficients);
}
template<typename T> void polynom<T>::operator+=(polynom<T>& rechts) {
  polynom<T> res=*this+rechts;
  deg=res.deg;
  delete[] coefficients;
  coefficients=new T[deg+1];
  std::copy(res.coefficients,res.coefficients+deg+1,coefficients);
}
template<typename T> void polynom<T>::operator-=(polynom<T>& rechts) {
  polynom<T> res=*this-rechts;
  deg=res.deg;
  delete[] coefficients;
  coefficients=new T[deg+1];
  std::copy(res.coefficients,res.coefficients+deg+1,coefficients);
}
template<typename T> bool polynom<T>::operator==(polynom<T>& rechts) const {
  if(deg==rechts.deg) {
    for(int i=0;i<deg+1;i++) {
       if(coefficients[i]!=rechts.coefficients[i]) return false;
    }
    return true;
  }
  return false;
}

template<typename T> bool polynom<T>::operator!=(polynom<T>& rechts) {
  return !(*this==rechts);
}
template<typename T> polynom<T> polynom<T>::operator<<(const unsigned int num) const {
  T arr[deg+num+1];
  std::fill(arr,arr+num,T(0));
  std::copy(coefficients,coefficients+deg+1,arr+num);
  return polynom<T>(arr,deg+num);
}
template<typename T> polynom<T> polynom<T>::operator>>(const unsigned int num) const {
  if(deg-num>=0) {
    T arr[deg-num+1];
    std::copy(coefficients+num,coefficients+deg+1,arr);
    return polynom<T>(arr,deg-num);
  }
  return polynom<T>(0);
}
