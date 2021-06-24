/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find the middle node of LL

ListNode* middleNode(ListNode* head) {
    ListNode *fast = head;
    ListNode *slow = head;

    while (fast != NULL and fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}