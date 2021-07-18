/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find min element in O(1) time.
stack<int> mainStack, minStack;

MinStack::MinStack() {
    while (mainStack.empty() == false)
        mainStack.pop();

    while (minStack.empty() == false)
        minStack.pop();
}

void MinStack::push(int x) {
    mainStack.push(x);

    if (minStack.empty() or minStack.top() >= x)
        minStack.push(x);

    return;
}

void MinStack::pop() {
    if (mainStack.empty())
        return;

    if (mainStack.top() == minStack.top())
        minStack.pop();

    mainStack.pop();
}

int MinStack::top() {
    if (mainStack.empty())
        return -1;

    return mainStack.top();
}

int MinStack::getMin() {
    if (mainStack.empty())
        return -1;

    return minStack.top();
}

