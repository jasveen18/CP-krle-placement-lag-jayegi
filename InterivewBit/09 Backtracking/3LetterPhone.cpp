/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find letter combinations of letter phone
void findLetterCombinations(string s, int i, vector<string> &res, vector<string> &keypad, string &curr) {
    // Base Case -
    if (i == s.size()) {
        res.push_back(curr);
        return;
    }

    // Recusive Case -
    int dig = s[i] - '0';
    for (int k = 0; k < keypad[dig].size(); k++) {
        curr += keypad[dig][k];
        findLetterCombinations(s, i + 1, res, keypad, curr);

        // Backtrack step
        curr.pop_back();
    }

    return;
}

vector<string> Solution::letterCombinations(string A) {
    vector<string> keypad {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;
    string curr = "";

    findLetterCombinations(A, 0, res, keypad, curr);
    return res;
}
