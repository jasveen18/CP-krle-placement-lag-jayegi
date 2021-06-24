/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find the intersection of 2 sorted LLs
Node* findIntersection(Node* head1, Node* head2) {
    Node *resHead = new Node(0);
    Node *curr1 = head1;
    Node *curr2 = head2;
    Node *curr3 = resHead;

    // Merge Sort wala hi algo
    while (curr1 != NULL and curr2 != NULL) {
        if (curr1 -> data < curr2 -> data) {
            curr1 = curr1 -> next;
        } else if (curr1 -> data > curr2 -> data) {
            curr2 = curr2 -> next;
        } else {
            curr3->next = new Node(curr1->data);

            // Traverse all
            curr1 = curr1->next;
            curr2 = curr2->next;
            curr3 = curr3->next;
        }
    }

    return resHead->next;
}