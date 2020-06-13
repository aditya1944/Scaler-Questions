#include<iostream>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void helper(TreeNode *A, TreeNode *B, bool &isSame){
    if(!isSame){
        return;
    }
    if(!A && !B){
        return;
    }
    if(!A && B){
        isSame==false;
        return;
    }
    if(A && !B){
        isSame = false;
        return;
    }
    if(A->val==B->val){
        helper(A->left, B->left,isSame);
        helper(A->right,B->right,isSame);
    }
    else{
        isSame = false;
        return;
    }
    return;
}
int isSameTree(TreeNode* A, TreeNode* B){
    bool isSame = true;
    helper(A,B,isSame);
    return isSame;
}