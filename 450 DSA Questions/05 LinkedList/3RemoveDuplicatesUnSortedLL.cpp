/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Remove Duplicates in a un sorted LL.
Node * removeDuplicates( Node *head)
{
    unordered_set<int> seen;

    Node* curr = head;
    while (curr != NULL and curr->next != NULL) {
        seen.insert(curr->data);

        while (curr != NULL and curr->next != NULL and seen.find(curr->next->data) != seen.end())
            curr->next = curr->next->next;

        curr = curr->next;
    }

    return head;
}