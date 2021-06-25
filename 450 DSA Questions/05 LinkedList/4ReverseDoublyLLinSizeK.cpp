/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Reverse a DLL in size of K.
Node* reverseDLLSizeK(Node * head, int k) {
    if (head == NULL or head->next == NULL)
        return head;

    Node* fast = head;
    Node* curr = head;
    Node* prev = NULL;
    int count = 0;

    while (curr != NULL and count < k) {
        fast = fast->next;

        curr->prev = fast;
        curr->next = prev;

        prev = curr;
        curr = fast;
        count++;
    }

    if (fast) {
        head->next = reverseDLLSizeK(fast, k);
        head->next->prev = head;
    }

    return prev;
}