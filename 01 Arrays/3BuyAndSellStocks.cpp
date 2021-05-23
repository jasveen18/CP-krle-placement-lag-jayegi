// Approach - Kind like Kadane's algo
// Time Complexity - O(N)
// Space Complexity - O(1)
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int minElement = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < n; i++) {
        minElement = min(minElement, prices[i]);
        maxProfit = max(maxProfit, prices[i] - minElement);
    }

    return maxProfit;
}