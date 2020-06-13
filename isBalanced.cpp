#include<iostream>
#include<math.h>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int helper(TreeNode *A, bool &isBalanced){
    if(!A){
        return 0;
    }
    if(!isBalanced){
        return 0;
    }
    int leftHeight = helper(A->left,isBalanced);
    int rightHeight = helper(A->right,isBalanced);
    int diff = abs(leftHeight - rightHeight);
    if(diff>1){
        isBalanced = false;
    }
    int maxHeight = std::max(leftHeight, rightHeight);
    return maxHeight + 1;
}
int isBalanced(TreeNode* A) {
    bool isBalanced = true;
    helper(A,isBalanced);
    if(isBalanced){
        return 1;
    }
    return 0;
}