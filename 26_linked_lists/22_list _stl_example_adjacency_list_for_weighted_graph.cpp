/*
    TOPIC: List STL Example - Adjacency List for Weighted Graph

    List Example => Implementing a Graph
    - What is graph data structure
      Suppose we are given a network of cities & distance between every city.
      Now, we are interested in storing this entire information in the memory of computer.

                        |1|               0 = Delhi
                       /  \               1 = Gurgaon
                    5 /    \ 3            2 = faridabad
                     /      \             3 = Noida
             ------|0|       |2| <---     4 = Ghaziabad
            |       \        /      |     
            |        \      /       |     
            |       6 \    / 8      |     
            |          \  /         |     
            |          |3|          |     
            |         /             |     
            |        /  2           |     
            |      |4|              |     
            |_______________________|     
                           10             


      Now, 0 (i.e delhi) is connected with 1 with length 5 (i.e 1,5), 3 with length 6 (i.e 3,6) & 2 with length 10 (i.e 2,10)
      So,  0 -> (1,5) (3,6) (2,10)
           1 -> (0,5) (2,3)
           2 -> (0,10) (1,3) (3,8)
           3 -> (0,6) (2,8) (4,2)
           4 -> (3,2)

    NOTE: The above representaion of graph is known as Adjacency List.

    Now, In the below code, we will store a network in the form of Adjacency List
*/


#include <iostream>
#include <list>
using namespace std;

int main()
{
    // list<pair<int,int> > l;           // static
    // list<pair<int,int> > l[5];        // static
    
    list<pair<int,int> > *l;             // dynamic
    
    int v;
    cout << "No of connections [i.e vertices]: ";            // total vertices
    cin >> v;

    l = new list<pair<int,int>>[v];      //  array of linked list

    int e;
    cout << "No of cities [i.e edges]: ";                 // total edges
    cin >> e;

    for(int i=0; i<v; i++)
    {
        int x,y,wt;
        cout << "Enter [x,y,distance]: ";
        cin >> x >> y >> wt;
        l[x].push_back(make_pair(y,wt));
        l[y].push_back(make_pair(x,wt));
    }

    //print the linked list
    for(int i=0; i<v; i++)
    {
        // if(i <= e)
        // {
        //     cout << "Linked list [Edge]: " << i << "-> ";
        // }

        cout << "Linked list [Edge]: " << i << "-> ";
        // print every linked list
        for(auto ele_pair:l[i])
        {
            cout << "(" << ele_pair.first << "," << ele_pair.second << ")"; 
        }
        cout << endl;
    }

    return 0;
}

/* 
OUTPUT:

Case 1:
    No of connections [i.e vertices] : 6
    No of cities [i.e edges]         : 4
    Enter [x,y,distance]             : 0 1 5
    Enter [x,y,distance]             : 0 3 6
    Enter [x,y,distance]             : 0 2 10
    Enter [x,y,distance]             : 1 2 3
    Enter [x,y,distance]             : 2 3 8
    Enter [x,y,distance]             : 3 4 2
    
    Linked list [Edge] : 0-> (1,5)(3,6)(2,10)
    Linked list [Edge] : 1-> (0,5)(2,3)
    Linked list [Edge] : 2-> (0,10)(1,3)(3,8)
    Linked list [Edge] : 3-> (0,6)(2,8)(4,2)
    Linked list [Edge] : 4-> (3,2)
    Linked list [Edge] : 5-> 

Case2:
    No of connections [i.e vertices] : 3
    No of cities [i.e edges]         : 3
    Enter [x,y,distance]             : 0 1 4 
    Enter [x,y,distance]             : 0 2 3
    Enter [x,y,distance]             : 1 2 4

    Linked list [Edge] : 0-> (1,4)(2,3)
    Linked list [Edge] : 1-> (0,4)(2,4)
    Linked list [Edge] : 2-> (0,3)(1,4)
    
                        ---------------

                              |0|     
                             /   \     
                          4 /     \ 3  
                           /       \   
                         |1|-------|2| 
                               4      

*/