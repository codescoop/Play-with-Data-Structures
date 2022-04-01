/* 
    TOPIC: 06 - Template

    Converting a class into a Templated class

    NOTE: filename: vector2.h

*/

template<typename T>
class Vector2

{
    int cs;       // cs: current size
    int ms;       // cs: max size
    T *arr;     // pointer
    
    public:
    Vector2()      // constructor
    {
        cs = 0;
        ms = 1;
        arr = new T[ms];
    }

    void push_back(const T d)      // d: data
    {
        if(cs == ms)
        {
            T *oldArr = arr;
            arr = new T[2*ms];
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

    T front() const
    {
        return arr[0];
    }
    
    T back() const
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
    T at(const int i)
    {
        return arr[i];
    }

    int size() const
    {
        return cs;
    }

    // operator overloading
    T operator[](const int i)
    {
        return arr[i];
    }

};