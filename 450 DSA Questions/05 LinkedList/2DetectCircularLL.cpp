/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Is this a circular LL?
// Floyd Warshall Cycle Detection Algo
bool isCircular(Node *head) {
    Node* fast = head, *slow = head;

    while (fast != NULL and fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow)
            return true;
    }

    return false;
}