// https://takeuforward.org/strivers-a2z-dsa-course/strivers-a2z-dsa-course-sheet-2  >> Step 3: Array

// #1 Largest element
// Brute: Sort >> arr[n-1] | O(NlogN)
// Optimal | O(N)
let largest = (arr) => {
    let largest = arr[0]
    arr.forEach(ele => {
        if(largest < ele) largest = ele
    })
    return largest
}

// #2 Second Largest without sorting
// Brute: Sort >> loop from arr[n-2] till arr[i] != largest | O(NlogN + N) 
// Better: Loop for largest >> Loop for Secondlargest till arr[i] > secondLargest && arr[i] != largest | O(2N)
// Optimal | O(N)
function getSecondLargest(arr) {
    let largest = arr[0]
    let slargest = -1
    for(let i=1; i<=arr.length-1; i++){
        if(arr[i] > largest){
            slargest = largest
            largest = arr[i]
        } else if (arr[i] < largest && arr[i] > slargest){
            slargest = arr[i]  
        }
    }
    return slargest
}

// #3 Check if the array is sorted | O(N)
function isSorted(n, a) {
    let isSorted = 1
    for (let i = 0; i < n - 1; i++){
        if (a[i] > a[i + 1]) {
            isSorted = 0 
        }
    }
    return isSorted
}

// #4 Remove duplicates from Sorted array
var removeDuplicates = function(arr) {
    let i = 0
	for (let j=1; j<=arr.length; j++){
		if(arr[i] != arr[j]) {
            arr[i+1] = arr[j]
            i++
        }
	}
    return i+1
};

// #5 Left Rotate an array by one place | O(N)
function rotate(nums) {
    let temp = nums[0]
    for(let i=1; i<=nums.length-1; i++){
        nums[i-1] = nums[i]
    }
    nums[nums.length-1] = temp
};


// #6 Left rotate an array by D places | TC = O(N+rotation) i.e o(N) | SC = O(rotation) 
// Brute
var rotate = function(nums, k) {
    const len = nums.length
    // decide rotation
    const rotation = k % len
    // save in temp till k
    const temp = []
    for(let i=0; i<rotation; i++){
        temp[i] = nums[i]
    }
    // shifting
    for(i=rotation; i<len; i++){
        nums[i-rotation] = nums[i]
    }
    // put back temp
    for(i=len-rotation; i<len; i++){
        nums[i] = temp[i-(len-rotation)]
    }
};
// Optimal  | TC = 0(2N) | SC = O(1) |  (save space complexity) (REVERSE(till roation) + REVERSE(rotation + arrLen) -> REVERSE(the new create reverse array))
function reverse(arr, startIndex ,endIndex){
    while(startIndex<=endIndex){
        let temp = arr[startIndex]
        arr[startIndex] = arr[endIndex]
        arr[endIndex] = temp
        startIndex++
        endIndex--
    }
}
var rotateLeft = function(nums, k) {
    const len = nums.length
    // decide rotation
    const rotation = k % len
    // reverse 0 till rotation-1
    // reverse rotation-1 till array length
    // reverse the modified array
    reverse(nums,0,rotation-1)
    reverse(nums,rotation,len-1)
    reverse(nums,0,len-1)
};
// Think about right shift by n position


// #7 Move Zeros to end  
// Brute | TC: O(2N) | SC: O(N) 
// >> store non zero in temp arr by iterating complete array (startIndex: 0 & endIndex: arrSize)
// >> Put non zero val at start of arr (startIndex: 0 & endIndex: tempSize)
// >> Put zero at the end (startIndex: tempSize & endIndex: arrSize)
let moveZeroes = function(nums) {
    const len = nums.length
    let temp = []
    for(let i=0; i<len; i++){
        if(nums[i] != 0){
            temp.push(nums[i])
        }
    }
    const nonZero = temp.length 
    for(i=0; i<nonZero; i++){
        nums[i] = temp[i]
    }
    for(i=nonZero; i<len; i++){
        nums[i] = 0
    }
};
// Optimal: 2 pointer approach | TC: O(N) | SC: O(1)
// >> Get first zero index by looping array & break when you find it.
// >> If you didn't find zero return (i.e when j = -1 after traversing array)
// >> Start looping using 2 pointer form first zero & swap when zero occur
let moveZero = function(nums) {
    const len = nums.length
    let j = -1   // for zero index
    // find the first zero index
    for(let i=0; i<len; i++){
        if(nums[i] === 0){
            j = i
            break
        }
    }
    // if no zero index then return
    if(j === -1) return
    // swap non zero with zero, starting from first zero index
    for(i=j+1; i<len; i++){
        if(nums[i]!==0){
            let temp = nums[i]
            nums[i] = nums[j]
            nums[j] = temp
            j++
        }
    }
};

