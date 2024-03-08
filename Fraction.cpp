#include <cstdlib>
#include <string.h>
#include <memory.h>
#include "Fraction.hh"

Fraction::Fraction(void) {
  the_numerator = 0;
  the_denominator = 0;
}


Fraction::Fraction(int whole_number) {
  the_numerator = whole_number;
  the_denominator = 1;
}

Fraction::Fraction(int numerator, int denominator) {
  the_numerator = numerator;
  the_denominator = denominator;
}

int Fraction::GetNumerator() {
  return the_numerator;
}

int Fraction::GetDenominator() {
  return the_denominator;
}

void Fraction::SetNumerator(int numerator) {
  the_numerator == numerator;
}

void Fraction::SetDenominator(int denominator) {
  the_denominator = denominator;
}

Fraction::~Fraction(void) {

}

void Fraction::Normalize() {
  if(the_numerator == 0 && the_denominator == 0){
    return;
}

  if((the_numerator < 0 && the_denominator < 0) || the_denominator < 0) {
    the_denominator = the_denominator * -1;
    the_numerator = the_numerator * -1;
}

  bool negative = false;

  if(the_numerator < 0){
	negative = true;
        the_numerator = the_numerator * -1;
}

  int maximum_divisor;
  if(the_numerator < the_denominator){
	maximum_divisor = the_numerator;
}else{
	maximum_divisor = the_denominator;
}
  int divisor = 0;
  for(int i = 1; i <= maximum_divisor; i++){
	if((the_numerator % i == 0) && (the_denominator % i == 0)){
            divisor = i;
	}
}
	if (divisor) {
	    the_numerator = the_numerator/divisor;
	    the_denominator = the_denominator/divisor;
	}
	if (negative){
	    the_numerator = the_numerator * -1;
	}
}i

ostream & operator << (ostream &os, Fraction & fraction) {
  os << fraction.GetNumerator();
  os << '/';
  os << fraction.GetDenominator();
  return os;
}

istream & operator >>(istream &is, Fraction & fraction) {
  char input[64];

  is.getline(input, 64);

  char *divide_symbol_loc = NULL;

  divide_symbol_loc = strchr(input, '/');

  if (divide_symbol_loc == NULL) {
    if (strlen(input)) {
	int numerator = atoi(input);
	if (numerator) {
	    fraction.SetNumerator(numerator);
	    fraction.SetDenominator(1);
	    return is;
	}else{
	    fraction.SetNumerator(0);
	    fraction.SetDenominator(0);
	    return is;
	}
    }else{
	fraction.SetNumerator(0);
	fraction.SetDenominator(0);
	return is;
    }
}

char str_numerator[32];
memcpy((void *)str_numerator, (void *)input, (divide_symbol_loc - input));
int numerator = 0;
numerator = atoi(str_numerator);
if (numerator) {
  fraction.SetNumerator(numerator);
} else {
  fraction.SetNumerator(0);
  fraction.SetDenominator(0);
  return is;
}

char str_denominator[32];
memcpy((void *)str_denominator, (void *)(divide_symbol_loc + 1), ((input + strlen(input)) - divide_symbol_loc));

int denominator = 0;

denominator = atoi(str_denominator);

if(denominator){
  fraction.SetDenominator(denominator);
}else{
  fraction.SetNumerator(0);
  fraction.Setdenominator(0);
}
return is;
}

