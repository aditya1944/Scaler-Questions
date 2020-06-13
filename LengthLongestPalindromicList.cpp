#include<iostream>
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
int palindromeLength(ListNode *ptr1, ListNode* ptr2){
    if(!ptr1 || !ptr2){
        return 0;
    }
    if(ptr1->val==ptr2->val){
        return 2 + palindromeLength(ptr1->next, ptr2->next);
    }
    return 0;
}
int solve(ListNode* A){
    int maxLength = 1;
    ListNode *reverseHead = NULL, *temp = A, *reverseTemp = NULL;
    bool flag = false;//true for even length and false for odd Length
    while(temp != NULL){
        int length1 = palindromeLength(reverseHead, temp);
        reverseTemp = reverseHead;
        reverseHead = temp;
        temp = temp->next;
        reverseHead->next = reverseTemp;
        int length2 = 1 + palindromeLength(reverseTemp,temp);
        maxLength = std::max(maxLength,std::max(length1,length2));
    }
    /*while(reverseHead){
        std::cout<<reverseHead->val<<" ";
        reverseHead = reverseHead->next;
    }*/
    return maxLength;
}
int main(){
    ListNode *l1 = new ListNode(2);
    ListNode *l2 = new ListNode(1);
    ListNode *l3 = new ListNode(2);
    ListNode *l4 = new ListNode(1);
    ListNode *l5 = new ListNode(2);
    ListNode *l6 = new ListNode(2);
    ListNode *l7 = new ListNode(1);
    ListNode *l8 = new ListNode(3);
    ListNode *l9 = new ListNode(2);
    ListNode *l10 = new ListNode(2);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    l5->next = l6;
    l6->next = l7;
    l7->next = l8;
    l8->next = l9;
    l9->next = l10;
    std::cout<<solve(l1);
    return 0;
}