#include<iostream>
struct ListNode {
    int val;
    ListNode *right,*down;
    ListNode(int x) {
        val = x;
        right = down = NULL;
    }
};
ListNode* merge(ListNode * A, ListNode* B){
    //merge two sorted Linked List;
    //use down pointer
    if(!A){
        return B;
    }
    if(!B){
        return A;
    }
    //use two pointer
    ListNode *head = NULL;
    if(A->val<=B->val){
        head = A;
        A->down = merge(A->down, B);
    }
    else{
        head = B;
        B->down = merge(A->down, B);
    }
    return head;
}
ListNode* flatten (ListNode* root) {
    if(!root || !(root->right)){
        return root;
    }
    flatten(root->right);
    return merge(root, root->right);
    //return root;
}