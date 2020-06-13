#include<iostream>
struct ListNode{
    int val;
    ListNode *next;
};
ListNode* solve(ListNode* A, int B){
    ListNode *end = A,*start = A,*prev = A;
    int count = 0;
    while(end!=NULL && count!=B){
        end = end->next;
        if(end==NULL){
            A = A->next;
            free(start);
            return A;
        }
        ++count;
    }
    while(end!=NULL){
        prev = start;
        start = start->next;
        end = end->next;
    }
    //start is at the desired position
    //prev is one step before
    //if prev==start then it is only item in list;
    if(prev==start){
        A =  NULL;
    }
    else if(start->next==NULL){
        //this is last node
        prev->next = NULL;
        delete(start);
    }
    else{
        //this is in between node
        prev->next = start->next;
        delete(start);
    }
    return A;
}