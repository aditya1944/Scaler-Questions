#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
int findMaxPow(int N){
    int pow = 0;
    int temp = 1;
    while(1){
        temp = temp*3;
        if(temp>N){
            break;
        }
        ++pow;
    }
    return pow;
}
std::vector<int> solve(int N){
    //use powers of 3
    std::vector<int> returnValue;
    if(N<3){
        returnValue.push_back(-1);
        return returnValue;
    }
    int sum = 0;
    int temp1 = N;
    while(sum<temp1){
        int maxPow = findMaxPow(N);
        //std::cout<<maxPow<<std::endl;
        int temp = pow(3, maxPow);
        sum+=temp;
        returnValue.push_back(temp);
        N = N-temp;
    }
    std::sort(returnValue.begin(), returnValue.end());
    return returnValue;
}
int main(){
    int N;
    std::cin>>N;
    std::vector<int> output = solve(N);
    for(int &x: output){
        std::cout<<x<<" ";
    }
    return 0;
}