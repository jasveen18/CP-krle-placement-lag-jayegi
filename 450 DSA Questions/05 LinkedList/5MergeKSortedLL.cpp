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
    for (int i = 1; i < K; i++) {
        arr[0] = merge2Lists(arr[0], arr[i]);
    }

    return arr[0];
}


// Approach 2 - Merge 2 lists using DnC.
// T - O(N*K*LogK) | S - O(K) (recrusive stack)
Node* mergeKListsDnC(Node* arr[], int start, int end) {
    // Base Case
    if (start == end)
        return arr[start];
    if (start > end)
        return NULL;

    // Recursive Case
    int mid = (start + end) / 2;
    Node* l1 = mergeKListsDnC(arr, start, mid);
    Node* l2 = mergeKListsDnC(arr, mid + 1, end);

    return merge2Lists(l1, l2);
}

Node * mergeKLists(Node *arr[], int K) {
    if (K == 0)
        return NULL;

    return mergeKListsDnC(arr, 0, K - 1);
}


// Approach 3 - Merge 2 lists using Priority Queue
// T - O(N*K*LogK) | S - O(K) (PQ ka space)

// Min priority queue
class MyComparator {
public:
    int operator()(Node *a, Node *b) {
        return b->data < a->data;
    }
};


Node * mergeKLists(Node *arr[], int K) {
    priority_queue<Node*, vector<Node*>, MyComparator> pq;

    for (int i = 0; i < K; i++) {
        if (arr[i])
            pq.push(arr[i]);
    }

    Node* res = new Node(-1);
    Node* curr = res;

    while (!pq.empty()) {
        Node* temp = pq.top(); pq.pop();

        if (temp->next)
            pq.push(temp->next);

        curr->next = temp;
        curr = curr->next;
    }

    return res->next;
}