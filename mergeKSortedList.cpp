#include<iostream>
#include<vector>
#include<queue>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
struct compare{
    bool operator()(const ListNode* l1, const ListNode* l2){
        if(l1->val>l2->val){
            return true;
        }
    }
};

ListNode* mergeKLists(std::vector<ListNode*> &A){
    std::priority_queue<ListNode*,std::vector<ListNode*>, compare> minHeap;
    const int size = A.size();
    for(int index = 0;index<A.size();++index){
        minHeap.push(A[index]);
    }
    bool isHead = true;
    ListNode* head = NULL,*temp;
    while(!minHeap.empty()){
        if(isHead){
            isHead = false;
            head = minHeap.top();
            temp = head;
            if(temp->next){
                minHeap.push(head->next);
            }
        }
        else{
            temp->next = minHeap.top();
            minHeap.pop();
            temp = temp->next;
            if(temp->next){
                minHeap.push(temp->next);
            }
        }
    }
    return head;
}