/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k) {
    stack<int> st;
    int n = q.size();

    for (int i = 0; i < k; i++) {
        int f = q.front(); q.pop();
        st.push(f);
    }

    for (int i = 0; i < k; i++) {
        int f = st.top(); st.pop();
        q.push(f);
    }

    for (int i = k; i < n; i++) {
        int f = q.front(); q.pop();
        q.push(f);
    }

    return q;
}