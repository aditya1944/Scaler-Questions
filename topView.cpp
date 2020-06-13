#include<iostream>
#include<queue>
#include<unordered_map>
#include<climits>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
std::vector<int> solve(TreeNode* A) {
    // use vertical Order Traversal and first of vertical distance is ans
    std::unordered_map<int, int> hashMap;
    std::queue<std::pair<TreeNode*, int> > q;
    q.push(std::make_pair(A,0));
    int maxLeftDistance = INT_MAX;
    int maxRightDistance = INT_MIN;
    while(!q.empty()){
        std::pair<TreeNode*, int> topPair = q.front();
        TreeNode* topNode = topPair.first;
        int verticalDistanceTopNode = topPair.second;
        maxLeftDistance = std::min(verticalDistanceTopNode,maxLeftDistance);
        maxRightDistance = std::max(verticalDistanceTopNode,maxRightDistance);
        if(hashMap.find(verticalDistanceTopNode)==hashMap.end()){
            //this vertical distance is not in hashMap
            hashMap.insert(std::make_pair(verticalDistanceTopNode, topNode->val));
        }
        if(topNode->left){
            q.push(std::make_pair(topNode->left,verticalDistanceTopNode-1));
        }
        if(topNode->right){
            q.push(std::make_pair(topNode->right,verticalDistanceTopNode+1));
        }
        q.pop();
    }
    int size = maxRightDistance - maxLeftDistance + 1;
    std::vector<int> returnValue(size);
    int index = 0;
    for(auto val:hashMap){
        returnValue[index++] = val.second;
    }
    return returnValue;
}