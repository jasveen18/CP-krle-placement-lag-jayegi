// O(N * log N)
int setBits(int N) {
    if (N == 0)
        return 0;

    return (N & 1) + setBits(N / 2);
}


int setBits(int n) {
    int ans = 0;
    while (N > 0) {
        ans += (N & 1);
        N = N / 2;
    }

    return ans;
}