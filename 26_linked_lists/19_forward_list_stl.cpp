/*
    TOPIC: Forward List STL

    Forward lists are implemented as singly-linked lists.

    Compared to other base standard sequence containers (array, vector and deque), forward_list perform
    generally better in inserting, extracting and moving elements in any position within the container, 
    and therefore also in algorithms that make intensive use of these, like sorting algorithms.

    The main drawback of forward_lists and lists compared to these other sequence containers is that they
    lack direct access to the elements by their position.
    For example, to access the sixth element in a forward_list one has to iterate from the beginning to 
    that position, which takes linear time in the distance between these.

    Ref: https://www.cplusplus.com/reference/forward_list/forward_list/

*/
