#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
bool compare(const std::vector<int> &v1, const std::vector<int> &v2){
    return v1[2]<v2[2];
}
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
};
int solve(int A, std::vector<std::vector<int> > &B){
    std::sort(B.begin(),B.end(),compare);
    DisJointSet *set = new DisJointSet();
    for(size_t vertex = 1;vertex<=A;++vertex){
        set->makeSet(vertex);
    }
    int edgeIndex = 0;
    int noOfEdges = 0;
    int minWeight = 0;
    while(noOfEdges<A-1){
        std::vector<int> edge = B[edgeIndex];
        size_t startVertex = (size_t)edge[0];
        size_t endVertex = (size_t)edge[1];
        if(!(set->compareLeader(startVertex,endVertex))){
            //they do not belongs to same set
            set->unionSet(startVertex,endVertex);
            ++noOfEdges;
            minWeight+=edge[2];
        }
        ++edgeIndex;
    }
    return minWeight;
}
int main(){
    /*DisJointSet *set = new DisJointSet();
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