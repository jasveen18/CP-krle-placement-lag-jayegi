/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Delete duplicates
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode* curr = A;
    while (curr != NULL and curr->next != NULL) {
        ListNode* temp = curr;

        while (temp != NULL and temp->val == curr->val)
            temp = temp->next;

        curr->next = temp;
        curr = curr->next;
    }

    return A;
}
