/**
 * @param {number[]} arr
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
const getPairsCount = function (arr, n, k) {
    let ans = 0;
    const seen = new Map();

    arr.forEach((element) => {
        const target = k - element;

        if (seen.has(target)) {
            ans += seen.get(target);
        }

        // Increment by one
        seen.set(
            element,
            seen.get(element) === undefined ? 1 : seen.get(element) + 1
        );
    });

    return ans;
};
