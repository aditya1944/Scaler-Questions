#include<iostream>
#include<vector>
#include<queue>
#include<set>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void helper(TreeNode* root,const int& min,const int& max, int &pairs){
    if(!root){
        return;
    }
    if(root->val==min || root->val==max){
        ++pairs;
    }
    else if(root->val>min || root->val<max){
        ++pairs;
    }
    helper(root->left, min, max,pairs);
    helper(root->right,min, max,pairs);
}
int solve(TreeNode* A, int B){
    int pairs = 0;
    //do inorder traversal
    std::queue<TreeNode*> q;
    q.push(A);
    while(!q.empty()){
        TreeNode* curr = q.front();
        int min = curr->val - B;
        if(min<0){
            min = 0;
        }
        int max = curr->val + B;
        helper(curr->left,min, max,pairs);
        helper(curr->right, min, max, pairs);
        if(curr->left){
            q.push(curr->left);
        }
        if(curr->right){
            q.push(curr->right);
        }
    }
    return pairs;
}