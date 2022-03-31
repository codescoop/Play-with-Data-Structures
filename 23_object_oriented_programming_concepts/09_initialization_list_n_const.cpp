/*
    TOPIC - Initialization List & Const

   Some More Concepts:
   - Const Data Members
   - Initialisation List
   - Const Parameters
   - Const Functions

   Const Data Members
   - These are Data members that are initilized once. They can't change their value.
   - "Const" keyword is used to make any element of a program constant.
     Eg: 
         const i = 5000;    // Read only mode
         i++;               // Error
         i = 4;             // Error

   Initialisation List
   - It initilises constant (i.e const) & other data members which are not constant.
     Eg:
         Car(string n, int m, int p, int taxamount):model(2000),tax(taxamount)
         {
            name = n;
            price = p + tax;
         }

   Const Parameters
   - Those parameters that don't get updated inside that function.
     Eg: 
         apply_discount(const int c = val)
         {
            return price*(1.0 - val);
         }

   Const Functions
   - Those functions which don't update data members of the class.
     Eg:
         int get_price() const{
            return price;
         }

   Why do we use const ?
   - Its makes debugging easy.
     Eg: we don't have to check the const functions during debugging.
 */

#include <iostream>
#include <cstring>
using namespace std;

// Creating a Class (or defining a new datatype)
class Car
{
private:
   float price;

public:
   int model_no;
   char *name;
   const int tax;           // const data memeber

   Car():tax(5000)          // Initialisation List (i.e Initilise "const" data member in default constructor)
   {
      name = NULL;
   }

   Car(char *n, int m, float p, int taxAmount):model_no(m),tax(taxAmount)    // Initialisation List (i.e initilise "const" & "non const" data members )
   {
      // model_no = m;
      price = p + tax;
      name = new char[strlen(n) + 1];
      strcpy(name, n);
   }

   Car(Car &o):tax(o.tax)    // Initialisation List (i.e Initilise "const" data member in copy constructor)
   {
      price = o.price;
      model_no = o.model_no;
      /* deep copy */
      name = new char(strlen(o.name) + 1);
      strcpy(name, o.name);
   }

   

   void set_price(const float val)           // const Parameters
   {
      price = val;
   }

   float get_price() const                   // const function
   {
      return price;
   }

   void print() const                        // const function
   {
      cout << "Car: " << name << endl;
      cout << "Model: " << model_no << endl;
      cout << "Price: " << price << "\n\n";
   }

};


int main()
{
   Car c("Swift", 2015, 80000, 10000);          // makes a call to parameterised constructor function

   c.print();

   cout << "c.tax: " << c.tax << endl; // read & print const data member

   return 0;
}

/*
OUTPUT:

   Car: Swift
   Model: 2015
   Price: 90000

   c.tax: 10000
*/
