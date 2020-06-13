#include<iostream>
#include<vector>
#include<stack>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Node{
    public:
        int max;
        int min;
        TreeNode* treeNode;
};
void traverseLeft(TreeNode* root, std::stack<TreeNode*> &st){
    while(root){
        st.push(root);
        root = root->left;
    }
}
std::vector<int> recoverTree(TreeNode* A){
    std::stack<TreeNode*> st;
    std::vector<int> returnValue(2);
    int prevVal=-1,currVal = -1;
    bool isFirst = true;
    traverseLeft(A,st);
    while(!st.empty()){
        TreeNode* curr = st.top();
        st.pop();
        if(isFirst){
            prevVal = currVal = curr->val;
            isFirst=false;
        }
        else{
            prevVal = currVal;
            currVal = curr->val;
            if(currVal<prevVal){
                returnValue[0] = prevVal;
                returnValue[1] = currVal;
            }
        }
        if(curr->right){
            traverseLeft(curr->right,st);
        }
    }
    return returnValue;
}