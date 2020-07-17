#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<queue>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
std::vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
    std::vector<int> returnValue;
    if(K==0){
        returnValue.push_back(target->val);
        return returnValue;
    }
    //convert tree in graph;
    std::unordered_map<int, std::vector<int> > adjacencyList;
    helper(root,adjacencyList);
    //graph made
    //do bfs
    returnValue = bfs(target->val,K,adjacencyList);
    return returnValue;
}
std::vector<int> bfs(int root,int K ,std::unordered_map<int, std::vector<int> > &adjacencyList){
    std::queue<int> q;
    q.push(root);
    std::vector<int> returnValue;
    int level = 0;
    std::unordered_set<int> visited;
    visited.insert(root);
    while(!q.empty()){
        int levelSize = q.size();
        while(levelSize--){
            int topNode = q.front();
            q.pop();
            for(int neighbourNode: adjacencyList[topNode]){
                if(visited.find(neighbourNode)!=visited.end()){
                    //this node is visited
                    continue;
                }
                if(level==K-1){
                    returnValue.push_back(neighbourNode);
                }
                else{
                    q.push(neighbourNode);
                }
                visited.insert(neighbourNode);
            }
        }
        ++level;
        if(level==K){
            break;
        }
    }
    return returnValue;
}
void helper(TreeNode* root,std::unordered_map<int, std::vector<int> > &adjacencyList){
    //do a travesal
    if(!root){
        return;
    }
    //root is not null
    if(root->right){
        adjacencyList[root->val].push_back(root->right->val);
        adjacencyList[root->right->val].push_back(root->val);
        helper(root->right,adjacencyList);
    }
    if(root->left){
        adjacencyList[root->val].push_back(root->left->val);
        adjacencyList[root->left->val].push_back(root->val);
        helper(root->left,adjacencyList);
    }
}