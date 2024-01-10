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
static const int fast_io = [](){
     std::ios_base::sync_with_stdio(false);
     std::cin.tie(nullptr);
     std::cout.tie(nullptr);
     return 0;
 }();
 
class Solution {
public:

    int maxDistance = 0;//will be used to store the maxDistance
    
    //at a current node, it returns the maxDepth from that node.
    int traverse(TreeNode* root, int start){
        
        int depth = 0;
        if(root == NULL) return depth;

        int leftDepth = traverse(root->left, start);
        int rightDepth = traverse(root->right, start);

        //if our root is the start node only, we return the maxDepth from it, basically height of it's tree
        if(root->val == start){
            maxDistance = max(leftDepth, rightDepth); //obvious
            depth = -1; //we set the returning depth as -1 to notify it's parent that it's immediate child is the 'start' node.
        }else if(leftDepth >= 0 && rightDepth >= 0){
            //if both leftDepth and rightDepth of our curr node is +ve, it means this node's subtree doesn't contain the 'start' node, otherwise one of them would have returned -1.
            depth = max(leftDepth, rightDepth) + 1; //we return the maxDepth we can get in this tree.
        }else{
            //if we are in this case, it means one of the left or right child is 'start' node. Here, we compare this 'start' node's maxDistance both down it's tree, or from 'start' node's position to the neighbour subtree's farthest node (which should be already stored in maxDistance variable).
            int distance = abs(leftDepth) + abs(rightDepth);
            maxDistance = max(maxDistance, distance);
            depth = min(leftDepth, rightDepth) - 1; //ofcourse, it will be a -ve value. But, it should also give the distance from 'start' node to it's parent node. For case: [1,2,null,3,null,4,null,5] 
        }

        return depth;
    }

    int amountOfTime(TreeNode* root, int start) {
        traverse(root, start);
        return maxDistance;
    }
};
