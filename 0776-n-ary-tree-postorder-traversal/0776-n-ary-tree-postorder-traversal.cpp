class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> ans;
        if (!root) return ans;
        stack<Node*> stk{ {root} };
        while (!stk.empty()) {
            root = stk.top();
            ans.push_back(root->val);
            stk.pop();
            for (Node* child : root->children) stk.push(child);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};