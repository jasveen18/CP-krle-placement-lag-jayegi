/**
 * @param {number[]} prices
 * @return {number}
 */
let maxProfit = function (prices) {
    let maxP = 0;
    let minEl = prices[0];

    prices.forEach((price) => {
        minEl = Math.min(minEl, price);
        maxP = Math.max(maxP, price - minEl);
    });

    return maxP;
};
