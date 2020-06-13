#include<iostream>
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL){}
};
ListNode* solve(ListNode *head){
    ListNode *temp = head;
    while(temp!=NULL){
        if(temp->next && temp->val==temp->next->val){
            //then there is duplicates
            //1->2->3->3->4
            ListNode *ptr = temp->next;
            temp->next = ptr->next;
            free(ptr);
        }
        else{
            temp = temp->next;
        }
        //temp = temp->next;
    }
    return head;
}
int main(){
    ListNode *head = new ListNode(1);
    ListNode *l0 = new ListNode(1);
    ListNode *l1 = new ListNode(2);
    ListNode *l2 = new ListNode(3);
    ListNode *l3 = new ListNode(4);
    ListNode *l4 = new ListNode(4);
    ListNode *l5 = new ListNode(6);
    ListNode *l6 = new ListNode(7);
    ListNode *l7 = new ListNode(7);
    ListNode *l8 = new ListNode(7);
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