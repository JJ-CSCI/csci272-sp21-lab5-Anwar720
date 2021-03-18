//------------------------------
//  DO NOT MODIFY NEXT LINE
//------------------------------
#include "catch.hpp"
//------------------------------

// Write the assignment code here
class Real{
  private:
  double re;

  public:
  Real(double);
  double GetReal();
  Real friend operator* (Real&, double );

};
Real::Real(double a): re{a}{}

double Real::GetReal(){ return re;}

Real operator*(Real& r, double m){
   return r.re * m;
}

// complex class
class Complex : public Real{
  private:
  double im;
  
  public:
  Complex(double , double);
  double GetImaginary( );
  Complex  operator* (double );
};
  Complex::Complex(double a, double b): Real{a}, im{b} { }

  double Complex::GetImaginary(){ return im;}

  Complex Complex::operator*(double m){
   Complex com(GetReal()*m,im*2);
   return com;
  }

  //Surreal class
  class Surreal: public Complex{

    private:
    double sur;

    public:
    Surreal( double , double ,double );
    double GetSurreal();
    Surreal  operator*(double);
  };
    Surreal::Surreal( double a ,double b ,double c): 
     Complex{a,b}, sur{c}{} 

    double Surreal::GetSurreal(){ return sur;}

    Surreal  Surreal::operator*(double m){
      Surreal s(GetReal()*m,GetImaginary()*m,sur*m);
      return s;
    }


//------------------------------
//   DO NOT MODIFY TEST CASES
//------------------------------
TEST_CASE( "Assignment" ) {
    SECTION( "c1" ) {
        Real n{10.0};
        REQUIRE( n.GetReal() == 10.0 );
    }
    SECTION( "c2" ) {
        Complex n{10.0, 20.0};
        REQUIRE( n.GetReal() == 10.0 );
        REQUIRE( n.GetImaginary() == 20.0 );
    }
    SECTION( "c3" ) {
        Surreal n{10.0, 20.0, 30.0};
        REQUIRE( n.GetReal() == 10.0 );
        REQUIRE( n.GetImaginary() == 20.0 );
        REQUIRE( n.GetSurreal() == 30.0 );
    }
    SECTION( "a1" ) {
        Real n{10.0};
        Real r = n * 2.0;
        REQUIRE( r.GetReal() == 20.0 );
    }
    SECTION( "a2" ) {
        Complex n{10.0, 20.0};
        Complex r = n * 2.0;
        REQUIRE( r.GetReal() == 20.0 );
        REQUIRE( r.GetImaginary() == 40.0 );
    }
    SECTION( "a3" ) {
        Surreal n{10.0, 20.0, 30.0};
        Surreal r = n * 2.0;
        REQUIRE( r.GetReal() == 20.0 );
        REQUIRE( r.GetImaginary() == 40.0 );
        REQUIRE( r.GetSurreal() == 60.0 );
    }
}
//------------------------------
