#include<iostream>
#include<unordered_map>
#define mod 1000000007
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int solve(TreeNode* A) {
    std::unordered_map<TreeNode*,long long> hashMap;
    int returnValue = helper(A,hashMap);
    return returnValue;
}

int helper(TreeNode* A, std::unordered_map<TreeNode*, long long> &hashMap){
    if(!A){
        return 0;
    }
    if(hashMap.find(A)!=hashMap.end()){
        return hashMap[A];
    }
    //select this or not select this
    int selected = A->val;
    if(A->left){
        selected= ((long long)selected + (long long)helper(A->left->left,hashMap))%mod;
        selected= ((long long)selected + (long long)helper(A->left->right,hashMap))%mod;
    }
    if(A->right){
        selected= ((long long)selected + (long long)helper(A->right->left,hashMap))%mod;
        selected= ((long long)selected + (long long)helper(A->right->right,hashMap))%mod;
    }
    int notSelected = 0;
    if(A->left){
        notSelected= ((long long)notSelected + (long long)helper(A->left,hashMap))%mod;
    }
    if(A->right){
        notSelected= ((long long)notSelected + (long long)helper(A->right,hashMap))%mod;
    }
    int returnValue = std::max(selected,notSelected);
    hashMap[A] = returnValue;
    return returnValue;
}