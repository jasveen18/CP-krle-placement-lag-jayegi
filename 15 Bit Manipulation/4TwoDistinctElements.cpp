vector<int> singleNumber(vector<int>& nums)
{
    int res1 = 0, res2 = 0, xo = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        xo ^= nums[i];
    }

    // This is the first distinct bit that the 2 unique numbers have.
    int firstDifferentBit = (xo & (~(xo - 1)));

    for (int i = 0; i < n; i++) {
        // Now we will group them into one with zero, and one with one.
        // Jo repeating wale honge, they are getting canceled.
        if (nums[i] & firstDifferentBit)
            res1 ^= nums[i];
        else
            res2 ^= nums[i];
    }

    return {res1, res2};
}