/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) {
    ListNode* before = NULL;
    ListNode* after = NULL;
    ListNode* beforeTraversal = NULL;
    ListNode* afterTraversal = NULL;

    ListNode* curr = A;

    while (curr != NULL) {
        if (curr -> val < B) {
            if (before == NULL) {
                before = curr;
                beforeTraversal = before;
            } else {
                beforeTraversal->next = curr;
                beforeTraversal = beforeTraversal->next;
            }
        } else {
            if (after == NULL) {
                after = curr;
                afterTraversal = after;
            } else {
                afterTraversal->next = curr;
                afterTraversal = afterTraversal->next;
            }
        }

        curr = curr->next;
    }

    // Now join both of them
    if (before == NULL)
        return after;
    if (after)
        afterTraversal->next = NULL;

    beforeTraversal->next = after;
    return before;
}
