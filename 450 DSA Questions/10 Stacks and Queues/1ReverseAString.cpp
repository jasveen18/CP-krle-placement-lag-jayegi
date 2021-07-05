/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Reverse String
//return the address of the string
char* reverse(char *S, int len) {
    stack<char> s;
    for (int i = 0; i < len; i++) {
        s.push(S[i]);
    }

    int i = 0;
    while (!s.empty()) {
        S[i] = s.top(); s.pop();
        i++;
    }

    return S;
}