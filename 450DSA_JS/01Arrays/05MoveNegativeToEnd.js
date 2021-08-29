/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
let moveNegative = function (nums) {
    const n = nums.length;
    let running = 0,
        start = 0;

    while (running < n) {
        if (nums[running] > 0) {
            [nums[running], nums[start]] = [nums[start], nums[running]];
            start++;
        }

        running++;
    }
};

arr = [-1, 2, 5, 7, -9, -10, 11];
moveNegative(arr);
console.log(arr); // [ 2, 5, 7, 11, -9, -10, -1 ]
