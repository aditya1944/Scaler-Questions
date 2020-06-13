#include<iostream>
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL){}
};
ListNode* reverse(ListNode *head, int length){
    if(length==1){
        return head;
    }
    /*else if(length==2){
        ListNode *ptr1 = head;
        ListNode *ptr2 = head->next;
        ptr2->next = ptr1;
        ptr1->next = NULL;
        return ptr2;
    }*/
    //std::cout<<head->val<<"C";
    ListNode *prev = NULL, *curr = head, *next = NULL;
    int count = 0;
    while(curr!=NULL && count<length){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        ++count;
    }
    ListNode *temp = prev;
    /*if(temp==NULL){
        std::cout<<"CSDcsdc";
    }
    while(temp){
        std::cout<<temp->val<<"a ";
        temp = temp->next;
    }*/
    //std::cout<<std::endl;
    return prev;
}
ListNode* solve(ListNode *head, int start, int end){
    int count = 1;
    ListNode *beforeStart = NULL, *afterEnd = NULL, *windowHead, *temp = head;
    while(temp!=NULL && count<=end+1){
        //std::cout<<"csscscs";
        if(count==start-1){
            beforeStart =  temp;
        }
        if(count==start){
            windowHead = temp;
        }
        if(count==end+1){
            afterEnd = temp;
        }
        ++count;
        temp = temp->next;
    }
    /*if(beforeStart)
        std::cout<<beforeStart->val<<std::endl;
    std::cout<<windowHead->val<<std::endl;
    if(afterEnd)
        std::cout<<afterEnd->val<<std::endl;*/
    int length = end-start+1;
    if(start==1){
        ListNode *head1 = reverse(head, length);
        head->next = afterEnd;
        return head1;
    }
    beforeStart->next = reverse(windowHead,length);
    windowHead->next = afterEnd;
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
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    l5->next = l6;
    l6->next = l7;
    l7->next = l8;
    /*while(head){
        std::cout<<head->val<<" ";
        head = head->next;
    }*/
    int start,end;
    std::cin>>start>>end;
    ListNode *output = solve(head,start,end);
    while(output){
        std::cout<<output->val<<" ";
        output = output->next;
    }
    return 0;
}