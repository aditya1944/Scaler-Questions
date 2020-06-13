#include<iostream>
#include<stack>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void traverseLeft(std::stack<TreeNode*> &st, TreeNode* root){
    while(root){
        st.push(root);
        root=root->left;
    }
}
void traverseRight(std::stack<TreeNode*> &st, TreeNode* root){
    while(root){
        st.push(root);
        root = root->right;
    }
}
int t2Sum(TreeNode* A, int B) {
    //use two pointers approach
    //use inorder and reverse inorder
    TreeNode* t1,*t2;
    //st1 will be used for forward inorder traversal;
    //st2 will be used for reverse inorder traversal;
    std::stack<TreeNode*> st1,st2;
    traverseLeft(st1,A);
    traverseRight(st2,A);
    while(st1.top()!=st2.top()){
        TreeNode* i1 = st1.top();
        TreeNode* i2 = st2.top();
        if(i1==i2){
            break;
        }
        int currSum = i1->val + i2->val;
        if(currSum==B){
            return 1;
        }
        else if(currSum>B){
            //decrement i2 ptr
            st2.pop();
            if(i2->left){
                traverseRight(st2,i2->left);
            }    
        }
        else{
            st1.pop();
            if(i1->right){
                traverseLeft(st1, i1->right);
            }
        }
    }
    return 0;
}