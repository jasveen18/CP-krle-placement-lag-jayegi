/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Split one circular LL into 2 CLL, both the parts should also be a Circular LL.

void splitList(Node *head, Node **head1_ref, Node **head2_ref) {
    Node* fast = head;
    Node* slow = head;

    while (fast->next != head and fast->next->next != head) {
        fast = fast->next->next;
        slow = slow->next;
    }

    // Make references
    *head1_ref = head;
    *head2_ref = slow->next;

    // Make the 1st LL a CLL.
    slow->next = head;

    // Make the 2nd LL a CLL.
    Node *curr = *head2_ref;
    while (curr->next != head)
        curr = curr->next;

    curr->next = *head2_ref;

    return;
}