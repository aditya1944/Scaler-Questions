#include<iostream>
#include<vector>
#include<unordered_set>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
std::string helper(TreeNode* A, std::unordered_set<std::string> &hash, bool &hasDuplicates){
    if(!A){
        // A is null;
        return "";
    }
    if(!(A->left) && !(A->right)){
        //current node is leaf node
        return std::to_string(A->val);
    }
    std::string leftTree = helper(A->left,hash,hasDuplicates);
    std::string rightTree = helper(A->right,hash, hasDuplicates);
    std::string currString = leftTree + std::to_string(A->val) + rightTree;
    if(hash.find(currString)!=hash.end()){
        hasDuplicates = true;
    }
    else{
        hash.insert(currString);
    }
    return currString;
}
int solve(TreeNode* A){
    std::unordered_set<std::string> hash;
    bool hasDuplicates = false;
    helper(A,hash,hasDuplicates);
    return hasDuplicates;
}