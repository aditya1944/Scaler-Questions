#include<iostream>
#include<vector>
#include<unordered_map>
class DisjointSet{
    class Node{
        public:
            size_t val;
            Node *parent;
            size_t rank;
            Node(size_t _val){
                val = _val;
                rank = 0;
            }
    };
    std::unordered_map<size_t, Node*> hashMap;
    public:
        void makeSet(size_t val){
            if(hashMap.find(val)!=hashMap.end()){
                //val is already in some set
                return;
            }
            Node *node = new Node(val);
            node->parent = node;
            hashMap[val] = node;
        }
        void unionSet(size_t v1, size_t v2){
            Node* l1 = getLeader(v1),*l2 = getLeader(v2);
            if(l1==l2){
                return;
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
        Node* getLeader(size_t val){
            Node *node = hashMap[val];
            if(node->parent==node){
                return node;
            }
            node->parent = getLeader(node->parent->val);
            return node->parent;
        }
        ~DisjointSet(){
            for(auto val:hashMap){
                delete val.second;
            }
        }
};
int solve(int A, std::vector<int> &B, std::vector<std::vector<int> > &C, int D){
    //calculate total no. of disjoint sets
    //then for each set calculate strength
    //if strength greater than equal to D then include that set in ans
    DisjointSet *set = new DisjointSet();
    for(int vertex = 1;vertex<=A;++vertex){
        set->makeSet(vertex);
    }
    for(int index = 0;index<C.size();++index){
        int startVertex = C[index][0];
        int endVertex = C[index][1];
        set->unionSet(startVertex,endVertex);
    }
    //now all disjoints set are made
    std::unordered_map<size_t,size_t> sets;
    for(int vertex = 1;vertex<=A;++vertex){
        size_t leader = set->getLeader(vertex)->val;
        sets[leader]+=B[vertex-1];
    }
    int ans=0;
    for(auto val:sets){
        if(val.second>=D){
            ++ans;
        }
    }
    return ans;
}
int main(){
    /*DisjointSet *set = new DisjointSet();
    set->makeSet(1);
    set->makeSet(2);
    set->makeSet(3);
    set->makeSet(4);
    set->makeSet(5);

    std::cout<<set->compareLeader(1,2)<<std::endl;
    set->unionSet(1,2);
    std::cout<<set->compareLeader(1,2)<<std::endl;
    set->unionSet(3,4);
    set->unionSet(2,4);
    std::cout<<set->compareLeader(1,3)<<std::endl;*/

}