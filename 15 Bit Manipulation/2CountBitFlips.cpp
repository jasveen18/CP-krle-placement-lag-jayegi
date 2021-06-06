// Function to find number of bits needed to be flipped to convert A to B
int countBitsFlip(int a, int b) {
    int ans = 0;
    while (a > 0 or b > 0) {
        if ((a & 1) != (b & 1))
            ans++;

        a = a / 2;
        b = b / 2;
    }

    return ans;
}