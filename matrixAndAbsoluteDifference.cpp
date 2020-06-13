#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<climits>
#include<unordered_set>
struct Edge{
    int startVertex;
    int endVertex;
    int weight;
};
class DisJointSet{
    class Node{
        public:
            int vertex;
            int rank;
            Node *parent;
    };
    std::unordered_map<int, Node*> hashMap;
    public:
        void makeSet(int vertex){
            Node *node = new Node();
            node->vertex = vertex;
            node->rank = 0;
            node->parent = node;
            hashMap[vertex] = node;
        }
        void unionSet(int v1, int v2){
            Node *l1 = getLeader(v1);
            Node *l2 = getLeader(v2);
            if(l1==l2){
                //do nothing 
                //they belongs to same set
                return;
            }
            if(l1->rank>l2->rank){
                l2->parent = l1;
            }
            else if(l1->rank==l2->rank){
                ++(l1->rank);
                l2->parent = l1;
            }
            else{
                l1->parent = l2;
            }
        }
        Node* getLeader(int vertex){
            Node* node = hashMap[vertex];
            if(node->parent==node){
                return node;
            }
            node->parent = getLeader(node->parent->vertex);
            return node->parent;
        }
        bool compareLeader(int v1, int v2){
            /*if(l1==NULL || l2==NULL){
                //std::cout<<v1<<" "<<v2<<std::endl;
                return true;
            }*/
            if(getLeader(v1)==getLeader(v2)){
                return true;
            }
            return false;
        }

};
bool compare(const Edge &e1, const Edge &e2){
    return e1.weight<e2.weight;
}
int solve(int A, int B, std::vector<std::vector<int> > &C){
    //make an adjacencyList
    //traverse from vertex 1 to vertex A*B using shortest Path
    //use kruskal algo
    //make a disjoint class
    //vertices are A * B;
    int vertex;
    std::vector<Edge> edgeList;
    //std::cout<<"Cscscs";
    for(int rowIndex = 0;rowIndex<A-1;++rowIndex){
        vertex = rowIndex*B;
        for(int colIndex = 0;colIndex<B-1;++colIndex){
            //down Edge
            Edge downEdge;
            downEdge.startVertex = vertex;
            downEdge.endVertex = vertex+B;
            downEdge.weight = abs(C[rowIndex][colIndex] - C[rowIndex+1][colIndex]);
            edgeList.push_back(downEdge);
            //right edge
            Edge rightEdge;
            rightEdge.startVertex = vertex;
            rightEdge.endVertex = vertex+1;
            rightEdge.weight = abs(C[rowIndex][colIndex] - C[rowIndex][colIndex+1]);
            edgeList.push_back(rightEdge);
            //std::cout<<vertex<<" ";
            ++vertex;
        }
    }
    //std::cout<<"Cscscs";
    //for rightMost Vertices;
    for(int rowIndex = 0;rowIndex<A-1;++rowIndex){
        vertex = rowIndex*B + (B-1);  
        //std::cout<<vertex<<" ";   
        //down Edge
        Edge downEdge;
        downEdge.startVertex = vertex;
        downEdge.endVertex = vertex+B;
        downEdge.weight = abs(C[rowIndex][B-1] - C[rowIndex+1][B-1]);
        //right edge
        edgeList.push_back(downEdge);
    }
    //for downMost Vertices
    vertex = (A-1)*B;
    for(int colIndex = 0;colIndex<B-1;++colIndex){    
        //rightEdge Edge
        //std::cout<<vertex<<" ";
        Edge rightEdge;
        rightEdge.startVertex = vertex;
        rightEdge.endVertex = vertex+1;
        rightEdge.weight = abs(C[A-1][colIndex] - C[A-1][colIndex+1]);
        //right edge
        edgeList.push_back(rightEdge);
        ++vertex;
    }
    //edgeList is ready
    //now sort the edgeList
    std::sort(edgeList.begin(),edgeList.end(),compare);
    //there are A*B vertices
    int totalVertices = A*B;
    int requiredEdges = A*B-1;
    DisJointSet *set = new DisJointSet();
    for(int vertex = 0;vertex<totalVertices;++vertex){
        set->makeSet(vertex);
    }
    int edgeIndex = 0;
    int ans = INT_MIN;
    int noOfEdges = 0;
    while(noOfEdges<requiredEdges){
        Edge edge  = edgeList[edgeIndex];
        int startVertex = edge.startVertex;
        int endVertex = edge.endVertex;
        if(!(set->compareLeader(startVertex,endVertex))){
            //they are not in same set
            int weight = edge.weight;
            set->unionSet(startVertex,endVertex);
            ans = std::max(ans,weight);
            ++noOfEdges;
        }
        ++edgeIndex;
    }
    /*std::unordered_set<int> hash;
    for(int vertex = 0;vertex<totalVertices;++vertex){
        hash.insert(set->getLeader(vertex)->vertex);
    }
    std::cout<<hash.size()<<std::endl;*/

    return ans;
}
int main(){
    int row,col;
    std::cin>>row>>col;
    std::vector<std::vector<int> >matx(row,std::vector<int>(col,0));
    for(int rowIndex = 0;rowIndex<row;++rowIndex){
        for(int colIndex = 0;colIndex<col;++colIndex){
            std::cin>>matx[rowIndex][colIndex];
        }
    }
    std::cout<<solve(row,col,matx)<<std::endl;
    return 0;
}