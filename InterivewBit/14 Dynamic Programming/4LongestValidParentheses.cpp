/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Longest valid parenthesis
int Solution::longestValidParentheses(string s) {
    int open = 0;
    int close = 0;

    int res = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            open++;
        }
        else {
            close++;
        }

        if (close == open) {
            res = max(res, close * 2);
        } else if (close >= open) {
            open = 0; close = 0;
        }
    }

    open = close = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '(') {
            open++;
        }
        else {
            close++;
        }

        if (close == open) {
            res = max(res, open * 2);
        } else if (open >= close) {
            open = 0; close = 0;
        }
    }

    return res;
}
