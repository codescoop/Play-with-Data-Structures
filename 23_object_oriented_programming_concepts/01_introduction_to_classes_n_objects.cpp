/* 
    TOPIC - Introduction to Classes & Objects

    There are 2 ways of writing code:
    - Procedural Programming (Functions)
    - Object Oriented Programming (OOPs)

    ----------------------------------------------------------------------------
    Object Oriented Programming (OOPs)

    > OOPs is a feature of the language. Some programming language support OOPS & some don't.
      But, most modern languages suppot this style of writing code.

    > What is Object Oriented Programming ?
      - It uses objects in programming.
      - It mapping real world entity to an object.
        (i.e Real World Entities => Object in Program)
      - The main aim of OOP is to bind together the data and the functions that operates on them. So that,
        no other part of code can access this data except that function.

    > Class
      - Class is a blueprint of data and functions or methods. 
      - Class does not take any space. 
      - A class definition starts with the keyword class followed by the class name & the class body, 
        enclosed by a pair of curly braces. 
      - A class definition must be followed either by a semicolon or a list of declarations.

    > Objects
      - Objects are instances of a class these are defined as user defined data types. 
      - Object take up space in memory and have an associated address. 
      - We declare objects of a class with exactly the same sort of declaration that we declare variables
        of basic types.
    
    Eg:  Car Car1;   // Declare Car1 of type Car
         Car Car2;   // Declare Car2 of type Car

 */

#include <iostream>
using namespace std;

// Creating a Class (or defining a new datatype) 
// NOTE: Class doesn't occupy any memory. It is just a blueprint of object.
class Car
{
public:                     // access modifiers
    char name[20];          // data members
    int price;              // data members
    int model_no;           // data members

    void print()            // function
    {
      cout << name;
      cout << price;
      cout << model_no;
    }
};

int main()
{
  // create an object
  Car c;

  // creating array of objects
  Car c_arr[10];    // can store info about max 10 cars


  cout << "sizeof(c) :" << sizeof(c) << endl;
  cout << "sizeof(Car) :" << sizeof(Car) << endl;
  /* NOTE: class "Car" doesn't occupy any memory.
          "sizeof(Car)" just display the total memory its Object will occupy when created. */
  cout << "sizeof(c_arr) :" << sizeof(c_arr) << endl;
  

  return 0;
}

/* 
OUTPUT:

    sizeof(c) :28
    sizeof(Car) :28
    sizeof(c_arr) :280
 */
