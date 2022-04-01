/* 
    TOPIC: 05 - Container Design

    We will be designing our own vector class.
    To understand, How STL containers are implemented ?

    NOTE: filename: vector.h

*/

class Vector
{
    int cs;       // cs: current size
    int ms;       // cs: max size
    int *arr;     // pointer
    
    public:
    Vector()      // constructor
    {
        cs = 0;
        ms = 1;
        arr = new int[ms];
    }

    void push_back(const int d)      // d: data
    {
        if(cs == ms)
        {
            int *oldArr = arr;
            arr = new int[2*ms];
            ms = 2*ms;
            for(int i=0; i<cs; i++)
            {
                arr[i] = oldArr[i];
            }
            // clear old memory
            delete [] oldArr;
        }
        arr[cs] = d;
        cs++;
    }

    void pop_back()
    {
        // we don't want to shrink the array. So, just decrement index
        cs--;
    }

    int front() const
    {
        return arr[0];
    }
    
    int back() const
    {
        return arr[cs-1];
    }

    bool empty() const
    {
        return cs==0;
    }

    int capacity() const
    {
        return ms;
    }

    // gives the element at i-th index
    int at(const int i)
    {
        return arr[i];
    }

    int size() const
    {
        return cs;
    }

    // operator overloading
    int operator[](const int i)
    {
        return arr[i];
    }

};