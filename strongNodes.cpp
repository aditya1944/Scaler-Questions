#include<iostream>
#include<climits>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void helper(TreeNode* A, int maxTillNow, int &count){
    if(!A){
        //A is null;
        return;
    }
    if(maxTillNow<=A->val){
        ++count;
    }
    maxTillNow = std::max(maxTillNow, A->val);
    helper(A->left, maxTillNow,count);
    helper(A->right,maxTillNow,count);
}
int solve(TreeNode* A) {
    int maxTillNow = INT_MIN;
    int count = 0;
    helper(A,maxTillNow,count);
    return count;
}
