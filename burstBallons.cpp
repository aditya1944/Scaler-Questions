#include<iostream>
#include<vector>
#include<climits>
int helper(std::vector<int> &A, int &maxValue){
    const int n = A.size();
    for(int index = 0;index<A.size();++index){
        //delete the element at currIndex;
        int currVal = A[index];
        int prev,next;
        if(index-1==0){
            prev = 1;
        }
        else{
            prev = A[index-1];
        }
        if(index+1==n){
            next = 1;
        }
        else{
            next = A[index+1];
        }
        A.erase(A.begin()+index);
        currVal+=helper(A,maxValue);
        maxValue = std::max(maxValue,currVal);
    }
}
int solve(std::vector<int> &A){
    int maxValue = INT_MIN;
    helper(A,maxValue);
    return maxValue;
}
int main(){
    int N;
    std::cin>>N;
    std::vector<int> vec(N);
    int output = solve(vec);
    std::cout<<output<<std::endl;
    return 0;
}