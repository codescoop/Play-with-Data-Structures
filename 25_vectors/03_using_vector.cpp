/* 
    TOPIC: Using Vector (with Pair)

    Car Sorting Problem
    --------------------
    We want to book a cab. 
    Assume that we are standing at origin(0,0) & 
    we are provides the coordinates (xi,yj) of each cabs as input.
    So, we have to sort the cab on the basis of distance from our location (i.e (0,0)).

                        ^
                        |      c1   
          c4            |    (x1,y1)
        (x4,y4)         |              c2
                        |            (x2,y2)
        <---------------|---------------->
                   (0,0)|
                        |       c3
                        |     (x3,y3)
                        |
                        v

    Approach-I : Using [vector + pair]
    Approach-II: Using [vector + custom class]

    Lets's solve the above problem using Approach-I

*/


#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;


bool compare(pair<int,int> p1, pair<int,int> p2)
{
    /* The 2D distance between two points A(x₁, y₁) & B((x₂, y₂)) is √[(x₂ - x₁)² + (y₂ - y₁)²]
       when, (x₁, y₁) = (0,0)
       then, Distance : √[(x₂)² + (y₂)²]
    */
    int distance1 = sqrt(p1.first*p1.first + p1.second*p1.second);
    int distance2 = sqrt(p2.first*p2.first + p2.second*p2.second);
    // If two cabs have same distance, then sort accourding to x coordinates.
    if(distance1 == distance2)
    {
        return p1.first < p2.first;
    }
    return distance1 < distance2;
}


int main()
{
    int n;
    cout << "Enter total cabs: ";
    cin >> n;

    vector<pair<int,int>> cabs;

    cout << "Enter cabs coordinates (xi,yj): ";
    for(int i=0; i<n; i++)
    {
        int x,y;
        cin >> x >> y;
        cabs.push_back(make_pair(x,y));
    }

    // sort cabs according to distance
    sort(cabs.begin(),cabs.end(), compare);

    // for each loop
    cout << "Cabs [Sorted Order]: \n";
    for(auto x:cabs)
    {
        cout << x.first << " " << x.second << endl;
    }
    return 0;
}


/* 
OUTPUT:

    Enter total cabs: 4

    Enter cabs coordinates (xi,yj):
    1 2
    2 2
    1 0
    3 4
    
    Cabs [Sorted Order]: 
    1 0
    1 2
    2 2
    3 4

*/