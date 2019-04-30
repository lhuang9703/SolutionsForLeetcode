# number : 589

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
using vec_it = vector<Node*>::reverse_iterator;
class Solution {
public:
    vector<int> preorder(Node* root) {
        //递归法
        
        if (root == nullptr)    { return result; }
        preVisit(root);
        return result;
        
        
        //迭代法
        /*
        if (root == nullptr)    { return result; }
        Node* p = root;
        stack<Node*> s;
        s.push(p);
        while (!s.empty()) {
            p = s.top();
            result.push_back(p->val);
            s.pop();
            for (vec_it it = p->children.rbegin(); it != p->children.rend(); it++) {
                s.push(*it);
            }
        }
        return result;
        */
    }
    void preVisit(Node* root) {
        result.push_back(root->val);
        for (auto node : root->children) {
            preorder(node);
        }
    }
private:
    vector<int> result;
};
