#include<iostream>
#include<vector>
#include<unordered_map>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* helper(std::vector<int> &inorder, std::vector<int> &preorder, int start, int end, std::unordered_map<int,int> &hashMap){
    if(start<end){
        return NULL;
    }
    //start 
    TreeNode* root = new TreeNode(preorder[start]);
    if(start==end){
        return root;
    }
    //find the index of preorder[start] in inorder Array
    int index = hashMap[preorder[start]];
    root->left = helper(inorder, preorder, start, index-1, hashMap);
    root->right = helper(inorder, preorder,index+1,end,hashMap);
    return root;
}
TreeNode* buildTree(std::vector<int> &A, std::vector<int> &B){
    //A is inorder
    //B is preorder
    std::unordered_map<int, int> hashMap;
    for(int index = 0;index<A.size();++index){
        hashMap[A[index]] = index;
    }
    int start = 0,end = A.size()-1;
    TreeNode *root = helper(A,B,start, end,hashMap);
}