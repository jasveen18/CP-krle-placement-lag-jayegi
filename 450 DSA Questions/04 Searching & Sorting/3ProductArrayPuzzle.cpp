/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - return the Product vector P that hold product except self at each index
vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
    if (n == 1)
        return {1};

    // Count the number of zeros
    int present = 0;
    for (int i = 0; i < n; i++)
        if (nums[i] == 0)
            present++;


    long long int totalProduct = 1;
    for (int i = 0; i < n; i++)
        if (nums[i] != 0)
            totalProduct *= nums[i];

    vector<long long int> res(n, 0);
    for (int i = 0; i < n; i++) {
        // If ek hi zero hai
        if (nums[i] == 0 and present == 1)
            res[i] = totalProduct;
        else if (present) // If one / more than one zero present
            res[i] = 0;
        else  // If no zero present
            res[i] = totalProduct / nums[i];
    }

    return res;
}