#include<iostream>
int main(){
    int N;
    std::cin>>N;
    if(N<2){
        return N;
    }
    //f[i] = f[i-1] + f[i-2];
    int first = 0,second = 1;
    int currCount = 2;
    while(currCount<=N){
        int next = first + second;
        first = second;
        second = next;
        ++currCount;
    }
    std::cout<<second<<std::endl;
    return 0;
}