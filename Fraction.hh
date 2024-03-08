#include <iostream>
#include <cstdlib>

class Fraction{

public:
  
  Fraction(void);
  Fraction(int numerator, int denominator);
  Fraction(int whole_number);
  ~Fraction(void);


  int GetNumerator();
  int GetDenominator();
  void SetNumerator(int);
  void SetDenominator(int);
  void Normalize();


private:

  int the_numerator;
  int the_denominator;
};

ostream& operator << (ostream& os, Fraction& fraction);
istream& operator >> (istream& is, Fraction& fraction);
