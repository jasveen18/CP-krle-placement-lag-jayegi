const rearrangeArray = function (nums, n) {
    let start = 0,
        end = n - 1;

    while (start < end) {
        while (start < n && nums[start] > 0) start++;
        while (end >= 0 && nums[end] < 0) end--;

        if (start < end) {
            [nums[start], nums[end]] = [nums[end], nums[start]];
        }
    }

    // All positive or all negative case
    if (start == 0 || start == n) return;

    let trav = 0;
    while (trav < n && start < n) {
        [nums[start], nums[trav]] = [nums[trav], nums[start]];
        start++;
        trav += 2;
    }
};
