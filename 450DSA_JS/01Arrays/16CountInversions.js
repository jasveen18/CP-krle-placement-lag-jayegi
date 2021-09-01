/**
 * @param {number[]} prices
 * @return {number}
 */

const mergeCountInv = function (nums, left, mid, right) {
    let leftArr = [];
    let rightArr = [];

    for (let i = left; i < mid + 1; i++) leftArr.push(nums[i]);
    for (let i = mid + 1; i < right + 1; i++) rightArr.push(nums[i]);

    let i = 0,
        j = 0,
        k = left,
        count = 0;
    while (i < leftArr.length && j < rightArr.length) {
        if (leftArr[i] <= rightArr[j]) nums[k++] = leftArr[i++];
        else {
            nums[k++] = rightArr[j++];
            count += mid + 1 - (left + i);
        }
    }

    while (i < leftArr.length) nums[k++] = leftArr[i++];
    while (j < rightArr.length) nums[k++] = rightArr[j++];

    return count;
};

const mergeSortCountInv = function (nums, left, right) {
    let count = 0;
    if (left >= right) return count;

    let mid = Math.floor((left + right) / 2);

    count += mergeSortCountInv(nums, left, mid);
    count += mergeSortCountInv(nums, mid + 1, right);
    count += mergeCountInv(nums, left, mid, right);

    return count;
};
