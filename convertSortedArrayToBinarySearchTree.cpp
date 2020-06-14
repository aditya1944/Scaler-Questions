#include<iostream>
#include<vector>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode* helper(const std::vector<int> &nums, int left, int right){
    if(left>right){
        return NULL;
    }
    int mid = left + (right-left)/2;
    TreeNode* node = new TreeNode(nums[mid]);
    node->left = helper(nums,left, mid-1);
    node->right = helper(nums,mid+1, right);
    return node;
}
TreeNode* sortedArrayToBST(std::vector<int> &nums){
    TreeNode* head = NULL;
    int left = 0,right = nums.size()-1;
    head = helper(nums,left,right);
    return head;
}