#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<unordered_map>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
std::vector<std::vector<int> > verticalOrderTraversal(TreeNode* A) {
    if(!A){
        std::vector<std::vector<int> > returnValue;
        return returnValue;
    }
    //do level order traversal storing the distance of treenode
    
    //key is level and value is value of node
    std::unordered_map<int, std::vector<int> > hashMap;
    
    //pair contains treenode and its vertical distance
    std::queue<std::pair<TreeNode*, int> > q;
    //push root in q
    q.push(std::make_pair(A,0));
    int minVerticalDistance = INT_MAX;
    int maxVerticalDistance =INT_MIN;
    while(!q.empty()){
        std::pair<TreeNode*, int> currPair = q.front();
        q.pop();
        TreeNode* currNode = currPair.first;
        int currVerticalDistance = currPair.second;
        minVerticalDistance = std::min(minVerticalDistance,currVerticalDistance);
        maxVerticalDistance = std::max(currVerticalDistance, maxVerticalDistance);
        hashMap[currVerticalDistance].push_back(currNode->val);
        if(currNode->left){
            q.push(std::make_pair(currNode->left,currVerticalDistance-1));
        }
        if(currNode->right){
            q.push(std::make_pair(currNode->right, currVerticalDistance+1));
        }
    }
    int size = maxVerticalDistance - minVerticalDistance + 1;
    std::vector<std::vector<int> > returnValue(size);
    for(auto val:hashMap){
        int distance = val.first;
        int absoluteDistance = distance - minVerticalDistance;
        returnValue[absoluteDistance] = val.second;
    }
    return returnValue;
}