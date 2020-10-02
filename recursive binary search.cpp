using namespace std;
#include <iostream>
#include <cmath>

//--------------------------------------------
// Name: Brandon Mendoza
// Compiler: g++
// --------------------------------------------

// x is what we are looking for in L; first and last are slot numbers 
//This returns the slot number in which x was found
//or -1
//Purpose: To find the element in the array using a binary search 
//Parameters: Passing the array we will be searching, the element we are looking for, and the location
//of the first and last element.
int binarySearch(int L[], int x, int first, int last) 
{
  if(first > last) //if we cant find element, return -1
    {
      return -1;
    }
  //comparing with the middle entry
  int middle = floor((first + last)/2); //noting that if first == last, then
  //there is one eleement left

  cout << "comparing against an element in slot " << middle << endl;
  //to display each time we find the mid point

  if(x == L[middle])
    {
      return middle; //x was found at middle location
    }
  else if(x < L[middle])
    {
      last = middle - 1; //go to first half of the array
    }
  else if(x > L[middle])
    {
      first = middle + 1; //go to the second half of the array
    }
  return binarySearch(L, x, first, last); //recursive call (end)
}


int main()
{ 
  int A[10]; //the array 
  int e;  // to look for this
   
  // fixed elements for A
  A[0] = 1; A[1]= 3; A[2]=5; A[3]= 7; A[4]=9; A[5]=11; A[6]=13;
  A[7] =15; A[8]= 17; A[9]= 19;

  cout << "What do you want to look for? ";
  cin >> e;

  // Call binarySearch here to look for e in A
  int respos = binarySearch(A, e, 0, 9);

  if(respos == -1) //if element not found
    { 
      cout << "Element not found" << endl;
    } 
  else //element found
    {
      cout << "Found it in position " << respos+1 << endl;
    }
}
