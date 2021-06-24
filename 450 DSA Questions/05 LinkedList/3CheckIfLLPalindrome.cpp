/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement -  to check whether the list is palindrome.

// Divide the list into 2 halves and reverse one of the list and compare.
bool isPalindrome(Node *head) {
    if (head == NULL or head->next == NULL)
        return true;

    Node* curr1 = head;
    Node* curr2 = head;

    while (curr1 != NULL and curr1->next != NULL) {
        curr1 = curr1->next->next;
        curr2 = curr2->next;
    }

    // curr1 will be latter part of the LL.
    curr1 = curr2;
    curr2 = NULL;

    curr1 = reverseLinkedListIterative(curr1);
    curr2 = head;

    // Check if both are equal
    while (curr1 != NULL and curr2 != NULL) {
        if (curr1->data != curr2->data)
            return false;

        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    return true;
}

// Iterative Process
Node* reverseLinkedListIterative(Node* head) {
    // Empty or only one element
    if (head == NULL or head->next == NULL)
        return head;

    Node *slow = NULL, *fast = head, *curr = head;

    // Traverse over all the nodes and change the connectings
    while (fast != NULL) {
        fast = fast->next;

        // Change bindings
        curr->next = slow;
        slow = curr;
        curr = fast;
    }

    return slow;
}