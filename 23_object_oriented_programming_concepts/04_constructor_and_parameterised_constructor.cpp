/* 
    TOPIC - Constructor and Parameterised Constructor

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
    - This function is hidden & is created by the compiler. 
      Now, if we want to override this function we have to create our own constructor.
      So, to create our own constructor, we have to define a function that has same name as class name.
    - Below is the Default Constructor create by compiler (It's an empty constructor):
        class_name()
        {
        }
    - This constructor function doesn't have any return type.

    Parameterised Constructor:
    - constructors which has parameters

    Constructor Overloading:
    - when we have more than one constructor inside a class it is known as constructor overloading
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
      cout << "Price: " << price << "\n\n";
    }
};


int main()
{
  // create an object
  Car c;                         // makes a call to the constructor function present inside the class
  c.name = "i20";
  c.make = "Hyundai";
  c.model_no = 2019;
  c.set_price(650000);                                        
  c.print();

  Car d("alto", "maruti suzuki", 2012, 80000);   // makes a call to parameterised constructor function
  d.print();
  
  Car f1("Swift");                               // makes a call to parameterised constructor function
  f1.print();

  return 0;
}

/* 
OUTPUT:

    Inside Car Constructor
    Car: i20
    Make: Hyundai
    Model: 2019
    Price: 650000

    Inside Car Constructor (Parameterised)
    Car: alto
    Make: maruti suzuki
    Model: 2012
    Price: 80000

    Inside Car Constructor (Parameterised)
    Car: Swift
    Make: **
    Model: 0
    Price: 0
 */
