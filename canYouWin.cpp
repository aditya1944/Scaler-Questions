#include<iostream>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void find(TreeNode* A, int C,TreeNode** ptr){
    if(!A){
        return ;
    }
    if(A->val==C){
        *ptr = A;
        return;
    }
    find(A->left,C,ptr);
    find(A->right,C,ptr);
}
int calculate(TreeNode* node){
    if(!node){
        return 0;
    }
    return 1 + calculate(node->left) + calculate(node->right);
}
int solve(TreeNode* A, int B, int C) {
    //total there are B nodes. 
    //initially friend has taken node with value C
    
    //function to return the node with value C
    TreeNode* ptr;
    TreeNode** temp = &ptr;
    find(A,C,temp);
    //ptr has the value
    //now calculate all node in left and right subtree
    int leftNodes = calculate(ptr->left);
    int rightNodes = calculate(ptr->right);
    
    //total node i have is the max of 3 parts
    int myNodes = std::max(leftNodes, std::max(rightNodes, B - (leftNodes+ rightNodes+1)));
    int hisNodes = B - myNodes;
    if(myNodes>hisNodes){
        return 1;
    }
    return 0;
}
