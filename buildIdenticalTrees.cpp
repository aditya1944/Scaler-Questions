#include<iostream>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int cntMatrix(TreeNode* A, TreeNode* B){
    //make A equal to B by inserting nodes in A
    if(!A && !B){
        //both are null
        return 0;
    }
    if(A && !B){
        //if A is not null and B is null
        return -1;
    }
    int returnValue = 0;
    int left,right;
    if(!A && B){
        //means A is null
        left = cntMatrix(NULL,B->left);
        if(left==-1){
            return -1;
        }
        right = cntMatrix(NULL,B->right);
        if(right==-1){
            return -1;
        }
        return left + right + 1;
    }
    //both are not null;
    left = cntMatrix(A->left, B->left);
    right = cntMatrix(A->right,B->right);
    
    return left + right;

    
}