/**
 * @param {Number[]} nums
 * @param {Number} k
 * @return {Number []} Kth Minimum and Maximum element in the array.
 */

const kthMinMaxElement = function (nums, k) {
    nums.sort((a, b) => a - b);
    return [nums[k - 1], ...nums.slice(-k, -k + 1)];
};

console.log(kthMinMaxElement([3, 4, 6, 2, 1], 2)); // [2, 4]
