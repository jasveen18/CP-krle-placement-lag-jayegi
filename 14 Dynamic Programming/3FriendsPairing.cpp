// T - O(N)
// S - O(1)
int countFriendsPairings(int n) {
    int prev = 2, doublePrev = 1;
    int mod = 1000000007;
    int res = prev;

    if (n <= 2)
        return n;

    for (int i = 3; i <= n; i++) {
        res = prev + (i - 1) * doublePrev;
        doublePrev = prev;
        prev = res;
    }

    return res;
}