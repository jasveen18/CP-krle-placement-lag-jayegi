// Approach - Stack
// T - O(N)
// S - O(N)
bool ispar(string x) {
    // Make stack to check balance
    stack<char> s;
    s.push(x[0]);

    // Pop or push as per condition
    for (int i = 1; i < x.size(); i++) {
        if (!s.empty()) {
            if ((s.top() == '(' and x[i] == ')') or
                    (s.top() == '{' and x[i] == '}') or
                    (s.top() == '[' and x[i] == ']')) {
                s.pop();
            } else s.push(x[i]);
        }
        else
            s.push(x[i]);
    }

    return s.empty();
}