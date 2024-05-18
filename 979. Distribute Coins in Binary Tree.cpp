class Solution {
private:
    int moves = 0;

public:
    int distributeCoins(TreeNode* root) {
        postOrder(root);
        return moves;
    }

private:
    int postOrder(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int leftExcess = postOrder(root->left);
        int rightExcess = postOrder(root->right);

        moves += abs(leftExcess) + abs(rightExcess);

        return root->val + leftExcess + rightExcess - 1;
    }
};
