#include<iostream>
#include<vector>
#define mod 10003
int solve(int A) {
    //f[i] = f[i-1] + (i-1) * f(i-2);
    if(A<3){
        return A;
    }
    int first = 1,second = 2;
    int count = 3;
    while(count<=A){
        int next = (first + ((count-1)%mod * second%mod)%mod)%mod;
        first = second;
        second = next;
        ++count;
    }
    return second;
}
int main(){
    int N;
    std::cin>>N;
    std::cout<<solve(N)<<std::endl;
    return 0;
}