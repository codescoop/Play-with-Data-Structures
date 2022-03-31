/*
    TOPIC - Copy Assigment Operator

    - There are Some Special Functions that C++ Classes gives you when you create a class/object.
    - Below are, 4 different special functions that are always present inside a class.
      1. Constructor
      2. Copy Constructor
      3. Copy Assignment Operator
      4. Destructor

    Constructor
    - A special function that is responsible for creating an object.
    - It gets called automatically and only once.
    - It has same name as class name
    - Parametrised Constructor
    - Constructor Overloading

    Copy Constructor
    - make a copy of given object
    - exits by default
    - shallow & deep Copy
    - You have to make your own copy constructor if deep copy is needed!
    - bu default copy constructor is shallow copy

    Copy Assignment Operator (=)
    - Copies when you do assignment.
        Car d;                                                   [NOTE: This is Declaration]
        d = c;         // call to copy assignment operator       [NOTE: This is Assignemnt]
    - Remember, Assignment is different from Initialization.
        Car d = c;     // call to copy constructor               [NOTE: This is Initialization]
    - Copy Assignment Operator can be called many time where as copy constructor is called only once.
    - Same problem of shallow & deep Copy.
    - you can write you own copy assignment operator

 */

#include <iostream>
#include <cstring>
using namespace std;

// Creating a Class (or defining a new datatype)
class Car
{
private:
   float price;               // data member

public:
   int model_no;              // data member
   char *name;                // pointer

   Car()                                   // constructor
   {
      name = NULL;
   }

   Car(char *n, int m, float p)            // parametrized constructor
   {
      model_no = m;
      price = p;
      name = new char[strlen(n) + 1];
      strcpy(name, n);
   }

   Car(Car &o)                              // copy constructor
   {
      cout << "Inside Copy Constructor \n";
      price = o.price;
      model_no = o.model_no;
      // name = o.name;           /* shallow copy */

      /* deep copy */
      name = new char(strlen(o.name) + 1);
      strcpy(name, o.name);
   }

   
   void operator=(Car &o)                  //Copy Assignment Operator
   {
      cout << "Inside Copy Assignment Operator \n";
      price = o.price;
      model_no = o.model_no;
      // name = o.name;           /* shallow copy */

      /* deep copy */
      name = new char(strlen(o.name) + 1);
      strcpy(name, o.name);
   }

   void set_price(float val)                // function
   {
      price = val;
   }

   float get_price()                        // function
   {
      return price;
   }

   void print()                             // function
   {
      cout << "Car: " << name << endl;
      cout << "Model: " << model_no << endl;
      cout << "Price: " << price << "\n\n";
   }
};

int main()
{
   // create an object
   Car c("Alto", 2012, 80000);              // makes a call to parameterised constructor function

   Car d(c);                                // makes a call to copy constructor

   Car f;
   f = c;                                   // makes a call to copy assignment operator

   // updating data for Object f
   f.model_no = 2021;
   f.name[0] = 'Q';

   c.print();
   f.print();

   return 0;
}

/*
OUTPUT: [For Shallow Copy]

   Car   : Qlto
   Model : 2012
   Price : 80000

   Car   : Qlto
   Model : 2021
   Price : 80000


OUTPUT: [For Deep Copy]

   Car   : Alto
   Model : 2012
   Price : 80000

   Car   : Qlto
   Model : 2021
   Price : 80000
*/
