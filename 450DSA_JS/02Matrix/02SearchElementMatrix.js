/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
const searchMatrix = function (matrix, target) {
    const n = matrix.length;
    const m = matrix[0].length;

    let i = 0,
        j = m - 1;

    while (i < n && j >= 0) {
        if (matrix[i][j] === target) return true;

        if (matrix[i][j] > target) j--;
        else if (matrix[i][j] < target) i++;
    }

    return false;
};
