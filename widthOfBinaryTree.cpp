#include<iostream>
#include<queue>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
struct Node{
    TreeNode* node;
    int index;
};
int widthOfBinaryTree(TreeNode* root){
    if(!root){
        //root is null;
        return 0;
    }
    std::queue<Node> q;
    Node node;
    node.node = root;
    node.index = 0;
    q.push(node);
    long double maxWidth = 0;
    int maxIndex = 0;
    while(!q.empty()){
        int levelSize = q.size();
        long double startIndex,endIndex;
        for(int i = 1;i<=levelSize;++i){
            Node currNode = q.front();
            q.pop();
            if(i==1){
                startIndex = currNode.index;
            }
            if(i==levelSize){
                endIndex = currNode.index;
            }
            if(currNode.node->left){
                node.node = currNode.node->left;
                node.index = 2 * (long double)currNode.index;
                q.push(node);
            }
            if(currNode.node->right){
                node.node = currNode.node->right;
                node.index = 2 * (long double)currNode.index+1;
                q.push(node);
            }
        }
        //std::cout<<endIndex - startIndex + 1<<endl;
        maxWidth = std::max(maxWidth,endIndex - startIndex + 1);
    }
    return maxWidth;
}