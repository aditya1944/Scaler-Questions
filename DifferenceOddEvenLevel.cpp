#include<vector>
#include<queue>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int solve(TreeNode* A){
    //maintain track at every level
    //firstLevel is odd
    bool oddLevel = true;
    int oddLevelSum = 0,evenLevelSum = 0;
    std::queue<TreeNode*> q;
    q.push(A);
    while(!q.empty()){
        if(oddLevel){
            int currLevelSize = q.size();
            int index = 0;
            while(index<currLevelSize){
                TreeNode* currNode = q.front();
                q.pop();
                oddLevelSum+=currNode->val;
                if(currNode->left){
                    q.push(currNode->left);
                }
                if(currNode->right){
                    q.push(currNode->right);
                }
                ++index;
            }
            oddLevel = false;
        }
        else{
            int currLevelSize = q.size();
            int index = 0;
            while(index<currLevelSize){
                TreeNode* currNode = q.front();
                q.pop();
                evenLevelSum+=currNode->val;
                if(currNode->left){
                    q.push(currNode->left);
                }
                if(currNode->right){
                    q.push(currNode->right);
                }
                ++index;
            }
            oddLevel = true;
        }
    }
    return oddLevelSum-evenLevelSum;
}