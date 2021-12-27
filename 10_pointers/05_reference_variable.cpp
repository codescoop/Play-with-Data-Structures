/* 
    Topic - References in C++
    
    Reference Variable
    - When a variable is declared as a reference, it becomes an alternative name for an existing variable.
    - A variable can be declared as a reference by putting ‘&’ in the declaration. 
*/

#include <iostream>
using namespace  std;


int main(){
    int num = 10;

    int &ref = num;    // ref is a reference to num
    cout << "ref : "<< ref << endl;

    ref = 20;          // value of num(alias name ref) is now changed to 20.
    cout << "ref : "<< ref << endl;
    
    num = 30;          // value of num is now changed to 20.
    cout << "ref : "<< ref << endl;

    return 0;
}

/* 
OUTPUT: 
    ref : 10
    ref : 20
    ref : 30


More About References Variable:

- Reference Variable:
    > A reference variable is an alias, that is, another name for an already existing 
      variable/memory instance.
    > Once a reference is initialized with a variable, either the variable name or the reference
      name may be used to refer to the variable.
    > The reference variable once deﬁned to refer to a variable cannot be changed to 
      point to other variable.

- Defining Reference Variable:
    > Reference variables are deﬁned by using '&' symbol in the deﬁnition.
    > Since they do not have any storage of their own and are just another name for the
      existing storage, they need to initialized before using them.
    > Eg: int x;
          int &y = x;
      The exisiting memory X will now also have another name Y.

- Reference Variable VS Pointer Variable
    > You cannot have NULL references. You must always be able to assume that a reference 
      is connected to a legitimate piece of storage.
    > Once a reference is initialized to an object, it cannot be changed to refer to another object. 
      Pointers can be pointed to another object at any time.
    > A reference must be initialized when it is created. Pointers can be initialized at any time.
*/