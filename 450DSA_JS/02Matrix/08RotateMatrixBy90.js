/**
 * @param {number[][]} matrix
 * @return None, modify in place
 */

const rotateBy90 = function (matrix) {
    const n = matrix.length;
    const m = matrix[0].length;

    // Transpose the matrix
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            if (i < j) {
                [matrix[i][j], matrix[j][i]] = [matrix[j][i], matrix[i][j]];
            }
        }
    }

    // Reverse each rows
    for (let i = 0; i < n; i++) {
        matrix[i].reverse();
    }

    return;
};

matrix = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9],
];
rotateBy90(matrix);
console.log(matrix);

/* 
[
    [7, 4, 1],
    [8, 5, 2],
    [9, 6, 3],
];
*/
