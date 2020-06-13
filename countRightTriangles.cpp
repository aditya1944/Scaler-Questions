#include<iostream>
#include<vector>
#include<unordered_map>
#define mod 1000000007
int solve(const std::vector<int> &X, const std::vector<int> &Y){
    int returnValue = 0;
    std::unordered_map<int, int> hashX,hashY;
    int size = X.size();
    for(int index = 0;index<size;++index){
        ++hashX[X[index]];
    }
    for(int index = 0;index<size;++index){
        ++hashY[Y[index]];
    }
    for(int index = 0;index<size;++index){
        int x = X[index];
        int y = Y[index];
        int XPointsExecptThis = hashX[x]-1;
        int YPointsExceptThis = hashY[y]-1;
        //std::cout<<"returnValue: "<<returnValue<<std::endl;
        returnValue = ((long long)returnValue + ((long long)XPointsExecptThis * (long long)YPointsExceptThis)%mod)%mod;
    }
    return returnValue;
}
int main(){
    int N;
    std::cin>>N;
    std::vector<int> X(N);
    std::vector<int> Y(N);
    for(int index = 0;index<N;++index){
        std::cin>>X[index];
    }
    for(int index = 0;index<N;++index){
        std::cin>>Y[index];
    }
    int output = solve(X,Y);
    std::cout<<output<<std::endl;
    return 0;
}