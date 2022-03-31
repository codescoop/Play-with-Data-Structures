/* 
    TOPIC - Shallow and Deep Copy

   In general, creating a copy of an object means to create an exact replica of the object having the 
   same literal value, data type, and resources.

   C++ Complier creates some Special Functions that C++ Classes gives you when you create a class/object
   for creating a copy of an object. These special functions are:
   - Copy Constructor
   - Copy Assignment Operator

   Depending upon the resources like dynamic memory held by the object, either we need to perform 
   Shallow Copy or Deep Copy in order to create a replica of the object.
   In general, if the variables of an object have been dynamically allocated then it is required to 
   do a Deep Copy in order to create a copy of the object.


   When you need to define you OWN copy constructor ?
   - If Some variables of the object are defined in the heap section of memory(i.e dynamically allocated) then
     we should create our own copy constructor (i.e because we want to perform Deep Copy)

   - If NONE of the data members are having dynamically allocated memory, then should use Default copy construction
     created by C++ Compiler & avoid creating your own copy constructor


   Shallow Copy:
   - In shallow copy, an object is created by simply copying the data of all variables of the original object.
     This works well if NONE of the variables of the object are defined in the heap section of memory (i.e 
     dynamically allocated / Pointer variables).
   - If some variables are dynamically allocated memory from heap section, then copied object variable will
     also reference then SAME memory location.
   - This will create ambiguity and run-time errors dangling pointer. Since both objects will reference to
     the same memory location, then change made by one will reflect those change in another object as well. 
     Since we wanted to create a replica of the object, this purpose will NOT be filled by Shallow copy. 

   Deep Copy:
   - In order to perform Deep copy, we need to explicitly define the copy constructor and assign dynamic memory
     as well if required. 
   - Also, it is required to dynamically allocate memory to the variables in the other constructors, as well.


   Note: By default, "Copy Constructor" and "Copy Assignment Operator" created by C++ compiler perform shallow copy.

 */

#include <iostream>
#include<cstring>
using namespace std;

// Creating a Class (or defining a new datatype) 
class Car
{
private:
    float price;          // data member

public:
    int model_no;         // data member
    char *name;           // pointer

    Car()                                         // constructor
    {
       name = NULL;
    }

    Car(char *n, int m, float p)                  // parametrized constructor
    {
       model_no = m;
       price = p;
       name = new char[strlen(n)+1];
       strcpy(name, n);
    }

    Car (Car &o)                                // copy constructor
    {
      price = o.price;
      model_no = o.model_no;
      // name = o.name;           /* shallow copy */

      /* deep copy */
      name = new char(strlen(o.name) + 1);
      strcpy(name, o.name);
    }

    void set_price(float val)                       // function
    { 
        price = val;
    }

    float get_price()                               // function
    {
      return price;
    }

    void print()                                    // function
    {
      cout << "Car: " << name << endl;
      cout << "Model: " << model_no << endl;
      cout << "Price: " << price << "\n\n";
    }
};


int main()
{
   // create an object
   Car c("Alto", 2012, 80000);   // makes a call to parameterised constructor function
   Car d(c);                     // makes a call to copy constructor
   
   // updating data for Object d
   d.model_no = 2021;
   d.name[0] = 'Z';          


   c.print();
   d.print();
   
   return 0;
}

/* 
OUTPUT: [For Shallow Copy]

   Car   : Zlto
   Model : 2012
   Price : 80000

   Car   : Zlto
   Model : 2021
   Price : 80000


OUTPUT: [For Deep Copy]

   Car   : Alto
   Model : 2012
   Price : 80000

   Car   : Zlto
   Model : 2021
   Price : 80000
*/
