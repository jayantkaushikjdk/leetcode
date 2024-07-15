/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
         unordered_map<int, TreeNode*> nodes;
        unordered_set<int> children;
        
        // Create all nodes and record the child nodes
        for (const auto& description : descriptions) {
            int parent = description[0];
            int child = description[1];
            int isLeft = description[2];
            
            // Ensure parent node exists
            if (nodes.find(parent) == nodes.end()) {
                nodes[parent] = new TreeNode(parent);
            }
            // Ensure child node exists
            if (nodes.find(child) == nodes.end()) {
                nodes[child] = new TreeNode(child);
            }
            
            // Assign child to the correct position
            if (isLeft == 1) {
                nodes[parent]->left = nodes[child];
            } else {
                nodes[parent]->right = nodes[child];
            }
            
            // Record child
            children.insert(child);
        }
        
        // The root is the only node that is not a child of any node
        TreeNode* root = nullptr;
        for (const auto& nodePair : nodes) {
            if (children.find(nodePair.first) == children.end()) {
                root = nodePair.second;
                break;
            }
        }
        
        return root;
    }
};

// Helper function to print the tree (for debugging purposes)
void printTree(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);

    }
