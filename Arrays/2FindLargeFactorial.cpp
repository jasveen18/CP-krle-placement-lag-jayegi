// Approach - Have an array to store the answer
// Time Complexity - O(N)
// Space Complexity - O(1)

// Multiply function
void multiply(vector<int> &nums, int num) {
    int carry = 0;

    // Multiply each digit with num
    for (int i = 0; i < nums.size(); i++) {
        int multValue = nums[i] * num;
        nums[i] = (multValue + carry) % 10;
        carry = (multValue + carry) / 10;
    }

    // Push the left over carry into array
    while (carry) {
        nums.push_back(carry % 10);
        carry /= 10;
    }
}

vector<int> factorial(int N) {
    vector<int> res;
    res.push_back(1);

    // Factorial logic - 1*2*3...N
    for (int i = 1; i <= N; i++) {
        multiply(res, i);
    }

    // The arrange of answer stored is in reverse order, therfore reverse
    reverse(res.begin(), res.end());
    return res;
}