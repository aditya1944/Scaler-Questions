#include<vector>
#include<queue>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
std::vector<int> solve(TreeNode* A){
    std::vector<int> returnValue;
    std::queue<TreeNode*> q;
    q.push(A);
    while(!q.empty()){
        int currLevelSize = q.size();
        int index = 0;
        bool isFirst=true;
        while(index<currLevelSize){
            TreeNode* currNode = q.front();
            if(isFirst){
                returnValue.push_back(currNode->val);
                isFirst = false;
            }
            if(currNode->left){
                q.push(currNode->left);
            }
            if(currNode->right){
                q.push(currNode->right);
            }
            q.pop();
            ++index;
        }
    }
    return returnValue;
}