/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Segregagte even and odd nodes, even will appear first.
Node* divide(int N, Node *head) {
    Node* even = new Node(0);
    Node* odd = new Node(0);

    Node* evenTraversal = even;
    Node* oddTraversal = odd;
    Node* curr = head;

    while (curr != NULL) {
        if (curr->data % 2 == 0) {
            evenTraversal->next = new Node(curr->data);
            evenTraversal = evenTraversal->next;
        } else {
            oddTraversal->next = new Node(curr->data);
            oddTraversal = oddTraversal->next;
        }

        curr = curr->next;
    }

    // Skip the first node (0) wala.
    evenTraversal->next = odd->next;
    return even->next;
}