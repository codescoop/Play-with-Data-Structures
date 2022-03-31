/* 
    TOPIC - Getters and Setters

    > Access Modifiers or Access Specifiers
      - They are used to implement important feature of Object Oriented Programming known as Data Hiding.
      - They are are used to set the accessibility of the class members.

      - 3 types of access modifiers: [public, private & protected]

        1. Public   : The data members and member functions declared public can be accessed inside & outside of class

        2. Private  : The class members declared as private can be accessed inside the class only.
                      (i.e These can't be accessed outside the class)

        3. Protected: Same as private,the difference is class member declared as Protected are inaccessible 
                      outside the class but they can be accessed by any subclass(derived class) of that class.
                      (i.e used for Inheritance)

    NOTE: If we do not specify any access modifiers for the members inside the class then 
          by default the access modifier for the members will be Private.


 */

#include <iostream>
using namespace std;

// Creating a Class (or defining a new datatype) 
class Car
{
private:
    float price;                                    // Data Member

public:
    string name;                                    // Data Member
    string make;                                    // Data Member
    int model_no;                                   // Data Member

    // Setter
    void set_price(float val)                       // function
    { 
      if(val > 0)
      {
        price = val;
      }
      else{
        price = 0;
      }
    }

    // getter
    float get_price()                               // function
    {
      return price;
    }

    void print()                                    // function
    {
      cout << "Car: " << name << endl;
      cout << "Make: " << make << endl;
      cout << "Model: " << model_no << endl;
      cout << "Price: " << price << endl;;
    }
};

int main()
{
  // create an object
  Car c;

  // assigning values(to object "c")
  c.name = "i20";
  c.make = "Hyundai";
  c.model_no = 2019;
  // c.price = 600000;                                        //Error

  c.set_price(650000);                                        // Setting price value

  // display price
  cout << "Price: " << c.get_price() << "\n\n";               // Getting price value

  // display all values
  c.print();

  return 0;
}

/* 
OUTPUT:
    Price: 650000

    Car: i20
    Make: Hyundai
    Model: 2019
    Price: 650000
 */
