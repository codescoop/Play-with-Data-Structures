/* 
    TOPIC: Linked List - Introduction

    Linked List: 
    - A linked list is a linear data structure, in which the elements are NOT stored at contiguous memory 
      locations. The elements in a linked list are linked using pointers 
    - In linked list, we allocate memory when we get new data point.

    |100| ----        _100_
     head    '------>|1|300|-------        _300_         _200_
    node*           int Address   '------>|3|200|------>|2|400|----         _400__
                     |------|                                     '------->|4|NULL|
                       node               |------|
                                            node

    - So, Linked list are collection of nodes allocated in the memory that stores data.

    - Some time we also need to store the address of the last node, if we want to perform operation
      at the end of linked list.

    |100| ----        _100_
     head    '------>|1|300|-------        _300_         _200_
    node*           int Address   '------>|3|200|------>|2|400|----         _400__
                     |------|                                     '------->|4|NULL|--->|400|
                       node               |------|                                      tail
                                            node                                        node*
*/

