/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Reverse a linked list in size of K.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* head, int k) {
    if (head == NULL)
        return head;

    ListNode* curr = head;
    ListNode* next = head;
    ListNode* prev = NULL;
    ListNode* headNode = head;
    int count = 0;

    while (next != NULL and count < k) {
        next = next->next;

        curr->next = prev;
        prev = curr;
        curr = next;

        count++;
    }

    if (next != NULL) {
        headNode->next = reverseList(next, k);
    }

    return prev;
}
