/* 
    String Class
*/

#include <iostream>
#include <string>
using namespace std;

int main(){
    // string init
    string s0;                                          //Empty string
    string s1("Hello");
    string s2 = "Hello World";
    string s3(s2);                                     // Init. using copy constructor
    string s4 = s2;
    char c[] = {'h','e','l','l','o','\0'};
    string s5(c);                                      // Init. string object from an array
    char c0[] = "hello";
    char c1[50] = {'a','b','c','d','\0'};

    cout << "s0: " << s0 <<endl;
    cout << "s1: " << s1 <<endl;
    cout << "s2: " << s2 <<endl;
    cout << "s3: " << s3 <<endl;
    cout << "s4: " << s4 <<endl;
    cout << "c: " << c <<endl;
    cout << "s5: " << s5 <<endl;
    cout << "c0: " << c0 <<endl;
    cout << "c1: " << c1 <<"\n\n";

    // Length of string | length()
    cout << "s0 [string length] : " << s0.length() << endl;              // length()
    cout << "s1 [string length] : " << s1.length() << endl;     // 5 bytes
    cout << "s4 [string length] : " << s4.length() << endl;
    cout << "c[][string length] : " << sizeof(c) << endl;       // 6 bytes
    cout << "s5 [string length] : " << s5.length() << endl;     // 5 bytes
    cout << "c0[][string length] : " << sizeof(c0) << endl;     // 6 bytes
    cout << "c1[50]  [string length] : " << sizeof(c1) << "\n\n";        // sizeof()

    // Empty String
    if(s0.empty()){                                                  // empty() : return boolean value
        cout << "s0 is an Empty string" << "\n\n";
    }

    // Append 
    s0.append("I love c++");                                          // append()
    cout << "s0: " << s0 <<endl;

    s0 += "and javascript";                                           // append method 2
    cout << "s0: " << s0 <<"\n\n";

    // Remove | clear()
    cout << "s0: " << s0 <<endl;
    cout << "s0: length before removing- " << s0.length() << endl;
    s0.clear();                                                        // clear()
    cout << "s0: " << s0 <<endl;
    cout << "s0: length after removing- " << s0.length() << "\n\n";
    
    // compare two string
    cout << "Comparing string lexically: ";
    s1 = "apple";
    s2 = "mango";
    cout << "s1: " << s1 << " | s2: " << s2 << endl; 
    cout << "s1.compare(s2): " << s1.compare(s2) << endl;             // compare(): return an integer ==0, <0 or >0 (laxicographic comparison)
    cout << "s2.compare(s1): " << s2.compare(s1) << endl;
    cout << "s1.compare(s1): " << s1.compare(s1) << "\n\n";

    // Overloaded Operators (<, >, =)
    if(s1<s2){
        cout << "s1: " << s1 << " | s2: " << s2 << endl; 
        cout << "s1<s2: mango is lexicographic greater than apple" << "\n\n";
    }

    // Accessing i-th character of string
    cout << "s1: " << s1 << endl;
    cout << "s1[3]: " << s1[3] << "\n\n" ;

    // Find substrings | find()
    s1 = "I want to have orange juice";
    int idx = s1.find("orange");                                      // find():  return index
    cout << "s1: " << s1 << endl;
    cout << "index of 'orange': " << idx << "\n\n";

    // Remove a word from string | erase()
    string word = "orange";
    int len = word.length();
    idx = s1.find("orange");
    cout << "s1: " << s1 << endl;
    s1.erase(idx, len);                                               // erase(idx,length)
    cout << "s1: " << s1 << "\n\n\n";


    // Iterate over all the characters
    cout << "Using FOR loop: ";
    for(int i=0; i<s1.length(); i++){
        cout << s1[i] << ",";
    }
    cout << "\n\n";
    
    // auto: It automatically defines the datatype depending on what value we have on right hand side
    cout << "FOR loop (using 'auto): ";
    for(auto i=0; i<s1.length(); i++){                              // using "auto"
        cout << s1[i] << ",";
    }
    cout << "\n\n\n";




    // Iterators
    cout << "Using Iterator: ";
    for(string::iterator it = s1.begin(); it!=s1.end(); it++){         // iterator (string class)
        cout << (*it) << ",";
    }
    cout << "\n\n";

    cout << "Iterator (using auto): ";
    for(auto it = s1.begin(); it!=s1.end(); it++){                     // using "auto"
        cout << (*it) << ",";
    }
    cout << "\n\n\n";

    /*  begin() : This function returns a bidirectional iterator pointing to the first element.
        end()   : This function returns a bidirectional iterator iterator pointing to the next to last element.
    */


    // For Each loop
    cout << "FOR EACH loop: " ;
    for(char ch:s1 ){                                                    // for each loop
        cout << ch << ",";
    }
    cout << "\n\n";
 
    cout << "FOR EACH loop (using 'auto'): " ;
    for(auto ch:s1 ){                                                    // using "auto"
        cout << ch << ",";
    }
    cout << endl;

    return 0;
}

/* 
OUTPUT:

    s0: 
    s1: Hello
    s2: Hello World
    s3: Hello World
    s4: Hello World
    c: hello
    s5: hello
    c0: hello
    c1: abcd

    s0 [string length] : 0
    s1 [string length] : 5
    s4 [string length] : 11
    c[][string length] : 6
    s5 [string length] : 5
    c0[][string length] : 6
    c1[50]  [string length] : 50

    s0 is an Empty string

    s0: I love c++
    s0: I love c++and javascript

    s0: I love c++and javascript
    s0: length before removing- 24
    s0: 
    s0: length after removing- 0

    Comparing string lexically: s1: apple | s2: mango
    s1.compare(s2): -1
    s2.compare(s1): 1
    s1.compare(s1): 0

    s1: apple | s2: mango
    s1<s2: mango is lexicographic greater than apple

    s1: apple
    s1[3]: l

    s1: I want to have orange juice
    index of 'orange': 15

    s1: I want to have orange juice
    s1: I want to have  juice


    Using FOR loop: I, ,w,a,n,t, ,t,o, ,h,a,v,e, , ,j,u,i,c,e,

    FOR loop (using 'auto): I, ,w,a,n,t, ,t,o, ,h,a,v,e, , ,j,u,i,c,e,


    Using Iterator: I, ,w,a,n,t, ,t,o, ,h,a,v,e, , ,j,u,i,c,e,

    Iterator (using auto): I, ,w,a,n,t, ,t,o, ,h,a,v,e, , ,j,u,i,c,e,


    FOR EACH loop: I, ,w,a,n,t, ,t,o, ,h,a,v,e, , ,j,u,i,c,e,

    FOR EACH loop (using 'auto'): I, ,w,a,n,t, ,t,o, ,h,a,v,e, , ,j,u,i,c,e,
*/