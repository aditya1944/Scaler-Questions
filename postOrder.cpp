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
    std::stack<TreeNode*> s1,s2;
    std::vector<int> returnValue;
    s1.push(A);
    while(s1.empty()){
        TreeNode* currNode = s1.top();
        s1.pop();
        s2.push(currNode);
        //returnValue.push_back(currNode->val);
        if(currNode->left){
            s1.push(currNode->left);
        }
        if(currNode->right){
            s1.push(currNode->right);
        }
    }
    while(!s2.empty()){
        returnValue.push_back(s2.top()->val);
        s2.pop();
    }
    return returnValue;
}