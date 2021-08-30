/**
 * @param {number[]} nums
 * @return {number}
 */
let jump = function (nums) {
    let n = nums.length;

    let minJumps = 1;
    let maxPossible = nums[0];
    let energy = nums[0];

    // If we are already at the last index
    if (n <= 1) return 0;

    for (let now = 1; now < n; now++) {
        // Store the max possible index we can reach
        maxPossible = Math.max(maxPossible, nums[now] + now);

        // If we are able to reach the end now
        if (energy >= n - 1) return minJumps;

        // If jump is required now
        if (energy === now) {
            energy = maxPossible;
            minJumps++;
        }
    }

    return -1;
};
