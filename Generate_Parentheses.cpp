# number : 22

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if (n <= 0)
            return result;
        addParentheses(result, "", n, 0, 0);
        return result;
    }
    void addParentheses(vector<string>& result, string str, int n, int left, int right)
    {
        if (right == n)
        {
            result.push_back(str);
            return;
        }
        if (left < n)
            addParentheses(result, str + "(", n, left + 1, right);
        if (right < left)
            addParentheses(result, str + ")", n, left, right + 1);
    }
};

/*
解法二：建树，树的根节点为”（“， 每个节点的左子节点为”（“， 右子节点为”）“，遍历树
的时候如果到达叶子节点（叶子节点一定是“）”）即获得一个结果。
*/
struct Node
{
    string val;
    Node *left;
    Node *right;
    Node(string s): val(s), left(NULL), right(NULL){}
};
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if (n <= 0)
            return result;
        Node *root = buildLeftTree(n, 0, 0);
        travel(result, root, "");
        return result;
    }
    Node* buildLeftTree(int n, int left, int right)
    {
        if (left < n)
        {
            Node* root = new Node("(");
            root->left = buildLeftTree(n, left + 1, right);
            root->right = buildRightTree(n, left + 1, right);
            return root;
        }
        return NULL;
    }
    Node* buildRightTree(int n, int left, int right)
    {
        if (right < left)
        {
            Node* root = new Node(")");
            root->left = buildLeftTree(n, left, right + 1);
            root->right = buildRightTree(n, left, right + 1);
            return root;
        }
        return NULL;
    }
    void travel(vector<string>& result, Node* root, string str)
    {
        if (root->left == NULL && root->right == NULL) //叶子节点
        {
            result.push_back(str + root->val);
            return;
        }
        str += root->val;
        if (root->left != NULL)
            travel(result, root->left, str);
        if (root->right != NULL)
            travel(result, root->right, str);
        return;
    }
};
