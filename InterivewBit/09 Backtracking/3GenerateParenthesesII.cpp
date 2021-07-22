/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Generate all valid parentheses, given number of pairs of brackets.
void generateItNow(int n, int open, int close, string curr, vector<string> &res) {
    // Base Case ->
    if (curr.size() == 2 * n) {
        res.push_back(curr);
        return;
    }

    // Recursive Case ->
    // If we can accomodate one more opening bracket
    if (open < n)
        generateItNow(n, open + 1, close, curr + '(', res);

    // If we can input a closing bracket without violating rules.
    if (open > close)
        generateItNow(n, open, close + 1, curr + ')', res);

    return;
}

vector<string> Solution::generateParenthesis(int A) {
    vector<string> res;
    int open = 0, close = 0;
    string curr = "";

    generateItNow(A, open, close, curr, res);

    sort(res.begin(), res.end());
    return res;
}
