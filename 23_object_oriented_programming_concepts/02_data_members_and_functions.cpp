/* 
    TOPIC - Data Members and Functions

    > Class
      - Class is a blueprint of data and functions or methods. 
      - Class does not take any space. 

    > Objects
      - Objects are instances of a class these are defined as user defined data types. 
      - Object take up space in memory and have an associated address. 


               class can have:
               /             \
    Data Members             Function (related to object)

    > What is Data Hiding ?
      -  Consider a real life example: What happens when a driver applies brakes? 
      -  The car stops. The driver only knows that to stop the car, he needs to apply the brakes. 
      -  He is unaware of how actually the car stops. 
      -  That is how the engine stops working or the internal implementation on the engine side. 
      -  This is what datahiding is.

    > Access Modifiers or Access Specifiers
      - They are used to implement important feature of Object Oriented Programming known as Data Hiding.
      - They are are used to set the accessibility of the class members. (i.e, it sets some restrictions on
        the class members not to get directly accessed by the outside functions.)
      - 3 types of access modifiers: [public, private & protected]

        1. Public   : All the class members declared under public will be available to everyone. 
                      The data members and member functions declared public can be accessed by other classes too. 
                      The public members of a class can be accessed from anywhere in the program using the 
                      direct member access operator (.) with the object of that class.

        2. Private  : The class members declared as private can be accessed only by the functions inside the class.
                      They are not allowed to be accessed directly by any object or function outside the class. 
                      Only the member functions or the friend functions are allowed to access the 
                      private data members of a class.
                      (i.e These can't be accessed outside the class)

        3. Protected: Protected access modifier is similar to that of private access modifiers, 
                      the difference is that the class member declared as Protected are inaccessible 
                      outside the class but they can be accessed by any subclass(derived class) of that class.

    NOTE: If we do not specify any access modifiers for the members inside the class then 
          by default the access modifier for the members will be Private.

 */

#include <iostream>
using namespace std;

// Creating a Class (or defining a new datatype) 
class Car
{
public:                                           // Access Modifier
    char name[20];                                // Data Member
    string make;                                  // Data Member
    int model_no;                                 // Data Member
    int price;                                    // Data Member

    float get_discounted_price(int discount)      // function
    {
      return price*(1 - (discount/100.0));
    }

    void apply_discount(int discount)             // function
    {
      price = price*(1 - (discount/100.0));
    }

    void print()                                  // function
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
  Car c, c1, d1;

  /* NOTE: we have created multiple objects (i.e c, c1, d1). 
           Now, all of these objects reside in different memory(i.e have there own individual Data Members).
           
           But, all the functions that we have, don't occupy any memory (as funtions are just bunch of
           instructions, rapped inside a name. So, they are a piece of code having some logic.)
           
           NOTE: these functions are NOT duplicated for different objects, they reside in a common memory.

           So, whenever a function is called using an object, it will work according to data of that particular object.

         __________          __________          __________   
        |char name |        |char name |        |char name |  
        |int make  |        |int make  |        |int make  |  
        | ...      |        | ...      |        | ...      |  
        | ...      |        | ...      |        | ...      |  
        |__________|        |__________|        |__________|  
             c                   c1                  d1       
             |                    |                  |
              ------------------------------------------------->   void print(){
             |                    |                  |               ...
             |                    |                  |             }
             |                    |                  |            
              ------------------------------------------------->   void apply_discount(int discount){
             |                    |                  |               ...
             |                    |                  |             }
             |                    |                  |            
             -------------------------------------------------->   float get_discounted_price(int discount){
                                                                     ...
                                                                   }
   */

  // assigning values(to object "c")
  c.name[0] = 'i';
  c.name[1] = '2';
  c.name[2] = '0';
  c.name[3] = '\0';
  c.make = "Hyundai";
  c.model_no = 2019;
  c.price = 600000;

  // try to print
  cout << "Car: " << c.name << endl;
  cout << "Make: " << c.make << endl;
  cout << "Model: " << c.model_no << endl;
  cout << "Price: " << c.price << "\n\n";

  int discount;
  cout << "Enter the discount% you want to give: ";
  cin >> discount;

  // cout << "Discounted Price: " << c.get_discounted_price(discount) << endl;
  c.apply_discount(discount);

  // again print all values (of object c)
  c.print();

  // again print all values (of object d1)
  // d1.print();


  return 0;
}

/* 
OUTPUT:

    Car: i20
    Make: Hyundai
    Model: 2019
    Price: 600000

    Enter the discount% you want to give: 30

    Car: i20
    Make: Hyundai
    Model: 2019
    Price: 420000
 */
