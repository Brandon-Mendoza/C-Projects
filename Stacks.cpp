//Your name: Brandon Mendoza
//Complier:  g++
//File type: client program client1.cpp
//===========================================================

using namespace std;
#include <iostream>
#include <stdlib.h>
#include <string>
#include "stack.h"

//Purpose of the program: To evaluate user post fix expressions.
//Algorithm: A stack to perform post fix equations. 
int main()
{
  stack postfixstack;  // integer stack
  string expression;   // user entered expression
  
  cout << "type a postfix expression: " ;
  cin >> expression;
  
  int i = 0;  // character position within expression
  char item;  // one char out of the expression
  
  int box1;  // receive things from pop
  int box2;  // receive things from pop
  
  while (expression[i] != '\0')
    {
     try
       {
	 item = expression[i];  // current char
	 
	 //If it is an operand, push it into the stack
	 if((item - '0') >= 0 && (item - '0') <= 9)
	   {
	     postfixstack.push(item - '0');
	   }
	 //else if the operator pops two operands, apply them and put them into the stack
	 else if(item == '+' || item == '-' || item == '*' || item == '/')
	   {
	     postfixstack.pop(box1);
	     postfixstack.pop(box2);

	     switch(item)
	       {
	       case '+':
		 postfixstack.push(box2 + box1);
		 break;
	       case '-':
		 postfixstack.push(box2 - box1);
		 break;
	       case '*':
		 postfixstack.push(box2 * box1);
		 break;
	       case '/':
		 postfixstack.push(box2 / box1);
		 break;
	       default:
		 throw "There is an error";
	       }
	     //switch cases for each operand 
	   }
	 else
	   {
	     throw "There is an error";
	   }
	 
	 
       } // this closes try
      // Catch exceptions and report problems and quit the program now (exit(1)). 
      // Error messages describe what is wrong with the expression.
      catch (stack::Overflow) 
	{
	  cout << "Overflow, expression is too long." << endl;
	  exit(1);
	}
      catch (stack::Underflow)
	{
	  cout << "Underflow, not enough operands." << endl;
	  exit(1);
	}

      catch (char const* errormsg ) // for invalid item case
	{
	  cout << "Invalid element." << endl;
	  exit(1);
	}

      // go back to the loop after incrementing i
     i++;
    }// end of while

 // After the loop successfully completes: 
 // Pop the result and show it.
  postfixstack.pop(box1);
  cout << "The result is: " << box1 << endl;
 // If anything is left on the stack, an incomplete expression 
 // was found so inform the user.
  if(!postfixstack.isEmpty())
    {
      cout << "Incomplete expression." << endl;
    }

}// end of the program

//Your name: Brandon Mendoza
//Complier:  g++
//File type: stack implementation file stack.cpp
//=========================================================

using namespace std;  
#include <iostream>
#include "stack.h"

//PURPOSE:  Constructor must initialize top to be -1 to begin with.
stack::stack()
{
  top = -1; // indicate an empty stack }
}
//PURPOSE:  Destructor does not have to do anything since this is a static array.
stack::~stack()
{ // nothing 
}
  
//PURPOSE:  checks top and returns true if empty, false otherwise.
bool stack::isEmpty()
{
  if ( top == -1)
    { 
      return true;
    }
  else
    {
      return false;
    }
}
//PURPOSE: checks top and returns true if full, false otherwise.
bool stack::isFull()
{  if (top == MAX-1 ) return true; else return false; }
  
//PURPOSE: calls isFull and if true, throws an exception (Overflow)
//   Otherwise, adds an element to el after incrementing top.
//PARAMETER: pass the element (elem) to be pushed 
void stack::push(el_t elem)
{ if (isFull()) /**/ 
    {
      throw Overflow();
    }
   else 
     { 
       top++; 
       el[top] = elem; 
     }
}
 
//PURPOSE: calls isEmpty and if true, throws an exception (Underflow)
//  Otherwise, removes an element from el and gives it back.
//PARAMETER: provide a holder (elem) for the element popped (pass by ref)
void stack::pop(el_t& elem)
{ if (isEmpty()) /**/ 
    {
      throw Underflow();
    }
  else 
    { 
      elem = el[top]; 
      top--;
    }
}
 
// PURPOSE: calls isEmpty and if true, throws an exception (underflow)
//    Otherwise, gives back the top element from el.
//PARAMETER: provide a holder (elem) for the element (pass by ref)
void stack::topElem(el_t& elem)
{ if (isEmpty()) /**/ 
    {
      throw Underflow();
    }
  else 
    {
      elem = el[top];
    }
}
 
//PURPOSE: dislayAll calls isEmpty and if true, displays [ empty ].
//         Otherwise, diplays the elements vertically.
void stack::displayAll()
{  
  cout << "STACK:---------" << endl;
   if (isEmpty())
     { 
       cout << "[ empty ]" << endl;
     }
   else 
     {
       for(int i = top; i >= 0; i--)
	 { 
	   cout << el[i] << endl; 
	 }
     }
   cout << "--------------" << endl;
}
 
 
//PURPOSE: pops all elements from the stack until 
// it is empty 
void stack::clearIt()
{
   el_t temp;  // ** comment a local variable here
   
   while(!isEmpty())
     {
       pop(temp);
     }// do not do top = -1, use a loop
}
 
// Your name: Brandon Mendoza
// Compiler:  g++ 
// File type: header file stack.h
//=======================================================

//----- Globally setting up the aliases ----------------

const int MAX = 10;   // The MAX number of elements for the stack
                      // MAX is unknown to the client

typedef int el_t;      // the el_t type is ** for now
                      // el_t is unknown to the client
//-------------------------------------------------------


class stack
{ 
  
 private: // to be hidden from the client
  
   el_t     el[MAX];       // el is  an array of el_t's
   int      top;           // top is index to the top of stack

 public:  // available to the client
  
  // Add exception handling classes here  
   class Overflow{};
   class Underflow{};
  
  // prototypes to be used by the client
  // Note that no parameter variables are given

  stack();   // constructor to create an object
  ~stack();  // destructor  to destroy an object
  
  // PURPOSE: if not full, enters an element at the top;
  //          otherwise throws an exception - Overflow
  // PARAMETER: pass the element to be pushed
  void push(el_t elem);
  
  // PURPOSE: if not empty, removes and gives back the top element;
  //          otherwise throws an exception - Underflow
  // PARAMETER: provide variable to receive the popped element (by ref)
  void pop(el_t& elem);
  
  // PURPOSE: if not empty, gives the top element without removing it;
  //          otherwise, throws an exception - Underflow
  // PARAMETER: element
  void topElem(el_t& elem);
  
  // ** Must add good comments for each function - See Notes1B

  //PURPOSE: Checks top and returns true if empty, false otherwise.
  bool isEmpty();

  //PURPOSE: checks top and returns true if full, false otherwise.
  bool isFull();

  //PURPOSE: dislayAll calls isEmpty and if true, displays [ empty ]. Otherwise, diplays the elements vertically.
  void displayAll();

  //PURPOSE:  pops all elements from the stack until it is empty.
  void clearIt();
  
};  

// Note: semicolon is needed at the end of the header file

