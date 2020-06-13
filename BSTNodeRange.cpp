#include<iostream>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int helper(TreeNode* A, int B, int C){
    if(!A){
        return 0;
    }
    int noOfNodes;
    if(A->val>C){
        noOfNodes = helper(A->left,B,C);
    }
    else if(A->val<B){
        noOfNodes = helper(A->right,B,C);
    }
    else{
        int leftNodes = helper(A->left,B,C);
        int rightNodes = helper(A->right,B,C);
        noOfNodes = leftNodes + rightNodes + 1;
    }
    return noOfNodes;
}
int solve(TreeNode* A, int B, int C){
    int noOfNodes = 0;
    noOfNodes = helper(A,B,C);
    return noOfNodes;
}