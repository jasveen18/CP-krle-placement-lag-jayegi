/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Reverse a doubly linked list.
Node* reverseDLL(Node * head) {
    if (head == NULL or head->next == NULL)
        return head;

    Node* fast = head;
    Node* curr = head;
    Node* prev = NULL;

    while (curr != NULL) {
        fast = fast->next;

        curr->prev = fast;
        curr->next = prev;

        prev = curr;
        curr = fast;
    }

    return prev;
}