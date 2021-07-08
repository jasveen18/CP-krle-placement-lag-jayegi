/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Check for palindrome
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


// Approach 1 - Using extra space
bool isPalin(string res) {
    int start = 0, end = res.size() - 1;

    while (start < end) {
        if (res[start] != res[end])
            return false;
        start++; end--;
    }

    return true;
}

int Solution::lPalin(ListNode* A) {
    ListNode *curr = A;
    string res = "";

    while (curr != NULL) {
        res += (curr->val - '0');
        curr = curr->next;
    }

    return isPalin(res);
}


// Approach 2 -
// 2 pointers by modifying Linked List
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* reverseList(ListNode* head) {
    if (head == NULL)
        return head;

    ListNode* curr = head;
    ListNode* next = head;
    ListNode* prev = NULL;

    while (next != NULL) {
        next = next->next;

        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

int Solution::lPalin(ListNode* A) {
    ListNode* mid = A;
    ListNode* fast = A;

    while (fast != NULL and fast->next != NULL) {
        mid = mid->next;
        fast = fast->next->next;
    }

    if (fast)
        mid = mid->next;

    // Now we can reverse the node from mid.
    ListNode* rev = reverseList(mid);
    ListNode* start = A;

    while (rev != NULL and start != NULL) {
        if (rev->val != start->val)
            return 0;
        rev = rev->next;
        start = start->next;
    }

    return 1;
}
