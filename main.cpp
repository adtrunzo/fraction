#include <iostream>
#include <cstdlib>
#include "Fraction.cpp"


int main(void) {
  Fraction *frac = new Fraction(4,6);

  cout << "Testing (4/6): \t\t";
  cout << *frac << endl;

  delete frac;

  frac = new Fraction(6);
  cout << "Testing (6): \t\t";
  cout << *frac << endl << endl;

  delete frac;

  while(1) {

    frac = new Fraction();
    cout << "Enter a fraction (ctrl-c to exit)L ";
    cin >> *frac;
    cout << endl << "You entered (before normalization): " << *frac;
    frac->Normalize();
    cout << endl << "You entered (after normalization): " << *frac << endl << endl;
    delete frac;
  
}
}
