/**
 * @param {number[]} nums
 * @param {number} n length
 * @returns {number[]} cyclically rotate by one
 */
const rotateByOne = function (nums, n) {
    return [nums[n - 1], ...nums.slice(0, n - 1)];
};

console.log(rotateByOne([1, 2, 3, 4, 5], 5));
// [5, 1, 2, 3, 4]
