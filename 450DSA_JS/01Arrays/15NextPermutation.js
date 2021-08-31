/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
let nextPermutation = function (nums) {
    const n = nums.length;
    const swap = (a, b) => ([nums[a], nums[b]] = [nums[b], nums[a]]);

    let i = n - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }

    // If given array is the last permutation
    if (i < 0) return nums.reverse();

    let j = n - 1;
    while (j >= 0 && nums[j] <= nums[i]) {
        j--;
    }

    swap(i, j);

    for (let k = i + 1; k < (i + n) / 2; k++) {
        swap(k, n - k + i);
    }
};
