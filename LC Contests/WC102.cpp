// 1. 905. Sort Array By Parity
class Solution {
public:
    static bool evenSort(int &a, int &b) {
        if (a & 1)
            return false;

        return true;
    }
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = -1;
        int j = -1;
        int n = nums.size();

        for (int x = 0; x < n; x++) {
            if (nums[x] & 1) {
                i = x;
                break;
            }
        }

        for (int x = i + 1; x < n; x++) {
            if (nums[x] % 2 == 0) {
                j = x;
                break;
            }
        }

        // No odd or no even element found
        if (i == -1 or j == -1)
            return nums;


        while (i < n and j < n) {
            swap(nums[i], nums[j]);

            while (j < n and (nums[j] & 1))
                j++;
            while (i < n and !(nums[i] & 1))
                i++;
        }

        return nums;
    }
};


// 2. 904. Fruit Into Baskets
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // The questions boils down to max sliding window with two or less distinct number
        int i = 0, j = 0;
        int n = fruits.size();
        int res = 0;
        unordered_map<int, int> basket;

        while (j < n) {
            basket[fruits[j]]++;

            if (basket.size() < 2) {
                res = max(res, j - i + 1);
                j++;
            }
            else if (basket.size() == 2) {
                res = max(res, j - i + 1);
                j++;
            } else if (basket.size() > 2) {

                while (i < n and basket.size() > 2) {
                    basket[fruits[i]]--;

                    if (basket[fruits[i]] == 0)
                        basket.erase(fruits[i]);

                    i++;
                }

                j++;
            }
        }

        return res;
    }
};


// 3. 907. Sum of Subarray Minimums
