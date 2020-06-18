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
TreeNode* helper(const std::vector<int> &preorder,int left, int right){
    if(left>right){
        return NULL;
    }
    TreeNode *head = new TreeNode(preorder[left]);
    if(left==right){
        return head;
    }
    int tempIndex = left+1;
    while(tempIndex<=right && preorder[tempIndex]<preorder[left]){
        ++tempIndex;
    }
    head->left = helper(preorder,left+1,tempIndex-1);
    head->right = helper(preorder,tempIndex,right);
    return head;
}
TreeNode* bstFromPreorder(const std::vector<int>& preorder){
    if(preorder.size()==0){
        return NULL;
    }
    //root , left, right
    int left = 0, right = preorder.size();
    TreeNode* head = helper(preorder,left, right);
    return head;
}
