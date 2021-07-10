/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find nearest smaller element
vector<int> Solution::prevSmaller(vector<int> &A) {
    int n = A.size();
    if (n == 0)
        return {};

    vector<int> res(n, -1);

    stack<pair<int, int>> st;
    st.push({A[n - 1], n - 1});

    for (int i = n - 2; i >= 0; i--) {
        while (st.empty() == false and st.top().first > A[i]) {
            int idx = st.top().second; st.pop();
            res[idx] = A[i];
        }

        st.push({A[i], i});
    }

    return res;
}
