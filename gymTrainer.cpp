#include<unordered_map>
#include<vector>
#include<unordered_set>
#include<iostream>
#define mod 1000000007
class DisJointSet{
    class Node{
        public:
            size_t vertex;
            Node *parent;
            size_t rank;
    };
    std::unordered_map<size_t, Node*> hashMap;
    public:
        void makeSet(size_t vertex){
            Node *newNode = new Node();
            newNode->vertex = vertex;
            newNode->parent = newNode;
            newNode->rank = 0;
            hashMap[vertex] = newNode;
        }
        void unionSet(size_t v1, size_t v2){
            Node *l1 = findLeader(v1);
            Node *l2 = findLeader(v2);
            if(l1==l2){
                return ;
            }
            if(l1->rank>l2->rank){
                l2->parent = l1;
            }
            else if(l1->rank==l2->rank){
                l2->parent = l1;
                ++(l1->rank);
            }
            else{
                l1->parent = l2;
            }
        }
        Node* findLeader(size_t vertex){
            Node *node = hashMap[vertex];
            if(!node){
                std::cout<<std::endl;
                std::cout<<vertex<<std::endl;
                return node;
            }
            if(node->parent==node){
                return node;
            }
            node->parent = findLeader(node->parent->vertex);
            return node->parent;
        }
        bool compareLeader(size_t v1, size_t v2){
            if(findLeader(v1)==findLeader(v2)){
                return true;
            }
            return false;
        }
        int findLeaderVertex(size_t vertex){
            return findLeader(vertex)->vertex;
        }
        bool ifExists(int vertex){
            if(!hashMap[vertex]){
                return false;
            }
            return true;
        }
        ~DisJointSet(){
            for(auto val:hashMap){
                delete val.second;
            }
        }
};
size_t fastMul(size_t base, size_t pow){
    if(pow==1){
        return base;
    }
    if(pow==0){
        return 1;
    }
    if(pow%2==0){
        size_t smallAns = fastMul(base,pow/2);
        size_t returnValue = ((long long)smallAns * (long long)smallAns)%mod;
        return returnValue;
    }
    if(pow%2!=0){
        size_t smallAns = ((long long)base * (long long)fastMul(base,pow-1))%mod;
        return smallAns;
    }
}
int solve(int A, std::vector<std::vector<int> > &B, std::vector<std::vector<int> > &C) {
    std::unordered_set<size_t> hash;
    DisJointSet *set = new DisJointSet();
    for(int person = 1;person<=A;++person){
        set->makeSet(person);
    }
    for(size_t index = 0;index<B.size();++index){
        //store all B vertices in hash
        hash.insert(B[index][0]);
        hash.insert(B[index][1]);
        set->unionSet(B[index][0],B[index][1]);
    }
    for(size_t index = 0;index<C.size();++index){
        if(hash.find(C[index][0])!=hash.end() || hash.find(C[index][1])!=hash.end()){
            return 0;
        }
        set->unionSet(C[index][0],C[index][1]);
    }
    std::unordered_set<size_t> totalSets;
    //calculate no. of sets in walkingFriends and talkingFriends
    //ans will be totalNo.of Sets * 2;
    for(size_t index = 0;index<C.size();++index){
        if(hash.find(C[index][0])!=hash.end() || hash.find(C[index][1])!=hash.end()){
            return 0;
        }
        set->unionSet(C[index][0],C[index][1]);
    }
    hash.clear();
    //calculate no. of sets in walkingFriends and talkingFriends
    //ans will be totalNo.of Sets * 2;
    for(size_t person = 1;person<=A;++person){
        hash.insert(set->findLeaderVertex(person));
    }
    //return 2^N;
    size_t returnValue = fastMul(2,hash.size());
    return returnValue;
}
int main(){
    //int A = 4;
    std::vector<std::vector<int> > B = {{1,5},{4,6},{18,3},{4,5},{15,9},{15,4}},C = {{13,20},{7,20},{8,19},{13,7},{13,8},{2,19}};
    solve(20,B,C);
    return 0;
}