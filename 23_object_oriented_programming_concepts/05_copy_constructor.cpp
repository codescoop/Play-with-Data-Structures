/* 
    TOPIC - Copy Constructor

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

    Why parameters be passed as "call by reference" in "copy constructor"?
    - It is necessary to pass object as reference and not by value because if you pass it by value its
      copy is constructed using the copy constructor. This means the copy constructor would call itself
      to make copy. This process will go on until the compiler runs out of memory.

    - Because if it's not by reference, it's by value. To do that you make a copy, and to do that you
      call the copy constructor. But to do that, we need to make a new value, so we call the copy constructor,
      and so on...
      (You would have infinite recursion because "to make a copy, you need to make a copy".)
 */

#include <iostream>
using namespace std;

// Creating a Class (or defining a new datatype) 
class Car
{
private:
    float price = 0;

public:
    string name = "**";  
    string make = "**";  
    int model_no = 0; 

    // constructor
    Car()
    {
       cout << "Inside Car Constructor" << endl;
    }
    /* NOTE: This above function doesn't have any return type & 
             This function will be called automatically without calling it.
     */

    // parameterised constructor
    Car(string n, string m, int m_no, int p)
    {
       cout << "Inside Car Constructor (Parameterised)" << endl;
       name = n;
       make = m;
       model_no = m_no;
       price = p;
    }

    // parameterised constructor
    Car(string n)
    {
       cout << "Inside Car Constructor (Parameterised)" << endl;
       name = n;
    }

    // copy constructor
    Car (Car &o)
    {
      cout << "Inside Copy Constructor" << endl;
      name = o.name;
      make = o.make;
      price = o.price;
      model_no = o.model_no;
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
      cout << "Make: " << make << endl;
      cout << "Model: " << model_no << endl;
      cout << "Price: " << price << "\n\n";;
    }
};


int main()
{
  // create an object
  Car d("alto", "maruti suzuki", 2012, 80000);   // makes a call to parameterised constructor function
  d.print();

  Car e(d);                      // makes a call to copy constructor function
  e.print();
  
  // another way
  Car y = d;                     // makes a call to copy constructor function
  y.print();

  return 0;
}

/* 
OUTPUT:

    Inside Car Constructor (Parameterised)
    Car: alto
    Make: maruti suzuki
    Model: 2012
    Price: 80000

    Inside Copy Constructor
    Car: alto
    Make: maruti suzuki
    Model: 2012
    Price: 80000

    Inside Copy Constructor
    Car: alto
    Make: maruti suzuki
    Model: 2012
    Price: 80000
 */
