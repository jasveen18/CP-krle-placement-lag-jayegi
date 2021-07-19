/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Remove K chars and then return the min sum of square of frequency.
int minValue(string s, int k) {
    // Pehle toh count nikal lete hai phir priority queue kr denge
    unordered_map<char, int> count;
    for (char x : s)
        count[x]++;

    priority_queue<int> pq;
    for (auto el : count)
        pq.push(el.second);

    while (pq.empty() == false and k > 0) {
        int top = pq.top(); pq.pop();
        top--;
        pq.push(top);
        k--;
    }

    int ans = 0;
    while (pq.empty() == false) {
        int top = pq.top(); pq.pop();
        // cout<<top<<endl;
        ans += (top * top);
    }

    return ans;
}