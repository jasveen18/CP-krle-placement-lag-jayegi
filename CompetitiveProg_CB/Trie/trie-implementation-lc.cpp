class Trie {
private:
    class Node {
    public:
        Node* nextChar[26];
        bool leafNode;
        Node() {
            for (int i = 0; i < 26; i++) nextChar[i] = NULL;
            leafNode = false;
        }
    };

    Node* root;

public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* curr = root;

        for (int i = 0; i < word.size(); i++) {
            if (curr->nextChar[word[i] - 'a'] == NULL) {
                curr->nextChar[word[i] - 'a'] = new Node();
            }

            curr = curr->nextChar[word[i] - 'a'];
        }

        curr->leafNode = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* curr = root;

        for (int i = 0; i < word.size(); i++) {
            if (curr->nextChar[word[i] - 'a'] == NULL)
                return false;

            curr = curr->nextChar[word[i] - 'a'];
        }

        // Check ki ye word complete hua ya ni
        if (curr->leafNode)
            return true;
        else
            return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* curr = root;

        for (int i = 0; i < prefix.size(); i++) {
            if (curr->nextChar[prefix[i] - 'a'] == NULL)
                return false;

            curr = curr->nextChar[prefix[i] - 'a'];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */