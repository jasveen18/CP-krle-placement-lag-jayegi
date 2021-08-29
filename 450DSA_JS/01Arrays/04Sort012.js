/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
let sortColors = function (nums) {
    const n = nums.length;
    let start = 0,
        running = 0,
        end = n - 1;

    while (running <= end) {
        if (nums[running] === 0) {
            // If zero, then put at the start
            [nums[running], nums[start]] = [nums[start], nums[running]];
            start++;
            running++;
        } else if (nums[running] === 1) {
            // If one, then no operation is required
            running++;
        } else if (nums[running] === 2) {
            // If two, then put at the end
            [nums[running], nums[end]] = [nums[end], nums[running]];
            end--;
        }
    }

    return;
};
