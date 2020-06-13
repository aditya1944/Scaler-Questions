#include<iostream>
#include<vector>
int helper(const std::string &A, const std::string &B, const std::string &C, int AIndex,int BIndex, int CIndex,std::vector<std::vector<std::vector<int> > > &dp){
    //flag==true check in A
    //flag==false check in B
    if(CIndex==C.size()){
        return 1;
    }
    if(dp[AIndex][BIndex][CIndex]!=-1){
        return dp[AIndex][BIndex][CIndex];
    }
    int way1 = 0,way2 = 0;
    if(AIndex<A.size()){
        way1 = 0;
        if(A[AIndex]==C[CIndex]){
            way1 = helper(A,B,C,AIndex+1,BIndex,CIndex+1,dp);
        }
    }
    if(BIndex<B.size()){
        if(B[BIndex]==C[CIndex]){
            way2 = helper(A,B,C,AIndex,BIndex+1,CIndex+1,dp);
        }
    }
    int returnValue = way1 || way2;
    dp[AIndex][BIndex][CIndex] = returnValue;
    return returnValue;
}
int isInterLeaving(const std::string &A, const std::string &B, const std::string &C){
    using namespace std;{
        vector<vector<vector<int> > > dp(101,vector<vector<int>>(101,vector<int>(150,-1)));
        int returnValue = helper(A,B,C,0,0,0,dp);
        return returnValue;
    }
}
int main(){
    std::string A,B,C;
    std::cin>>A>>B>>C;
    std::cout<<isInterLeaving(A,B,C);
    return 0;
}