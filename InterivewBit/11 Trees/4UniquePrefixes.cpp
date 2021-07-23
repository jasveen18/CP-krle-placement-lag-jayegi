/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Unique prefixes -> search bar hai, kitna type krne pe sirf ek word display krega.
class Trie {
private:
    class Node {
    public:
        int nums;
        vector<Node*> next;

        Node() {
            nums = 0;
            next = vector<Node*> (26, NULL);
        }
    };

    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insertWord(string word) {
        Node* curr = root;

        for (int i = 0; i < word.size(); i++) {
            if (curr->next[word[i] - 'a'] == NULL) {
                curr->next[word[i] - 'a'] = new Node();
            }

            curr->nums++;
            curr = curr->next[word[i] - 'a'];
        }
    }

    string findPrefix(string word) {
        Node* curr = root;
        string res = "";

        for (int i = 0; i < word.size(); i++) {
            if (curr->nums == 1)
                return res;

            res += word[i];

            curr = curr->next[word[i] - 'a'];
        }

        return word;
    }
};

vector<string> Solution::prefix(vector<string> &A) {
    vector<string> res;
    int n = A.size();

    // Insert into trie first
    // Iterate again, now when you reach a position where there is only one element, then we can say that we are certain of the word.
    Trie* root = new Trie();
    for (int i = 0; i < n; i++) {
        root->insertWord(A[i]);
    }

    for (int i = 0; i < n; i++) {
        res.push_back(root->findPrefix(A[i]));
    }

    return res;
}
