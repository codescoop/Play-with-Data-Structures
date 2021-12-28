/* 
    Topic - Type of Memory Allocation
    
    There are two ways that memory gets allocated for data storage:
    
    - Compile Time Allocation (or static allocation)
       > Memory for named variables is allocated by the compiler
       > Exact size and type of storage must be known at compile time
       > For standard array declarations, this is why the size has to be constant
       > It uses stack for managing the static allocation of memory

    - Dynamic Memory Allocation (or run time allocation)
       > Memory allocated “on the ﬂy” during run time
       > dynamically allocated space usually placed in a program segment known as the heap or 
         the free store
       > Exact amount of space or number of items does not have to be known by the compiler in advance.
       > For dynamic memory allocation pointers are crucial. Also, memory allocation & deallocation
         is done by programmer (using new & delete operators)
       > It uses heap for managing the dynamic allocation of memory
       
    NOTE: For dynamically allocated memory it is programmers responsibility to deallocate 
          memory when no longer needed. If programmer doesn’t deallocate memory, it causes 
          memory leak (memory is not deallocated until program terminates). 

    Extra Info:
    
    - Symbol Table in Compiler
        > A Symbol table is a data structure used by the compiler, where each 
          identifier in program’s source code is stored along with information associated 
          with it relating to its declaration. 
        > It stores identifier as well as it’s associated attributes like scope, type, 
          line-number of occurrence, etc.

*/

#include <iostream>
using namespace  std;


int main(){
    // Compile Time (Static Allocation)
    
    int b[100];
    /*  In above statement, 'b' value is mapped with the address of array in symbol table 
        during compile time */

    cout << "Size of b[100]: " << sizeof(b) << endl;
    /*  The above value of b is coming from symbol table. According to which 'b' is a array. So, it print 
        the size of the complete array allocated during compile time */
    
    cout << "b: " << b << "\n\n";       // starting address of array

    int z[100];
    // b = z;                           // Illegal (over writing value of 'b')
    /*  As b is a constant that is stored inside symbol table. So, b is a part of real only memory & 
        it cannot be over written */


    // Run Time (Dynamic Allocation)
    int range;
    cout << "Enter Range: ";
    cin >> range;

    int *a = new int[range];           // allocate memory
    /*  In above statement, memory to [pointer variable 'a'] is assigned in static memory & 
        memory to [interger array] is assigned in the heap memory during run time.
        Now, The "new" opertor will return the address of dynamically allocated array & assign it 
        to pointer variable. */

    cout << "Size of a: " << sizeof(a) << endl;
    /*  As value of 'a' is coming from static memory. According to which 'a' is a pointer (not a array).
        So, it will print the size of pointer variable (not the size of complete array) */

    cout << "a: " << a << endl;      // starting address of array
    
    a = new int[30];                   // legal (over writing value of 'a')
    /*  As pointer variable 'a' is created inside static memory so its value can be over written */

    delete [] a;                       // freeup the  memory

    return 0;
}

