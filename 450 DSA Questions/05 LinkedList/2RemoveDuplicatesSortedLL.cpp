/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Remove Duplicates in a sorted LL.

Node *removeDuplicates(Node *head) {
    Node* curr = head;
    while (curr != NULL) {
        int valHere = curr->data;
        Node* temp = curr;

        // Iterate till we find duplicate value
        while ((temp != NULL) and valHere == temp->data)
            temp = temp->next;

        curr->next = temp;
        curr = curr->next;
    }

    return head;
}