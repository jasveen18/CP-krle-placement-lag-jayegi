/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number [][]} Union and intersection of nums1 and num2
 */
const unionIntersection = function (nums1, nums2) {
    let one = 0,
        two = 0;
    let n1 = nums1.length,
        n2 = nums2.length;
    const union = [];
    const intersection = [];

    while (one < n1 && two < n2) {
        if (nums1[one] === nums2[two]) {
            union.push(nums1[one]);
            intersection.push(nums1[one]); // Only insert when present in both arrays
            one++;
            two++;
        } else if (nums1[one] < nums2[two]) {
            union.push(nums1[one]);
            one++;
        } else if (nums[one] > nums2[two]) {
            union.push(nums2[two]);
            two++;
        }
    }

    // Pick the leftover elements for union
    while (one < n1) {
        union.push(nums1[one++]);
    }
    while (two < n2) {
        union.push(nums2[two++]);
    }

    return [union, intersection];
};

arr1 = [1, 2, 3, 4, 5, 6, 7];
arr2 = [4, 5, 8, 10, 11];

console.log(unionIntersection(arr1, arr2));
/*
[ 
    [1, 2, 3,  4,  5, 6, 7, 8, 10, 11], 
    [ 4, 5 ] 
]
*/
