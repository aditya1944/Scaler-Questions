#include<vector>
#include<iostream>
#include<queue>
#include<algorithm>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
std::vector<std::vector<int> > zigzagLevelOrder(TreeNode* A){
    std::vector<std::vector<int> > returnValue;
    std::queue<TreeNode*> q;
    q.push(A);
    bool flag = true;
    while(!q.empty()){
        if(flag){
            int size = q.size();
            std::vector<int> currentLevel(size);
            int index = 0;
            while(index<size){
                currentLevel[index] = q.front()->val;
                if(q.front()->right){
                    q.push(q.front()->right);
                }
                if(q.front()->left){
                    q.push(q.front()->left);
                }
                q.pop();
                ++index;
            }
            std::reverse(currentLevel.begin(),currentLevel.end());
            returnValue.push_back(currentLevel);
            flag = false;
        }
        else{
            int size = q.size();
            std::vector<int> currentLevel(size);
            int index = 0;
            while(index<size){
                currentLevel[index] = q.front()->val;
                if(q.front()->right){
                    q.push(q.front()->right);
                }
                if(q.front()->left){
                    q.push(q.front()->left);
                }
                q.pop();
                ++index;
            }
            //std::reverse(currentLevel.begin(),currentLevel.end());
            returnValue.push_back(currentLevel);
            flag = false;
            flag = true;
        }
    }
    return returnValue;
}