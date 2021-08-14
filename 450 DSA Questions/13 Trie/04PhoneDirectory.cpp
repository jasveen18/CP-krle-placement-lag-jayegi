class Trie {
    class Node {
    public:
        bool leaf;
        vector<Node*> next;

        Node() {
            leaf = false;
            next = vector<Node*> (26, NULL);
        }
    };

    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void addWord(string word) {
        Node* curr = root;
        for (int i = 0; i < word.size(); i++) {
            int pos = word[i] - 'a';

            if (curr->next[pos] == NULL)
                curr->next[pos] = new Node;

            curr = curr->next[pos];
        }

        curr->leaf = true;
    }

    void getall(Node* curr, vector<string> &yaha, string strcurr) {
        if (curr->leaf == true) {
            yaha.push_back(strcurr);
            return;
        }

        int i = 0;
        for (i = 0; i < 26; i++) {
            if (curr->next[i] != NULL) {
                char add = i + 'a';
                getall(curr->next[i], yaha, strcurr + add);
            }
        }

        return;
    }

    void findAnswers(string abhi, vector<vector<string>> &res, int idx) {
        Node* curr = root;
        for (int i = 0; i < abhi.size(); i++) {
            int pos = abhi[i] - 'a';

            if (curr->next[pos] == NULL) {
                res[idx].push_back("0"); return;
            }

            curr = curr->next[pos];
        }

        // Recursive function to include all
        vector<string> yaha;
        getall(curr, yaha, abhi);

        // res[idx].emplace_back(yaha);
        res[idx] = yaha;
        return;
    }
};



class Solution {
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s) {
        Trie t;

        for (int i = 0; i < n; i++)
            t.addWord(contact[i]);

        vector<vector<string>> res(s.size());
        for (int i = 0; i < s.size(); i++) {
            string abhi = s.substr(0, i + 1);
            t.findAnswers(abhi, res, i);
        }
        // res.push_back("0");
        return res;
    }
};