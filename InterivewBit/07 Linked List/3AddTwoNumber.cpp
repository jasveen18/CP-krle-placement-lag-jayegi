/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Add Two Numbers
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry = 0;
    ListNode* curr1 = l1;
    ListNode* curr2 = l2;
    ListNode* res = new ListNode(-1);
    ListNode* trav = res;


    while (curr1 != NULL or curr2 != NULL) {
        int dig1 = curr1 == NULL ? 0 : curr1->val;
        int dig2 = curr2 == NULL ? 0 : curr2->val;

        int sum = dig1 + dig2 + carry;
        trav->next = new ListNode((sum % 10));
        carry = sum / 10;

        trav = trav->next;

        if (curr1)
            curr1 = curr1->next;
        if (curr2)
            curr2 = curr2->next;
    }

    if (carry) {
        trav->next = new ListNode(carry);
    }

    return res->next;
}
