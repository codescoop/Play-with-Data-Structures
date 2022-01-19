/* 
    Problem - Sort Game

    Sanju needs your help! He gets a list of employees with their salary. The maximum salary is 100.

    Sanju is supposed to arrange the list in such a manner that the list is sorted in decreasing order
    of salary. And if two employees have the same salary, they should be arranged in lexicographical
    manner such that the list contains only names of those employees having salary greater than or 
    equal to a given number x.
    Help Sanju prepare the same!

    Input Format: On the first line of the standard input, there is an integer x. 
                  The next line contans integer N, denoting the number of employees. 
                  N lines follow, which contain a string and an integer, denoting the name of 
                  the employee and his salary.

    Constraints:  1 <= N <= 10^5 
                  1 <= | Length of the name | <= 100 
                  1 <= x, salary <= 100

    Output Format: You must print the required list.

    Sample Input:   79
                    4
                    Eve 78
                    Bob 99
                    Suzy 86
                    Alice 86

    Sample Output:  Bob 99
                    Alice 86
                    Suzy 86

*/

#include <iostream>
#include <algorithm>
using namespace std;

// custom comparator to sort the employees
bool compare(pair<string,int> emp1, pair<string,int> emp2)
{
    if(emp1.second == emp2.second){
        return emp1.first < emp2.first;
    }
    return emp1.second > emp2.second;
}


// function to drive code
int main()
{
    int salary_limit;
    cout << "Enter salary threshold: ";
    cin >> salary_limit;

    int total_emp;
    cout << "Total Employees: ";
    cin >> total_emp;
    
    pair<string,int> emp[total_emp];
    cout << "Enter Employee Data [Name & Salary]: \n";
    for(int idx=0; idx<=total_emp-1; idx++)
    {
        cin >> emp[idx].first >> emp[idx].second;
    }

    sort(emp, emp+total_emp, compare);

    cout << "List after sorting: \n";
    for(int idx=0; idx<=total_emp-1; idx++)
    {
        if(emp[idx].second >= salary_limit){
            cout << emp[idx].first << " " << emp[idx].second << endl;
        }
            
    }

    return 0;
}

/* 
OUTPUT:

    Enter salary threshold: 79
    Total Employees: 4

    Enter Employee Data [Name & Salary]: 
    Eve 78
    Bob 99
    Suzy 86
    Alice 86

    List after sorting: 
    Bob 99
    Alice 86
    Suzy 86


APPROACH:
    - We just need to prepare a custom comparator to sort the employees.

CODE:
    #include <iostream>
    #include <vector>
    #include <string>
    #include <algorithm>

    using namespace std;


    class Employee
    {
        public:

        int salary;
        string name;

        Employee( int sal , string nam)
        {
            salary = sal;
            name = nam;
        }
    };

    bool operator>( string s1 , string s2 )
    {
        int min = s1.size() < s2.size() ? s1.size() : s2.size(); 

        int index = 0;

        while( index < min && s1[index] == s2[index])
        {
            index++;
        }

        if( index >= min )
        {
            if( s1.size() > s2.size() ) return true;
            else return false;
        }

        if( s1[index] > s2[index] ) return true;
        else return false;

    }

    bool lol( Employee e1 , Employee e2 )
    {
        if( e1.salary > e2.salary )
        {
            return true;
        }
        else
        if( e1.salary < e2.salary )
        {
            return false;
        }

        return e2.name > e1.name;
    }

    void sort2( vector<Employee> &v )
    {
        sort( v.begin() , v.end() , lol);
    }

    int main()
    {
        int n2;
        cin >> n2;

        int n;
        cin >> n;

        vector<Employee> v;

        for(int i = 0 ; i < n ; i++ )
        {
            string s;
            cin >> s;

            int n;
            cin >> n;

            Employee E( n , s);
            v.push_back(E);
        }

        sort2(v);

        for(int i = 0 ; i < n ; i++ )
        {
            if( v[i].salary < n2 ) break;

            cout << v[i].name << " " << v[i].salary << "\n";
        }

        return 0;
    }
*/