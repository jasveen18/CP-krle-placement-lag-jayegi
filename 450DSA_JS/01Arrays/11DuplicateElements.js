/**
 * @param {number[]} nums
 * @return {number}
 */
const findDuplicate = function (nums) {
    let ans = -1;
    let n = nums.length;

    // Mark the count of 1, 2, 3 in nums
    for (let i = 0; i < n; i++) nums[nums[i] % n] += n;

    for (let i = 0; i < n; i++) {
        if (nums[i] / n >= 2) ans = i;
        // count = 2
        else nums[i] = nums[i] % n; // reverse the count
    }

    return ans;
};
