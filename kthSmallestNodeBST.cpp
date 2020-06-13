#include<iostream>
#include<unordered_set>
#include<stack>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void traverseLeft(TreeNode* root, std::stack<TreeNode*> &st){
    while(root){
        st.push(root);
        root = root->left;
    }
}
int kthsmallest(TreeNode* A, int B){
    int count = 0;
    std::stack<TreeNode*> st;
    traverseLeft(A, st);
    while(!st.empty()){
        TreeNode* currNode = st.top();
        st.pop();
        ++count;
        if(count==B){
            return currNode->val;
        }
        traverseLeft(A->right,st);
    }
    //use iterative version
}