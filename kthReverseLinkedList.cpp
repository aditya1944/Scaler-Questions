#include<iostream>
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL){}
};
ListNode* solve(ListNode *head, int K){
    int count = 1;
    ListNode *prev = NULL,*curr = head, *next = NULL;
    while(count<=K){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        ++count;   
    }
    if(next!=NULL){
        head->next = solve(next, K);
    }
    return prev;
}
int main(){
    ListNode *head = new ListNode(1);
    ListNode *l1 = new ListNode(2);
    ListNode *l2 = new ListNode(3);
    ListNode *l3 = new ListNode(4);
    ListNode *l4 = new ListNode(5);
    ListNode *l5 = new ListNode(6);
    //ListNode *l6 = new ListNode(7);
    head->next = l1;
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    //l5->next = l6;
    int K;
    std::cin>>K;
    ListNode *output = solve(head,K);
    while(output){
        std::cout<<output->val<<" ";
        output = output->next;
    }
    return 0;
}