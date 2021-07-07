/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Merge 2 LL.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    if (A == NULL and B == NULL)
        return NULL;

    if (A == NULL)
        return B;
    if (B == NULL)
        return A;

    if (A->val < B->val) {
        A->next = mergeTwoLists(A->next, B);
        return A;
    } else {
        B->next = mergeTwoLists(A, B->next);
        return B;
    }
}
