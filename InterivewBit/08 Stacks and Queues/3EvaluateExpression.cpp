/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Evaluate Expression
int Solution::evalRPN(vector<string> &A) {
    stack<int> st;
    int res = 0;

    for (int i = 0; i < A.size(); i++) {
        if ((A[i][0] == '+' or A[i][0] == '-' or A[i][0] == '*' or A[i][0] == '/') and A[i].size() == 1) {
            int first = st.top(); st.pop();
            int second = st.top(); st.pop();
            int res;
            if (A[i][0] == '+')
                res = second + first;
            if (A[i][0] == '-')
                res = second - first;
            if (A[i][0] == '*')
                res = second * first;
            if (A[i][0] == '/')
                res = second / first;

            st.push(res);
        } else {
            st.push(stoi(A[i]));
        }
    }

    return st.top();
}
