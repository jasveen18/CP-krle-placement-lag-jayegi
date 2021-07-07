/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Kth from middle.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::solve(ListNode* head, int k) {
    ListNode* curr = head;
    int size = 0;

    while (curr != NULL) {
        size++;
        curr = curr->next;
    }

    int mid = (size / 2) + 1;
    if (mid <= k)
        return -1;
    int trav = 0;
    mid = mid - k - 1;

    ListNode* res = head;
    while (res != NULL and trav < mid) {
        res = res->next;
        trav++;
    }

    return res->val;
}
