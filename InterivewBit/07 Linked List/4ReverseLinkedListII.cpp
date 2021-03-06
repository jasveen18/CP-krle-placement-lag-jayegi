/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Reverse a LL from B to C.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    if (A == NULL)
        return A;

    ListNode* dummy = new ListNode(0); // create a dummy node to mark the head of this list
    dummy->next = A;

    ListNode* pre = dummy; // make a pointer pre as a marker for the node before reversing
    for (int i = 0; i < B - 1; i++) pre = pre->next;

    ListNode* start = pre->next; // a pointer to the beginning of a sub-list that will be reversed
    ListNode* fast = start->next; // a pointer to a node that will be reversed (fast)

    // 1 - 2 -3 - 4 - 5 ; m=2; n =4 ---> pre = 1, start = 2, then = 3
    // dummy-> 1 -> 2 -> 3 -> 4 -> 5

    for (int i = 0; i < C - B; i++) {
        start->next = fast->next;
        fast->next = pre->next;
        pre->next = fast;
        fast = start->next;
    }

    // first reversing : dummy->1 - 3 - 2 - 4 - 5; pre = 1, start = 2, then = 4
    // second reversing: dummy->1 - 4 - 3 - 2 - 5; pre = 1, start = 2, then = 5 (finish)

    return dummy->next;
}
