#include<iostream>
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int _val){
        val = _val;
    }
};
ListNode* reverse(ListNode* head){
    if(!head){
        return NULL;
    }
    if(!head->next){
        return head;
    }
    ListNode* prev = NULL,*curr = head, *next = NULL;
    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    curr = NULL;
    next = NULL;
    delete(curr);
    delete(next);
    return prev;
}
ListNode* merge(ListNode* oddHead, ListNode* evenHead){
    ListNode* newHead = oddHead;
    ListNode* newNode = newHead;
    bool isFlag = true;
    oddHead = oddHead->next;
    while(oddHead && evenHead){
        if(isFlag){
            newNode->next = evenHead;
            evenHead = evenHead->next;
            newNode = newNode->next;
            newNode->next = NULL;
        }
        else{
            newNode->next = oddHead;
            oddHead = oddHead->next;
            newNode = newNode->next;
            newNode->next = NULL;
        }
        isFlag = isFlag^1;
    }
    if(oddHead){
        newNode->next = oddHead;
    }
    if(evenHead){
        newNode->next = evenHead;
    }
    oddHead = NULL;
    evenHead = NULL;
    delete(oddHead);
    delete(evenHead);
    return newHead;
}
ListNode* solve(ListNode*node){
    if(!node){
        return NULL;
    }
    if(!node->next){
        return node;
    }
    ListNode* evenHead = NULL,*evenNode = NULL,*oddHead = NULL,*oddNode = NULL;
    int index = 1;
    while(node){
        if(index%2==0){
            //this is even Node;
            if(!evenHead){
                evenHead = evenNode = node;
            }
            else{
                evenNode->next = node;
                evenNode = evenNode->next;
                
            }
            node = node->next;
            evenNode->next = NULL;
        }
        else{
            if(!oddHead){
                oddHead = oddNode = node;
            }
            else{
                oddNode->next = node;
                oddNode = oddNode->next;
            }
            node = node->next;
            oddNode->next = NULL;
        }
        ++index;
    }
    oddNode = NULL;
    evenNode = NULL;
    delete(oddNode);
    delete(evenNode);
    /*while(evenNode){
        std::cout<<evenNode->val<<" ";
        evenNode = evenNode->next;
    }*/
    evenHead = reverse(evenHead);
    ListNode* temp = evenHead;
    ListNode* newList = merge(oddHead,evenHead);
    return newList;
}
int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    ListNode *returnValue = solve(head);
    while(returnValue){
        std::cout<<returnValue->val<<" ";
        returnValue = returnValue->next;
    }
    return 0;
}