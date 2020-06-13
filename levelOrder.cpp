#include<iostream>
#include<vector>
#include<queue>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
std::vector<std::vector<int> > levelOrder(TreeNode* A) {
    std::vector<std::vector<int> > returnValue;
    std::queue<TreeNode*> q;
    q.push(A);
    while(!q.empty()){
        int currLevelNodeSize = q.size();
        std::vector<int> temp(currLevelNodeSize);
        int tempIndex = 0;
        while(tempIndex<currLevelNodeSize){
            TreeNode* currNode = q.front();
            q.pop();
            if(currNode->left){
                q.push(currNode->left);
            }
            if(currNode->right){
                q.push(currNode->right);
            }
            temp[tempIndex] = currNode->val;
            ++tempIndex;
        }
        returnValue.push_back(temp);   
    }
    return returnValue;
}