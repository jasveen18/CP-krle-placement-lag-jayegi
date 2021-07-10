/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Merge K sorted lists.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct sortByValue {
    bool operator()(ListNode* &a, ListNode* &b) {
        return a->val > b->val;
    }
};

ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    priority_queue<ListNode*, vector<ListNode*>, sortByValue> pq;

    for (int i = 0; i < A.size(); i++) {
        if (A[i] != NULL)
            pq.push(A[i]);
    }

    ListNode* root = new ListNode(-1);
    ListNode* trav = root;

    while (!pq.empty()) {
        ListNode* least = pq.top(); pq.pop();
        trav->next = least;
        trav = trav->next;

        if (least->next)
            pq.push(least->next);
    }

    return root->next;
}
