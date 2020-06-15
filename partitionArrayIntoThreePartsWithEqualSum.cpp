#include<iostream>
#include<vector>
#include<numeric>
bool solve(std::vector<int> &A){
   int totalSum = std::accumulate(A.begin(),A.end(),0);
    if(totalSum%3!=0){
        return false;
    }
    int requiredSum = totalSum/3,currentSum=0;
    bool firstBoundary = false,secondBoundary = false;
    int index = 0;
    for(;index<A.size();++index){
        currentSum += A[index];
        if(currentSum==requiredSum){
            firstBoundary = true;
            break;
        }
    }
    currentSum=0;
    for(++index;index<A.size();++index){
        currentSum+=A[index];
        if(currentSum==requiredSum){
            if(index==A.size()-1){
                return false;
            }
            secondBoundary = true;
            break;
        }
    }
    //cout<<firstBoundary<<" "<<secondBoundary<<endl;
    bool returnValue = firstBoundary & secondBoundary;
    return returnValue;
}