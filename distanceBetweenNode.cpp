#include<iostream>
#include<queue>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* findLCA(TreeNode* root, int B, int C){
    if(!root){
        return NULL;
    }
    if(root->val>B && root->val<C){
        //found it
        return root;
    }
    else if(root->val==B || root->val==C){
        return root;
    }
    TreeNode *returnValue;
    if(root->val<B){
        returnValue = findLCA(root->right,B,C);
    }
    else if(root->val>C){
        returnValue = findLCA(root->left, B,C);
    }
    return returnValue;
}
int solve(TreeNode* A, int B, int C){
    //find lowest common ancestor of B and C;
    int distance = 0;
    TreeNode *root = findLCA(A,B,C);
    //from root find distance of A and B;
    //use level order traversal
    //total distance will be distance of A + distance of B;
    std::queue<TreeNode*> q;
    q.push(root);
    bool Bfound = false,Cfound =false;
    int Bdistance = 0,Cdistance = 0;
    int level = -1;
    while(!q.empty()){
        int currLevelSize = q.size();
        int index = 0;
        ++level;
        while(index<currLevelSize){
            TreeNode* currNode = q.front();
            q.pop();
            if(!Bfound&&currNode->val==B){
                Bfound = true;
                Bdistance = level;
            }
            if(!Cfound&&currNode->val==C){
                Cfound = true;
                Cdistance = level;
            }
            ++index;
        }
        if(Bfound && Cfound){
            break;
        }   
    }
    distance = Bdistance + Cdistance;
    return distance;
}