const intersectionArray = function (nums1, nums2) {
    let one = 0,
        two = 0;
    let n1 = nums1.length,
        n2 = nums2.length;
    const intersection = [];

    while (one < n1 && two < n2) {
        if (nums1[one] === nums2[two]) {
            intersection.push(nums1[one]); // Only insert when present in both arrays
            one++;
            two++;
        } else if (nums1[one] < nums2[two]) one++;
        else if (nums[one] > nums2[two]) two++;
    }

    return intersection;
};

const commonInThree = function (nums1, nums2, nums3) {
    let res = intersectionArray(nums1, nums2);
    res = intersectionArray(res, nums3);

    return res;
};

nums1 = [1, 2, 3, 4, 5];
nums2 = [3, 4, 5, 6, 6];
nums3 = [4, 5, 6, 7, 8];

console.log(commonInThree(nums1, nums2, nums3)); // [4, 5]
