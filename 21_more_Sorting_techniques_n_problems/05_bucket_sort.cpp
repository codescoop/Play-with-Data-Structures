/*
    Topic - Bucket Sort

    Bucket Sort is a sorting algorithm that divides the unsorted array elements into several groups 
    called buckets. Each bucket is then sorted by using any of the suitable sorting algorithms or
    recursively applying the same bucket algorithm.
    Finally, the sorted buckets are combined to form a final sorted array.

*/

#include <iostream>
#include <vector>
using namespace std;

class Student 
{
public:
    int marks;
    string name;
};


// bucket sort to sort an array of students
void bucket_sort(Student s[], int n)
{
    // assuming marks are in the range [0 to 100]
    vector<Student> v[101];

    // O(N) time - Just iterationg over array & inserting students in the vector as per marks
    for(int i=0; i<n; i++)
    {
        int mk = s[i].marks;
        v[mk].push_back(s[i]);
    }

    // Iterate over vector in reverse order & print the students
    for(int i=100; i>=0; i--)
    {
        for(vector<Student>::iterator it = v[i].begin(); it != v[i].end(); it++)
        {
            cout << (*it).marks << " " << (*it).name << endl;
        }
    }
    
}


// function to drive code
int main()
{
    int n;
    cout << "Enter total Students: ";
    cin >> n;

    Student s[n];

    cout << "Enter Students [Marks & Name]: ";
    for(int i=0; i<n; i++)
    {
        cin >> s[i].marks >> s[i].name;
    }

    cout << "Sorted [As per Marks]: \n";
    bucket_sort(s,n);

    return 0;
}


/*
OUTPUT:

    Enter total Students: 6
    
    Enter Students [Marks & Name]: 
    39 Ario
    65 Brad
    54 Creo
    98 Raman
    25 Joy
    65 Deep
    
    Sorted [As per Marks]: 
    98 Raman
    65 Brad
    65 Deep
    54 Creo
    39 Ario
    25 Joy

*/