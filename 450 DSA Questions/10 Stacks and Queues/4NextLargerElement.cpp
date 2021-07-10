/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find the next larger element in array
vector<long long> nextLargerElement(vector<long long> arr, int n) {
    vector<long long> res(n, -1);

    stack<pair<long long, long long>> st;
    st.push({arr[0], 0LL});

    for (long long i = 1; i < n; i++) {
        while (st.empty() == false and st.top().first < arr[i]) {
            long long idx = st.top().second;
            res[idx] = arr[i];
            st.pop();
        }

        st.push({arr[i], i});
    }

    return res;
}