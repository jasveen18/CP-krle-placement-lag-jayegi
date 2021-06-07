// T - O(N)
// S - O(1)
int minFlips (string S) {
    int evenOne = 0, oddOne = 0;
    int n = S.size();

    for (int i = 0; i < n; i++) {
        // One at odd places
        if (i & 1 and S[i] != '1')
            oddOne++;
        else if (!(i & 1) and S[i] != '0')
            oddOne++;

        // One at even places
        if (i & 1 and S[i] != '0')
            evenOne++;
        else if (!(i & 1) and S[i] != '1')
            evenOne++;
    }

    return min(evenOne, oddOne);
}