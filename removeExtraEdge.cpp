#include<iostream>
#include<unordered_set>
#include<vector>
//incorrect ans will do again
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void helper(std::unordered_set<size_t> &hash,TreeNode* A,int &duplicatedNodeVal){
    if(!A || duplicatedNodeVal!=-1){
        return;
    }
    hash.insert(A->val);
    if(A->left && hash.find(A->left->val)!=hash.end()){
        duplicatedNodeVal = A->left->val;
        return;
    }
    if(A->right && hash.find(A->right->val)!=hash.end()){
        duplicatedNodeVal = A->right->val;
        return;
    }
    helper(hash,A->left,duplicatedNodeVal);
    helper(hash,A->right,duplicatedNodeVal);
}
void findParent(int duplicatedNodeVal, TreeNode* A,std::vector<TreeNode*> &parents){
    if(!A){
        return;
    }
    if(A->left && A->left->val==duplicatedNodeVal){
        parents.push_back(A);
    }
    if(A->right && A->right->val==duplicatedNodeVal){
        parents.push_back(A);
    }
    findParent(duplicatedNodeVal,A->left,parents);
    findParent(duplicatedNodeVal,A->right,parents);
}
void deleteNode(TreeNode* A,TreeNode* parentNode, int duplicatedNodeVal){
    if(!A || duplicatedNodeVal==-1){
        return;
    }
    if(A==parentNode){
        //this is it
        //check whether left or right pointer points to duplicatedNode
        if(A->left && A->left->val==duplicatedNodeVal){
            A->left = NULL;
        }
        else if(A->right && A->right->val==duplicatedNodeVal){
            A->right = NULL;
        }
        duplicatedNodeVal = -1;
        return;
    }
    deleteNode(A->left,parentNode, duplicatedNodeVal);
    deleteNode(A->right,parentNode,duplicatedNodeVal);
}
TreeNode* solve(TreeNode* A){
    //step 1  first find which node is duplicated
    //by using hash
    //traverse again and keep track of the parent of the duplicated node(there would be two parents)
    //
    std::unordered_set<size_t> hash;
    int duplicatedNodeVal = -1;
    helper(hash,A,duplicatedNodeVal);
    //duplicated Node is done
    std::vector<TreeNode*> parents;
    findParent(duplicatedNodeVal, A,parents);
    //we have parents
    if(parents[0]->val>parents[1]->val){
        //find the parents[0] and delete duplicated Node(can exists in both left and right child)
        deleteNode(A,parents[0],duplicatedNodeVal);
    }
    else{
        //find the parent[1] and delete duplicated Node(can exists in both left and right child)
        deleteNode(A,parents[1],duplicatedNodeVal);
    }
    return A;
}