/* 
OUTPUT: 
    Size of b[100]: 400
    b: 0x7ffd2db1b450

    Enter Range: 16
    Size of a: 8
    a: 0x5615bf6856d0



More Info:

- Stack, Static, and Heap in C++ (the short answer):

    > stack variable
      lifetime    = from declaration until declaring scope is exited
      visibility  = from declaration until scope is exited
    
    > heap variable
      lifetime    = defined by you (new to delete)
      visibility  = defined by you (whatever you assign the pointer to)

    > static variable (global scope)
      lifetime    = program runtime (1)
      visibility  = the compilation unit it is instantiated in (2)
    
    > static variable (class)
      lifetime    = program runtime (1)
      visibility  = determined by access modifiers (private/protected/public)
  
    > more exactly: from initialization until deinitialization of the compilation unit (i.e. C / C++ file).
                    Order of initialization of compilation units is not defined by the standard.

    > Beware: if you instantiate a static variable in a header, each compilation unit gets its own copy.



- What Static, Heap, and Stack Memory are:
    > A static variable is basically a global variable, even if you cannot access it globally. 
        Usually there is an address for it that is in the executable itself. 
        There is only one copy for the entire program. 
        No matter how many times you go into a function call (or class) (and in how many threads!) 
        the variable is referring to the same memory location.

    > The heap is a bunch of memory that can be used dynamically. 
        If you want 4kb for an object then the dynamic allocator will look through its list of 
        free space in the heap, pick out a 4kb chunk, and give it to you. 
        Generally, the dynamic memory allocator (malloc, new, etc.) starts at the end of memory and 
        works backwards.

    > Explaining how a stack grows and shrinks is a bit outside the scope of this answer, but 
        suffice to say you always add and remove from the end only. 
        Stacks usually start high and grow down to lower addresses. 
        You run out of memory when the stack meets the dynamic allocator somewhere in the middle 
        (but refer to physical versus virtual memory and fragmentation). 
        Multiple threads will require multiple stacks (the process generally reserves a minimum 
        size for the stack).

- When you would want to use each one:
    > Statics/globals are useful for memory that you know you will always need and you know that 
      you don't ever want to deallocate. (By the way, embedded environments may be thought of as 
      having only static memory... the stack and heap are part of a known address space shared by 
      a third memory type: the program code. Programs will often do dynamic allocation out of their
      static memory when they need things like linked lists. But regardless, the static memory itself
      (the buffer) is not itself "allocated", but rather other objects are allocated out of the 
      memory held by the buffer for this purpose. You can do this in non-embedded as well, and console games
      will frequently eschew the built in dynamic memory mechanisms in favor of tightly controlling the 
      allocation process by using buffers of preset sizes for all allocations.)

    > Stack variables are useful for when you know that as long as the function is in scope (on the 
      stack somewhere), you will want the variables to remain. Stacks are nice for variables that you 
      need for the code where they are located, but which isn't needed outside that code. They are also
      really nice for when you are accessing a resource, like a file, and want the resource to 
      automatically go away when you leave that code.

    > Heap allocations (dynamically allocated memory) is useful when you want to be more flexible than 
      the above. Frequently, a function gets called to respond to an event (the user clicks the 
      "create box" button). The proper response may require allocating a new object (a new Box object) 
      that should stick around long after the function is exited, so it can't be on the stack. But you 
      don't know how many boxes you would want at the start of the program, so it can't be a static.

- Garbage Collection
    > I've heard a lot lately about how great Garbage Collectors are, so maybe a bit of a dissenting 
      voice would be helpful.

    > Garbage Collection is a wonderful mechanism for when performance is not a huge issue. 
      I hear GCs are getting better and more sophisticated, but the fact is, you may be forced to accept 
      a performance penalty (depending upon use case). And if you're lazy, it still may not work properly. 
      At the best of times, Garbage Collectors realize that your memory goes away when it realizes that 
      there are no more references to it (see reference counting). But, if you have an object that refers 
      to itself (possibly by referring to another object which refers back), then reference counting alone 
      will not indicate that the memory can be deleted. In this case, the GC needs to look at the entire 
      reference soup and figure out if there are any islands that are only referred to by themselves. 
      Offhand, I'd guess that to be an O(n^2) operation, but whatever it is, it can get bad if you are at 
      all concerned with performance. (Edit: Martin B points out that it is O(n) for reasonably efficient 
      algorithms. That is still O(n) too much if you are concerned with performance and can deallocate in 
      constant time without garbage collection.)

    > Personally, when I hear people say that C++ doesn't have garbage collection, my mind tags that as 
      a feature of C++, but I'm probably in the minority. Probably the hardest thing for people to learn 
      about programming in C and C++ are pointers and how to correctly handle their dynamic memory 
      allocations. Some other languages, like Python, would be horrible without GC, so I think it comes 
      down to what you want out of a language. If you want dependable performance, then C++ without 
      garbage collection is the only thing this side of Fortran that I can think of. If you want ease 
      of use and training wheels (to save you from crashing without requiring that you learn "proper" 
      memory management), pick something with a GC. Even if you know how to manage memory well, it will 
      save you time which you can spend optimizing other code. There really isn't much of a performance 
      penalty anymore, but if you really need dependable performance (and the ability to know exactly 
      what is going on, when, under the covers) then I'd stick with C++. There is a reason that every 
      major game engine that I've ever heard of is in C++ (if not C or assembly). Python, et al are fine 
      for scripting, but not the main game engine.

*/