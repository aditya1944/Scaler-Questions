#include<iostream>
#include<queue>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
bool helper(TreeNode* A, TreeNode* B){
    if(!A && !B){
        return true;
    }
    if(!A && B){
        return false;
    }
    if(A && !B){
        return false;
    }
    if(A->val == B->val){
        bool isLeftSymmetric = helper(A->left, A->right);
        bool isRightSymmetric = helper(B->left,B->right);
        return isLeftSymmetric && isRightSymmetric;
    }
    else{
        return false;
    }
}
int isSymmetric(TreeNode* A){
    bool returnValue = helper(A->left, A->right);
    return returnValue;
}