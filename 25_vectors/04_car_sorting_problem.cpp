/* 
    TOPIC: Using Vector (with Pair)

    Car Sorting Problem
    --------------------
    We want to book a cab. 
    Assume that we are standing at origin(0,0).
    we are provides 3 inputs: 1 cab name &  2 as coordinates (xi,yj).
    So, we have to sort the cab on the basis of distance from our location (i.e (0,0)) & 
        if distance of two cabs are same, then sort according to the name.

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

    Approach: Using [vector + custom class]

*/


#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;


class Car
{
    public:
        string car_name;
        int x,y;

        Car(string name, int x, int y)      // parameterized constructor
        {
            car_name = name;
            this->x = x;
            this->y = y;
        }

        int find_dist()
        {
            // returns square of dist from origin
            return x*x + y*y;

            /* The 2D distance between two points A(x₁, y₁) & B((x₂, y₂)) is √[(x₂ - x₁)² + (y₂ - y₁)²]
            when, (x₁, y₁) = (0,0)
            then, Distance : √[(x₂)² + (y₂)²]
            */
        }
};

bool compare(Car c1, Car c2)
{
    int distance1 = c1.find_dist();
    int distance2 = c2.find_dist();
    // If two cabs have same distance, then sort according to car name.
    if(distance1 == distance2)
    {
        // return c1.car_name.length() < c2.car_name.length();
        return c1.car_name < c2.car_name;
    }
    return distance1 < distance2;
}


int main()
{
    int n;
    cout << "Enter total cabs: ";
    cin >> n;

    vector<Car> v;

    cout << "Enter Car [Name & Coordinates(xi,yj)]: ";
    for(int i=0; i<n; i++)
    {
        int x,y;
        string name;
        cin >> name >> x >> y;
        Car obj(name,x,y);
        v.push_back(obj);
    }

    // sort car according to distance
    sort(v.begin(),v.end(), compare);

    // for each loop
    cout << "Car [Sorted Order]: \n";
    for(auto i:v)
    {
        cout << i.car_name << " " << i.x << " " << i.y << " | Distance: " << i.find_dist()<< endl;
    }
    return 0;
}


/* 
OUTPUT:

    Enter total cabs: 4

    Enter Car [Name & Coordinates(xi,yj)]: 
    Breeza  3 4
    Swift   0 1        
    Safari  1 0
    Nano    2 4

    Car [Sorted Order]: 
    Safari  1 0 | Distance: 1
    Swift   0 1 | Distance: 1
    Nano    2 4 | Distance: 20
    Breeza  3 4 | Distance: 25

*/