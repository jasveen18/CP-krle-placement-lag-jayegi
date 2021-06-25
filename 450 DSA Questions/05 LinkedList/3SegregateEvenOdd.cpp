/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Segregagte even and odd nodes, even will appear first.

// Make a new LL to store the values
// O(N) time | O(1) space
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


// Modify the current LL
// O(N) time | O(1) space
Node* divide(int N, Node *head) {
    Node* evenStart = NULL;
    Node* oddStart = NULL;
    Node* even = NULL;
    Node* odd = NULL;


    Node* curr = head;

    while (curr != NULL) {
        Node* fast = curr->next;

        // Modify nodes bindings as per requirements
        if (curr->data % 2 == 0) {
            if (evenStart == NULL) {
                evenStart = curr;
                even = evenStart;
            } else {
                even->next = curr;
                even = even->next;
            }
        } else {
            if (oddStart == NULL) {
                oddStart = curr;
                odd = oddStart;
            } else {
                odd->next = curr;
                odd = odd->next;
            }
        }

        curr = fast;
    }

    // Make the last node to point to null
    if (odd) {
        odd->next = NULL;
    }

    // Check if there are no even numbers present
    if (even) {
        even->next = oddStart; // Connect the last even number to first of odd
        return evenStart;
    } else {
        return oddStart;
    }
}