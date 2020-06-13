#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void leftTree(TreeNode* node, std::vector<int> &vec){
    if(!node->left && !node->right){
        //ignore currNode is leaf node
        return;
    }
    vec.push_back(node->val);
    if(node->left){
        leftTree(node->left,vec);
    }
    /*else if(node->right){
        leftTree(node->right,vec);
    }*/
}
void rightTree(TreeNode* node, std::vector<int> &vec){
    if(!node || (!node->left && !node->right)){
        //ignore when currNode is leaf node
        return;
    }
    rightTree(node->right, vec);
    vec.push_back(node->val);
}
void leaves(TreeNode* node, std::vector<int> &vec){
    if(!node){
        return;
    }
    if(!node->left && !node->right){
        vec.push_back(node->val);
        return;
    }
    leaves(node->left,vec);
    leaves(node->right,vec);
}
std::vector<int> solve(TreeNode* A) {
    //left View and right View
    //all leaves node
    std::vector<int> returnValue;
    leftTree(A,returnValue);
    leaves(A,returnValue);
    rightTree(A->right,returnValue);
    return returnValue;
}