/* 
   Question & Answers
   
   INDEX:
    Q1:  Basic Maths Concepts
    Q2:  Why start + (end – start)/2 is preferable method for calculating middle of an array
         over (start + end)/2 ?
    Q3:  Why did we make an array ofsize 100005?
    Q4:  Can an array size be more than 100000 in C++? If so, how?
    Q5:  I need to store about 10^7 elements in an array. Such a large size is not permissible. 
         I thought about using pointers but that is giving an error. How should we go about storing 
         the elements when the number of elements is too large as of the order of 10^7?
    Q6:  Calculate-power-function
    Q7:  Sequence [1 + 1/2 + 1/3 + 1/4 + .. + 1/n] = logn. How ?
    Q8:  Difference between an Arithmetic and Geometric Progressions
         Commenly used AP, GP sequences? 
    Q9:  Program to find sum of series [1 + 1/2 + 1/3 + 1/4 + .. + 1/n]
   Q10:  How many approx loops are allowed in 1 sec time limit?
         How many Number of Instructions/Opertions can be executed in 1 sec?
         How many instructions can be executed in Codeforces and TopCoder judge PCs in one second?
   Q11:  Gigabyte(GB) = 1024 MB  or Gibibyte(Gib) = 1000 MiB ?
   Q12:  Mbps Vs MBps?
   Q13:  How many digit a data type can store ?
         What is the range of a long long int and an int in powers of 10?
         Which data type should i use to store upto 18 digits in a variable in c++?
   Q14:  Does type unsigned long long int is it enough for 1 - 10^9 range?
   Q15:  What range of values can integer types store in C++ ??
         what are the ranges of [unsigned  & unsigned] short int, int, long int?


------------------------------------------------------------------------------------------
Q1: Basic Maths Concepts

S1: Permutation & Combination - https://www.mathsisfun.com/combinatorics/combinations-permutations.html
    Pascal's Triangle         - https://www.mathsisfun.com/pascals-triangle.html
    Logarithms & Exponents    - https://www.mathsisfun.com/algebra/logarithms.html


------------------------------------------------------------------------------------------
Q2: Why start + (end – start)/2 is preferable method for calculating middle of an array
    over (start + end)/2 ?

S2: Because (start + end)/2 can caused OVERFLOW !
    when "start" and "end" are all about INT_MAX , then (start+end) of course will be overflow !
    (Note that end - start may overflow, but only if start < 0 or end < 0.)
    
    Ref- https://stackoverflow.com/questions/38688028/why-prefer-start-end-start-2-over-start-end-2-when-calculating-the


------------------------------------------------------------------------------------------
Q3: Why did we make an array ofsize 100005?
    
S3: As given in the question that N goes upto 10^5, so we take an array of size of 10^5 + 5 so that 
    maximum number of elements can accumulate in that array and we usually take few elements more than
    the maximum number of the elements to access elements like n, or n+1 if need be.

    There is no fixed rule to take the size of array as 100005…we generally take the size of the array 
    as the constraints plus 5. we add the extra 5 so that if at any point i exceeds the the maximum value
    of the constraints in the last iteration of loop, and tries to access a[100001] (for ex.), 
    the program doesn’t give runtime error.


------------------------------------------------------------------------------------------
Q4: Can an array size be more than 100000 in C++? If so, how?

S4: When you declare a local variable as an array, it is restricted to the size of the stack.
    To have larger arrays, you need to either declare it as a static variable or in file scope

    // This array is in file scope 
    int arr[10000000]; 
    
    int fn(int param) 
    { 
        // Causes stack overflow 
        int arr1[10000000]; 
        
        // This works fine, same storage everytime this function is called 
        static int arr2[10000000] 
    } 

    Static variables live in what is called the static heap. Ideally you should use new or malloc to 
    allocate memory on the runtime heap, unless you know beforehand how much you need.
    I have a suspicion you may be asking this because you tried using a large array in Turbo C++
    In that case you should know that since Turbo C++ is a legacy compiler built for 16 bit processors,
    the maximum contiguous array you can have is 64 KB, without using complex tricks involving 
    8086 segmented memory addressing.


------------------------------------------------------------------------------------------
Q5: I need to store about 10^7 elements in an array. Such a large size is not permissible. 
    I thought about using pointers but that is giving an error. How should we go about storing 
    the elements when the number of elements is too large as of the order of 10^7?

S5: In a C/C++ function, the local memory (whatever memory you allocate statically inside the function)
    is stored in a stack. The stack memory has limitations. Generally that limit is around 4MB. 
    This limit is configurable. So, if you calculate, that turns out to be 10^6 ints roughly, which means
    usually you can't statically allocate memory beyond 10^6 ints in a function and if you do, you get a
    runtime error.

    If you globally allocate some space (statically or dynamically), you can use memory even beyond 
    10^6 ints. Here, the limitation is enforced by the address space available in the system or it may
    be configured in the execution environment. 
    For example, SPOJ Pyramid cluster enforces 256MB memory limit and SPOJ Cube cluster has a limit 
    of 1536MB. If you use memory beyond that, you will receive a SIGKILL on SPOJ/Codechef.

    So for your use case, you can globally define an array of 10^7 ints (~40MB), chars (~10MB) or 
    long longs (80MB).


------------------------------------------------------------------------------------------
Q6: Calculate-power-function

S6: 1. Naive Iterative approach
    2. Divide and Conquer approach
    3. Optimized divide and conquer approach
    Reference: AfterAcademy  - https://afteracademy.com/blog/calculate-power-function
               TechieDelight - https://www.techiedelight.com/power-function-implementation-recursive-iterative/
               StackOverflow - https://stackoverflow.com/questions/2882706/how-can-i-write-a-power-function-myself


------------------------------------------------------------------------------------------
Q7: Sequence [1 + 1/2 + 1/3 + 1/4 + .. + 1/n] = logn. 
    How ?

S7: logn
                                                                      n        n
    There is no simple closed form. But a rough estimate is given by: ∑ 1/r ≈ ∫ dx/x = logn
                                                                     r=1     1

    Reference: https://math.stackexchange.com/questions/3367037/sum-of-1-1-2-1-3-1-n


------------------------------------------------------------------------------------------
Q8: Difference between an Arithmetic and Geometric Progressions
    Commenly used AP, GP sequences? 

S8: - Sum of the First n Positive Integers 
      S(n) ​= 1+2+3+4+.....+n  = __n*(n+1)__
                                    2

    - Sum of the Squares of the First n Positive Integers 
      S(n) ​= 1+4+9+16+...+n^2  =  __n*(n+1)*(2n+1)__
                                          6

    - Sum of the Cubes of the First n Positive Integers
      S(n) ​= 1+8+27+64+...+n^3  =  __n^2_*_(n+1)^2__
                                         4

    - Sequence [1 + 1/2 + 1/3 + 1/4 + .. + 1/n] = logn

    - Sequence [(1+2+4+8+16+ ..... 2^(n-1)]   =   _(2^(n-1)_-_1)__
                                                        n-1
      [Above sequence is calculated by formula: Sum of n terms in Geometric Progressions]


    Arithmetic Sequence & Geometric Sequence

    - An arithmetic Sequence is a set of numbers in which each new phrase differs from the previous term
      by a fixed amount. 
      (The variation between the members of an arithmetic sequence is linear.) 

      Geometric Sequence is a series of integers in which each element after the first is obtained by 
      multiplying the preceding number by a constant factor.
      (The variation in the sequence’s elements is exponential.)


    - If the difference between any two consecutive terms is always the same, a sequence of integers is
      termed an Arithmetic Sequence.
        a, a + d, a + 2d, a + 3d, a + 4d
        where a = the first term,
              d = common difference between terms.
        Eg:  5, 11, 17, 23, 29, 35, …,  the constant difference is 6.

      If the ratio of any two consecutive terms is always the same, a sequence of numbers is called a
      Geometric Sequence.
        a, ar, ar2, ar3, ar4 …
        where a = first term,
              d = common difference between terms.
        Eg: 2, 6, 18, 54, 162,… The constant multiplier is 3 in this case. 
    

    Formula: 
      In AP, a =  first term of the sequence
             d =  common difference
      In GP, a =  first term of the sequence
             r =  common ratio

    - Nth Term
       Then, the nth term of the sequence is given by: 
       a(n)  =  a + (n−1)d

       Then, the nth term of the sequence is given by: 
       a(n)  =  a * r^(n−1)


    - Sum of n terms 
      In AP, S(n) = __n_*_[2a_+_(n – 1)d]__
                      2

      In GP, S(n) = __a_*_(1_-_r^n)__   ; r!=1 and r<1
                         1 - r 

                  = __a_*_(r^n_-_1)__   ; r!=1 and r<1
                         r - 1 
 
    Reference: https://www.cuemath.com/algebra/arithmetic-and-geometric-progression/
               https://www.geeksforgeeks.org/difference-between-an-arithmetic-sequence-and-a-geometric-sequence/


------------------------------------------------------------------------------------------
Q9: Program [find sum of series 1 + 1/2 + 1/3 + 1/4 + .. + 1/n]

S9: If inverse of a sequence follows rule of an A.P i.e, Arithmetic progression, then it is said to be 
    in Harmonic Progression.
    In general, the terms in a harmonic progression can be denoted as: 1/a, 1/(a+d), 1/(a+2d), 1/(a+3d) … 1/(a+nd). 
    As Nth term of AP is given as (a + (n – 1)d). 
    Hence, Nth term of harmonic progression is reciprocal of Nth term of AP, which is : 1/(a + (n – 1)d) 
    where “a” is the 1st term of AP and “d” is the common difference.

    Reference: GeeksForGeeks - https://www.geeksforgeeks.org/c-program-find-sum-series-1-12-13-14-1n/


------------------------------------------------------------------------------------------
Q10: How many approx loops are allowed in 1 sec time limit?
     How many Number of Instructions/Opertions in 1 sec?
     How many instructions can be executed in Codeforces and TopCoder judge PCs in one second?

A10:- Every online judges have different time limits depending upon their server
    - Number of iterations that can occur in one second is different for different languages. 
       E.g. The number of iterations that can occur in one second in C++ is much more than that in Python.
    - Plus, the time required also depends upon what is happening in those iterations.

    - Number of iterations allowed for each range of n :
      1.n=10^5  - most used constraint in competitve programming, 
                  three types of complexity is allowed in these type of questions:
                  O(n) ,O(nlogn) and O(nrootn), you have to use fast io in O(nrootn) complexity.
      2.n=10^6  - only two types of complexity is allowed here,
                  O(n) and O(nlogn).
      3.n>=10^9 - you can use maximum of O(logn) complexity.
      4.n=10^3  - these kinds of questions requires O(n), O(n^2) or O(n^2logn) complexity.
      5.n=10^2  - you can use O(n), O(n^2), O(n^2logn), O(n^3) orO(n^3logn) complexity.
      6.n<=20   - These question requires exponential complexity. 
                  mostly bitmasking questions are given in these ranges of n.

      So basically use can use maximum of 10^8 iterations , but if you are using above 10^7 iterations make
      sure you io method is fast, sometimes simple io doesn’t fit in time limit.
      and obviously O(1) works for all kind of constraints.
      Hope it helps.

    - Hi, I answered once similar question on TopCoder forum 230 (small modification here).
      when N <= 10,   then both O(N!) and O(2N) are ok (for 2N probably N <= 20 is ok too)
      when N <= 100,  then O(N3) is ok (I guess that N4 is also ok, but never tried)
      when N <= 1000, then N2 is also ok
      when N <= 10^6, then O(N) is fine (I guess that 10.000.000 is fine too, but I never tried in contest)
      when N = 10^9,  then O(N) is NOT ok, you have to find something better…
  
      But it also depends what are you doing in the loop. For example you have to know how are data structures,
      you are using, implemented - when you are inserting into map in C++ such operation is O(log(n)) 
      (where n is map size), so for loop with 10^7 inserts to map, you will get time limit probably.
  
      Also be aware that on TopCoder you are NOT reading input, you simply get it as method parameter and 
      here it is consuming your time, especially when you use something else than C/C++(Java, Python that’s serious problem), 
      that’s why I assumed that you can do 10^8 operations per second, on CodeChef 
      I would expect that max is 10^7.

    References - https://www.quora.com/How-many-instructions-can-be-executed-in-Codeforces-and-TopCoder-judge-PCs-in-one-second
               - https://discuss.codechef.com/t/how-many-approx-loops-are-allowed-in-1-sec-lime-limit/375    


------------------------------------------------------------------------------------------
Q11: Gigabyte(GB) = 1024 MB  or Gibibyte(Gib) = 1000 MiB

A11: 1GB = 1024MB and 1000MB (It depends)
     There are 2 different standards based units
     - Decimal Based  : The decimal based is the Kilobyte and is in base 10, this means 1GB is 1000 MB
     - Binary Based   : The binary based is the Kilobyte and is in base 2, this means 1GB is 1024 MB

     The clarity arises when you are using it in places of Decimal or Binary:
     - In case of Decimal places:
        1 Kilobyte = 1000 Bytes or B    = 10^3 B 
        1 Megabyte = 1000 KB            = 10^6 B = 10^3 KB 
        1 Gigabyte = 1000 MB            = 10^9 B = 10^6 KB = 10^3 MB 

     - In case of Binary Places: 
        1 Kilobyte= 1024 Byte or B      = 2^10 B                           = (1024)^1 B  = 1024 Bytes
        1 Megabyte= 1024 KB             = 2^20 B = 2^10 KB                 = (1024)^2 B  = 1,048,576 Bytes
        1 Gigabyte= 1024 MB             = 2^30 B = 2^20 KB  = 2^10 MB      = (1024)^3 B  = 1,073,741,824 Bytes

     The term gigabyte is commonly used to mean either 1000^3 bytes or 1024^3 bytes depending on the context. 
     Disk manufacturers prefer the decimal term (i.e 1000)
     while 
     Memory manufacturers use the binary (i.e 1024)

     Decimal definition
     - 1 GB = 1,000,000,000 bytes (= 1000^3 B   = 10^9 B)
     - Based on powers of 10, this definition uses the prefix as defined in the International System of Units (SI). 
     - This is the recommended definition by the International Electrotechnical Commission (IEC). 
     - This definition is used in networking contexts and most storage media, particularly hard drives, 
       flash-based storage, and DVDs, and is also consistent with the other uses of the SI prefix in 
       computing, such as CPU clock speeds or measures of performance.

     Binary definition
     - 1 GiB = 1,073,741,824 bytes (= 1024^3 B   = 2^30 B).
     - The binary definition uses powers of the base 2, as is the architectural principle of binary computers. 
     - This usage is widely promulgated by some operating systems, such as Microsoft Windows in reference 
       to computer memory (e.g., RAM). This definition is synonymous with the unambiguous unit gibibyte.

     The difference between units based on decimal and binary prefixes increases as a semi-logarithmic 
     (linear-log) function
      - E.g, the decimal kilobyte value is nearly 98% of the kibibyte, 
             a megabyte is under 96% of a mebibyte, and 
             a gigabyte is just over 93% of a gibibyte value. 
             This means that a 300 GB (279 GiB) hard disk might be indicated variously as 
             300 GB, 279 GB or 279 GiB, depending on the operating system.
     
     The chart goes in the following way:
        1 bit     : The smallest unit of storage.    [A bit stores just a 0 or 1]
        1 byte    =    8 bits      [One byte = collection of 8 bits (Eg 01011010) = 8 bits can make 256 different patterns]
        128 bytes = 1024 bits  
        1 kb      = 1024 bytes 
        1 mb      = 1024 kb    
        1 gb      = 1024 mb    
        1 tb      = 1024 gb    


------------------------------------------------------------------------------------------
Q12: What is the difference between Mbps and MBps?

A12: Mbps : Megabits per second.     (used for file size)
     MB/s : Megabytes per second.    (used for download speeds)
     Generally, Internet service providers show in Mbps.

     In short, bits are for moving data over network and bytes are stored data in a storage.
     The capital B represents 1 Byte.
     The smaller b represents 1 Bit.

     1 MBps = 8 Mbps
     as 
     1 Byte = 8 Bits
     
     In short 1MBps will have a speed 8 times greater than 1 Mbps
     The difference between a Gigabyte (GB) and a Gigabit (Gb) is the same, 
     with a Gigabyte being 8 times larger than a Gigabit.


    - Storage Calculation in Linux and Windows is bit different and partition format is also different. 
      So it depends on partition format, windows always sticks with NTFS where as Linux with ext3/ext4. 
      In my experience Linux gives you more space in storage calculation.

      1TB - 1024 GB (Giga Byte)
      1GB = 1024 MB (Mega Byte)
      1MB = 1024 KB (Kilo Byte)
      1KB = 1024 bytes
      1 byte = 8 bits (1 byte contains 256 characters. Bcz with 8 bits, 2^8 = 256 patterns are formed)


    - These calculations are different with internet or moving data over a cable or network connection. 
      It is calculated in bits, if it is shown in bytes then:

       8 bits = 1 Kilo Bytes

       1 Mega Bits (mb) = 128  Kilo Bytes (KB)
       2 Mega Bits (mb) = 256  Kilo Bytes (KB)
      10 Mega Bits (mb) = 1.22 Mega Bytes (MB)
      50 Mega Bits (mb) = 6.1  Mega Bytes (MB)

    If your internet connection is 10mbps then you will get actual download speed of 1.2MBps and 
    if your connection is 1mbps then download speed will be 128KBps.

    Calculation is like this :
      10 mb = 10,000 bits
  
      10,000bits / 8 = 1250
      1250 / 1024 = 1.22 MB

    I hope you understand now. It is little confusing but once you know then it is all cleared.
    2mbps connection is 256KBps download speed
    1mbps connection is 128KBps download speed
    just whatever the connection is, divide it by 8 and you get the download speed which is usually 
    calculated in Bytes.
    small letter ‘k’ , ‘m’, ‘g’, etc are for bits and Capital letter ‘K’, ‘M’, ‘G’, etc are for bytes.
    In short bits are for moving data over network and bytes are stored data in a storage.


------------------------------------------------------------------------------------------
Q13: How many digit a data type can store ?
     What is the range of a long long int and an int in powers of 10?
     Which data type should i use to store upto 18 digits in a variable in c++?

A13: 18-digits gives a maximum possible value of 999,999,999,999,999,999 ≈ 9.9 × 10^17. 
     This will fit into an unsigned, 64-bit integer (maximum value 264, which is about 1.8446744 × 10^19).
     Try using the uint64_t type to ensure that you get this.

     There is a rule by which you can calculate how many digit a data type can store and
     the logic is  2^10 = 10^3 (nearly) 
     i.e as long long int is an 64 bit integer, it can support  18 digit number because 2^64 = 10^18(nearly) by the above rule. If you want to handle more digits, you can go for boost library.

     Reference - [Bits and Bytes] https://web.stanford.edu/class/cs101/bits-bytes.html
                 https://stackoverflow.com/questions/49653592/type-unsigned-long-long-int-is-it-enough-for-1-109-range


------------------------------------------------------------------------------------------
Q14: Does type unsigned long long int is it enough for 1 - 10^9 range?

A14: - 10^9 is way smaller than 2^32
     - So in your case, no need to use unsigned long long (it fits, yes), which is overkill and can lead
       to slower operation.
     - Use the proper type, normalized in stdint.h include: uint32_t or uint_least32_t (uint32_t vs uint_fast32_t 
       vs uint_least32_t)
     - long is also guaranteed to be at least 32 bits, so it's a good & simple choice as well.

     - Yes it is (assuming that you are adopting the notation 10^9 to mean 1e9).
     - An "unsigned long long" has to be capable of storing a number between [0 and (2^64)-1]. 
       Your maximum is much smaller than this.
     - Note also that an "unsigned long" has to be capable of storing a number between [0 and (2^32)-1].
       Your maximum is also smaller than this.

    - The answer is yes, but you don't need unsigned long long, unsigned long would be enough.
    - A 32-bit number can represent over 4 * 10^9. Up to 4,294,967,296 (= 2^32).

    Reference - https://stackoverflow.com/questions/49653592/type-unsigned-long-long-int-is-it-enough-for-1-109-range


------------------------------------------------------------------------------------------
Q15: What range of values can integer types store in C++ ??
     what are the ranges of [unsigned  & unsigned] short int, int, long int?

A15: 
     ____________________________________________________________________________________________________________
    |    Data Type        | Size  |       Range                       |       Range          |   No Of Digits    | 
    |_____________________|(bytes)|___________________________________|_____(In Binary)______|___(In Decimal)____|
    | short int           |   2   | -32,768 to 32,767                 | -(2^15) to (2^15)-1  |                   |
    | unsigned short int  |   2   |  0 to 65,535                      |   2^16               |                   |
    |                     |       |                                   |                      |                   |
    | int                 |   4   | -2,147,483,648 to 2,147,483,647   | -(2^31) to (2^31)-1  | -10^9  to 10^9    |
    | unsigned int        |   4   |  0 to 4,294,967,295               |   2^32               |  10^9             |
    |                     |       |                                   |                      |                   |
    | long int            |   4   | -2,147,483,648 to 2,147,483,647   | -(2^31) to (2^31)-1  | -2*10^9 to 2*10^9 |
    | unsigned long int   |   4   |  0 to 4,294,967,295               |   2^32               | 10^9              |
    |                     |       |                                   |                      |                   |
    | long long int       |   8   |-(2^63)to 9,223,372,036,854,775,807| -(2^63) to (2^63)-1  |-2*10^18 to 2*10^18|
    | unsign long long int|   8   |  0 to 18,446,744,073,709,551,615  |   2^64               | 10^18             |
    |                     |       |                                   |                      |                   |
    | signed char         |   1   | -128 to 127                       | -(2^7) to (2^7)-1    |                   |
    | unsigned char       |   1   |  0 to 255                         |   2^8                |                   |
    |                     |       |                                   |                      |                   |
    | bool                |   1   |  false & true                     |                      |                   |
    |                     |       |                                   |                      |                   |
    | float               |   4   |  3.4E ± 38                        |  7 significant digits|                   |
    | double              |   8   |  1.7E ± 308                       | 15 significant digits|                   |
    | long double         |  12   |                                   |                      |                   |
    |                     |       |                                   |                      |                   |
    | wchar_t             | 2or4  |  1 wide character                 |                      |                   |
    |                     |       |                                   |                      |                   |
    | void                |   0   |  valueless or Empty               |                      |                   |
    '------------------------------------------------------------------------------------------------------------'

    Referernce - https://stackoverflow.com/questions/1819189/what-range-of-values-can-integer-types-store-in-c


------------------------------------------------------------------------------------------
Q16: 

A16: 


 */