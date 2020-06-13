#include<iostream>
#include<vector>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* helper(const std::vector<int> &A, int left, int right){
    if(left>right){
        return NULL;
    }
    int mid = (left + right)/2;
    TreeNode *head = new TreeNode(A[mid]);
    head->left = helper(A,left, mid-1);
    head->right = helper(A,mid+1,right);
    return head;
}
TreeNode* sortedArrayToBST(const std::vector<int> &A){
    if(A.size()==0){
        return NULL;
    }
    TreeNode* head = helper(A,0,A.size()-1);
    return head;
}