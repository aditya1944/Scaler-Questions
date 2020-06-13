#include<iostream>
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL){}
};
ListNode* solve(ListNode *head){
    ListNode *ptr1 = head,*ptr2 = head;
    while(ptr2!=NULL && ptr2->next!=NULL){
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
        ptr2 = ptr2->next;
    }
    return ptr1;
}
int main(){
    ListNode *head = new ListNode(1);
    ListNode *l0 = new ListNode(2);
    ListNode *l1 = new ListNode(3);
    ListNode *l2 = new ListNode(4);
    ListNode *l3 = new ListNode(5);
    ListNode *l4 = new ListNode(6);
    ListNode *l5 = new ListNode(7);
    ListNode *l6 = new ListNode(8);
    ListNode *l7 = new ListNode(9);
    ListNode *l8 = new ListNode(10);
    head->next = l0;
    l0->next = l1;
    l1->next = l2;
    l2->next - l3;
    l3->next = l4;
    l4->next = l5;
    l5->next = l6;
    l6->next = l7;
    l7->next = l8;
    ListNode *output = solve(head);
    while(output){
        std::cout<<output->val<<" ";
        output = output->next;
    }
    return 0;
}