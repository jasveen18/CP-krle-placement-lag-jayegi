/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Check if parentheses are balanced
bool ispar(string x) {
    stack<char> s;

    s.push(x[0]);
    for (int i = 1; i < x.size(); i++) {
        if (!s.empty()) {
            if ((s.top() == '(' and x[i] == ')') or (s.top() == '{' and x[i] == '}') or (s.top() == '[' and x[i] == ']')) {
                s.pop();
            } else s.push(x[i]);
        }
        else
            s.push(x[i]);
    }

    return s.empty();
}