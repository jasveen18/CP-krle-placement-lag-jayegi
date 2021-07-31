/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Swap List Nodes in pairs
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* A) {
    if (A == NULL or A->next == NULL)
        return A;

    ListNode* temp = swapPairs(A->next->next);
    ListNode* newHead = A->next;

    newHead->next = A;
    A->next = temp;

    return newHead;
}
