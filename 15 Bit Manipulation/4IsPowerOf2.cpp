// Function to check if given number n is a power of two.
bool isPowerofTwo(long long n) {
    // Base Case
    if (n == 0)
        return false;

    // If the number is power of 2,
    // (n-1) will flip all the bits results in zero when & is used.
    return (n & (n - 1)) == 0;
}