// #8 Linear Search
function linearSearch(arr, k) {
    for(let i=0; i<arr.length; i++){
        if(arr[i] === k) return true
    }
    return false
}

// #9 Union of 2 Sorted array (i.e add 2 array without duplicate values)
// Brute | TC: O(NlogN) (i.e logn is time complexity of set) | SC: O(N1+N2) 
// >> Put them in SET
var union = function() {
    const arr1 = [1,3,3,4,5]
    const arr2 = [1,1,4,6,7]
    const mySet = new Set();
    let union = []
    
    for(let i=0; i < arr1.length; i++){
        mySet.add(arr1[i])
    }
    for(let i=0; i < arr2.length; i++){
        mySet.add(arr2[i])
    }
    union = Array.from(mySet);
    // for(i=0; i<=mySet.length; i++){
    //     union.push(mySet[i] || 0)
    // }
    console.log("arr1", arr1)
    console.log("arr2", arr2)
    console.log("mySet", mySet)
    console.log("union", union)
};


// Optimal | TC: O(N) | SC: O(1)
// >> 2 pointer appoach as the array are sorted



// #9B Intersection of two sorted in an array (i.e element that are present in both array)
// Brute | TC O(N square) | SC O(N)
// for every element of arr1 >> traverse the arr2 >> by making a check on visible array
// So there will be 2 loop one inside another
// Condition of second loop >> if(arr[i] === arr[j] && vis[j] === 0) >> save element in intersection array
// as the array are sorted >> so if at any monent arr[j] > arr[i] break

// Optimal | TC O(n+n) | SC O(1)
// 2 pointer approach because the array is sorted
// if both pointer array values are same then just move increment both i.e i++ & j++ & save the value in intersection array
// if both pointer array values are different then just increment i >> i.e i++ >> if a[i] < b[j] 
// else increment j >> i.e j++ >> if a[i] > b[j]



// #10 Find missing number in an array
// Brute | TC O(n square) | SC O(1)
// 2 loop >> one inside another >> compare value of i with every value of j 
// maintain a flag = -1 in the outer loop
// if value is found >> inner loop break & flag =1 break
// in case when value will not found then flag value will be -1 >> So, that i value is missing number

// Better | TC O(2N) | SC O(N)
// using Hashing 
// Use a Hash hasving all zeros & traverse a array
// for every value i.e arr[i] >> update the hash index of that value to 1
// After marking all value at hash >> just traverse the hash
// the hash INDEX which has 0 is the missing value

// Optimal: It has 2 optimal solution >> 1. using sum >> 2. using XOR
// Using Sum Approach | TC O(N) | SC O(1)
// >> Iterate the array & get sum of all value 
// >> Also, calculate the sum using formula (n + (n+1)) / 2
// >> the differnce btw above 2 sum is the missing value

//Using XOR (a^a = 0 i.e xor of 2 same number is zero) | TC O(N) | SC O(1)
// NOTE: XOR approch is better because for the case of Sum apporch for 10^2 >> we will be needing the long int 
// >> But for XOR approach never exceed max number


// #11 Maximum Consecutive Ones
// Optimal | TC O(N) | SC O(1)
// Maintain a count & maxCount while iterating a loop 


// #12 Find the number that appears once, and other numbers twice
// Brute | TC O() | SC O()
// Optimal | TC O() | SC O()


// #13 Longest subarray with given sum K(positives)
// Brute | TC O() | SC O()
// Optimal | TC O() | SC O()


// #14 	Longest subarray with sum K (Positives + Negatives)
// Brute | TC O() | SC O()
// Optimal | TC O() | SC O()