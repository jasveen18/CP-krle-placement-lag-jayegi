/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Evaluate a postfix notation
int evaluatePostfix(string S) {
    stack<int> st;

    for (int i = 0; i < S.size(); i++) {
        // If number hai toh push
        if ((S[i] - '0') >= 0 and (S[i] - '0') <= 9) {
            st.push(S[i] - '0');
        }

        // If operator hai toh stack ke upar ke do element ko lekr operate kr do
        else {
            int first = st.top(); st.pop();
            int second = st.top(); st.pop();
            int res = 0;
            if (S[i] == '+') {
                res = first + second;
            } else if (S[i] == '-') {
                res = second - first;
            } else if (S[i] == '*') {
                res = second * first;
            } else if (S[i] == '/') {
                res = second / first;
            }

            st.push(res);
        }
    }

    return st.top();
}