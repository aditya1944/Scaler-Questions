#include<iostream>
#include<vector>
#include<stack>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void traverseLeft(std::stack<TreeNode*> &st, TreeNode* temp){
    while(temp){
        st.push(temp);
        temp = temp->left;
    }
}
std::vector<int> inorderTraversal(TreeNode* A) {
    std::stack<TreeNode*> st;
    std::vector<int> returnValue;
    traverseLeft(st, A);
    while(!st.empty()){
        TreeNode* curr = st.top();
        st.pop();
        returnValue.push_back(curr->val);
        if(curr->right){
            traverseLeft(st,curr->right);
        }
    }
    return returnValue;
}