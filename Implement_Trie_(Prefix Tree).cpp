# number : 208

const int MAX_SIZE = 26;
class Trie {
public:
    struct TrieNode {
        bool isEnd;
        int num;
        TrieNode *children[MAX_SIZE];
        TrieNode()
        {
            num = 0;
            isEnd = false;
            for (int i = 0; i < MAX_SIZE; i++)
                children[i] = NULL;
        }
    };
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int length = word.size();
        if (length == 0) { return; }
        TrieNode *p = root;
        for (int i = 0; i < length; i++)
        {
            int index = word[i] - 'a';
            if (p->children[index] == NULL)
            {
                TrieNode* pNode = new TrieNode();
                p->children[index] = pNode;
                p->num++;
            }
            p = p->children[index];
        }
        p->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int length = word.size();
        if (length == 0)    { return false; }
        TrieNode *p = root;
        for (int i = 0; i < length; i++)
        {
            int index = word[i] - 'a';
            if (p->children[index] == NULL) { return false; }
            p = p->children[index];
        }
        return p->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int length = prefix.size();
        if (length == 0)    { return false; }
        TrieNode *p = root;
        for (int i = 0; i < length; i++)
        {
            int index = prefix[i] - 'a';
            if (p->children[index] == NULL) { return false; }
            p = p->children[index];
        }
        return true;
    }
private:
    TrieNode *root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
