#include <iostream>
#include "hwPackage.h"
#include "hwOvernightPackage.h"
#include <string>

using namespace std;

int main()
{
  Package package("AmyJohnson", "3465RegentsRd", "SanDiego", "CA", 92130, "EdwardJohnes", "439NWGreens", "Fayetteville", "NY", 13066, "HG9983", "06/03/2016", 10, 0.7, "upto1000");

  package.printPackage();
  package.calculateCost();

  OvernightPackage overNight("MaryPalmer", "6534SpringburstDr", "PalmSprings", "CA", 92240, "DennisGarcia", "8FifthSt", "Denver", "CO", 66665, "UI0900", "10/11/2016", 20.1, 0.8, "upto5000", 7);
  cout << endl;

  overNight.printOvernightPackage();
  overNight.calcOvernightCost();

  return 0;
}
