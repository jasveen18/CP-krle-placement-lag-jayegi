/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Function to add two numbers represented by linked list.

Node* reverseList(Node* head) {
    if (head == NULL or head->next == NULL)
        return head;

    Node* subProb = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;

    return subProb;
}


struct Node* addTwoLists(struct Node* first, struct Node* second) {
    // Reverse the LL so that we have ones place at first and then follow
    Node* revfirst = reverseList(first);
    Node* revsecond = reverseList(second);

    Node* curr1 = revfirst;
    Node* curr2 = revsecond;
    Node* curr3 = NULL; // For traversing the new List.
    int carry = 0;

    Node* sumHead = new Node(0);
    curr3 = sumHead;

    while (curr1 != NULL or curr2 != NULL) {
        int dig1 = curr1 == NULL ? 0 : curr1->data;
        int dig2 = curr2 == NULL ? 0 : curr2->data;

        // Sum
        int sum = (dig1 + dig2 + carry);
        curr3->next = new Node(sum % 10);
        carry = sum / 10;

        // Traverse ahead if possible
        if (curr1)
            curr1 = curr1->next;
        if (curr2)
            curr2 = curr2->next;

        curr3 = curr3->next;
    }

    // Check if carry is left
    if (carry)
        curr3->next = new Node(carry);

    // Skip the first node with '0' value.
    return reverseList(sumHead->next);
}