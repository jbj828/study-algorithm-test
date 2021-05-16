/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function (prices) {
  let profit = 0;

  for (let i = 1; i < prices.length; i++) {
    let prev = prices[i - 1];
    if (prev < prices[i]) {
      profit += prices[i] - prev;
    }
  }

  return profit;
};
