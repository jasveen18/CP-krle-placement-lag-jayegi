/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
let spiralOrder = function (matrix) {
    const res = [];
    const n = matrix.length; // row
    const m = matrix[0].length; // col

    console.log(n, m);

    let rs = 0,
        re = n - 1;
    let cs = 0,
        ce = m - 1;

    while (rs <= re && cs <= ce) {
        // First row
        for (let col = cs; col <= ce; col++) res.push(matrix[rs][col]);
        rs++;

        // Last col
        for (let row = rs; row <= re; row++) res.push(matrix[row][ce]);
        ce--;

        // Last row
        if (rs <= re) {
            for (let col = ce; col >= cs; col--) res.push(matrix[re][col]);
            re--;
        }

        // First col
        if (cs <= ce) {
            for (let row = re; row >= rs; row--) res.push(matrix[row][cs]);
            cs++;
        }
    }

    return res;
};
