#include<iostream>
#include<vector>
#include<stack>
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
std::vector<int> preorderTraversal(TreeNode* A) {
    //root left right
    std::stack<TreeNode*> st;
    std::vector<int> returnValue;
    st.push(A);
    while(!st.empty()){
        TreeNode* currNode = st.top();
        st.pop();
        returnValue.push_back(currNode->val);
        if(currNode->right){
            st.push(currNode->right);
        }
        if(currNode->left){
            st.push(currNode->left);
        }
    }
    return returnValue;
}