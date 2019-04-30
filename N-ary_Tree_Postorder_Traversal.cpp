# number : 590

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
    vector<int> postorder(Node* root) {
        //递归解法
        if (root == nullptr)    { return result; }
        postVisit(root);
        return result;
        
        //迭代解法一，每次出栈判断是第几次出栈，第一次则把孩子节点逆序压栈，第二次则表示
        //孩子节点都已经访问过了，可以直接访问
        /*
        if (root == nullptr)    { return result; }
        stack<Node*> s;
        unordered_map<Node*, int> mp;
        Node* p = root;
        s.push(p);
        mp.insert(make_pair(p, 0));
        while (!s.empty()) {
            p = s.top();
            if (mp[p] == 0) {
                for (vec_it it = p->children.rbegin(); it != p->children.rend(); it++) {
                    s.push(*it); 
                    mp.insert(make_pair(p, 0));
                }
                mp[p] = 1;
            } else {
                result.push_back(p->val);
                s.pop();
            }
        }
        return result;
        */
        
        //迭代解法二
        /*
        if (root == nullptr)    { return result; }
        stack<Node*> s;
        Node* p = root;
        s.push(p);
        while (!s.empty()) {
            p = s.top();
            result.push_back(p->val);
            s.pop();
            for (auto node : p->children) {
                s.push(node);
            }
        }
        reverse(result.begin(), result.end());
        return result;
        */
    }
    void postVisit(Node* root) {
        if (root == nullptr)    { return; }
        for (auto node : root->children) {
            postVisit(node);
        }
        result.push_back(root->val);
        return;
    }
private:
    vector<int> result;
};
