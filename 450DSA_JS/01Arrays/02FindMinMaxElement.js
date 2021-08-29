/**
 * @param {Number[]} nums
 * @return {Number []} Minimum and Maximum element in the array.
 */

const minMaxElement = function (nums) {
    return [Math.min(...nums), Math.max(...nums)];
};

console.log(minMaxElement([3, 4, 6, 2, 1])); // [1, 6]
