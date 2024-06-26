class Solution {
public:
  void InOrderTraversal(TreeNode* node, vector<int>& nodes) {
    if (!node) { return; }
    InOrderTraversal(node->left, nodes);
    nodes.push_back(node->val);
    InOrderTraversal(node->right, nodes);
  }

  TreeNode* BuiltBST(vector<int>& nodes, int l, int r) {
    if (l > r) { return NULL; }
    int m = l + (r - l) / 2;
    TreeNode* curr = new TreeNode(nodes[m]);
    curr->left = BuiltBST(nodes, l, m - 1);
    curr->right = BuiltBST(nodes, m + 1, r);
    return curr;
  }

  TreeNode* balanceBST(TreeNode* root) {
    vector<int> nodes;
    InOrderTraversal(root, nodes);
    return BuiltBST(nodes, 0, (int)nodes.size() - 1);
  }
};
