#include<iostream>
#include<vector>
bool canJump(const std::vector<int> &nums){
    if(nums.size()==1){
        return true;
    }
    int maxIndexTillNow = 0;
    const int destIndex = nums.size()-1;
    for(int index = 0;index<nums.size();++index){
        if(maxIndexTillNow<index){
            return false;
        }
        maxIndexTillNow = std::max(maxIndexTillNow,nums[index] + index);
        if(maxIndexTillNow>=destIndex){
            return true;
        }
    }
}
int main(){
    int N;
    std::cin>>N;
    std::vector<int> vec(N);
    for(int index = 0;index<N;++index){
        std::cin>>vec[index];
    }
    std::cout<<canJump(vec)<<std::endl;
    return 0;
}