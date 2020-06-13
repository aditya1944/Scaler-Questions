#include<iostream>
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
 
 
int findFreq(ListNode **curr, int val){
    if((*curr)->val==val){
        *curr = (*curr)->next;
        return 1 + findFreq(curr,val);
    }
    else{
        return 0;
    }
}
ListNode* deleteDuplicates(ListNode* A) {
    if(!A){
        return A;
    }
    ListNode *curr = A;
    ListNode *newHead=NULL, *newTemp = NULL;
    while(curr!=NULL){
        int val = curr->val;
        ListNode *temp1 = curr;
        ListNode **temp = &curr;
        int freq = findFreq(temp, val);
        if(freq==1){
            if(!newHead){
                newHead = newTemp = temp1;
            }
            else{
                newTemp->next = temp1;
                newTemp = newTemp->next;
            }
            newTemp->next = NULL;
        }
    }
    return newHead;
}