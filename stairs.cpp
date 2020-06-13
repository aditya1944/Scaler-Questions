#include<iostream>
int solve(int N){
    //f[i] = f[i-1] + f[i-2];
    if(N==0 || N==1){
        return 1;
    }
    else if(N==2){
        return 2;
    }
    int first = 1,second = 2;
    int currCount = 3;
    while(currCount<=N){
        int next = first + second;
        first = second;
        second = next;
        ++currCount;
    }
    return second;
}
int main(){
    int N;
    std::cin>>N;
    int output = solve(N);
    std::cout<<output<<std::endl;
    return 0;
}