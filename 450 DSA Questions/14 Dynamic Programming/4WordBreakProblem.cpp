// T - O(N*N)
// S - O(N*N)
// A : given string to search
// B : vector of available strings
int dp[100][100];
int partitionWords(string &s, unordered_map<string, int> &present, int i, int j) {
    // Base Case
    if (i >= j)
        return dp[i][j] = 1;

    // Lookup
    if (dp[i][j] != 0)
        return dp[i][j];

    int canDoPartition = 0;
    for (int k = i; k <= j; k++) {
        if (present.find(s.substr(i, k - i + 1)) != present.end()) {
            // cout<<"here: "<<s.substr(i, k-i+1)<<endl;
            int subProb = partitionWords(s, present, k + 1, j);
            canDoPartition |= subProb;
        }
    }

    return dp[i][j] = canDoPartition;
}


int wordBreak(string A, vector<string> &B) {
    unordered_map<string, int> present;
    for (int i = 0; i < B.size(); i++) {
        present[B[i]] = 1;
    }

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++)
            dp[i][j] = 0;
    }

    return partitionWords(A, present, 0, A.size() - 1);
}