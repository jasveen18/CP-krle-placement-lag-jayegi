/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Merge K Sorted linked List
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
    // cout<<pq.size();
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