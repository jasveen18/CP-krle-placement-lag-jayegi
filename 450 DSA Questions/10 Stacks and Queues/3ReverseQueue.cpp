/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Reverse a queue
void reverseQueue(queue<int> &q) {
    if (q.size() == 0) {
        return;
    }

    int frontEl = q.front(); q.pop();
    reverseQueue(q);
    q.push(frontEl);

    return;
}