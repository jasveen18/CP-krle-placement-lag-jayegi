/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Function to pop an element from queue by using 2 stacks.
int StackQueue :: pop() {
    int n = s1.size();
    if (n == 0)
        return -1;

    while (s1.size() > 1) {
        s2.push(s1.top());
        s1.pop();
    }

    int item = s1.top();
    s1.pop();

    while (s2.empty() == false) {
        s1.push(s2.top());
        s2.pop();
    }

    return item;
}