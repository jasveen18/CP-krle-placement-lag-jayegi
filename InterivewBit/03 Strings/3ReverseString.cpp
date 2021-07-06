/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Reverse the words
string Solution::solve(string A) {
    string word = "";
    vector<string> res;
    int n = A.size();

    for (int i = 0; i < n; i++) {
        while (i < n - 1 and A[i] == ' ' and A[i + 1] == ' ')
            i++;

        if (A[i] == ' ') {
            res.push_back(word);
            word = "";
        } else {
            word += A[i];
        }
    }
    res.push_back(word);

    reverse(res.begin(), res.end());
    string ans = "";
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++)
            ans += res[i][j];
        ans += " ";
    }

    int start = 0, end = ans.size() - 1;
    while (start < ans.size() and ans[start] == ' ')
        start++;
    while (end >= 0 and ans[end] == ' ')
        end--;

    string fin = "";
    for (int i = start; i <= end; i++)
        fin += ans[i];
    return fin;
}
