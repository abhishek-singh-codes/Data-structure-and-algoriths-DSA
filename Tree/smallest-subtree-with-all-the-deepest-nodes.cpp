/*
Link: https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/?envType=daily-question&envId=2026-01-09
Logic = Calculate height 

if  left height == right height   
  this node is the answer

if left height > right height : 
  answwer is in left subtree
else 
  answer is in right subtree 
*/


class Solution {
public:
    // calculate total depth
    int getDepth(TreeNode* root){
        if(root == NULL)return 0;
        int leftMax = getDepth(root->left);
        int rightMax = getDepth(root->right);
        return max(leftMax, rightMax) + 1;
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int leftDepth = getDepth(root->left);
        int rightDepth = getDepth(root->right);
        if(leftDepth == rightDepth){
            return root;
        }
        if(leftDepth > rightDepth){
            return subtreeWithAllDeepest(root -> left);
        }else{
            return subtreeWithAllDeepest(root -> right);
        }
    }
};
