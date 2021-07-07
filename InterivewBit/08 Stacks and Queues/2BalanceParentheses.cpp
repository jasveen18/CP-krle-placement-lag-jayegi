/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Balance Parentheses
int Solution::solve(string A) {
    stack<char> st;
    int n = A.size();
    st.push(A[0]);

    for (int i = 1; i < n; i++) {
        if (!st.empty() and st.top() == '(' and A[i] == ')')
            st.pop();
        else
            st.push(A[i]);
    }

    return st.empty();
}
