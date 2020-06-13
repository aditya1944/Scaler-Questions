#include<vector>
#include<iostream>
#include<climits>
int solve(std::vector<int> &A, int B, int C, int D){
    //element of choice either take it or not
   std::vector<int> leftArray(A.size(),0),rightArray(A.size(),0);
   leftArray[0] = B*A[0];
   for(int index = 1;index<A.size();++index){
       leftArray[index] = std::max(leftArray[index-1],B*A[index]);
   }
   rightArray[rightArray.size()-1] = D*A[A.size()-1];
   for(int index = A.size()-2;index>=0;--index){
       rightArray[index] = std::max(rightArray[index+1],A[index]*D);
   }
   //leftAray and rightArray done
   int ans = INT_MIN;
   for(int index = 0;index<A.size();++index){
       ans = std::max(ans,leftArray[index] + C*A[index] + rightArray[index]);
   }
   return ans;
}
int main(){
    int N,B,C,D;
    std::cin>>N;
    std::vector<int> vec(N);
    for(int index = 0;index<N;++index){
        std::cin>>vec[index];
    }
    std::cin>>B>>C>>D;
    int output = solve(vec,B,C,D);
    std::cout<<output<<std::endl;
    return 0;
}