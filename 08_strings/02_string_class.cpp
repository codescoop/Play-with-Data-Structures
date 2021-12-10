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
    char c[50] = {'a','b','c','d','\0'};
    string s5(c);                                      // Init. string object from an array

    cout << "s0: " << s0 <<endl;
    cout << "s1: " << s1 <<endl;
    cout << "s2: " << s2 <<endl;
    cout << "s3: " << s3 <<endl;
    cout << "s4: " << s4 <<endl;
    cout << "s5: " << s5 <<"\n\n";

    // Lenght of string
    cout << "s5: string length - " << s5.length() << "\n\n";         // length()

    // Empty String
    if(s0.empty()){                                                  // empty() : return boolean value
        cout << "s0 is an Empty string" << "\n\n";
    }

    // Append 
    s0.append("I love c++");                                          // append()
    cout << "s0: " << s0 <<endl;

    s0 += "and javascript";                                           // append method 2
    cout << "s0: " << s0 <<"\n\n";

    // Remove
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

    // Find substrings
    s1 = "I want to have orange juice";
    int idx = s1.find("orange");                                      // find():  return index
    cout << "s1: " << s1 << endl;
    cout << "index of 'orange': " << idx << "\n\n";

    // Remove a word from string
    string word = "orange";
    int len = word.length();
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