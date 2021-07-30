/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Remove redundant braces
int Solution::braces(string A) {
    stack<char> st;

    for (int i = 0; i < A.size(); i++) {
        // If the curr char is ')'
        if (A[i] == ')') {
            char top = st.top(); st.pop();

            // We are popping
            // Case 1 - If immediate pop have open parentheses   -> ((a + b))
            // Case 2 - if immediate pop doesn't hit any operand -> (a) wala case
            bool flag = true;

            while (st.empty() == false and top != '(') {
                // Top doesnt have immediate open parentheses.
                if (top == '+' or top == '-' or top == '*' or top == '/')
                    flag = false;

                top = st.top(); st.pop();
            }

            if (flag)
                return true;
        }

        else {
            st.push(A[i]);
        }
    }

    return 0;
}
