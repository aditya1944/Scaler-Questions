#include<iostream>
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL){}
};
ListNode* reverse(ListNode *head){
    ListNode *prev = NULL, *next = NULL,*curr = head;
    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
void merge(ListNode *head, ListNode *head2){
    bool flag = true;
    ListNode *l1 = head,*l2 = head2; 
    while(l1!=NULL && l2!=NULL){
        ListNode *temp = l2;
        l2 = l2->next;
        temp->next = l1->next;
        l1->next = temp;
        l1 = temp->next;
    }
}
ListNode* solve(ListNode *head){
    //find mid of linked List
    ListNode *ptr1 = head,*ptr2 = head;
    while(ptr2!=NULL && ptr2->next !=NULL ){
        ptr1 = ptr1->next;
        ptr2 = ptr2->next->next;
    }
    ListNode *head2 = ptr1->next;
    ptr1->next = NULL;
    //now you have two linked list pointed by head1 and head2
    head2 = reverse(head2);
    merge(head,head2);
    return head;
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