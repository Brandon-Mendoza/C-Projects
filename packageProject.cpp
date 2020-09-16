//Main
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

//cpp file for Overnight Package
#include <iostream>
#include "hwOvernightPackage.h"

using namespace std;

OvernightPackage :: OvernightPackage() : Package()
{
  overnightFee = 0;
}

OvernightPackage :: OvernightPackage(string sName, string sAddress, string sCity, string sState, long sZipCode, string rName, string rAddress, string rCity, string rState, long rZipCode, string l, string d, double w, double perOunce, string iType, double oFee) : Package(sName, sAddress, sCity, sState, sZipCode, rName, rAddress, rCity, rState, rZipCode, l, d, w, perOunce, iType)
{
  overnightFee = oFee;
}

void OvernightPackage :: calcOvernightCost() const
{
  double cost;
  
  cost = ((Package :: getCostPerOunce() + overnightFee) * Package :: getWeight());

  if(Package :: getInsuranceType() == "upto1000")
    {
      cost = cost + 5.25;
    }
  else if(Package :: getInsuranceType() == "upto5000")
    {
      cost = cost + 5.50;
    }
  cout << "Your total cost is: $" << cost << endl;
}

void OvernightPackage :: printOvernightPackage() const
{
  Package :: printPackage();
  
  if(overnightFee >= 0)
    {
      cout << "Overnight fee: $" << overnightFee << endl;
    }
  else 
    {
      cout << "Overnight Fee: Invalid fee" << endl;
    }
}

//h file for overnight package
#ifndef HWOVERNIGHTPACKAGE_H
#define HWOVERNIGHTPACKAGE_H
#include <iostream>
#include "hwPackage.h"

using namespace std;

class OvernightPackage : public Package
{
 private:
  double overnightFee;

 public: 
  OvernightPackage();
  OvernightPackage(string, string, string, string, long, string, string, string, string, long, string, string, double, double, string, double);
  void calcOvernightCost() const;
  void printOvernightPackage() const;

};
#endif

//cpp file for regular package
#include <iostream>
#include "hwPackage.h"

using namespace std;

Package :: Package()
{
  senderName = "";
  senderAddress = "";
  senderCity = "";
  senderState = "";
  senderZIPcode = 0;
  recipName = "";
  recipAddress = "";
  recipCity = "";
  recipState = "";
  recipZIPcode = 0;
  label = "";
  date = "";
  weight = 0;
  costPerOunce = 0;
  insuranceType = "";
}

Package :: Package(string sName, string sAddress, string sCity, string sState, long sZipCode, string rName, string rAddress, string rCity, string rState, long rZipCode, string l, string d, double w, double perOunce, string iType)
{
  senderName = sName;
  senderAddress = sAddress;
  senderCity = sCity;
  senderState = sState;
  senderZIPcode = sZipCode;
  recipName = rName;
  recipAddress = rAddress;
  recipCity = rCity;
  recipState = rState;
  recipZIPcode = rZipCode;
  label = l;
  date = d;
  if(w >= 0)
    {
      weight = w;
    }
  else 
    {
      weight = -1;
    }
  if(perOunce >= 0)
    {
      costPerOunce = perOunce;
    }
  else
    {
      costPerOunce = -1;
    }
  insuranceType = iType;
}

double Package :: getWeight() const
{
  return weight;
}

double Package :: getCostPerOunce() const
{
  return costPerOunce;
}

string Package :: getInsuranceType() const
{
  return insuranceType;
}

void Package :: calculateCost() const
{
  double cost;

  cost = weight * costPerOunce;

  if(insuranceType == "upto1000")
    {
      cost = cost + 5.25;
    }
  else if(insuranceType == "upto5000")
    {
      cost = cost + 5.50;
    }
  cout << "Your total cost is: " << cost << endl;
}

void Package :: printPackage() const 
{
  cout << endl << "Sender details: " << endl;
  cout << "Name: " << senderName << endl;
  cout << "Address: " << senderAddress << endl;
  cout << "City: " << senderCity << endl;
  cout << "State: " << senderState << endl;
  cout << "ZIP Code: " << senderZIPcode << endl;
  cout << endl << "Recipient details: " << endl;
  cout << "Name: " << recipName << endl;
  cout << "Address: " << recipAddress << endl;
  cout << "City: " << recipCity << endl;
  cout << "State: " << recipState << endl;
  cout << "ZIP Code: " << recipZIPcode << endl;
  cout << endl << "Package details: " << endl;
  cout << "Label: " << label << endl;
  cout << "Date: " << date << endl;
  if(weight >= 0)
    {
      cout << "Weight: " << weight << endl;
    }
  else
    {
      cout << "Weight: Invalid weight" << endl;
    }
  if(costPerOunce >= 0)
    {
      cout << "Cost per ounce: " << costPerOunce << endl;
    }
  else
    {
      cout << "Cost per ounce: Invalid cost" << endl;
    }
  cout << "Insurance Type: " << insuranceType << endl;
}

//h file for regular package
#ifndef HWPACKAGE_H
#define HWPACKAGE_H
#include <iostream>

using namespace std;

class Package
{
 private:  
  string senderName;
  string senderAddress;
  string senderCity;
  string senderState;
  long senderZIPcode;
  string recipName;
  string recipAddress;
  string recipCity;
  string recipState;
  long recipZIPcode;
  string label;
  string date;
  double weight;
  double costPerOunce;
  string insuranceType;
  
 public: 
  Package();
  Package(string, string, string, string, long, string, string, string, string, long, string, string, double, double, string);
  double getWeight() const;
  double getCostPerOunce() const;
  string getInsuranceType() const;
  void calculateCost() const;
  void printPackage() const;
};
#endif


