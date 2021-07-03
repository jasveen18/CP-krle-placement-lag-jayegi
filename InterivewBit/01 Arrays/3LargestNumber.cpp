/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Given a list of non negative integers, arrange them such that they form the largest number.
string Solution::largestNumber(const vector<int> &A) {
    // Sort them using a comparator function
    int n = A.size();
    vector<string> nums(n);

    // Store the numbers as string to compare them
    for (int i = 0; i < n; i++) {
        nums[i] = to_string(A[i]);
    }

    // Sort on the basis of who will contribute more.
    sort(nums.begin(), nums.end(), [] (string & a, string & b) {
        string af = (a) + (b);  // 81 22
        string bf = (b) + (a); // 22 81

        return af > bf; // Answer goes to 8122
    });

    string res = "";
    for (int i = 0; i < n; i++) {
        res += nums[i];
    }

    // Remove zeroes from beginning
    int i = 0;
    while (i < res.size() and res[i] == '0')
        i++;

    if (i == res.size())
        return "0";
    else
        return res.substr(i);
}