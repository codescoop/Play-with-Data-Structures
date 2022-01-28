/*
    Topic: Counting Problems - Inclusion Exclusion Principle

    - Count number of objects in a particlar kind of a sets


    Principle of Inclusion Exclusion (PIE)
    - The principle of inclusion and exclusion (PIE) is a counting technique that computes the 
      number of elements that satisfy at least one of several properties while guaranteeing that 
      elements satisfying more than one property are not counted twice.

    - The Principle of Inclusion-Exclusion (abbreviated PIE) provides an organized method/formula to 
      find the number of elements in the union of a given group of sets, the size of each set, and 
      the size of all possible intersections among the sets.

    - The inclusion-exclusion principle is an important combinatorial way to compute the size of a set or
      the probability of complex events. It relates the sizes of individual sets with their union.

    Basics:

    Set: A set is an unordered collection of different elements. If the order of the elements is changed or
         any element of a set is repeated, it does not make any changes in the set.
         Eg:  Set of odd numbers less than 10,   A = {1,3,5,7,9}
              Set of vowels in English alphabet, B = {a,e,i,o,u}

    Type of Set: 1. Empty Sets     - The set, which has no elements, is also called a Null set or Void set. 
                                     Eg: It is denoted by {}.
                 2. Singleton Sets - The set which has just one element is named a singleton set. 
                                     Eg: Set A = { 8 }
                 3. Finite         - A set which has a finite number of elements is known as finite sets.
                                     Eg: Set A = {3,4,5,6,7}
                 4. Infinite Sets  - The set whose elements can't be estimated, but it has some figure or number, which is large to precise in a set which is known as Infinite Set.
                                     Eg: Set C = {Number of Cows in India}
                 5. Equal Sets     - If every element of set A is also the elements of set B and if every element of set A is also the elements of set A are called equal sets. (A = B)
                                     Eg: A = {3,4,5,6} and B = {6,5,4,3}, then A = B
                 6. Subsets        - A set S is said to be a subset of set T if each element of set S is present in set T. 
                                     Eg: It is denoted by the symbol (⊂) and written as S ⊂ T.
                 7. Power Sets     - The set of all subsets is known as power sets.We know the empty set is a subset of all sets, and each set is a subset of itself.
                                     Eg: If Set A = {a, b}, then subsets are {},{a},{b},{a,b} Now, power set P(A) = {{},{a},{b},{a,b}}  So, Now, the Power Set has (2)^2 = 4 elements.
                 8. Universal Sets - A set that contains all the elements of other sets is called universal sets.
                                     It is represented as ‘U’ Eg: set A = {1,2}, set B = {3} and C = {5,6} then universal set, U = {1,2,3,4,5,6,} Therefore, A ⊂ U, B ⊂ U And C ⊂ U
                 9. Disjoint Sets  - If two sets X and Y do not have any common elements, and their intersection results in zero(0). 
                                     Eg: It can be represented as; X ∩ Y = 0.

    Union, Intersection, Difference and Complement of Sets-

    - Union of Sets: The union of two sets consists of all their elements. It is denoted by (⋃).
                     Eg: Set A = {2,3,7} and set B = { 4,5,8}
                         A ⋃ B = {2,3,7,4,5,8}
    
    - Intersection of Sets: The set of all elements, which are common to all the given sets, 
                            gives an intersection of sets. It is denoted by ⋂.
                            Eg: set A = {2,3,7} and set B = {2,4,9}
                                A ⋂ B = {2}

    - Difference of Sets: The difference between set S and set T is such that it has only those elements 
                          which are in the set S and not in the set T
                          S – T = {p : p ∊ S and p ∉ T}

    - Complement of a Set: Let U be the universal set and let A ⊂ U. 
                           Then, the complement of A, denoted by A’ or (U - A)
                           A’ = {x   U : x  A}


    - Cardinality:  The total number of elements present in a set.

    - Cardinal Number of a Set: The number of distinct elements in a finite set is known as the cardinal 
                                number of a set.
                              - Basically, through cardinality, we define the size of a set. 
                              - The cardinal number of a set A is denoted as n(A), 
                                where A is any set and n(A) is the number of members in set A.
        Eg: Consider a set A consisting of the prime numbers less than 10.
            Set A ={2, 3, 5, 7}.
            As the set A consists of 4 elements, therefore, the cardinal number of set A is given as n(A) = 4
    

    - Properties related to difference, union and intersection and the cardinal number of set
      1) Union of Disjoint Sets: If A and B are two finite sets and if A ∩ B = ∅ (i.e no element is common to both the sets) then, 
                                 n(A ∪ B) = n(A) + n(B)
      2) Union of two sets: If A and B are two finite sets, then 
                            n(A ∪ B) = n(A) + n(B) – n(A ∩ B)
      3) Union of three sets: If A, B and C are three finite sets, then;
                        n(A ∪ B ∪ C) = n(A) + n(B) + n(C) – n(A ∩ B) – n(B ∩ C) – n(A ∩ C) + n(A ∩ B ∩ C)


    Questions to be Solved-

    - How many no's from 1 to 100 are multiples of 2 & 3?
      Eg:  A -> multiple of 2  =  100/2  =  50
           B -> multiple of 3  =  100/3  =  33     // lower bound value
         A∩B -> multiple of 6  =  100/6  =  16     // 2*3 = 6

         |A∪B| = |A| + |B| - |A∩B|                 // union of set A and B
               = 50 + 33 - 16
               = 67
*/