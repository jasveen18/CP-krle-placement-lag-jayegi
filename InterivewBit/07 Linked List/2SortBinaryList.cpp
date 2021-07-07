/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Sort binary tree.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* Solution::solve(ListNode* head) {
    ListNode* zero = NULL;
    ListNode* one = NULL;

    ListNode* zeroTraversal = NULL;
    ListNode* oneTraversal = NULL;

    ListNode* curr = head;

    while (curr != NULL) {
        if (curr->val == 0) {
            if (zero == NULL) {
                zero = curr;
                zeroTraversal = curr;
            } else {
                zeroTraversal->next = curr;
                zeroTraversal = zeroTraversal->next;
            }
        } else {
            if (one == NULL) {
                one = curr;
                oneTraversal = curr;
            } else {
                oneTraversal->next = curr;
                oneTraversal = oneTraversal->next;
            }
        }

        curr = curr->next;
    }

    if (!zero)
        return one;

    if (!one)
        return zero;

    zeroTraversal->next = one;
    oneTraversal->next = NULL;

    return zero;
}
