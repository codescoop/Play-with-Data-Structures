// https://takeuforward.org/strivers-a2z-dsa-course/strivers-a2z-dsa-course-sheet-2  >> Step 3: Array

// Subarray Sum Equals K - https://leetcode.com/problems/subarray-sum-equals-k/description/
// Two Sum - https://leetcode.com/problems/two-sum/description/
// Move Zeroes -  https://leetcode.com/problems/move-zeroes/
// Sort Colors - https://leetcode.com/problems/sort-colors/description/



// Type: Subarray [continious part of subarray]
// - Find all subarray
let arr = [1,13,4,8,1]
for(let i= 0; i<arr.length; i++){
    let subarr = []
    for(let j=i; j<arr.length; j++){
        subarr.push(arr[j])
        console.log(subarr)
        // console.log(`[${arr[i]},${arr[j]}]`)
    }
}

// - Find all subarray whose sum is equal to k  - https://leetcode.com/problems/subarray-sum-equals-k/
const k = 13
arr = [1,13,4,8,1]
let count = 0
for(let i= 0; i<arr.length; i++){
    let subarr = []
    let sum = 0
    for(let j=i; j<arr.length; j++){
        subarr.push(arr[j])
        sum = sum + arr[j]
        if(sum === k){
            count++
            console.log(subarr)
        }
        // console.log(`[${arr[i]},${arr[j]}]`)
    }
}
console.log("count: ", count)

// Find all subarray whose sum is equal to k [Using Hashmap] - https://leetcode.com/problems/subarray-sum-equals-k/
var subarraySum = function(nums, k) {
    const presumMap = new Map()
        presumMap.set(0,1)
        let sum = 0
        let count = 0

        for (let i=0; i<nums.length; i++){
            sum += nums[i]
            const remaining = sum - k
            if(presumMap.has(remaining)){
                count += presumMap.get(remaining)
            }
            presumMap.set(sum, (presumMap.get(sum) || 0) + 1)
        }
        return count
};

// Two Sum - https://leetcode.com/problems/two-sum/description/

// Move Zeroes -  https://leetcode.com/problems/move-zeroes/
var moveZeroes = function(nums) {
    // i for zeros
    // j for non-zeros
    let i = 0 
    for(i = 0; i < nums.length; i++)
    {
        if(nums[i] === 0){
            break
        }
    }
     for(let j = i+1; j < nums.length; j++)
    {
        if(nums[j] !== 0){
            [nums[i],nums[j]] = [nums[j],nums[i]]
            i++
        }
    }
};

// Sort Colors - https://leetcode.com/problems/sort-colors/description/