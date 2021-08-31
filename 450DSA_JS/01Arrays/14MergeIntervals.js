/**
 * @param {number[][]} intervals
 * @return {number[][]}
 */
let merge = function (intervals) {
    intervals.sort((a, b) => {
        if (a[0] === b[0]) return a[1] - b[1];
        return a[0] - b[0];
    });

    const n = intervals.length;

    let res = [];
    let end = intervals[0][1];
    let start = intervals[0][0];

    for (let i = 1; i < n; i++) {
        // If not overlapping
        if (end < intervals[i][0]) {
            res.push([start, end]);
            start = intervals[i][0];
        }

        end = Math.max(end, intervals[i][1]);
    }

    // Process last input
    if (end >= intervals[n - 1][0]) res.push([start, end]);
    else res.push([intervals[n - 1]]);

    return res;
};
