/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Rotate LL.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int B) {
    if (A == NULL or A->next == NULL)
        return A;

    int size = 1;
    ListNode* tail = A;

    while (tail->next != NULL) {
        size++;
        tail = tail->next;
    }

    B = B % size;
    B = size - B;
    B = B % size;

    if (B == 0)
        return A;

    ListNode* curr = A;
    while (curr != NULL and B > 1) {
        curr = curr->next;
        B--;
    }

    ListNode*head = curr->next;
    curr->next = NULL;

    tail->next = A;
    return head;
}
