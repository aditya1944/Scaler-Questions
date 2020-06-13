#include<iostream>
#include<queue>
#include<vector>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
std::vector<int> solve(TreeNode* A) {
    // use level order traversal and last node of each level is ans
    std::vector<int> returnValue;
    std::queue<TreeNode*> q;
    q.push(A);
    while(!q.empty()){
        int sizeofCurrentLevel = q.size();
        int index = 0;
        while(index<sizeofCurrentLevel){
            TreeNode* topNode = q.front();
            if(sizeofCurrentLevel-index==1){
                //top node of queue is last in its level
                returnValue.push_back(topNode->val);
            }
            if(topNode->left){
                q.push(topNode->left);
            }
            if(topNode->right){
                q.push(topNode->right);
            }
            q.pop();
            ++index;
        }
    }
    return returnValue;
}