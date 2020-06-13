#include<iostream>
#include<vector>
#include<queue>
struct Node{
    int numerator,denominator;
    int numeratorIndex;
    int denominatorIndex;
};
struct compare{
    bool operator()(const Node& node1,const Node& node2){
        //this compare function works for maxHeap;
        Node n1 = node1,n2 = node2;
        if(n1.denominator==n2.denominator){
            //one with larger numerator is larger
            return n1.numerator>n2.numerator;
        }
        else{
            //denominator is not same;
            //make thier denominator same;
            n1.denominator = node1.denominator*node2.denominator;
            n2.denominator = node2.denominator*node1.denominator;
            n1.numerator = n1.numerator*node2.denominator;
            n2.numerator = n2.numerator*node1.denominator;
            return n1.numerator>n2.numerator;
        }
    }
};
std::vector<int> solve(std::vector<int> &A, int B){
    std::priority_queue<Node, std::vector<Node> ,compare> minHeap;
    for(int i = 0;i<A.size()-1;++i){
        Node node;
        node.numerator = A[i];
        node.denominator = A[A.size()-1];
        node.numeratorIndex = i;
        node.denominatorIndex = A.size()-1;
        //std::cout<<node.numerator<<" "<<node.denominator<<std::endl;
        minHeap.push(node);
    }
    Node popedNode;
    int count = 1;
    while(count<=B){
        popedNode = minHeap.top();
        //std::cout<<popedNode.numerator<<" "<<popedNode.denominator<<std::endl;
        if(count==B){
            break;
        }
        minHeap.pop();
        Node newNode;
        int newDenominatorIndex = popedNode.denominatorIndex-1;
        if(newDenominatorIndex==popedNode.numeratorIndex){
            // do not insert
            ++count;
            continue;
        }
        newNode.denominatorIndex = newDenominatorIndex;
        newNode.numerator = popedNode.numerator;
        newNode.denominator = A[newNode.denominatorIndex];
        minHeap.push(newNode);
        ++count;
    }
    std::vector<int> returnValue={popedNode.numerator,popedNode.denominator};
    return returnValue;
}
int main(){
    int N,B;
    std::cin>>N;
    std::vector<int> arr(N);
    for(int index = 0;index<N;++index){
        std::cin>>arr[index];
    }
    std::cin>>B;
    std::vector<int> output = solve(arr,B);
    std::cout<<output[0]<<" "<<output[1]<<std::endl;
    return 0;
}