/**
 * @param {Number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
let reverseArray = function (nums) {
    const n = nums.length;
    for (let i = 0; i < Math.floor(n / 2); i++) {
        [nums[i], nums[n - i - 1]] = [nums[n - i - 1], nums[i]];
    }
};

arr = [1, 2, 3, 4];
reverseArray(arr);
console.log(arr); // [4, 3, 2, 1]
