/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Even Reverse
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
ListNode* Solution::solve(ListNode* A) {
    // 2 chiz, ek ll for odd nodes and ek for even nodes.
    if (A == NULL or A->next == NULL)
        return A;

    ListNode* odd = NULL;
    ListNode* even = NULL;

    ListNode* oddTrav = NULL;
    ListNode* evenTrav = NULL;

    ListNode* curr = A;

    int i = 1;
    while (curr != NULL) {
        if (i & 1) {
            if (odd == NULL) {
                odd = curr;
                oddTrav = odd;
            } else {
                oddTrav->next = curr;
                oddTrav = oddTrav->next;
            }
        } else {
            if (even == NULL) {
                even = curr;
                evenTrav = even;
            } else {
                evenTrav->next = curr;
                evenTrav = evenTrav->next;
            }
        }
        i++;
        curr = curr->next;
    }

    oddTrav->next = NULL;
    evenTrav->next = NULL;

    even = reverseList(even);

    oddTrav = odd;
    evenTrav = even;

    while (oddTrav and evenTrav) {
        ListNode* oddTemp = oddTrav->next;
        ListNode* evenTemp = evenTrav->next;
        // cout<<oddTrav->val<<" "<<" "<<evenTrav->val<<"|";

        oddTrav->next = evenTrav;
        evenTrav->next = oddTemp;

        oddTrav = oddTemp;
        evenTrav = evenTemp;
    }

    // while(oddTrav) {
    //     cout<<oddTrav->val<<" ";
    //     oddTrav = oddTrav->next;
    // } cout<<" | ";
    // while(evenTrav) {
    //     cout<<evenTrav->val<<" ";
    //     evenTrav = evenTrav->next;
    // }

    return odd;
}
