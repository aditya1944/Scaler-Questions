#include<iostream>
#include<climits>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//returns pair first value is min Value and second Value is max Value;
std::pair<int, int> helper(TreeNode* root, bool &isValid){
    if(!isValid){
        std::pair<int, int> dummy;
        return dummy;
    }
    if(!root){
        //root is null;
        std::pair<int, int> p;
        p.first = INT_MAX;
        p.second = INT_MIN;
        return;
    }
    //check validity here
    std::pair<int, int> leftPair = helper(root->left, isValid);
    std::pair<int, int> rightPair = helper(root->left, isValid);

    if(leftPair.second>root->val || rightPair.first<root->val){
        isValid = false;
        std::pair<int, int> dummy;
        return dummy;
    }
    std::pair<int, int> returnValue;
    returnValue.first = std::min(root->val, leftPair.first);
    returnValue.second = std::max(root->val, rightPair.second);
    return returnValue;
}
int isValidBST(TreeNode* A) {
    bool isValid = true;
    helper(A,isValid);
    return isValid;
}