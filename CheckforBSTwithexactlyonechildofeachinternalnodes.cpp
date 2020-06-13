#include<vector>
#include<iostream>
std::string solve(std::vector<int> &A) {
    for(int index = 0;index<A.size();++index){
        int currNode = A[index];
        int nextNode = A[index+1];
        int lastNode = A[A.size()-1];
        int diff1 = currNode - nextNode;
        int diff2 = currNode - lastNode;
        if(diff1*diff2<0){
            return "NO";
        }
    }
    return "YES";
}