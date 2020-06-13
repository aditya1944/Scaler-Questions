#include<iostream>
#include<vector>
#include<climits>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
struct Info{
    int max;
    int min;
    int maxSize;
    bool isBst;
};
Info helper(TreeNode* root){
    if(!root){
        Info info;
        info.isBst = true;
        info.max = INT_MIN;
        info.min = INT_MAX;
        info.maxSize = 0;
        return info;
    }
    Info left = helper(root->left);
    Info right = helper(root->right);
    Info returnValue;
    if(!left.isBst || !right.isBst){
        //any of the subtree is not bst
        //hence including this node will be also not bst.
        returnValue.max = 0;
        returnValue.min = 0;
        returnValue.isBst = false;
        returnValue.maxSize = std::max(left.maxSize,right.maxSize);
        return returnValue;
    }
    //left subtree and right subtree are bst now check if including this node will also be bst or not
    if(left.max>=root->val || right.max<=root->val){
        //validity failed
        //including this node will be not bst;
        returnValue.max = 0;
        returnValue.min = 0;
        returnValue.maxSize = std::max(left.maxSize,right.maxSize);
        returnValue.isBst = false;
    }
    //good case
    //including this case will result in bst
    returnValue.isBst = true;
    returnValue.max = std::max(root->val, right.max);
    returnValue.min = std::min(root->val,left.min);
    returnValue.maxSize = left.maxSize + right.maxSize;
    return returnValue;
}
int solve(TreeNode* A){
    //first index store minimum value of subtree 
    //second index store maximum value of subtree
    Info info = helper(A);
    return info.maxSize;
}