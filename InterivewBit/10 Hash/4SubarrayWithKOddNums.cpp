/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Count number of subarrays with exactly K odd numbers.
int Solution::solve(vector<int> &A, int B)
{
    int count = 0;
    int sum = 0;
    int n = A.size();
    unordered_map<int, int>mp;

    for (int i = 0; i < n; i++) {
        sum += (A[i] % 2);
        if (sum == B) {
            count++;
        }

        if (mp.find(sum - B) != mp.end()) {
            count += mp[sum - B];
        }
        mp[sum]++;
    }
    return count;
}