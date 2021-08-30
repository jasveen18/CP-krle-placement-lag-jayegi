/**
 * @param {number[]} nums
 * @param {number} K
 * @param {number} N
 * @returns {number}
 */
const getMinDiff = function (nums, N, K) {
    nums.sort((a, b) => a - b);

    let minel = nums[0];
    let maxel = nums[N - 1];
    let minHeight = maxel - minel;

    for (let i = 1; i < N; i++) {
        if (nums[i] >= K) {
            minel = Math.min(nums[0] + K, nums[i] - K);
            maxel = Math.max(nums[i - 1] + K, nums[N - 1] - K);

            minHeight = Math.min(minHeight, maxel - minel);
        }
    }

    return minHeight;
};
