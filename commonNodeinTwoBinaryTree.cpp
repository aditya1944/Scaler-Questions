#include<iostream>
#include<stack>
#include<unordered_set>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void traverseLeft(TreeNode *node, std::stack<TreeNode*> &st1){
    while(node){
        st1.push(node);
        node = node->left;
    }
}
int solve(TreeNode* A, TreeNode* B){
    //do it iteratively
    int sum = 0;
    std::stack<TreeNode*> st1,st2;
    traverseLeft(A,st1);
    traverseLeft(B,st2);
    while(!st1.empty() && !st2.empty()){
        TreeNode* node1 = st1.top(),*node2 = st2.top();
        if(node1->val==node2->val){
            sum+=node1->val;
            st1.pop();
            st2.pop();
            traverseLeft(node1->right,st1);
            traverseLeft(node2->right,st2);
        }
        else if(node1->val<node2->val){
            st1.pop();
            traverseLeft(node1->right,st1);
        }
        else{
            st2.pop();
            traverseLeft(node2->right,st2);
        }
    }
    return sum;
}