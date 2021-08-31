/**
 * @param {number[]} nums
 * @param {number} n length
 * @returns {number} max sum
 */

const kadaneAlgorithm = function (nums, n) {
    let maxSumTillNow = nums[0];
    let maxSumGlobal = nums[0];

    for (let i = 1; i < n; i++) {
        maxSumTillNow = Math.max(maxSumTillNow + nums[i], nums[i]);
        maxSumGlobal = Math.max(maxSumGlobal, maxSumTillNow);
    }

    return maxSumGlobal;
};
