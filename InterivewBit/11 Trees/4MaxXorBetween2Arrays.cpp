/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Max xor between 2 arrays.
// Let's make a trie
class Trie {
private:
    class Node {
    public:
        vector<Node*> next;
        Node() {
            next = vector<Node*> (2, NULL);
        }
    };

    Node* root;
public:
    Trie() {
        root = new Node();
    }

    void insertNumber(int num) {
        Node* curr = root;

        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if (curr->next[bit] == NULL)
                curr->next[bit] = new Node();

            curr = curr->next[bit];
        }
    }

    int calculateMaxXOR(int num) {
        Node* curr = root;
        int res = 0;

        for (int i = 31; i >= 0; i--) {
            int bit = ((num >> i) & 1) ? 0 : 1; // Opposite direction jaana hai
            if (curr->next[bit]) {
                res <<= 1;  // Shift by one for next bit
                res |= 1; // If bit is present, then add to the answer
                curr = curr->next[bit];
            } else {
                res <<= 1;
                res |= 0;
                curr = curr->next[bit ? 0 : 1];
            }
        }

        return res;
    }
};


int Solution::solve(vector<int> &A, vector<int> &B) {
    // TrieNode* root = buildTrie(A);
    Trie* root = new Trie();

    for (int i = 0; i < A.size(); i++) {
        root->insertNumber(A[i]);
    }

    int res = 0;
    for (int i = 0; i < B.size(); i++) {
        res = max(res, root->calculateMaxXOR(B[i]));
    }

    return res;
}
