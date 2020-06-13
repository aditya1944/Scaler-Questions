#include<iostream>
#include<unordered_map>
#include<vector>
struct Node{
    Node *left,*right;
    //std::unordered_map<char, Node*> hashMap;
};
bool exists(Node* head, std::vector<int> &vec){
    bool isNewNodeMade = false;
    for(int val: vec){
        if(!val){
            //val is 0;
            if(head->left){
                head = head->left;
            }
            else{
                head->left = new Node();
                isNewNodeMade = true;
            }
        }
        else{
            //val is 1;
            if(head->right){
                head = head->right;
            }
            else{
                head->right = new Node();
                isNewNodeMade = true;
            }
        }
    }
    if(isNewNodeMade){
        return false;
    }
    else{
        return true;
    }
}
std::vector<int> solve(std::vector<std::vector<int> > &matx){
    Node *head = NULL;
    int index = 0;
    std::vector<int> duplicateRowIndex;
    for(auto vec: matx){
        //vec has vector
        if(exists(head,vec)){
            duplicateRowIndex.push_back(index);
        }
    }
    return duplicateRowIndex;
}
int main(){
    std::vector<std::vector<int> > matx(5,std::vector<int>(5,0));
    //function 
    return 0;
}