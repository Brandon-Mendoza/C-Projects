//Your name: Brandon Mendoza
//Complier:  g++
//File type: client program client2.cpp (main)
//===========================================================

using namespace std;
#include <iostream>
#include <stdlib.h>
#include <string>
#include "queue.h"

//Purpose of the program: To display all the combinations of A,B, and C  until the queue overflows.
//Algorithm: To remove the front element and add A,B, and C to the queue. 
int main()
{ // ** "A", "B", "C" in the queue
  queue q;
  q.add("A");
  q.add("B");
  q.add("C");

  //** while loop -- indefinitely

  while(true)
    {
      try
	{
	  string front;
	  q.remove(front);
	  cout << front << endl;
	  q.add(front + "A");
	  q.add(front + "B");
	  q.add(front + "C");
	}
      catch(queue::Overflow)
	{
	  cerr << "The queue overflowed" << endl;
	  exit(1);
	}// end of loop
    }
} //end of program 

//Your name: Brandon Mendoza
//Complier:  g++
//File type: function file for queue.cpp
//===========================================================

using namespace std;
#include <iostream>
#include "queue.h"  

// constructor 
queue::queue()
{
  count = 0; 
  front = 0;
  rear = -1;
}

//destructor 
queue::~queue()
{ // nothing
}

// PURPOSE: returns true if queue is empty, otherwise false
bool queue::isEmpty()
{
  if(count <= 0)
    {
      return true;
    }
  else
    {
      return false;
    }
}

// PURPOSE: returns true if queue is full, otherwise false
bool queue::isFull()
{
  if(count >= MAX_SIZE)
    {
      return true;
    }
  else
    {
      return false;
    }
}

// PURPOSE: if full, throws an exception Overflow
// if not full, enters an element at the rear 
// PAREMETER: provide the element (newElem) to be added
void queue::add(el_t newElem)
{
  if(isFull())
    {
      throw Overflow();
    }
  else
    {
      rear = (rear + 1) % MAX_SIZE;
      el[rear] = newElem;
      count++;
    }
}

// PURPOSE: if empty, throw Underflow
// if not empty, removes the front element to give it back 
// PARAMETER: provide a holder (removedElem) for the element removed (pass by ref)
void queue::remove(el_t& removedElem)
{
  if(isEmpty())
    {
      throw Underflow();
    }
  else
    {
      removedElem = el[front];
      front = (front + 1) % MAX_SIZE;
      count--;
    }
  
}

// PURPOSE: if empty, throws an exception Underflow
// if not empty, give back the front element (but does not remove it)
//PARAMETER: provide a holder (theElem) for the element (pass by ref)
void queue::frontElem(el_t& theElem)
{
  if(isEmpty())
    {
      throw Underflow();
    }
  else
    {
      theElem = el[front];
    }
}

// PURPOSE: returns the current size to make it 
// accessible to the client caller
int queue::getSize()
{
  return count;
}

// PURPOSE: display everything in the queue horizontally
// from front to rear enclosed in [   ]
// if empty, displays [ empty ]
void queue::displayAll()
{  
  if (isEmpty()) 
    { 
      cout << "[ empty ]" << endl;
    }
  else
    {
      int j = front;
      cout << "[";
      for (int i = 1; i <= count; i++)
	{ 
	  cout << el[j] << " ";
	  j = (j + 1) % MAX_SIZE;
	}
      cout << "]" << endl;   
    }  
}

// PURPOSE: if empty, throws an exception Underflow
//if queue has just 1 element, does nothing
//if queue has more than 1 element, moves the front one to the rear by
//calling remove followed by add.
void queue::goToBack()
{
  string temp; // ** comment a local variable

  if(isEmpty())
    {
      throw Underflow();
    }
  else if(count == 1)
    {
      return;
    }
  else
    {
      temp = el[front];
      remove(temp);
      add(temp);
    }
}

// Your name: Brandon Mendoza
// Compiler:  g++ compiler
// File type: queue header file queue.h
//=====================================================

using namespace std;
#include<string>

//----- Globally setting up the aliases ----------------

typedef string el_t;          // el_t is an alias for the data type
// el_t is unknown to the client  

const int MAX_SIZE = 50;  // this is the max number of elements - need to change it to 50 for client2.
// MAX_SIZE is unknown to the client
//-------------------------------------------------------

class queue  
{
  private:
  // Data members are:
  el_t el[MAX_SIZE]; // an array called el.
                     // Elements will be found between front and rear but
                     // front may be behind rear since the queue wraps around
  int  count;          // how many elements do we have right now?
  int  front;          // where the front element of the queue is.
  int  rear;           // where the rear element of the queue is.

  public:    // prototypes to be used by the client
  // Note that no parameter variables are given

  //add exception handling classes here with comments
  class Overflow{}; //exception handling class for when the queue is overflowed
  class Underflow{}; //exception handling class for when the queue is underflowed

   queue();   // constructor to create an object 
   ~queue();  //destructor to destroy an object

   // PURPOSE: returns true if queue is empty, otherwise false
   bool isEmpty();

   // PURPOSE: returns true if queue is full, otherwise false
   bool isFull();

   // PURPOSE: if full, throws an exception Overflow
   // if not full, enters an element at the rear 
   // PRAMETER: provide the element to be added
   void add(el_t);

   // PURPOSE: if empty, throws an exception Underflow
   // if not empty, removes the front element to give it back 
   // PRAMETER: provide a holder for the element removed (pass by ref)
   void remove(el_t&);

   // PURPOSE: if empty, throws an exception Underflow
   // if not empty, give back the front element (but does not remove it)
   // PARAMETER: provide a holder for the element (pass by ref)
   void frontElem(el_t&);

   // PURPOSE: returns the current size to make it 
   // accessible to the client caller
   int getSize();

   // PURPOSE: display everything in the queue from front to rear
   //  enclosed in []
   // if empty, displays [ empty ]
   void displayAll();

   // PURPOSE: if empty, throws an exception Underflow
   //if queue has just 1 element, does nothing
   //if queue has more than 1 element, moves the front one to the rear
   void goToBack();

};           

