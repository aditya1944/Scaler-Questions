#include<unordered_map>
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