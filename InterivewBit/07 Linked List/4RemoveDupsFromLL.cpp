/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Remove the duplicates entirely, jo distince honge bss unko rakho.
// Given 1->2->3->3->4->4->5, return 1->2->5.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode* dist = NULL;
    ListNode* trav = NULL;
    ListNode* curr = A;

    // If list is smaller than 3 nodes
    if (A == NULL or A->next == NULL)
        return A;
    if (A->val != A->next->val and A->next->next == NULL)
        return A;


    // Check for first node
    if (curr->val != curr->next->val) {
        dist = curr;
        trav = dist;
    }


    // Traversal and removal from middle nodes
    while (curr != NULL and curr->next != NULL and curr->next->next != NULL) {
        if (curr->val != curr->next->val and curr->next->val != curr->next->next->val) {
            if (dist == NULL) {
                dist = curr->next;
                trav = dist;
            } else {
                trav->next = curr->next;
                trav = trav->next;
            }
        }

        curr = curr->next;
    }


    // Check for last node
    if (curr->val != curr->next->val) {
        if (dist) {
            trav->next = curr->next;
            trav = trav->next;
        }
    }

    // If there was nothing
    if (trav)
        trav->next = NULL;

    return dist;
}
