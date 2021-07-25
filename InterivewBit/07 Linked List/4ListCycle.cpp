/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - List Cycle
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    // Floyd Warshall laga dete hai
    ListNode* slow = A;
    ListNode* fast = A;

    while (fast != NULL and fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;

        if (slow == fast)
            break;
    }

    if (fast == NULL or fast->next == NULL)
        return NULL;

    fast = A;
    while (slow != fast) {
        fast = fast->next;
        slow = slow->next;
    }

    return fast;
}
