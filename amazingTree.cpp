#include<iostream>
#include<queue>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

std::string solve(TreeNode* A, int B){
    //at level B (1-Based)
    std::queue<TreeNode*> q;
    q.push(A);
    int level = 1;
    std::string returnValue = "";
    while(!q.empty()){
        int size = q.size();
        while(size--){
            TreeNode* top = q.front();
            q.pop();
            if(level==B){
                returnValue+=std::to_string(top->val);
            }
            if(top->left){
                q.push(top->left);
            }
            if(top->right){
                q.push(top->right);
            }
        }
        if(level==B){
            break;
        }
        ++level;
    }
    return returnValue;
}