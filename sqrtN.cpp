#include<iostream>
int solve(int N){
    int low = 1, high = N;
    int ans = 1;
    while(low<=high){
        int mid = low + (high - low)/2;
        if(mid*mid>N){
            high = mid-1;
        }
        else{
            ans = mid;
            low = mid+1;
        }
    }
    return ans;
}
int main(){
    int N;
    std::cin>>N;
    int output = solve(N);
    std::cout<<output<<std::endl;
    return 0;
}