/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Function to merge K sorted linked list.

// Approach 1 - Merge 2 lists one by one
// T - O(N*K*K) | S - O(1)
Node *merge2Lists(Node* left, Node* right) {
    if (!left)
        return right;
    if (!right)
        return left;

    if (left->data < right->data) {
        left->next = merge2Lists(left->next, right);
        return left;
    } else {
        right->next = merge2Lists(left, right->next);
        return right;
    }
}

Node * mergeKLists(Node *arr[], int K) {
    Node* startList = NULL;
    Node* traversal = NULL;

    for (int i = 1; i < K; i++) {
        arr[0] = merge2Lists(arr[0], arr[i]);
    }

    return arr[0];
}


// Approach 1 - Merge 2 lists one by one
// T - O(N*K*LogK) | S - O(1)