#include<iostream>
#include<queue>
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
void connect(TreeLinkNode* A){
    std::queue<TreeLinkNode*> q;
    q.push(A);
    while(!q.empty()){
        int sizeOfCurrentLevel = q.size();
        int index = 0;
        while(index<sizeOfCurrentLevel){
            TreeLinkNode* currNode = q.front();
            q.pop();
            if(sizeOfCurrentLevel-index==1){
                currNode->next = NULL;
            }
            else{
                currNode->next = q.front();
            }
            if(currNode->left){
                q.push(currNode->left);
            }
            if(currNode->right){
                q.push(currNode->right);
            }
            ++index;
        }
    }
    return;
}