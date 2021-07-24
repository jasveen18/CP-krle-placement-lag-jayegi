/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - The task is to find minimum number of parentheses ‘(‘ or ‘)’ (at any positions) we must add to make the resulting parentheses string valid.
int Solution::solve(string A) {
    int open = 0;
    int res = 0;

    for (int i = 0; i < A.size(); i++) {
        if (A[i] == '(')
            open++;
        else {
            open--;

            // if invalid case pahuch gye
            if (open < 0) {
                res++;
                open = 0;
            }
        }
    }

    return res + open;
}
