/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Reorder List
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* reverseList(ListNode* head) {
    if (head == NULL or head->next == NULL)
        return head;

    ListNode* temp = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;

    return temp;
}

ListNode* Solution::reorderList(ListNode* A) {
    ListNode* slow = A;
    ListNode* fast = A;

    // Get to the middle of the list
    while (fast != NULL and fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }

    // Now break the list from slow and reverse it
    ListNode* newHead = slow->next;
    slow->next = NULL;
    newHead = reverseList(newHead);

    slow = A;
    while (slow != NULL and newHead != NULL) {
        ListNode* slowNext = slow->next;
        ListNode* newNext = newHead->next;

        // Update the bindings
        slow->next = newHead;
        newHead->next = slowNext;

        // Move ahead
        slow = slowNext;
        newHead = newNext;
    }

    return A;
}
